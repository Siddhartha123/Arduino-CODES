int delay_time=0;
float p=1;        // p is the fraction of full power
float i;
int x;
long int count=0;
int cnt;
void setup() {
  // put your setup code here, to run once:
attachInterrupt(digitalPinToInterrupt(2),toggle,CHANGE);
pinMode(4,OUTPUT);
delay_time=10000*(1-p);
Serial.begin(230400);
}

void toggle(){
 delayMicroseconds(delay_time);
 digitalWrite(4,HIGH);
 delayMicroseconds(3000);
 digitalWrite(4,LOW);
 cnt++;
 count=cnt/100+count;
 Serial.println(count);
}
void loop() {
/*  // put your main code here, to run repeatedly:
x=x%1024+10;
delay(1000);
i=x;
p=i/1024;
if(p<0)
p=0;
if(p>1)
p=1;
delay_time=10000*(1-p);*/
}
