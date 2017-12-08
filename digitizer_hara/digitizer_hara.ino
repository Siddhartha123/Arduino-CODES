#define a1 5
#define a2 4
#define a_pwm 3
#define b2 6
#define b1 8
#define b_pwm 9
void setup() {
  // put your setup code here, to run once:
pinMode(a1,OUTPUT);
pinMode(a2,OUTPUT);
pinMode(b1,OUTPUT);
pinMode(b2,OUTPUT);
pinMode(a_pwm,OUTPUT);
pinMode(b_pwm,OUTPUT);
Serial.begin(9600);
}
char c;
void loop() {
  // put your main code here, to run repeatedly:
 if (Serial.available())
 {
  c=Serial.read();
  switch(c){
    case 'w':
    forward();
    break;
    case 'a':
    left();
    break;
    case 'd':
    forward();
    break;
    case 's':
    halt();
    break;
    case 't':
    triangle();
    break;
    case 'q':
    square();
    break;
  }
  halt();
}
halt1();
}
void left()
 {
  digitalWrite(a1,HIGH);
  digitalWrite(a2,LOW);
  analogWrite(a_pwm,80);
  digitalWrite(b1,LOW);
  digitalWrite(b2,HIGH);
  analogWrite(b_pwm,80);
      delay(100);
  Serial.println("a");
  
 }

  void right()
 {
          digitalWrite(a2, HIGH);
          digitalWrite(a1, LOW);
          analogWrite(a_pwm,80);
  digitalWrite(b1,HIGH);
  digitalWrite(b2,LOW);
  analogWrite(b_pwm,80);
  delay(100);
  Serial.println("d");
 }    
  void forward()
 {
  digitalWrite(a1,LOW);
  digitalWrite(a2,HIGH);
  analogWrite(a_pwm,130);
  digitalWrite(b1,LOW);
  digitalWrite(b2,HIGH);
  analogWrite(b_pwm,130);
  delay(100);
    Serial.println("w");
 }    
 void halt(){
   digitalWrite(a1,HIGH);
  digitalWrite(a2,HIGH);
  analogWrite(a_pwm,110);
  digitalWrite(b1,HIGH);
  digitalWrite(b2,HIGH);
  analogWrite(b_pwm,110);
 }
  void halt1(){
   digitalWrite(a1,HIGH);
  digitalWrite(a2,HIGH);
  analogWrite(a_pwm,110);
  digitalWrite(b1,HIGH);
  digitalWrite(b2,HIGH);
  analogWrite(b_pwm,110);
 }

 void triangle(){
digitalWrite(a1,HIGH);
  digitalWrite(a2,LOW);
  analogWrite(a_pwm,65);
  digitalWrite(b1,LOW);
  digitalWrite(b2,HIGH);
  analogWrite(b_pwm,65);
      delay(300);
         digitalWrite(a2, HIGH);
          digitalWrite(a1, LOW);
          analogWrite(a_pwm,65);
  digitalWrite(b1,HIGH);
  digitalWrite(b2,LOW);
  analogWrite(b_pwm,65);
  delay(600);
  digitalWrite(a1,HIGH);
  digitalWrite(a2,LOW);
  analogWrite(a_pwm,65);
  digitalWrite(b1,LOW);
  digitalWrite(b2,HIGH);
  analogWrite(b_pwm,65);
      delay(300);
      Serial.println('t');
      
 }

 void square(){
  triangle();
  triangle();
  Serial.println('q');
 }

