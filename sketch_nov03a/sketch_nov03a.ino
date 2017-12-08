void setup() {
  // put your setup code here, to run once:
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
analogWrite(3,200);
analogWrite(9,200);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(4,HIGH);
digitalWrite(5,LOW);
digitalWrite(7,HIGH);
digitalWrite(8,LOW);
}
