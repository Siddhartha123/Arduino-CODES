#include "PCF8574.h"
#include <Wire.h>

// adjust addresses if needed
PCF8574 PCF_27(0x27);  // add switches to lines  (used as input)
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
  Serial.println("\nTEST PCF8574\n");

}
  uint8_t value=0;
void loop() {
  // put your main code here, to run repeatedly:
value = PCF_27.read(3);
Serial.println(value);
delay(700);
}
