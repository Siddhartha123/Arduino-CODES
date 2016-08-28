int x,y,inpx=A0,inpy=A1;
int l1=3,l2=4,r1=5,r2=6,testx,testy;
float pwmr,pwml,x1,y1;
void setup() {
  // put your setup code here, to run once:
testx=analogRead(inpx);
testy=analogRead(inpy);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 /*Serial.print(analogRead(inpx));
  Serial.print(" ");
  Serial.print(analogRead(inpy));
  Serial.print(" ");
*/
y=map(analogRead(inpy),2*testy-1023,1023,-100,100);
x=map(analogRead(inpx),2*testx-1023,1023,100,-100);
 Serial.print(x);
  Serial.print(" ");
  Serial.print(y);
  Serial.print(" ");
 
if(x>=0)
{
  x1=x;
  y1=y;
  pwml=max(abs(x1),abs(y1));
  pwmr=pwml*(abs((x1*x1-y1*y1)));
  pwmr= pwmr/(x1*x1+y1*y1);
  Serial.print(pwml);
  Serial.print(" ");
  Serial.print(pwmr);
  Serial.print(" ");
  
  
}
else if(x<0)
{
  pwmr=max(abs(x),abs(y));
  pwml=pwmr*abs((x*x-y*y)/(x*x+y*y));
  Serial.print(pwml);
  Serial.print(" ");
  Serial.print(pwmr);
  Serial.print(" ");
  
  }
if(abs(y)>abs(x))
{
  if(y>0)
  {
    l1=1;
    l2=0;
    r1=1;
    l2=0;
    Serial.print("forward");
    Serial.print(" ");
    Serial.print(" forward");
    Serial.print(" ");
  }
  else
  {
    l1=0;
    l2=1;
    r1=0;
    l2=1;
    Serial.print("backward");
    Serial.print(" ");
    Serial.print("backward");
    Serial.print(" ");
  
  } 
  }
else if(abs(y)<abs(x))
{
  if(x*y>=0)
  {
    l1=1;
    l2=0;
    r1=0;
    r2=1;
  Serial.print("forward");
    Serial.print(" ");
    Serial.print(" backward");
    Serial.print(" ");
  
  }
  else
  {
    l1=0;
    l2=1;
    r1=1;
    r2=0;
    Serial.print("backward");
    Serial.print(" ");
    Serial.print(" forward");
    Serial.print(" ");
  
  }
}

Serial.println("");
  

}
