#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {

}

void loop(){
  if(Serial.available()){
    if(Serial.read()=='a')
    soft();
  }
}

void soft(){
  float a=0;
  myservo.attach(12);
  int i;
  for(i=180;i>=0;i-=5){
    myservo.write(i);
    delay(100);
  }
  delay(50);
  for(i=0;i<50;i++){
    a+=analogRead(A6);
  }
  a=a/50;
  Serial.println(a);
  myservo.write(180);
  delay(700);
  myservo.detach();
}

