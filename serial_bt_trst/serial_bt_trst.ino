void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}
int i=0;
void loop() {
  // put your main code here, to run repeatedly:
Serial.println(i);
i++;
delay(100);
}
