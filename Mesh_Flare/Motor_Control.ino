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
