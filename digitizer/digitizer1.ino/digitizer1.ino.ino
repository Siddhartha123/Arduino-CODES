#define l1 7
#define l2 4
#define pwml_pin 5
#define r1 6
#define r2 2
#define pwmr_pin 3

char c;
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
    right();
    break;
    case 's':
    halt();
    break;
  }
  halt();
}
halt();
}


void forward(){
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  digitalWrite(pwmr_pin,HIGH);
  digitalWrite(pwml_pin,HIGH);
  delay(100);
  Serial.print('w');
}

void right(){
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(r1,LOW);
  digitalWrite(pwmr_pin,HIGH);
  digitalWrite(pwml_pin,HIGH);
  delay(70);
  Serial.print('d');
}
void left(){
  digitalWrite(l2,HIGH);
  digitalWrite(l1,LOW);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  digitalWrite(pwmr_pin,HIGH);
  digitalWrite(pwml_pin,HIGH);
  delay(70);
  Serial.print('a');
}

void halt(){
    digitalWrite(l2,HIGH);
  digitalWrite(l1,HIGH);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(pwmr_pin,HIGH);
  digitalWrite(pwml_pin,HIGH);
}

