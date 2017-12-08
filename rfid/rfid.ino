// RFID_UART.ino

#include <SoftwareSerial.h>

#define RFID_RX_PIN 10
#define RFID_TX_PIN 11

// #define DEBUG
// #define TEST

SoftwareSerial RFID(RFID_RX_PIN, RFID_TX_PIN);

void setup() {
  
  Serial.begin(115200);
  Serial.println("RFID Test..");
  RFID.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), f, FALLING);
}

void loop() { 
while(RFID.available())
{
  Serial.print(char(RFID.read()));
}
}
void f()
{
  Serial.println("hi");
}

