int pwmr=5,pwml=3,ra=9,rb=10,la=8,lb=4,pwm_r,pwm_l;
float vert,hor;
void setup() {
 Serial.begin(9600);
pinMode(ra,OUTPUT);
pinMode(rb,OUTPUT);
pinMode(la,OUTPUT);
pinMode(lb,OUTPUT);
pinMode(pwml,OUTPUT);
pinMode(pwmr,OUTPUT);
}

void loop()
{
  vert=analogRead(A0)-507-30-26+43;//negative value for forward
  hor=analogRead(A1)-507;//positive value for right
 Serial.print(hor);
 Serial.print("    ");
 Serial.print(vert);
 
  vert=map(vert,-512,512,-64,64);
  hor=map(hor,-512,512,-64,64);
  if(vert>0)
  reverse_motor();
 
  if(vert<0)
  un_reverse();
 if(hor<5 && hor>-5 && vert>-5 &&vert<5)
 {
  pwm_r=0;
  pwm_l=0;
 }
 else
 {
    pwm_r=128-hor+abs(vert);
    pwm_l=128+hor+abs(vert);
 }
 if(pwm_r>255) pwm_r=255;
 if(pwm_l>255) pwm_l=255;
 analogWrite(pwmr,pwm_r);
 analogWrite(pwml,pwm_l);
 
 Serial.print("     *     ");
 Serial.print(pwm_r);
 Serial.print("     *     ");
 Serial.print(pwm_l);
 
 Serial.println("");
 
 }

void un_reverse()
{
  digitalWrite(rb,HIGH);
  digitalWrite(ra,LOW);
  digitalWrite(lb,HIGH);
  digitalWrite(la,LOW);
  
}
 void reverse_motor()
 {
  digitalWrite(ra,HIGH);
  digitalWrite(rb,LOW);
  digitalWrite(la,HIGH);
  digitalWrite(lb,LOW);
  }

