void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
delay(5000);
}
char a;
char b[100];
int flag;
int i=0;
void loop() {
  while(Serial.available())
{
a=Serial.read();
b[i]=a;
i++;
}
Serial.print(b);
strcpy(b,"");
}
