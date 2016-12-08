#include<ps2.h>

/*
 * Motor pins
 */

#define R1 20
#define R2 21
#define pwmR_pin 15                //Right Motor=M4
uint8_t PWM_Right;
 
#define L1 22
#define L2 23
#define pwmL_pin  4            //Left Motor=M2
uint8_t PWM_Left;


/*
 * Mouse control
 * 
 * Pin 5 is the mouse data pin, pin 6 is the clock pin
 * Feel free to use whatever pins are convenient.
 */

 #define m_clk 9
 #define m_data 8
PS2 mouse(m_clk, m_data); //(clock_pin, data_pin) any pin can be used

float calib_factor=1;
char mouse_x,mouse_y;       //byte read from the mouse
int change_x,change_y;       //change in co-ordinates of the mouse
int current_x,current_y;      //current co-ordinates of the mouse
void calculate_xy();

/*
 * PID control consants and sensor related variables
 */
#define thresh 512
#define kp 72
#define kd 5
#define ki 0.00015
float power;
float  previousError;
float error;
float totalError;
uint8_t activeSensor;
float avgSensor;
float totalSensor;
int sensor[7];                            //raw readings from sensor array from left to right

void process_sensor();
void PID_program();
/*
 * Miscellaneous variables and declarations
 */
uint8_t i;




void setup()
{
    pinMode(R1,OUTPUT);
    pinMode(R2,OUTPUT);
    pinMode(L1,OUTPUT);
    pinMode(L2,OUTPUT);
    pinMode(pwmR_pin,OUTPUT);
    pinMode(pwmL_pin,OUTPUT);
  Serial.begin(9600);
  mouse.init();
  attachInterrupt(digitalPinToInterrupt(10),finish,LOW);
  
}
void loop()
{
    calculate_xy();
}

