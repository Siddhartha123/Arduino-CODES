#include<EEPROM.h>
float kp,ki,kd;
uint8_t pwmR_base,pwmL_base,j;
String s;
String s1="        ";
void setup()
{
  Serial.begin(9600);
  initialize_variables();
}

void loop()
{
  change_variables();
}
void initialize_variables()
{
   EEPROM.get(0,kp);
   EEPROM.get(4,ki);
   EEPROM.get(8,kd);
   pwmL_base=EEPROM.read(9);
   pwmR_base=EEPROM.read(10);
}
void change_variables() {
 while(Serial.available())
  {
    s=Serial.readStringUntil(',');
    for(j=1;j<strlen(&s[0]);j++)
      s1[j-1]=s[j];
      s1[j-1]='\0';
    switch(s[0])
    {
      case 'p':
          kp=atof(&s1[0]);
          EEPROM.put(0,kp);
          Serial.print("\nkp ");
          Serial.print(kp,3);
          break;
      case 'i':
          ki=atof(&s1[0]);
          EEPROM.put(4,ki);
          Serial.print("\nki ");
          Serial.print(ki,3);
          break;
      case 'd':
          kd=atof(&s1[0]);
          EEPROM.put(8,kd);
          Serial.print("\nkd ");
          Serial.print(kd,3);
          break;
      case 'l':
          pwmL_base=atof(&s1[0]);
          EEPROM.put(9,pwmL_base);
          Serial.print("\npwmL_base ");
          Serial.print(pwmL_base);
          break;
      case 'r':
          pwmR_base=atof(&s1[0]);
          EEPROM.put(10,pwmR_base);
          Serial.print("\npwmR_base ");
          Serial.print(pwmR_base);
          break;
       case 'a':
       Serial.print("\n Values");
       Serial.print("\nkp");
          Serial.print(kp,3);
           Serial.print("\nki");
          Serial.print(ki,3);
            Serial.print("\nkd");
          Serial.print(kd,3);
           Serial.print("\npwmL_base ");
          Serial.print(pwmL_base);
          Serial.print("\npwmR_base ");
          Serial.print(pwmR_base);
    }
  }
}
