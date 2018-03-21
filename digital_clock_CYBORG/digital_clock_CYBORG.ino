#include <Wire.h>
#include "PCF8574.h"
#include <RTClib.h>

RTC_DS1307 rtc;
PCF8574 PCF_1(0x38);
PCF8574 PCF_2(0x39);
PCF8574 PCF_3(0x3A);
PCF8574 PCF_4(0x3B);
int h,m;
int h1=0;
int h2=0;
int m1=8;
int m2=0;
const long interval = 500;           // interval at which to blink (milliseconds)
 unsigned long previousMillis=0;
  unsigned long currentMillis = millis();
void setup()
{

  PCF_1.write8(sev_seg(h1));                  
  PCF_2.write8(sev_seg(h2));              
  PCF_3.write8(sev_seg(m1));         
  PCF_4.write8(sev_seg(m2));   
  
}
void loop(){  
/*
// constants won't change :
const long interval = 500;           // interval at which to blink (milliseconds)

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) 
  {
    previousMillis = currentMillis;
    update_time();//Update time value
    
  }
  write_to();//Write to pins
*/
}


  void update_time()
  {
DateTime now = rtc.now();
  h=now.hour();
  m=now.minute();
  h1=h/10;
  h2=h%10;
  m1=m/10;
  m2=m%10;
  }
int  sev_seg(int t)
{
  int d=0;
  switch (t)
  {
  case 0:
  d = 253;
  break;
  case 1:
  d = 97;
  break;
  case 2:
  d =218;
  break;
  case 3:
  d=242;
  break;
  case 4:
  d=102;
  break;
  case 5:
  d = 182;
  break;
  case 6:
  d =190;
  case 7:
  d = 225;
  break;
  case 8:
  d = 255;
  break;
  case 9:
  d =246;
  break;  
  }
  return d;
}
  void write_to()
  {
  PCF_1.write8(sev_seg(h1));                  
  PCF_2.write8(sev_seg(h2));               
  PCF_3.write8(sev_seg(m1));         
  PCF_4.write8(sev_seg(m2));            
  }



