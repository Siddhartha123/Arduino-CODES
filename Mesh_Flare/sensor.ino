void process_sensor()
{
  for(i=0;i<7;i++)
      sensor[i]=analogRead(14+i)>thresh?1:0;
      
  for(i=0; i<7; i++) 
    {
     if(sensor[i])
        activeSensor++;
     totalSensor += sensor[i] * (i+1);
    }
    avgSensor = totalSensor/activeSensor;
    activeSensor = 0; totalSensor = 0;
}
void PID_program()
{ 
    
    previousError = error;                                  // save previous error for differential 
    error = avgSensor - 4.5;                               // Count how much robot deviate from center
    totalError += error;                                      // Accumulate error for integral
    power = kp*error + kd*(error-previousError) + ki*totalError;
    
    if( power>255.0 ) { power = 255.0; }
    if( power<-255.0 ) { power = -255.0; }
    
    if(power<0) // Turn left
    {
      PWM_Right = 255;
      PWM_Left = 255 - abs(int(power));
    }
    
    else // Turn right
    {
      PWM_Right = 255 - int(power);
      PWM_Left = 255;
    }
}

void generate_path()
{
   
}

