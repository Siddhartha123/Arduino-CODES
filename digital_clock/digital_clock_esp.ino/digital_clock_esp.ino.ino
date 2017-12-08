#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
#include <ESP8266WiFi.h>
const char* ssid = "LENOVO_WIFI";
const char* password = "12345678";
const char* host = "192.168.206.11";
const int httpPort = 80;
tmElements_t tm;
void setup()
{
    Serial.begin(115200);
    Serial.println();
    Serial.print("connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
}

bool getTime(String str)
{
    tm.Hour = str.substring(0, 1).toInt();
    tm.Minute = str.substring(3, 4).toInt();
    tm.Second = str.substring(6, 7).toInt();
    tm.Day = str.substring(8, 9).toInt();
    tm.Month = str.substring(11, 12).toInt();
    tm.Year = str.substring(14, 17).toInt();
    return true;
}

void loop()
{
    if (WiFi.status() == WL_CONNECTED) {
        WiFiClient client;
        if (client.connect(host, httpPort)) {
            String url = "/iot/now.php";
            Serial.print("requesting URL: ");
            Serial.println(url);
            client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: 192.168.206.11\r\n" + "Connection: close\r\n\r\n");
            Serial.println("request sent");
            String line = client.readString();
            Serial.println(line);
            if (getTime(&line[0])) {
                RTC.write(tm);
            }
        }
    }
}
