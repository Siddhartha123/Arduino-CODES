#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal_PCF8574.h>
RTC_DS1307 rtc;
LiquidCrystal_PCF8574 lcd(0x27); 
char daysOfTheWeek[7][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
char months[12][4]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","SEP","OCT","NOV","DEC"};
  int error;
void setup() {
   Serial.begin(115200);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  Wire.pins(0,2);
  Wire.begin();
  Wire.beginTransmission(0x27);
  error = Wire.endTransmission();
  if (error == 0) {
    Serial.println(" LCD found.");
    lcd.begin(16, 2); // initialize the lcd
    lcd.clear();
    lcd.print("DIGITAL CLOCK");
}
}

void loop() {
  lcd.home();
  lcd.clear();
  lcd.setCursor(1, 0);
   DateTime now = rtc.now();
   lcd.print(now.hour(), DEC);
    lcd.print(':');
    lcd.print(now.minute(), DEC);
    lcd.print(' ');
   lcd.print(now.day(), DEC);
   lcd.print('/');
    lcd.print(now.month()); //months[now.month()-1]
    lcd.print(' ');
    lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
     //lcd.setCursor(0, 1);
    delay(1000);
}
