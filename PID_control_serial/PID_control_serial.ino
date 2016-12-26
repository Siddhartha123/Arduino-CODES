void setup() {
Serial.begin(9600);
}
int i;
float kp,ki,kd;
char c;

String s;
String s1="                     ";
void loop() {
 while(Serial.available())
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
          Serial.print("\nkp ");
          Serial.print(kp);
          break;
      case 'i':
          ki=atof(&s1[0]);
          Serial.print("\nki ");
          Serial.print(ki);
          break;
      case 'd':
          kd=atof(&s1[0]);
 
          Serial.print("\nkd ");
          Serial.print(kd);
          break;
       case 'a':
       Serial.print("\n Values");
       Serial.print("\nkp");
          Serial.print(kp);
           Serial.print("\nki");
          Serial.print(ki);
            Serial.print("\nkd");
          Serial.print(kd);
       
    }
  }
}
