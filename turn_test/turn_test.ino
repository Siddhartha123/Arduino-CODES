#define l1 7
#define l2 4
#define pwml_pin 3
#define r1 6
#define r2 2
#define pwmr_pin 5
char s;
void setup() {
  // put your setup code here, to run once:
Serial.begin(38400);
pinMode(l1,OUTPUT);
pinMode(l2,OUTPUT);
pinMode(pwml_pin,OUTPUT);
pinMode(r1,OUTPUT);
pinMode(r2,OUTPUT);
pinMode(pwmr_pin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()){
  s=Serial.read();

  s=s-47;
  right();
  delay(100*s);
  halt();
}
}
void forward(){
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  analogWrite(pwml_pin,160);
  analogWrite(pwmr_pin,220);
  delay(1500);
  halt();
}

void back(){
  digitalWrite(l2,HIGH);
  digitalWrite(l1,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(r1,LOW);
  analogWrite(pwml_pin,145);
  analogWrite(pwmr_pin,220);
  delay(1500);
  halt();
}

void left(){
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(r1,LOW);
  analogWrite(pwmr_pin,100);
  analogWrite(pwml_pin,100);
  delay(1000);
  halt();
}
void right(){
  digitalWrite(l2,HIGH);
  digitalWrite(l1,LOW);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  analogWrite(pwmr_pin,100);
  analogWrite(pwml_pin,100);
}

void halt(){
    digitalWrite(l2,HIGH);
  digitalWrite(l1,HIGH);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(pwmr_pin,HIGH);
  digitalWrite(pwml_pin,HIGH);
}
