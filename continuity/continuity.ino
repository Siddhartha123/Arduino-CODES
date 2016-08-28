void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
while(1)
{
  while(digitalRead(12))
  digitalWrite(13,HIGH);
  digitalWrite(13,LOW);
  
}
}
