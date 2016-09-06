#define SERIAL_BUFFER_SIZE 512
#include <ESP8266.h>


ESP8266 wifi(Serial2);

void setup(void)
{
  
}

void loop(void)
{
while(1)
{
 wifi.GPIO(1,LOW);
 delay(1000);
  wifi.GPIO(1,HIGH);
 delay(1000);
}
}

