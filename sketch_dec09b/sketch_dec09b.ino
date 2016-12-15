void setup() {

  // put your setup code here, to run once:
pinMode(20,OUTPUT);
pinMode(21,OUTPUT);
pinMode(15,OUTPUT);
analogWrite(15,255);
digitalWrite(21,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(20,HIGH);
delay(1000);
digitalWrite(20,LOW);
delay(10000);
}
