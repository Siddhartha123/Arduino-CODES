#include <ESP8266WiFi.h>
 
const char* ssid = "LENOVO_WIFI";
const char* password = "12345678";
 
int ledPin = D5; // GPIO13
WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
   char value;
   int idx;
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readString();
  Serial.println(request);
  client.flush();
 
  // Match the request
 


    idx=request.indexOf("val=") ;
    if(idx!=-1)
    {
      if(request[idx+4]==49)
      value=value+2;
      else if(request[idx+4]=48)
      value=value-2;
      analogWrite(ledPin,value);
    }
 
// Set ledPin according to the request
//digitalWrite(ledPin, value);
 delay(1000);
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: application/json");
  client.println(""); //  do not forget this one
  client.print("{\"val\":");
  client.print((int)value);
  client.println("}");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
 
