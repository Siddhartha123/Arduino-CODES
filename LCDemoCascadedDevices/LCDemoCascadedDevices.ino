#include "LedControl.h"
char numbers[10][7][8]={
{01110000,10001000,10011000,10101000,11001000,10001000,01110000}, //0
{01000000,11000000,01000000,01000000,01000000,01000000,11100000},//1
{01110000,10001000,00001000,00010000,00100000,01000000,11111000},//2
{11111000, 00010000, 00100000, 00010000, 00001000, 10001000, 01110000},//3
{00010000, 00110000, 01010000, 10010000, 11111000, 00010000, 00010000},//4
{11111000, 10000000, 11110000, 00001000, 00001000, 10001000, 01110000},//5
{ 00110000, 01000000, 10000000, 11110000, 10001000, 10001000,01110000},//6
{ 11111000, 10001000, 00001000,00010000,00100000, 00100000, 00100000},//7
{ 01110000, 10001000, 10001000, 01110000, 10001000, 10001000, 01110000},//8
{01110000,10001000, 10001000, 01111000, 00001000, 00010000, 01100000} //9
};
int count=0;

/*
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
4 devices
 */
LedControl lc=LedControl(12,11,10,4);

/* we always wait a bit between updates of the display */
unsigned long delaytime=500;

/* 
 This time we have more than one device. 
 But all of them have to be initialized 
 individually.
 */
void setup() {

  int devices=lc.getDeviceCount();
  //we have to init all devices in a loop
  for(int address=0;address<devices;address++) {
    lc.shutdown(address,false);
  }
   //attachInterrupt(2, increase_count, CHANGE) ;  //pin 2 is used as interrupt
}

void loop(){
  int i;
for(i=0;i<9999;i++)
{
increase_count();
delay(1000);
}
 }

void write_char(int num,int device)
{
  int i,j;
  for(i=0;i<8;i++)
  {
    for(j=0;j<8;j++)
      lc.setLed(device,i,j,numbers[num][i][j]);
  }
}

void led_write(int c)
{
int  i,n;
   for(i=0;i<4;i++)
   {
        n=c%10;
        write_char(n,i);
        c=c/10;
   }
}
void increase_count()
{
  count++;
  led_write(count);
}



