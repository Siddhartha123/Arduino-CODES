#include <ESP8266WiFi.h>
#include "ESP8266WebServer.h"
#include<FS.h>
const char* ssid = "SONU-MI";
const char* password = "12345678";
ESP8266WebServer server(80); 
 void setup() {
  // put your setup code here, to run once:
 Serial.print("Connecting to ");
  Serial.println(ssid);
 SPIFFS.begin();
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

  server.on("/",std::bind(f));
}
void f(){
  
 File file = SPIFFS.open("/dash/img/logo.png", "r");
    server.sendHeader("Cache-Control", "max-age=2628000,public");
    server.streamFile(file, "image/png");
    file.close();
}
void loop() {
  server.handleClient();
}
