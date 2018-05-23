#include <NewPing.h>
#include <LiquidCrystal.h>


#define TRIGGER_PIN  A0  
#define ECHO_PIN     A1 
#define MAX_DISTANCE 200

#define l1 A4
#define l2 A5
#define r1 A3
#define r2 A2
#define pwmR 11
#define pwmL 10

NewPing distance_sensor(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
LiquidCrystal lcd(12,8,5,4,3,2);
int distance;
char c;
void setup() {
  // put your setup code here, to run once:
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  pinMode(r1,OUTPUT);
  pinMode(r1,OUTPUT);
  pinMode(pwmL,OUTPUT);
  pinMode(pwmR,OUTPUT);
//  digitalWrite(r2,1);
//  digitalWrite(l1,1);
  analogWrite(pwmL,200);
  analogWrite(pwmR,200);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("hello world");
}
void forward(){
  digitalWrite(r1,1);
  digitalWrite(l1,1);
  digitalWrite(r2,0);
  digitalWrite(l2,0);
  delay(50);
}

void right(){
  digitalWrite(r1,0);
  digitalWrite(l1,1);
  digitalWrite(r2,0);
  digitalWrite(l2,0);
  delay(50);
}
void left(){
  digitalWrite(r1,1);
  digitalWrite(l1,0);
  digitalWrite(r2,0);
  digitalWrite(l2,0);
  delay(50);
}
void halt(){
  digitalWrite(r1,0);
  digitalWrite(l1,0);
  digitalWrite(r2,0);
  digitalWrite(l2,0);
  delay(50);
}
void loop() {
  // put your main code here, to run repeatedly:
  delay(50);
  distance=distance_sensor.ping_cm();
  if(Serial.available()){
    c=Serial.read();
    switch(c){
      case 'F':
      forward();
      break;
      case 'S':
      halt();
      break;
      case 'R':
      right();
      break;
      case 'L':
      left();
      break;
    }
    halt();
}
}
