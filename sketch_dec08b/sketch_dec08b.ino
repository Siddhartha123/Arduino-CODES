void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}
int x;
int i;
void loop() {
  // put your main code here, to run repeatedly:
for(i=0;i<7;i++)
{
  x=analogRead(A0+i);
  Serial.print(x);
  Serial.print("  ");
}
Serial.println();

}
