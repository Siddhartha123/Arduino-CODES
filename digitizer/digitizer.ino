#include <ESP8266WiFi.h>
#define l1 D1
#define l2 D2
#define r1 D4
#define r2 D3
#define  pwml_pin D5
#define pwmr_pin D6
int pwmr,pwml;
int d;
char stat=0;
const char* ssid = "SONU-MI";
const char* password = "12345678";
WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  pinMode(r1, OUTPUT);
    pinMode(r2, OUTPUT);
   pinMode(l1, OUTPUT);
     pinMode(l2, OUTPUT);
       pinMode(pwmr_pin, OUTPUT);
         pinMode(pwml_pin, OUTPUT);
forward();
analogWrite(pwmr_pin,1023);
    analogWrite(pwml_pin,1023);
    

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
    
    stat=request[request.indexOf("stat=")+5 ];
    if(stat=='0')
   halt();
   else if(stat=='1')  forward();
   else if(stat=='2')  left();
   else if(stat=='3') right();
    pwmr=4*request[request.indexOf("pwmr=")+5 ];
    pwml=4*request[request.indexOf("pwml=")+5 ];
    analogWrite(pwmr_pin,pwmr);
    analogWrite(pwml_pin,pwml);
    d=request[request.indexOf("d=")+2];
    delay(d);
    halt();
// Set ledPin according to the request
//digitalWrite(ledPin, value);
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: application/json");
  client.println(""); //  do not forget this one
  client.print("{\"pwmr\":");
  client.print((int)pwmr);
   client.print(",\"pwml\":");
  client.print((int)pwml);
     client.print(",\"delay\":");
  client.print((int)d);
     client.print(",\"status\":");
  client.print((int)stat);
  client.println("}");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
void halt(){
  digitalWrite(r1,LOW);
digitalWrite(r2,LOW);
digitalWrite(l1,LOW);
digitalWrite(l2,LOW);
}

void forward(){
  digitalWrite(r1,HIGH);
digitalWrite(r2,LOW);
digitalWrite(l1,HIGH);
digitalWrite(l2,LOW);
}

void left(){
  digitalWrite(r1,HIGH);
digitalWrite(r2,LOW);
digitalWrite(l2,HIGH);
digitalWrite(l1,LOW);
}

void right(){
  digitalWrite(r2,HIGH);
digitalWrite(r1,LOW);
digitalWrite(l1,HIGH);
digitalWrite(l2,LOW);
}


