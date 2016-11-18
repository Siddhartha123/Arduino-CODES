#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX

void setup() 
{
  BTSerial.begin(9600);  // HC-05 default speed in AT command more
}

void loop()
{
BTSerial.println("hi");
delay(1000);
}


