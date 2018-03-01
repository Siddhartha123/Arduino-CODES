int delay_time=0;
float p=0.75;            // p is the fraction of full power
float i;
void setup() {
  // put your setup code here, to run once:
attachInterrupt(digitalPinToInterrupt(2),toggle,CHANGE);
pinMode(4,OUTPUT);
delay_time=10000*(1-p);
}

void toggle(){
 delayMicroseconds(delay_time);
 digitalWrite(4,HIGH);
 delayMicroseconds(1000);
 digitalWrite(4,LOW);
}
void loop() {
  // put your main code here, to run repeatedly:
i=analogRead(A0);
p=i/1024;
if(p<0)
p=0;
if(p>1)
p=1;
delay_time=10000*(1-p);
}
