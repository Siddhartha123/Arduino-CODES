#define L1 20
#define L2 21
#define pwmL_pin  15

#define R1 22
#define R2 23
#define pwmR_pin 3           

#define thresh 512

float kp=0.034,ki=0,kd=0;
uint8_t i,s_val[5],sensor[5];
float error,cumm_error,prev_error,k;

void setup()
{
      pinMode(R1,OUTPUT);
    pinMode(R2,OUTPUT);
    pinMode(L1,OUTPUT);
    pinMode(L2,OUTPUT);
    pinMode(pwmR_pin,OUTPUT);
    pinMode(pwmL_pin,OUTPUT);
    Serial.begin(9600);
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
  for(i=0;i<5;i++)
      {
        sensor[i]=analogRead(A5-i)>thresh?0:1;
       /* if(!sensor[i])
        sensor_val+="B";
        else
        sensor_val+="W";*/
      }
     // Serial.println(sensor_val);
}

void follow_line()
{
  while (1)
  {
    readinput();
    /*if(sensor_val=="WWWWWBB" || sensor_val=="WWWWBBB" ||sensor_val=="WWWWWWB")
    {
          digitalWrite(L2,HIGH);
          digitalWrite(L1, LOW);
          analogWrite(pwmR_pin,75);
          analogWrite(pwmL_pin,75);
          delay(400);
    }*/
    if(sensor[0]+sensor[1]+sensor[2]+sensor[3]+sensor[4]==0)
        {
          analogWrite(pwmR_pin,0);
          analogWrite(pwmL_pin,0);
          continue;
        }
    for(i=0;i<5;i++)
              s_val[i]=i-2;
     for(i =0;i<5;i++)
        error+=(s_val[i]*s_val[i]*s_val[i]+1773*s_val[i])*sensor[i];
    cumm_error+=error;
 k=kp*error + kd*(prev_error - error) + ki*(cumm_error);
 Serial.println(k);
   if(error>0)
        {
          analogWrite(pwmL_pin,90);
          analogWrite(pwmR_pin,105-abs(k));
        }
      else if(error<=0)
            {
          analogWrite(pwmR_pin,105);
          analogWrite(pwmL_pin,90-abs(k));
        }
        prev_error=error;
        error=0;
     }
}

