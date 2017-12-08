#define L1 20
#define L2 21
#define pwmL_pin  15

#define R1 22
#define R2 23
#define pwmR_pin 3

#define thresh 512

float kp=0.01593,ki=0,kd=0;
int i,j,s_val[5],sensor[7];
float error=0,cumm_error=0,prev_error=0;
int k;
long l;
int u;

void setup()
{
      pinMode(R1,OUTPUT);
    pinMode(R2,OUTPUT);
    pinMode(L1,OUTPUT);
    pinMode(L2,OUTPUT);
    pinMode(pwmR_pin,OUTPUT);
    pinMode(pwmL_pin,OUTPUT);
    Serial.begin(115200);
    goFront();
}

void loop()
   {
     readinput();
     follow_line();
 //  delay(1000);
   }

     void goFront()
  {
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
    digitalWrite(L1,HIGH);
    digitalWrite(L2, LOW);
  }
void readinput()
{
  l=0;
  for(j=0;j<7;j++)
      {
        sensor[j]=analogRead(A6-j)>thresh?0:1;
       l=l*10+sensor[j];
      }
u=0;
u=digitalRead(18);
u=u*10+(analogRead(A7)>thresh?0:1);
u=u*10+digitalRead(19);
}


void follow_line()
{
  while (1)
  {
    readinput();
    if(sensor[0]*sensor[1]==1 && sensor[2]+sensor[3]+sensor[4]!=0 && sensor[5]+sensor[6]==0)
    goLeft();
    else if(sensor[5]*sensor[6]==1 && sensor[2]+sensor[3]+sensor[4]!=0 && sensor[0]+sensor[1]==0)
    goRight();

   if(sensor[5]+sensor[1]+sensor[2]+sensor[3]+sensor[4]==0)
        {
          analogWrite(pwmR_pin,0);
          analogWrite(pwmL_pin,0);
          continue;
        }
    for(i=0;i<5;i++)
              {s_val[i]=i-2;
              }

     for(i =0;i<5;i++)
        error+=((s_val[i]*s_val[i]*s_val[i])+1773*s_val[i])*sensor[i+1];
        //error+=s_val[i]*sensor[i];
    cumm_error+=error;
 k=kp*error + kd*(prev_error - error) + ki*(cumm_error);
 Serial.println(error);
 Serial.println(k);
 goFront();
   if(error>0)
        {
          analogWrite(pwmL_pin,200);
          analogWrite(pwmR_pin,200-abs(k));
        }
      else if(error<=0)
            {
          analogWrite(pwmR_pin,200);
          analogWrite(pwmL_pin,200-abs(k));
        }
        prev_error=error;
        error=0;
     }
}


 void goLeft()
     {
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
    digitalWrite(L1,HIGH);
    digitalWrite(L2, LOW);
       analogWrite(pwmL_pin,150);
       analogWrite(pwmR_pin,150);
       delay(60);
       Serial.print("GOING SHARP LEFT\n");
       do
       {
     digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
    digitalWrite(L2,HIGH);
    digitalWrite(L1, LOW);
     analogWrite(pwmL_pin,120);
     analogWrite(pwmR_pin,100);
    // delay(50);
     readinput();

     /*digitalWrite(a1,HIGH);
     digitalWrite(a2,LOW);
     digitalWrite(b1,HIGH);
     digitalWrite(b2,LOW);
     analogWrite(a_pwm,0);
     analogWrite(b_pwm,0);
     delay(50);*/
     if( sensor[2]==1)
           break;
       }while (1);


     }


     void goRight()
     {
       digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
    digitalWrite(L1,HIGH);
    digitalWrite(L2, LOW);
       analogWrite(pwmL_pin,150);
       analogWrite(pwmR_pin,150);
       //delay(60);
        Serial.print("GOING SHARP RIGHT\n");
       do
       {
        digitalWrite(R2, HIGH);
    digitalWrite(R1, LOW);
    digitalWrite(L1,HIGH);
    digitalWrite(L2, LOW);
     analogWrite(pwmL_pin,120);
     analogWrite(pwmR_pin,100);
     delay(50);
     readinput();

     if(sensor[4]==1)
           break;
       }while (1);


     }
