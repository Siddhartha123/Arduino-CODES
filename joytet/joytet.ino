int pwm_r=5,pwm_l=3,ra=9,rb=10,la=8,lb=4;
float vert,hor;
void setup() {
 Serial.begin(9600);
pinMode(ra,OUTPUT);
pinMode(rb,OUTPUT);
pinMode(la,OUTPUT);
pinMode(lb,OUTPUT);
pinMode(pwm_l,OUTPUT);
pinMode(pwm_r,OUTPUT);
digitalWrite(rb,HIGH);
  digitalWrite(ra,LOW);
  digitalWrite(lb,HIGH);
  digitalWrite(la,LOW);
analogWrite(pwm_r,255);
analogWrite(pwm_l,255);

}  // put your setup code here, to run once:



void loop() {
  // put your main code here, to run repeatedly:

}
