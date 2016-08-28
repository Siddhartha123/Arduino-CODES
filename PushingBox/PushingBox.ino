#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>

byte mac[] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF };  //Replace with your Ethernet shield MAC
byte ip[] = {123,456,7,890};     // Your Arduino device IP address
char devid[] = "v42FE15BC09B20df";  // THIS IS THE DEVICE ID FROM PUSHINGBOX

char postmsg[100];
char server[] = "api.pushingbox.com";
EthernetClient client;
 
 
void setup()
{
  Ethernet.begin(mac, ip);
  delay(1000);
}
 
void loop()
{
  // Post to Google Form.............................................
  if (client.connect(server, 80)) 
  {
    sprintf(postmsg,"GET /pushingbox?devid=%s HTTP/1.1",devid);  // NOTE** In this line of code you can see where the temperature value is inserted into the web address. It follows 'status=' Change that value to whatever you want to post.
    client.println(postmsg);
    client.println("Host: api.pushingbox.com");
    client.println("Connection: close");
    client.println();
    delay(1000);
    client.stop();
  }
  delay(1000);
  if (!client.connected()) 
  {
    client.stop();
    return;
  }
  
 
}
