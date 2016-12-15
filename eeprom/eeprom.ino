#include<EEPROM.h>
float i=10;
float h;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
EEPROM.put(0,i);
EEPROM.get(0,h);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(h);
}
