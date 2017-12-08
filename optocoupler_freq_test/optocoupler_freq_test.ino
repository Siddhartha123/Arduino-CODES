void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(3,OUTPUT);
}
uint8_t x;
void loop() {
  // put your main code here, to run repeatedly:
x=analogRead(A0);
Serial.println(x);
analogWrite(x);
}
