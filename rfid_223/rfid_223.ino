#include <SoftwareSerial.h>

SoftwareSerial rfid(10, 10); // RX, TX
int count = 0;                                          // count = 0
char input[12];                                         // character array of size 12 
boolean flag = 0;                                       // flag =0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 rfid.begin(9600);
attachInterrupt(digitalPinToInterrupt(2),test,FALLING);
}

void test(){
  sei();
  Serial.println("Card detected");
  count = 0;
      while( count < 12)          // Read 12 characters and store them in input array
      {
         //input[count] = rfid.read();
         while(!rfid.available());
         input[count]=rfid.read();
         count++;
      }
      Serial.println(input);
      if((input[0] ^ input[2] ^ input[4] ^ input[6] ^ input[8] == input[10]) &&  (input[1] ^ input[3] ^ input[5] ^ input[7] ^ input[9] == input[11]))
            Serial.println("No Error");
      else
            Serial.println("Error");      
}
void loop(){
  
}

