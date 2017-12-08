#define L1 20
#define L2 21
#define pwmL_pin  15

#define R1 22
#define R2 23
#define pwmR_pin 3           
uint8_t c;
char ch;


void setup() {
    
    pinMode(R1,OUTPUT);
    pinMode(R2,OUTPUT);
    pinMode(L1,OUTPUT);
    pinMode(L2,OUTPUT);
    pinMode(pwmR_pin,OUTPUT);
    pinMode(pwmL_pin,OUTPUT);
    
    Serial.begin(115200);
}

void loop() 
{
  while(Serial.available())
  {
    ch=Serial.read();
    if(ch=='s')
   {
        delay(2);
        c=Serial.read();  
        Serial.print(c);
        c=Serial.read();
       Serial.println(c);
  } 
   }
}
