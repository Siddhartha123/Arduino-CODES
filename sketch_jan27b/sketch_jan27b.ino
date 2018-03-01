#define m1a 5
#define m1b 6
char ch;
#define m2a 10
#define m2b 11
void setup() {
  Serial.begin(38400);
  // put your setup code here, to run once:
pinMode(m1a,OUTPUT);
pinMode(m1b,OUTPUT);
pinMode(m2a,OUTPUT);
pinMode(m2b,OUTPUT);
digitalWrite(m1a,LOW);
digitalWrite(m1b,LOW);
digitalWrite(m2a,LOW);
digitalWrite(m2b,LOW);
} 
/*forward();
//delay(5000);
halt();
//delay(500);
right();
//delay(5000);
halt();
//delay(500);
left();
//delay(5000);
halt();
while(1);

}*/
void forward()
{
 analogWrite(m1a,100);
digitalWrite(m1b,HIGH);
analogWrite(m2a,100);
digitalWrite(m2b,LOW);
delay(100);
}
void halt(){
  digitalWrite(m1a,LOW);
digitalWrite(m1b,LOW);
digitalWrite(m2a,LOW);
digitalWrite(m2b,LOW);
delay(100);
}
void right(){
  analogWrite(m1a,100);
digitalWrite(m1b,HIGH);
analogWrite(m2a,100);
digitalWrite(m2b,HIGH);
//digitalWrite(m2a,LOW);
//digitalWrite(m2b,LOW);
delay(100);
  }
  void left(){
 //digitalWrite(m1a,LOW);
//digitalWrite(m1b,LOW);
digitalWrite(m1a,100);
digitalWrite(m1b,LOW);
analogWrite(m2a,100);
digitalWrite(m2b,LOW);
delay(100);
  }
   void back()
   {
  analogWrite(m1a,100);
digitalWrite(m1b,LOW);
analogWrite(m2a,100);
digitalWrite(m2b,HIGH);
delay(100);
  }
void loop()
{
 
  if(Serial.available()>0)
 {
 ch=Serial.read();

if((ch)=='w')
forward();


else if((ch)=='a')
left();


else if((ch)=='d')
right();


else if((ch)=='s')
back();
 }
else
{halt();}
}

