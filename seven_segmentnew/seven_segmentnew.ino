#include <EEPROM.h>
int pins[4][3]={{2,3,4},{5,6,7},{8,9,10},{11,12,13}}; //for each sub-array 1st pin is latch, 2nd pin is data and 3rd pin is clock
int s[10] ={129,243,73,97,51,37,5,241,1,49};
int count=0,flag=0;
int a,b;
char c[4];
 int i,j,k=0;
 char val;
void print_digit(int digit,int place)
{
    digitalWrite(pins[place-1][0], LOW);
    shiftOut(pins[place-1][1],pins[place-1][2] , MSBFIRST,255-s[digit]);
    digitalWrite(pins[place-1][0], HIGH);
}
void setup() {
  Serial.begin(9600);
for(i=0;i<4;i++)
{
  for(j=0;j<3;j++)
    pinMode(pins[i][j],OUTPUT);
}
read_eeprom();
}

void loop()
{
  /*a=analogRead(A0);
  increase_count();
  delay(500);
  while(a>100 && a<400)
    {
      flag=1;
      b=analogRead(A1);
      if(b>100 && b<400)
      {
        flag=2;
        increase_count();
        break;
      }
    }
  flag=0;*/
  increase_count();
  delay(350);
}
  
void increase_count()
{
  int temp;
count++;
Serial.println(count);
temp=count;
for(i=0;i<4;i++)
{
  j=temp%10;
  print_digit(j,i+1);
  temp=temp/10;  
}
EEPROM.put(0,count);//write "count" to eeprom
}

 void read_eeprom()
  {
    count=0;
  for(i=0;i<4;i++)
  {
    val=(char)EEPROM.read(i);  
    count+=pow(10,i)*(val-48);
  }
  }

