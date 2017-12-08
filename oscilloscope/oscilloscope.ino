#include "TLC2543.h"
TLC2543 oscilloscope;
void setup() {
  // put your setup code here, to run once:
oscilloscope.begin();
Serial.begin(250000);
delay(500);

byte mode=0x06;
pinMode(3,OUTPUT);
TCCR2B=TCCR2B & 0b11111000 | mode;
analogWrite(3,128);
      digitalWrite(chipSelectPin, LOW);
      delayMicroseconds(10);
}
float x,y;

void loop() {
  // put your main code here, to run repeatedly:
x=((float)oscilloscope.readAdc(1)+1)*5/4096;
Serial.println(x);
}
