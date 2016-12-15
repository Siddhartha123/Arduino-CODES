#define L1 20
#define L2 21
#define pwmL_pin  15

#define R1 22
#define R2 23
#define pwmR_pin 3           

#define thresh 512

float kp=0.01593,ki=0,kd=0;
int i,s_val[5],sensor[5];
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
        Serial.print(sensor[i]);
        Serial.print("  ");
      }
      Serial.println("");
     // Serial.println(sensor_val);
}

void follow_line()
{
  while (1)
  {
    readinput();
    if(l==1111000 && u==000 || l==1111100 && u==000)
    goLeft();
    else if(l==00011111 && u==000 || l==0011111 && u==000)
    goRight();
    
   if(sensor[0]+sensor[1]+sensor[2]+sensor[3]+sensor[4]==0)
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
     delay(50);
     readinput();
     
     /*digitalWrite(a1,HIGH);
     digitalWrite(a2,LOW);
     digitalWrite(b1,HIGH);
     digitalWrite(b2,LOW);
     analogWrite(a_pwm,0);
     analogWrite(b_pwm,0);
     delay(50);*/
     if( l==0110000 || l==1110000 || l==0111000)
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
       delay(60);
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
  
     if(l==0000110 ||l==0000111 || l==0001110)
           break;
       }while (1);
      
      
     }

