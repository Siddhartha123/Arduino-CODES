#include<SoftwareSerial.h>
SoftwareSerial wifi(2,3);

void setup() {
wifi.begin(115200);
Serial.begin(9600);
Serial.setTimeout(1500);
wifi.print("AT\n");
Serial.println(wifi.readString());

}

void loop() {
  // put your main code here, to run repeatedly:

}
