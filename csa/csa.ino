#include <Servo.h>
#define l1 6
#define l2 8
#define pwml_pin 11
#define r1 7
#define r2 4
#define pwmr_pin 5
String s;
int deg;
volatile long int shaftCountRight,shaftCountLeft;
float threshold=50,countsPerDegree=1.7;
Servo myservo;  // create servo object to control a servo
void setup() {
Serial.begin(38400);
attachInterrupt(digitalPinToInterrupt(2),leftShaft,RISING);
attachInterrupt(digitalPinToInterrupt(3),rightShaft,RISING);
pinMode(l1,OUTPUT);
pinMode(l2,OUTPUT);
pinMode(pwml_pin,OUTPUT);
pinMode(r1,OUTPUT);
pinMode(r2,OUTPUT);
pinMode(pwmr_pin,OUTPUT);
pinMode(13,OUTPUT);
pinMode(A1,OUTPUT);
  myservo.attach(12);  // attaches the servo on pin 9 to the servo object
  delay(200);
  myservo.write(180);
  delay(800);
  myservo.detach();
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()){
  Serial.readStringUntil('*');
  s=Serial.readStringUntil('#');
  //Serial.print(s);
  Serial.flush();

  if(s=="forward")
    forward();
  else if(s.startsWith("right") || s.startsWith("write")){
    deg=(s.substring(6,s.indexOf(" degrees"))).toInt();
    right(deg);
  }
     else if(s.startsWith("left")){
    deg=(s.substring(5,s.indexOf(" degrees"))).toInt();
    left(deg);
  }
  else if(s.startsWith("calib")){
    countsPerDegree=(s.substring(6,s.indexOf(" f"))).toFloat();
  }
    else if(s=="backward")
    back();
    else if(s=="testing")
   soft();
  s="";
}
}

void forward(){
  int i;
  shaftCountLeft=0;
  shaftCountRight=0;
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  analogWrite(pwml_pin,180);
  analogWrite(pwmr_pin,180);
  for(i=0;i<40;i++){
    if(shaftCountLeft>shaftCountRight)
    {
      analogWrite(pwmr_pin,244);
      delay(40);
      analogWrite(pwmr_pin,180);
    }
    else if(shaftCountLeft<shaftCountRight)
     {
      analogWrite(pwml_pin,200);
      delay(40);
      analogWrite(pwml_pin,180);
    }
    else
      delay(20);
  }
  halt();
}

void back(){
   int i;
  shaftCountLeft=0;
  shaftCountRight=0;
  digitalWrite(l2,HIGH);
  digitalWrite(l1,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(r1,LOW);
 analogWrite(pwml_pin,180);
  analogWrite(pwmr_pin,180);
  for(i=0;i<40;i++){
    if(shaftCountLeft>shaftCountRight)
    {
      analogWrite(pwmr_pin,244);
      delay(40);
      analogWrite(pwmr_pin,180);
    }
    else if(shaftCountLeft<shaftCountRight)
     {
      analogWrite(pwml_pin,200);
      delay(40);
      analogWrite(pwml_pin,180);
    }
    else
      delay(20);
  }
  halt();
}

void right(int deg){
  int count=deg*countsPerDegree;
  shaftCountRight=0;
  shaftCountLeft=0;
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(r1,LOW);
  analogWrite(pwml_pin,150);
  analogWrite(pwmr_pin,150);
  while((shaftCountRight+shaftCountLeft)<count);
  halt();
}

void left(int deg){
  int count=deg*countsPerDegree;
  shaftCountRight=0;
  shaftCountLeft=0;
  digitalWrite(l2,HIGH);
  digitalWrite(l1,LOW);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  analogWrite(pwml_pin,150);
  analogWrite(pwmr_pin,150);
  while((shaftCountRight+shaftCountLeft)<count);
  halt();
}

void halt(){
    digitalWrite(l2,HIGH);
  digitalWrite(l1,HIGH);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(pwmr_pin,HIGH);
  digitalWrite(pwml_pin,HIGH);
}

void soft(){
  float a=0;
  myservo.attach(12);
  int i;
  for(i=180;i>=0;i-=5){
    myservo.write(i);
    delay(100);
  }
  delay(100);
  for(i=0;i<50;i++){
    a+=analogRead(A6);
    delay(10);
  }
  a=a/50;
   Serial.print(a);
  
  myservo.write(180);
  delay(700);
  myservo.detach();
  if(a>threshold){ 
    digitalWrite(13,HIGH);
  delay(3000);
  digitalWrite(13,LOW);
  }
  else{ 
  digitalWrite(A1,HIGH);
  delay(3000);
  digitalWrite(A1,LOW);
  }
}

void leftShaft(){
  shaftCountLeft++;
}

void rightShaft(){
  shaftCountRight++;
}
