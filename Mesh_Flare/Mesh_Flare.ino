#include<ps2.h>

/*
 * Motor pins
 */

#define R1 8
#define R2 10
#define pwmR_pin 5                //Right Motor=M4
int PWM_Right;
 
#define L1 9
#define L2 4
#define pwmL_pin 3            //Left Motor=M2
int PWM_Left;


/*
 * Mouse control
 * 
 * Pin 5 is the mouse data pin, pin 6 is the clock pin
 * Feel free to use whatever pins are convenient.
 */

 #define m_clk 6
 #define m_data 5
PS2 mouse(9, 8); //(clock_pin, data_pin) any pin can be used
float calib_factor=1;
char mouse_x,mouse_y;       //byte read from the mouse
int change_x,change_y;       //change in co-ordinates of the mouse
int current_x,current_y;      //current co-ordinates of the mouse


/*
 * PID control consants and sensor related variables
 */

#define kp 72
#define kd 5
#define ki 0.00015
float power;
float  previousError;
float error;
float totalError;
int activeSensor;
float avgSensor;
float totalSensor;
int sensor[7];
int sensor_read[7];                              //raw readings from sensor array from left to right

/*
 * Miscellaneous variables and declarations
 */
 int i;




void setup()
{
  
}
void loop()
{
 
}

