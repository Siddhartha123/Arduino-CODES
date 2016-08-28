
#include <SoftwareSerial.h>
#include <ESP8266.h>

SoftwareSerial mySerial(2,3); /* RX:D2, TX:D3 */
ESP8266 wifi(mySerial);

void setup(void)
{
 wifi.GPIO(1,HIGH);
 delay(1000);
 wifi.GPIO(1,LOW);
 delay(1000);
}

void loop(void)
{
}

