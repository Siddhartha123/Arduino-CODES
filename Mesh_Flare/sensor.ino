#define L1 20
#define L2 21
#define pwmL_pin  15

#define R1 22
#define R2 23
#define pwmR_pin 3           

#define thresh 512

float kp=0.034,ki=0,kd=0;
uint8_t i,s_val[5],sensor[5],power;
float error,cumm_error,prev_error,k;



void process_sensor()
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
     process_sensor();
    /*if(sensor_val=="WWWWWBB" || sensor_val=="WWWWBBB" ||sensor_val=="WWWWWWB")
    {
          digitalWrite(L2,HIGH);
          digitalWrite(L1, LOW);
          analogWrite(pwmR_pin,75);
          analogWrite(pwmL_pin,75);
          delay(400);
    }*/
    memset(arr,9,sizeof(arr));
    if(sensor[0]+sensor[1]+sensor[2]+sensor[3]+sensor[4]==0)
        {
          analogWrite(pwmR_pin,0);
          analogWrite(pwmL_pin,0);
          continue;
        }

     if(l==0011100 && u==010)
     {
      //Front();
      //return to grid 1,3  
      w=1;arr[0]=3;
     }
     else if(l==1111000 && u==000 || l==1111100 && u==000)
     {
      //goSharpLeft();
      //return to grid 1,1
      w=1;arr[0]=1;
     }
     else if(l==00011111 && u==000 || l==0011111 && u==000)
     {
      //goSharpRight(); 
      //return to grid 1,5
      w=1;arr[0]=5;
     }
     else if(l==1111000 && u==010 || l=1111100 && u==010)
     {
      //goSharpLeft();
      //return to grid 2,1,3
      w=2;arr[0]=1;arr[1]=3;
     }
     else if(l==0001111 && u==010 || l=0011111 && u==010)
     {
      //Front();
      //return to grid 2,3,5
      w=2;
      arr[0]=3;arr[1]=5;
     }
     else if(l==1111111 && u==000)
     {
      //goSharpLeft();
      //return to grid 2,1,5
      w=2;arr[0]=1;arr[1]=5;
     }
     else if(l==0011100 && u==001 || l==0011100 && u==011 || l==0011110 && u==001 || l==0011110 && u==011)
     {
      //goSoftRight();
      //return to grid 1,4
      w=1;
      arr[0]=4;
     }
      else if(l==0011100 && u==100 || l==0011100 && u==110 || l==0111100 && u==100 || l==0111100 && u==110)
     {
      //goSoftLeft();
      //return to grid 1,2
      w=1;arr[0]=2;
     }
      else if(l==1111000 && u==001 || l==1111000 && u==011 || l==1111100 && u==001 || l==1111100 && u==011)
     {
      //goSharpLeft();
      //return to grid 2,1,4
      w=2;
      arr[0]=1;arr[1]=4;
     }
      else if(l==1111000 && u==110 || l==1111100 && u==100 || l==1111100 && u==110 || l==1111000 && u==100)
     {
      //goSharpLeft();
      //return to grid 2,1,2
      w=2;arr[0]=1;arr[1]=2;
     }
      else if(l==0011110 && u==011 || l==0011100 && u==011 )
     {
      //Front();
      //return to grid 2,3,4
      w=2;arr[0]=3;arr[1]=4;
     }
      else if(l==0011100 && u==110 || l==0111100 && u==110 )
     {
      //goSoftLeft();
      //return to grid 2,2,3
      w=2;arr[0]=2;arr[1]=3;
     }
      else if(l==0001111 && u==011 || l==0011111 && u==001 || l==0011111 && u==011 )
     {
      //goSoftRight();
      //return to grid 2,4,5
      w=2;arr[0]=4;arr[1]=5;
     }
      else if(l==0011100 && u==101)
     {
      //goSoftLeft();
      //return to grid 2,2,4
      w=2;arr[0]=2;arr[1]=4;
     }
      else if(l==0001111 && u==110 || l==0011111 && u==100 || l==0011111 && u==110)
     {
      //goSoftLeft();
      //return to grid 2,2,5
      w=2;arr[0]=2;arr[1]=5;
     }
}

void Front()
{
  while(1)
  {
       for(j=0;j<5;j++)
        error+=(s_val[j]*s_val[j]*s_val[j]+1773*s_val[j])*sensor[j];
  cumm_error+=error;
 k=kp*error + kd*(prev_error - error) + ki*(cumm_error);
 //Serial.println(k);
 power=k;
   if(error>0)
        {
          analogWrite(pwmL_pin,90);
          analogWrite(pwmR_pin,120-abs(power));
          Serial.print("90      ");
          Serial.println(120-abs(power));
        }
      else if(error<=0)
            {
          analogWrite(pwmR_pin,120);
          analogWrite(pwmL_pin,90-abs(power));
           
          Serial.print(90-abs(power));
          Serial.print("120      ");
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
     process_sensor();
     
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
     process_sensor();
  
     if(l==0000110 ||l==0000111 || l==0001110)
           break;
       }while (1);
      
      
     }

}

/*void linefollow()
{
  num_path=0;
  for(i=1;i<7;i++)
  {
    if(sensor_val[i-1]=='W' &&sensor_val[i]=='B')
    num_path++;
  }
  Serial.println(num_path);
  
   if(sensor_val== "BBWWWBB")
    d=0;//goFront();
   else if(sensor_val=="BBWWBBB" || sensor_val=="BWWWBBB")
            d=10;//SOFT LEFT
    else if(sensor_val=="BBBWWBB"|| sensor_val=="BBBWWWB")
            d=-10;//SOFT RIGHT
   else if(sensor_val=="BWWBBBB" || sensor_val=="BWWWWBB")
            d=20;//LEFT
   else if(sensor_val=="BBBBWWB" || sensor_val=="BBBBWWW" || sensor_val=="BBBBBWW")
            d=-20;//RIGHT
    else if(sensor_val=="BBWWWWB")
    {
            d=16;
            analogWrite(pwmR_pin,PWM_Right+3*d/2);
            analogWrite(pwmL_pin,PWM_Left-d/2);
    }
    else if(sensor_val=="WWBBBBB" || sensor_val=="WWWBBBB" || sensor_val=="WWWWBBB" || sensor_val=="WWWWWBB" || sensor_val=="WWWWWWB" || sensor_val[0]=='W' && num_path==2)
    {
            digitalWrite(L2,HIGH);
            digitalWrite(L1, LOW);
            analogWrite(pwmL_pin,60);
            analogWrite(pwmR_pin,73);
            delay(turn_delay);
            digitalWrite(L1,HIGH);
            digitalWrite(L2, LOW);
    }
    else if(sensor_val=="WWWWWW")
    {
             if(sensor_val_prev=="BBBWWBB")
                     d=-10; 
             else if(sensor_val_prev=="BBWWBBB")
                     d=10;                     
    }
else
    f=1;   
if(!f)
    {
 Serial.print(PWM_Left-d);
  Serial.println(PWM_Right+d);
 analogWrite(pwmR_pin,PWM_Right+d);
  analogWrite(pwmL_pin,PWM_Left-d);
    }
else
        {
        stopm();
        f=0;
        }  
 }*/

