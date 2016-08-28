#define max_speed 255
#define motor_left 3
#define motor_right 5

bool l1,l2,r1,r2,temp;
int sensors[5];
int right_speed,left_speed;
float set_point;
float Kp,Ki,Kd;
int sensors_average,sensors_sum;
float proportional,derivative,integral,last_proportional;
int error_value,pos;

void setup()
{
  
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
}

void loop()
{
    sensors_read(); //Reads sensor values and computes sensor sum and weighted average
    pid_calc(); //Calculates position[set point] and computes Kp,Ki and Kd
    calc_turn(); //Computes the error to be corrected
    motor_drive(right_speed,left_speed); //Sends PWM signals to the motors
}
void motor_drive(int right_speed, int left_speed)
{ // Drive motors according to the calculated values for a turn
analogWrite(motor_right, right_speed);
analogWrite(motor_left, left_speed);
delay(50); // Optional
}


void calc_turn()
{ //Restricting the error value between -256 and +256.
    if (error_value< -256)
        error_value = -256;

    if (error_value> 256)
        error_value = 256;

// If error_value is less than zero calculate right turn speed values
    if (error_value< 0)
    {
        right_speed = max_speed + error_value;
        left_speed = max_speed;
    }
// If error_value is greater than zero calculate left turn values
    else
    {
        right_speed = max_speed;
        left_speed = max_speed - error_value;
    }
}

void sensors_read()
{
    sensors_sum = 0;
    for (int i = 0; i < 5; i++)
    {
      sensors[i] = analogRead(i);
      sensors_average += sensors[i] * i * 1000; //Calculating the weighted mean of the sensor readings
      sensors_sum += int(sensors[i]); //Calculating sum of sensor readings
    }
}

void pid_calc()
{ 
    pos = sensors_average / sensors_sum;
    //proportional = pos – set_point;
    integral = integral + proportional;
    derivative = proportional - last_proportional;
    last_proportional = proportional;
    error_value =proportional * Kp + integral * Ki + derivative * Kd;
}
void reverse_sense(char a[])
{
   if(a=="left")
   {
      temp=l1;
      l1=l2;
      l2=temp;
   }
   
   if(a=="right")
   {
      temp=r1;
      r1=r2;
      r2=temp;
   }

}
  
