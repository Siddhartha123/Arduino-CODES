#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// make some custom characters:
byte c1[8] = {
  0b11111,
  0b11111,
  0b11000,
  0b11000,
  0b11000,
  0b11000,
  0b11000,
  0b11111
};
byte c2[8] = {
  0b11111,
  0b11111,
  0b00011,
  0b00011,
  0b00011,
  0b00011,
  0b00011,
  0b11111
};

byte c3[8] = {
  0b11111,
  0b11000,
  0b11000,
  0b11000,
  0b11000,
  0b11000,
  0b11111,
  0b11111
};

byte c4[8] = {
  0b11111,
  0b00011,
  0b00011,
  0b00011,
  0b00011,
  0b00011,
  0b11111,
  0b11111
};



void setup() {
  // initialize LCD and set up the number of columns and rows:
  lcd.begin(16, 2);

  // create a new character
  lcd.createChar(10, c1);
  lcd.createChar(11, c2);
    lcd.createChar(12, c3);
        lcd.createChar(13, c4);
lcd.setCursor(0,0);
  lcd.write(byte(10)); // when calling lcd.write() '0' must be cast as a byte
lcd.setCursor(1,0);
  lcd.write(byte(11)); // when calling lcd.write() '0' must be cast as a byte
lcd.setCursor(0,1);
  lcd.write(byte(12)); // when calling lcd.write() '0' must be cast as a byte
  lcd.setCursor(1,1);
  lcd.write(byte(13)); // when calling lcd.write() '0' must be cast as a byte
}

void loop() {

}
