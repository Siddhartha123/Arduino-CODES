void setup() {
  // put your setup code here, to run once:
pinMode(3,OUTPUT);
}
int i;
void loop() {
  // put your main code here, to run repeatedly:
for(i=1;i<=51;i++)
{
  analogWrite(3,i*5);
  delay(100);
}
analogWrite(3,0);
delay(400);
}

