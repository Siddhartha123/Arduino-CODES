//3,4,8
void  motor(int a,int b)
{
digitalWrite(4,a);
digitalWrite(8,b);
}
void setup() {
  // put your setup code here, to run once:
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(8,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
motor(1,0);
analogWrite(3,255);
delay(800);
motor(1,1);
delay(500);
motor(0,1);
delay(800);
motor(1,1);
delay(500);
}
