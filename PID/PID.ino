#define  a1     8
#define  a2     9
#define  b1     12
#define  b2     13
#define  a_pwm  10
#define  b_pwm  11

int THRESHOLD;
float error=0;
float prev_error=0;
float cumm_error=0;
int k;
float kp = 0.03167;
float kd=0.01593;
float ki=0;
int base = 255;
int s[5]={0,0,0,0,0};
int s_val[5];
String cmp_value;
int maxi=100;
int mini=900;

void setup()
   {
    pinMode(a1,OUTPUT);
    pinMode(a2,OUTPUT);
    pinMode(b1,OUTPUT);
    pinMode(b2,OUTPUT);
    pinMode(a_pwm,OUTPUT);
    pinMode(b_pwm,OUTPUT);
    cmp_value="";
    Serial.begin(9600);

    }

void loop()
   {
     readInput();
     follow_line();
   }

void readInput()
  {
      cmp_value="";
      s[0]=analogRead(S0);
      s[1]=analogRead(S1);
      s[2]=analogRead(S2);
      s[3]=analogRead(S3);
      s[4]=analogRead(S4);
       for(int i =0;i<5;i++)
        {
          if (s[i]>THRESHOLD)
                  {s[i]=1;cmp_value+="W";}
                  else {s[i]=0;cmp_value+="B";}
        }
        Serial.println(cmp_value);
  }
void follow_line()
{
  while (1)
  {
    readInput();
    for(int i =0;i<5;i++)
              s_val[i]=i-2;

    for(int i =0;i<5;i++)
        error+=(s_val[i]*s_val[i]*s_val[i]*s_val[i]+1773*s_val[i])*s[i];
    cumm_error+=error;
 Serial.println(error);
 k=kp*error + kd*(prev_error - error) + ki*(cumm_error);
    Serial.println(k);
     digitalWrite(b2,0);
     digitalWrite(b1,1);
     digitalWrite(a2,0);
     digitalWrite(a1,1);
      if(error>0)
        {
          analogWrite(a_pwm,255);
          analogWrite(b_pwm,255-abs(k));
        }
      else if(error<=0)
            {
          analogWrite(b_pwm,255);
          analogWrite(a_pwm,255-abs(k));
        }
        prev_error=error;
        error=0;
     }
     }


void stopM()
   {
     digitalWrite(a1,HIGH);
     digitalWrite(a2,LOW);
     digitalWrite(b1,HIGH);
     digitalWrite(b2,LOW);
     analogWrite(a_pwm,0);
     analogWrite(b_pwm,0);
     delay(100);
     Serial.print("stop\n");
   }

   void goright()
     {
       digitalWrite(a1,HIGH);
       digitalWrite(a2,LOW);
       digitalWrite(b1,HIGH);
       digitalWrite(b2,LOW);
       analogWrite(a_pwm,150);
       analogWrite(b_pwm,150);
       delay(60);
        Serial.print("GOING SHARP RIGHT\n");
       do
       {
         digitalWrite(a1,HIGH);
     digitalWrite(a2,LOW);
     digitalWrite(b1,LOW);
     digitalWrite(b2,HIGH);
     analogWrite(a_pwm,120);
     analogWrite(b_pwm,100);
     delay(50);
     readInput();

      digitalWrite(a1,HIGH);
     digitalWrite(a2,LOW);
     digitalWrite(b1,HIGH);
     digitalWrite(b2,LOW);
     analogWrite(a_pwm,0);
     analogWrite(b_pwm,0);
     delay(50);
     if(cmp_value=="BWWWB"||cmp_value=="BBWBB")
           break;
       }while (1);
      //allign();
      follow_line();
     }

     void goleft()
     {
       digitalWrite(a1,HIGH);
       digitalWrite(a2,LOW);
       digitalWrite(b1,HIGH);
       digitalWrite(b2,LOW);
       analogWrite(a_pwm,150);
       analogWrite(b_pwm,150);
       delay(60);
       Serial.print("GOING SHARP LEFT\n");
       do
       {
         digitalWrite(b1,HIGH);
     digitalWrite(b2,LOW);
     digitalWrite(a1,LOW);
     digitalWrite(a2,HIGH);
     analogWrite(a_pwm,120);
     analogWrite(b_pwm,100);
      delay(50);
     readInput();

     digitalWrite(a1,HIGH);
     digitalWrite(a2,LOW);
     digitalWrite(b1,HIGH);
     digitalWrite(b2,LOW);
     analogWrite(a_pwm,0);
     analogWrite(b_pwm,0);
     delay(50);
     if(cmp_value=="BWWWB" || cmp_value=="BBWBB")
           break;
       }while (1);
       //allign();
      follow_line();
     }

    /*void allign()
     {
       readInput();
       if(cmp_value=="BBWBB" || cmp_value=="BWWWB" || cmp_value=="WWWWW")
       {
         digitalWrite(a1,HIGH);
     digitalWrite(a2,LOW);
     digitalWrite(b1,HIGH);
     digitalWrite(b2,LOW);
     analogWrite(a_pwm,75);
     analogWrite(b_pwm,75);
     delay(50);
       }
     else if(cmp_value=="BBWWW" || cmp_value=="BBBWW" || cmp_value=="BBBWB"|| cmp_value=="BBWWB"||cmp_value=="BWWWW")
       {
         digitalWrite(a1,HIGH);
     digitalWrite(a2,LOW);
     digitalWrite(b1,HIGH);
     digitalWrite(b2,LOW);
     analogWrite(a_pwm,75);
     analogWrite(b_pwm,50);
     delay(50);
       }
     else if(cmp_value=="WWWBB"|| cmp_value=="WWBBB" || cmp_value=="BWBBB"|| cmp_value=="BWWBB"|| cmp_value=="WWWWB")
       {
         digitalWrite(a1,HIGH);
     digitalWrite(a2,LOW);
     digitalWrite(b1,HIGH);
     digitalWrite(b2,LOW);
     analogWrite(a_pwm,50);
     analogWrite(b_pwm,75);
     delay(50);
       }
     }*/
