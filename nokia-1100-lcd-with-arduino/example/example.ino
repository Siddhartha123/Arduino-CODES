#include <Arduino.h>
#include "driver_nokia_1100_lcd.h"
void setup(){
        lcd_init();
        lcd_gotoyx(2,2);
        lcd_string("Hye  :)");
        delay(5000);
        lcd_clear();
        lcd_gotoyx(0,0);
}
void loop(){
  lcd_string("Nokia ");
  delay(2000);
  lcd_string("1100 ");
  delay(2000);
  lcd_string("LCD ");
  delay(2000);
  lcd_string("- SaKul");
  delay(2000);
  lcd_clear();
  lcd_gotoyx(0,0);
  delay(2000);
  
}
