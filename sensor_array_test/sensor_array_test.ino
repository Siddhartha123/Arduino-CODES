void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}
int i; 
void loop() {
  // put your main code here, to run repeatedly:
for(i=0;i<6;i++)
{
Serial.print(analogRead(14+i));
Serial.print("                     ");
}
Serial.println();
}
