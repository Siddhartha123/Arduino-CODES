#include <ESP8266WiFi.h>
char value;
char input[12];
int idx;
String rfid;
int count = 0;
String input1;
const char* ssid = "abc";
const char* password = "123456789";
int status = WL_IDLE_STATUS;
char servername[] = "192.168.43.229"; // remote server we will connect to
String c;
WiFiClient client;
int ledPin = LED_BUILTIN;
WiFiServer server(80);

void setup()
{
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

void loop()
{
    if (Serial.available()) // CHECK FOR AVAILABILITY OF SERIAL DATA
    {
        count = 0; // Reset the counter to zero

        while (Serial.available() && count < 12) {
            input[count] = Serial.read(); // Read 1 Byte of data and store it in the input[] variable
            count++; // increment counter delay(5); }
            delay(5);
        }
        Serial.flush();
        rfid = input;
        Serial.print(input); // PRINTING RFID TAG
        //Serial.println(rfid);
        Serial.println();
        input1 = "GET /room_automation/mcu_request.php?id=" + rfid + " HTTP/1.0";

        if (client.connect(servername, 80)) {
            Serial.println("connected");
            // Make a HTTP request:
            //Serial.println("Request Sent");
            client.println(input1);

            client.println();
            while (1) {
                if (client.available()) {
                    c = client.readString();
                    Serial.print(c);
                    int s = c.indexOf("ACCESS=");
                    if (c[s + 7] == '1') {
                        Serial.println("Access granted");
                        break;
                    }
                    else {
                        Serial.println("Not Recognised");
                        break;
                    }
                }
            }
        }
        else {
            Serial.println("cant connect");
        }
    }

    // Check if a client has connected
    WiFiClient client = server.available();
    if (!client) {
        return;
    }

    // Wait until the client sends some data
    Serial.println("new client");
    while (!client.available()) {
        delay(1);
    }
    Serial.println("Sending request");
    // Read the first line of the request
    String request = client.readString();
    Serial.println(request);
    client.flush();

    // Match the request
    idx = request.indexOf("id=");
    if (idx != -1) {
        if (request.substring(idx + 3, idx + 6) == "off") {
            Serial.println("Turn the led on");
        }
        else {
            Serial.println("Not allowed");
        }
    }

    // Set ledPin according to the request
    //digitalWrite(ledPin, value);
    delay(1000);
    // Return the response
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.println(""); //  do not forget this one
    Serial.println("Client disonnected");
    Serial.println("");
}
