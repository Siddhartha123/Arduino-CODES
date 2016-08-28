#include <SoftwareSerial.h>
//#define _SS_MAX_RX_BUFF 256 
#define ESP8266_rxPin 2
#define ESP8266_txPin 3

#include <avr/power.h>

//SSID + KEY
const char SSID_ESP[] = "LENOVO_WIFI";
const char SSID_KEY[] = "skumar2k16";

// URLs
String URL_webhost = "GET http://www.kevindarrah.com/micro/ESP_part3/from_micro.php?unit=";
//MODES
const char CWMODE = '1';//CWMODE 1=STATION, 2=APMODE, 3=BOTH
const char CIPMUX = '1';//CWMODE 0=Single Connection, 1=Multiple Connections

SoftwareSerial ESP8266(ESP8266_rxPin, ESP8266_txPin);// rx tx

//DEFINE ALL FUNCTIONS HERE
boolean setup_ESP();
boolean read_until_ESP(const char keyword1[], int key_size, int timeout_val, byte mode);
void timeout_start();
boolean timeout_check(int timeout_ms);
void serial_dump_ESP();
boolean connect_ESP();
void connect_webhost();

//DEFINE ALL GLOBAL VAARIABLES HERE
int unit_id = 1;
int sensor_value = 123;
int sensor_readBack = 0;
unsigned long timeout_start_val;
char scratch_data_from_ESP[20];//first byte is the length of bytes
char payload[150];
byte payload_size=0, counter=0;
char ip_address[16];
String URL_withPacket = "                                                                                                    ";
String payload_closer = " HTTP/1.0\r\n\r\n";
unsigned long multiplier[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int LED_value = 0;

char t1_from_ESP[5];
char d1_from_ESP[11];
char d2_from_ESP[11];

//DEFINE KEYWORDS HERE
const char keyword_OK[] = "OK";
const char keyword_Ready[] = "Ready";
const char keyword_no_change[] = "no change";
const char keyword_blank[] = "#&";
const char keyword_ip[] = "192.";
const char keyword_rn[] = "\r\n";
const char keyword_quote[] = "\"";
const char keyword_carrot[] = ">";
const char keyword_sendok[] = "SEND OK";
const char keyword_linkdisc[] = "Unlink";
const char keyword_t1[] = "t1";
const char keyword_d1[] = "d1";
const char keyword_d2[] = "d2";
const char keyword_doublehash[] = "##";


void setup(){//        SETUP     START
  //Pin Modes for ESP TX/RX
  pinMode(ESP8266_rxPin, INPUT);
  pinMode(ESP8266_txPin, OUTPUT);
  
  ESP8266.begin(115200);//default baudrate for ESP
 // ESP8266.listen();//not needed unless using other software serial instances
  Serial.begin(9600); //for status and debug
  connect_ESP();
  //delay(5000);//delay before kicking things off
  //setup_ESP();//go setup the ESP 
}//                    SETUP     END

void loop(){//         LOOP     START
}//                    LOOP     END
