#include "PCF8574.h"
#include <Wire.h>

// adjust addresses if needed
PCF8574 PCF_27(0x38);  // add switches to lines  (used as input)
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
  Serial.println("\nTEST PCF8574\n");
PCF_27.write(3,1);
}
void loop() {
  // put your main code here, to run repeatedly:
PCF_27.write(1,1);
delay(1000);
PCF_27.write(1,0);
delay(1000);

}
