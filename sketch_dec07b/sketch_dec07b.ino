void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}
int x;
void loop() {
  // put your main code here, to run repeatedly:

x=digitalRead(18);
Serial.print(x);
Serial.print("  ");
x=analogRead(A7);
Serial.print(x);
Serial.print("  ");
x=digitalRead(19);
Serial.println(x);
}
