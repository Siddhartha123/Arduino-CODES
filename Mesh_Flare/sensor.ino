void read_sensor()
{
  for(i=0;i<7;i++)
    sensor_read[i]=analogRead(i+14);
}
void process_sensor()
{
  for(i=0;i<7;i++)
      sensor[i]=sensor_read[i]>512?1:0;
      
  for(int i=0; i<7; i++) 
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
    read_sensor();
    previousError = error;                                  // save previous error for differential 
    error = avgSensor - 4.5;                               // Count how much robot deviate from center
    totalError += error;                                      // Accumulate error for integral
    power = kp*error + kd*(error-previousError) + ki*totalError;
    
    if( power>255 ) { power = 255.0; }
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

