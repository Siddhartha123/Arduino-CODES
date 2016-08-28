
void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
digitalWrite(13,HIGH);
delay(4000);
digitalWrite(13,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
attachInterrupt(digitalPinToInterrupt(3),test,CHANGE);

}
void test()
{
  digitalWrite(13,HIGH);
  delay(1000);
digitalWrite(13,LOW);
}


