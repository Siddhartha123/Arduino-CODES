void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}
int i;
char c;
float kp,ki,kd;
String s;
String s1="                     ";
void loop() {
  if(Serial.available())
  {
    s=Serial.readStringUntil(',');
    c=s[0];
    for(i=1;i<strlen(&s[0]);i++)
      s1[i-1]=s[i];
      s1[i-1]='\0';
    switch(c)
    {
      case 'p':
          kp=atof(&s1[0]);
          break;
      case 'i':
          ki=atof(&s1[0]);
          break;
      case 'd':
          kd=atof(&s1[0]);
          break;
    }
  }
  // put your main code here, to run repeatedly:
Serial.print("\nkp");
Serial.print(kp);

Serial.print("\nkd");
Serial.print(kd);

Serial.print("\nki");
Serial.print(ki);

delay(3000);
}
