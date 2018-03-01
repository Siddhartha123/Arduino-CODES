#include <ESP8266WiFi.h>
const char* ssid = "abc";
const char* pass = "123456789";
int status = WL_IDLE_STATUS;
char servername[]="192.168.43.245";  // remote server we will connect to

WiFiClient client;

void setup() {
  Serial.begin(115200);
  Serial.println("Attempting to connect to WPA network...");
  Serial.print("SSID: ");
  Serial.println(ssid);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
    Serial.println("Connected to wifi");
    Serial.println("\nStarting connection...");
    // if you get a connection, report back via serial:
    if (client.connect(servername, 80)) {
      Serial.println("connected");
      // Make a HTTP request:
      client.println("GET /iot/request.php?id=123 HTTP/1.0");
      client.println();
    
    }
  
}

void loop() {
if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }

}
