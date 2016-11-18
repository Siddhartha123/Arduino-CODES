void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(analogRead(A0));Serial.print("             ");
/*Serial.print(analogRead(A1));Serial.print("             ");
Serial.print(analogRead(A2));Serial.print("             ");
Serial.print(analogRead(A3));Serial.print("             ");
Serial.print(analogRead(A4));Serial.print("             ");
Serial.print(analogRead(A5));Serial.println("");
*/
}
