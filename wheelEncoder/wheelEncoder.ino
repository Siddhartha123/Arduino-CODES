volatile long int shaftCountRight,shaftCountLeft;
#define l1 6
#define l2 8
#define pwml_pin 9
#define r1 7
#define r2 4
#define pwmr_pin 5

float countsPerDegree=1.63;
String s;

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
forward();
}

void loop() {
if(Serial.available()){
  Serial.readStringUntil('*');
  s=Serial.readStringUntil('#');
 countsPerDegree= s.toFloat();
 right(180);
}
}

void leftShaft(){
  shaftCountLeft++;
//  Serial.print("left count : ");
//  Serial.println(shaftCountLeft);
}

void rightShaft(){
  shaftCountRight++;
//  Serial.print("right count : ");
//  Serial.println(shaftCountRight);
}

void forward(){
  int i;
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  analogWrite(pwml_pin,180);
  analogWrite(pwmr_pin,180);
  for(i=0;i<100;i++){
    if(shaftCountLeft>shaftCountRight)
    {
      analogWrite(pwmr_pin,244);
      delay(40);
      analogWrite(pwmr_pin,175);
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

void halt(){
   digitalWrite(l2,HIGH);
  digitalWrite(l1,HIGH);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(pwmr_pin,HIGH);
  digitalWrite(pwml_pin,HIGH);
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
  while(shaftCountRight+shaftCountLeft<count);
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
  while(shaftCountRight+shaftCountLeft<count);
  halt();
}
