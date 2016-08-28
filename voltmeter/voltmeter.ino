void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}
float y;
void loop() {
  // put your main code here, to run repeatedly:
y=(float)analogRead(A0)*5/1023;
Serial.println(y);
delay(100);
}
