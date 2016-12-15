/*
void finish()
{
    for(i=0;i<7;i++)
    {
      sensor[i]=analogRead(14+i)>thresh?1:0;  
      if(sensor[i]==0)    //black line
        break;
     }
     if(i==7)
     digitalWrite(15,HIGH);
     while(true)
     {
     }
}
int a=90;*/
  void goFront()
  {
    analogWrite(pwmR_pin, 63);
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
    analogWrite(pwmL_pin,50);
    digitalWrite(L1,HIGH);
    digitalWrite(L2, LOW);
  }

  void stopm()
  {
     analogWrite(pwmR_pin, 0);
      analogWrite(pwmL_pin,0);
      delay(100);
  }
