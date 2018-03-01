#define m1a 5
#define m1b 6

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
forward();
delay(10000);
halt();
while(1);

}
void forward(){
 analogWrite(m1a,100);
digitalWrite(m1b,HIGH);
analogWrite(m2a,100);
digitalWrite(m2b,LOW);
delay(10);
}
void halt(){
  digitalWrite(m1a,LOW);
digitalWrite(m1b,LOW);
digitalWrite(m2a,LOW);
digitalWrite(m2b,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
if(Serial.read()=='w')
forward();
while(Serial.read()=='w');
halt();
}
}
