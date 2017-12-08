/*
  NOKIA 1100 Screen
  This is the driver of the LCD based on code by spiralbrain
  modified by:
  name:kuldeep singh dhaka
  email:kuldeepdhaka9@gmail.com
  date:17 May 2012
  Source: http://sunbizhosting.com/~spiral/ 
  
  Driver For  Arduino Dueminalove Atmega328
  Interfacing with the Nokia 1100 LCD, PCF8814 ( 96X65 )
  
  licence: gpl-v3 http://www.gnu.org/licenses/gpl.html [i just want to make its source available to every one]
*/
/*
  PIN configuration:
  
  to know the pins, view the screen from front, pin 1 is on right side
  read : http://www.circuitvalley.com/2011/09/nokia-1100-lcd-interfacing-with.html
  example
    |-----------------|
    |  screen         |
    |    front        |
    |_________________|
     | | | | | | | | |
     1 2 3 4 5 6 7 8 9
     
     PIN 1: XRES
     PIN 2: XCS
     PIN 3: GND
     PIN 4: SDA
     PIN 5: SCLK
     PIN 6: VDDI
     PIN 7: VDD
     PIN 8: LED+
     PIN 9: Unused

	 WE shorted PIN 6,7,8
	the lcd needs 3v logic therefore we are using potentiometers
*/
#define DEFAULT_PIN_CONIF /* use defined pin config */
#ifdef DEFAULT_PIN_CONIF
#define LCD_PIN_SCE 10
#define LCD_PIN_SDIN 11
#define LCD_PIN_RESET 12
#define LCD_PIN_SCLK 13
#else 
#error define pin-out attached to arduino. 
#endif
/*
  contrast can be varied by or'ing with LED_VOB_LSB|contrast value
  for info see LED_VOB_LSB
*/
#define LCD_CONTRAST 0x05
/*
	contain the screen height and width in pixel
*/
#define SCREEN_HEIGHT 65
#define SCREEN_WIDTH 96
/*
	flags used to understand by lcd if the bits is taken as command or store in ram
*/
#define FLAG_CMD LOW
#define FLAG_DATA HIGH
/*
  some constants that will be ored with command to effect
    ON : turn on the command
    OFF : turn off the command
    DISPLAY: turn display on/of used with LCD_MODE only, (LCD_MODE|DISPLAY|ON/OFF)
    ALL : turn on all , only used with LCD_MODE , (LCD_MODE|ALL|ON/OFF) use off for normal display
    INVERT : invert pixels, only used with LCD_MODE , (LCD_MODE|INVERT|ON/OFF) , it bring lcd into normal form use off
  *note: you can use (LCD_MODE|ALL/INVERT|OFF)  to bring lcd into normal mode
*/
#define ON 0x01
#define OFF 0x00
#define ALL 0x04
#define INVERT 0x06
#define DISPLAY 0x0E
/*
	Command list of list
        LCD_NOP                                 : no operation
	LCD_MODE				: lcd  mode, LCD_MODE|(ALL/INVERT/DISPLAY|ON/OFF)
	LCD_VOB_MSB				: use LCD_VOB_MSB|0x04 ,the value after | is a mystry,dont mess(previos notice)
	LCD_VOB_LSB				: use LCD_VOB_LSB|(contrast value,0x00 to 0x1F)
	LCD_CHARGE_PUMP_ON 		: read the datasheet , i could nt understand
								voltage muliplication          value
								     X2							0x00
									 X3							0x01
									 X4							0x02
									 X5							0x03
	LCD_RAM_ADDR_MODE		: use LCD_RAM_ADDR_MODE|(conditon ,OFF/ON),write in RAM,
								 OFF : write horizontally (by default)
								 ON : write vertically
	LCD_CHANGE_ROW_LSB				: accessed by LCD_ROW_LSB|(b3 b2 b1 b0), last four bits of the address
	LCD_CHANGE_ROW_MSB				: accessed by LCD_ROW_MSB|(b6 b5 b4),first 3 bits of the address; alias is 0x18
	LCD_CHANGE_COL					: move to col,LCD_COL|(b2 b1 b0)
	LCD_MIRROR_Y			: mirror on y axis , use(LCD_MIRROR_Y| condition 0x08 or OFF)
								turn on/enable mirroring, conditon->0x08 , dont use ON because its 0x01
								turn off/disable mirroring, conditon->OFF
	LCD_MIRROR_X			: turn on mirroring on x axis . this is a speical instruction & 
                                          i couldt found|dont exists reset counter; its alias is 0xA0,didnt worked,
                                          and datasheet says , NOP: MX is pad selected?
	LCD_EXT_OSC				: use a external oscillator (LCD_EXT_OSC|ON / OFF)
	LCD_SOFT_RESET			: internal or software reset
 * special instruction: use 0x08 not ON for enabling LCD_MIRROR_X
*/
#define LCD_NOP 0xE3
#define LCD_MODE 0xA0
#define LCD_VOB_MSB 0x20
#define LCD_VOB_LSB 0x80
#define LCD_CHARGE_PUMP_ON 0x2F
#define LCD_RAM_ADDR_MODE 0xAA
#define LCD_CHANGE_ROW_LSB 0x00
#define LCD_CHANGE_ROW_MSB 0x10
#define LCD_CHANGE_COL 0xB0
#define LCD_MIRROR_Y 0xC0
#define LCD_MIRROR_X 0xA0
#define LCD_EXT_OSC 0x3A
#define LCD_SOFT_RESET 0xE2
//#define LCD_DATA_DISPLAY_LEN , read page no 27
//#define LCD_FACTORY_DEFAULT ,read page no 27 of datasheet
//#define LCD_REFRESH_RATE ,read page 27,29 of datasheet
/*----------------------------------------------------------------------------------------------*/
#define CHAR_WIDTH 6
#define CHAR_HEIGHT 8
static const byte ASCII[][CHAR_WIDTH] ={
   {0x00, 0x00, 0x00, 0x00, 0x00, 0x00} // 20
  ,{0x00, 0x00, 0x00, 0x5f, 0x00, 0x00} // 21 !
  ,{0x00, 0x00, 0x07, 0x00, 0x07, 0x00} // 22 "
  ,{0x00, 0x14, 0x7f, 0x14, 0x7f, 0x14} // 23 #
  ,{0x00, 0x24, 0x2a, 0x7f, 0x2a, 0x12} // 24 $
  ,{0x00, 0x23, 0x13, 0x08, 0x64, 0x62} // 25 %
  ,{0x00, 0x36, 0x49, 0x55, 0x22, 0x50} // 26 &
  ,{0x00, 0x00, 0x05, 0x03, 0x00, 0x00} // 27 '
  ,{0x00, 0x00, 0x1c, 0x22, 0x41, 0x00} // 28 (
  ,{0x00, 0x00, 0x41, 0x22, 0x1c, 0x00} // 29 )
  ,{0x00, 0x14, 0x08, 0x3e, 0x08, 0x14} // 2a *
  ,{0x00, 0x08, 0x08, 0x3e, 0x08, 0x08} // 2b +
  ,{0x00, 0x00, 0x50, 0x30, 0x00, 0x00} // 2c ,
  ,{0x00, 0x08, 0x08, 0x08, 0x08, 0x08} // 2d -
  ,{0x00, 0x00, 0x60, 0x60, 0x00, 0x00} // 2e .
  ,{0x00, 0x20, 0x10, 0x08, 0x04, 0x02} // 2f /
  ,{0x00, 0x3e, 0x51, 0x49, 0x45, 0x3e} // 30 0
  ,{0x00, 0x00, 0x42, 0x7f, 0x40, 0x00} // 31 1
  ,{0x00, 0x42, 0x61, 0x51, 0x49, 0x46} // 32 2
  ,{0x00, 0x21, 0x41, 0x45, 0x4b, 0x31} // 33 3
  ,{0x00, 0x18, 0x14, 0x12, 0x7f, 0x10} // 34 4
  ,{0x00, 0x27, 0x45, 0x45, 0x45, 0x39} // 35 5
  ,{0x00, 0x3c, 0x4a, 0x49, 0x49, 0x30} // 36 6
  ,{0x00, 0x01, 0x71, 0x09, 0x05, 0x03} // 37 7
  ,{0x00, 0x36, 0x49, 0x49, 0x49, 0x36} // 38 8
  ,{0x00, 0x06, 0x49, 0x49, 0x29, 0x1e} // 39 9
  ,{0x00, 0x00, 0x36, 0x36, 0x00, 0x00} // 3a :
  ,{0x00, 0x00, 0x56, 0x36, 0x00, 0x00} // 3b ;
  ,{0x00, 0x08, 0x14, 0x22, 0x41, 0x00} // 3c <
  ,{0x00, 0x14, 0x14, 0x14, 0x14, 0x14} // 3d =
  ,{0x00, 0x00, 0x41, 0x22, 0x14, 0x08} // 3e >
  ,{0x00, 0x02, 0x01, 0x51, 0x09, 0x06} // 3f ?
  ,{0x00, 0x32, 0x49, 0x79, 0x41, 0x3e} // 40 @
  ,{0x00, 0x7e, 0x11, 0x11, 0x11, 0x7e} // 41 A
  ,{0x00, 0x7f, 0x49, 0x49, 0x49, 0x36} // 42 B
  ,{0x00, 0x3e, 0x41, 0x41, 0x41, 0x22} // 43 C
  ,{0x00, 0x7f, 0x41, 0x41, 0x22, 0x1c} // 44 D
  ,{0x00, 0x7f, 0x49, 0x49, 0x49, 0x41} // 45 E
  ,{0x00, 0x7f, 0x09, 0x09, 0x09, 0x01} // 46 F
  ,{0x00, 0x3e, 0x41, 0x49, 0x49, 0x7a} // 47 G
  ,{0x00, 0x7f, 0x08, 0x08, 0x08, 0x7f} // 48 H
  ,{0x00, 0x00, 0x41, 0x7f, 0x41, 0x00} // 49 I
  ,{0x00, 0x20, 0x40, 0x41, 0x3f, 0x01} // 4a J
  ,{0x00, 0x7f, 0x08, 0x14, 0x22, 0x41} // 4b K
  ,{0x00, 0x7f, 0x40, 0x40, 0x40, 0x40} // 4c L
  ,{0x00, 0x7f, 0x02, 0x0c, 0x02, 0x7f} // 4d M
  ,{0x00, 0x7f, 0x04, 0x08, 0x10, 0x7f} // 4e N
  ,{0x00, 0x3e, 0x41, 0x41, 0x41, 0x3e} // 4f O
  ,{0x00, 0x7f, 0x09, 0x09, 0x09, 0x06} // 50 P
  ,{0x00, 0x3e, 0x41, 0x51, 0x21, 0x5e} // 51 Q
  ,{0x00, 0x7f, 0x09, 0x19, 0x29, 0x46} // 52 R
  ,{0x00, 0x46, 0x49, 0x49, 0x49, 0x31} // 53 S
  ,{0x00, 0x01, 0x01, 0x7f, 0x01, 0x01} // 54 T
  ,{0x00, 0x3f, 0x40, 0x40, 0x40, 0x3f} // 55 U
  ,{0x00, 0x1f, 0x20, 0x40, 0x20, 0x1f} // 56 V
  ,{0x00, 0x3f, 0x40, 0x38, 0x40, 0x3f} // 57 W
  ,{0x00, 0x63, 0x14, 0x08, 0x14, 0x63} // 58 X
  ,{0x00, 0x07, 0x08, 0x70, 0x08, 0x07} // 59 Y
  ,{0x00, 0x61, 0x51, 0x49, 0x45, 0x43} // 5a Z
  ,{0x00, 0x00, 0x7f, 0x41, 0x41, 0x00} // 5b [
  ,{0x00, 0x02, 0x04, 0x08, 0x10, 0x20} // 5c ¥
  ,{0x00, 0x00, 0x41, 0x41, 0x7f, 0x00} // 5d ]
  ,{0x00, 0x04, 0x02, 0x01, 0x02, 0x04} // 5e ^
  ,{0x00, 0x40, 0x40, 0x40, 0x40, 0x40} // 5f _
  ,{0x00, 0x00, 0x01, 0x02, 0x04, 0x00} // 60 `
  ,{0x00, 0x20, 0x54, 0x54, 0x54, 0x78} // 61 a
  ,{0x00, 0x7f, 0x48, 0x44, 0x44, 0x38} // 62 b
  ,{0x00, 0x38, 0x44, 0x44, 0x44, 0x20} // 63 c
  ,{0x00, 0x38, 0x44, 0x44, 0x48, 0x7f} // 64 d
  ,{0x00, 0x38, 0x54, 0x54, 0x54, 0x18} // 65 e
  ,{0x00, 0x08, 0x7e, 0x09, 0x01, 0x02} // 66 f
  ,{0x00, 0x0c, 0x52, 0x52, 0x52, 0x3e} // 67 g
  ,{0x00, 0x7f, 0x08, 0x04, 0x04, 0x78} // 68 h
  ,{0x00, 0x00, 0x44, 0x7d, 0x40, 0x00} // 69 i
  ,{0x00, 0x20, 0x40, 0x44, 0x3d, 0x00} // 6a j
  ,{0x00, 0x7f, 0x10, 0x28, 0x44, 0x00} // 6b k
  ,{0x00, 0x00, 0x41, 0x7f, 0x40, 0x00} // 6c l
  ,{0x00, 0x7c, 0x04, 0x18, 0x04, 0x78} // 6d m
  ,{0x00, 0x7c, 0x08, 0x04, 0x04, 0x78} // 6e n
  ,{0x00, 0x38, 0x44, 0x44, 0x44, 0x38} // 6f o
  ,{0x00, 0x7c, 0x14, 0x14, 0x14, 0x08} // 70 p
  ,{0x00, 0x08, 0x14, 0x14, 0x18, 0x7c} // 71 q
  ,{0x00, 0x7c, 0x08, 0x04, 0x04, 0x08} // 72 r
  ,{0x00, 0x48, 0x54, 0x54, 0x54, 0x20} // 73 s
  ,{0x00, 0x04, 0x3f, 0x44, 0x40, 0x20} // 74 t
  ,{0x00, 0x3c, 0x40, 0x40, 0x20, 0x7c} // 75 u
  ,{0x00, 0x1c, 0x20, 0x40, 0x20, 0x1c} // 76 v
  ,{0x00, 0x3c, 0x40, 0x30, 0x40, 0x3c} // 77 w
  ,{0x00, 0x44, 0x28, 0x10, 0x28, 0x44} // 78 x
  ,{0x00, 0x0c, 0x50, 0x50, 0x50, 0x3c} // 79 y
  ,{0x00, 0x44, 0x64, 0x54, 0x4c, 0x44} // 7a z
  ,{0x00, 0x00, 0x08, 0x36, 0x41, 0x00} // 7b {
  ,{0x00, 0x00, 0x00, 0x7f, 0x00, 0x00} // 7c |
  ,{0x00, 0x00, 0x41, 0x36, 0x08, 0x00} // 7d }
  ,{0x00, 0x10, 0x08, 0x08, 0x10, 0x08} // 7e ->
  ,{0x00, 0x78, 0x46, 0x41, 0x46, 0x78} // 7f <- 
};
/*
	LCD_GOTOXY():
		note:
			move to a new position
		tricks:
			use LCD_ROW() & LCD_COL()
*/	
#define lcd_gotoyx(ROW,COL)\ 
    lcd_row(ROW);\
	lcd_col(COL);
#define lcd_on() lcd_normal();
/*-----------------------*/
void lcd_string(char *);
void lcd_character(char);
void lcd_row(byte);
void lcd_col(byte);
void lcd_clear();
void lcd_refresh();
void lcd_init();
void lcd_write(byte,byte);
void lcd_all();
void lcd_invert();
void lcd_normal();
void lcd_off_partial();
void lcd_off();
void lcd_contrast(byte value); 
/*----------------------------------------------------------------------------------------------*/
/*
	LCD_WRITE()
		note:
			send/write data to LCD
		trick:
			dont mess with it, i have prevous comment are
			LINE 1:
				dc is sampled with the first rising SCLK edge
			LINE 2:
				LCD enable
			LINE 3:
				First rising SCLK edge
			LINE 5:
				SDIN is sampled at the rising edge of SCLK.
*/
void lcd_write(byte dc,byte data){
	digitalWrite(LCD_PIN_SDIN, dc);
	digitalWrite(LCD_PIN_SCE, LOW);
	digitalWrite(LCD_PIN_SCLK, HIGH);
	digitalWrite(LCD_PIN_SCLK, LOW);
	shiftOut(LCD_PIN_SDIN, LCD_PIN_SCLK, MSBFIRST, data);
	digitalWrite(LCD_PIN_SCE, HIGH);
}
/*
	LCD_INIT():
		note:
			this define how will the pins will be used
			for more reference also read LCD_REFRESH() & LCD_CLEAR()
*/
void lcd_init(){
	pinMode(LCD_PIN_SCE, OUTPUT);
	pinMode(LCD_PIN_RESET, OUTPUT);
	pinMode(LCD_PIN_SDIN, OUTPUT);
	pinMode(LCD_PIN_SCLK, OUTPUT);
	digitalWrite(LCD_PIN_RESET, LOW);
	digitalWrite(LCD_PIN_SCE, HIGH);
	digitalWrite(LCD_PIN_SCLK, LOW);
	lcd_refresh();
	delay(200);
	lcd_clear();
}
/*
	LCD_REFRESH()
		note:
			* you can or a 5 bit binary number with LCD_VOB_LSB to set contrast [see datasheet for more]
				0x00 : lowest contrast
				0x01 : heigher than 0x00
				0x02 : heigher than 0x01
				.
				.
				.
				0x1F : heighest contrast
			* charge pump inbuild
				i didnt understood it use here but in prevous code is was there so didnt want to mess
			*we have to reset the deivce beacuse it is required for initalisation [see datasheet]
*/
void lcd_refresh(){
	digitalWrite(LCD_PIN_RESET, LOW);
	digitalWrite(LCD_PIN_RESET, HIGH);
	lcd_write(FLAG_CMD,LCD_CHARGE_PUMP_ON);
	lcd_contrast(LCD_CONTRAST);
	lcd_on();
}
/*
	LCD_CLEAR()
		note:
			every pixel is cleared by sending 0x00 for 864 times
			864 times because the their is a single pixel line at the last (65 pixel height)
*/
void lcd_clear(){
/*	date: 21/05/2012
	added lcd_gotoxy to reset at zero position
*/
	lcd_gotoyx(0,0);
	int index;
	for(index=0; index < 864; index++)
		lcd_write(FLAG_DATA,0x00);
/*
	date: 21/05/2012
	added to wait a while after clearing lcd
*/
	delay(200);
}
/*
	LCD_COL():
		note:
			set the X address or COLOUMN number for lcd
			it is send in two parts
				first the 4 LSB's
				second the 3 MSB's (exclude the 7 MSB)[first bit referenced as bit0]
				for example
					b7 | b6 | b5 | b4 | b3 | b2 | b1 | b0
					   |<- 2nd CMD  ->|<-   1St CMD   ->|
		tricks:
                        since we are using horizontal addressing mode thats why we are multiplying character size
			LINE 1:
				0x0F is used to remove 3 MSB BITS
			LINE 2:
				ADDR>>4 is used to shift the 3 MSB to right so that they can be send[read datasheet for why?]
				0x07 is used to remove the 8Th bit (that is now at 4th place after shifting)
*/
void lcd_col(byte addr){
	addr *= CHAR_WIDTH;
	lcd_write(FLAG_CMD,LCD_CHANGE_ROW_LSB | ( addr & 0x0F));
	lcd_write(FLAG_CMD,LCD_CHANGE_ROW_MSB | ( (addr >> 4) & 0x07 ));
}
/*
	LCD_ROW():
		note:
			set the x address or row number for lcd
			only 4 LSB's are send
			b7 | b6 | b5 | b4 | b3 | b2 | b1 | b0
					          |<-  only send  ->|
		tricks:
			LINE1:
				0x0F is used to remove the first 3 MSB's or only retain first 4 LSB's
							  
*/						
void lcd_row(byte addr){
	lcd_write(FLAG_CMD,LCD_CHANGE_COL | ( addr & 0x0F ));
}
/*
	LCD_STRING():
		note:
			print a string on lcd recursively
		trick:
			print character using LCD_CHARACTER()
*/
void lcd_string(char *string){
	while(*string)
	  lcd_character(*string++);
}
/*
	LCD_CHARACTER():
		note:
			print character to lcd
		trick:
			CHARACTER - 0x20 is make is eligible for ascii array
			it print recursily CHAR_WIDTH no of times 8 bit to lcd
*/
void lcd_character(char ch){
	byte index;
	for(index=0; index < CHAR_WIDTH; index++)\
		lcd_write(FLAG_DATA,ASCII[ ch -0x20 ][index]);
}
/*
  turn off the lcd by power down all its component
    Power-down mode,display off, row/col at VSS, oscillator off, HVgen disabled
  see datasheet page number 29,table 11
*/
void lcd_off(){
	lcd_write(FLAG_CMD,LCD_MODE|DISPLAY|OFF);
	lcd_write(FLAG_CMD,LCD_MODE|ALL|ON);
}
/*
  turn off the lcd by power down some components
    display off, row/col at VSS, oscillator on, HVgen enabled
  see datasheet page number 29,table 11
*/
void lcd_off_partial(){
	lcd_write(FLAG_CMD,LCD_MODE|DISPLAY|OFF);
	lcd_write(FLAG_CMD,LCD_MODE|ALL|OFF);
}
/*
  start or power on the lcd or power up
  see datasheet page number 29,table 11
*/
void lcd_normal(){
	lcd_write(FLAG_CMD,LCD_MODE|DISPLAY|ON);
	lcd_write(FLAG_CMD,LCD_MODE|ALL|OFF);
	lcd_write(FLAG_CMD,LCD_MODE|INVERT|OFF);
}
/*
  start or re-initalise lcd in inverse vedio mode
  see datasheet page number 29,table 11
*/
void lcd_invert(){
	lcd_write(FLAG_CMD,LCD_MODE|DISPLAY|ON);
	lcd_write(FLAG_CMD,LCD_MODE|ALL|OFF);
	lcd_write(FLAG_CMD,LCD_MODE|INVERT|ON);
}
/*
  start or re-initalise the lcd in all pixel mode
  see datasheet page number 29,table 11
*/
void lcd_all(){
	lcd_write(FLAG_CMD,LCD_MODE|DISPLAY|ON);
	lcd_write(FLAG_CMD,LCD_MODE|ALL|ON);
}
/*
  LCD_CONTRAST():
    note:
      change contrast of lcd
    trick:
      LINE 1:
        contrast value are feed into Vob register , 
        only 5 LSB bits are send so AND'd with
        0x1F to remove 3 MSB's
        see datasheet for more
*/
void lcd_contrast(byte value){
	lcd_write(FLAG_CMD,LCD_VOB_MSB|0x04);
	lcd_write(FLAG_CMD,LCD_VOB_LSB|(value & 0x1F));
}
