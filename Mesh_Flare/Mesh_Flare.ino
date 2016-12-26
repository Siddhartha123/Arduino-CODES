#include <ps2.h>
/*
 * Motor pins
 */

#define R1 22
#define R2 23
#define pwmR_pin 3               
uint8_t PWM_Right=93;
 
#define L1 20
#define L2 21
#define pwmL_pin  15            
uint8_t PWM_Left=80;
/*
 * Mouse control
 * 
 * Pin 5 is the mouse data pin, pin 6 is the clock pin
 * Feel free to use whatever pins are convenient.
 */
 #define m_clk 11
 #define m_data 10
PS2 mouse(m_clk, m_data); //(clock_pin, data_pin) any pin can be used

float calib_factor=1;
char mouse_x=0,mouse_y=0;       //byte read from the mouse
int change_x=0,change_y=0;       //change in co-ordinates of the mouse
int current_x=0,current_y=0;      //current co-ordinates of the mouse
void calculate_xy();

/*
 * PID control consants and sensor related variables
 */
 #define gridX  13
#define gridY 15
#define thresh 512
//float kp=5,ki=0,kd=0;
float power;
float  previousError=0;
float error;
float cumm_error,prev_error,k;
float totalError;
uint8_t activeSensor;
float avgSensor;
float totalSensor;
//int sensor[7];                            //raw readings from sensor array from left to right
String sensor_val,sensor_val_prev;
String s,s1="                                ";
char c;
uint8_t distance=0;
void process_sensor();
void PID_program();
void change_constants();
void goFront();
void goLeft();
void goRight();
void Front();
void showgrid();
void trialrun();
void follow_line();
/*
 * Miscellaneous variables and declarations
 */
uint8_t i=100;
int d;
int dx=5, dy=11;
uint8_t grid[gridX][gridY] = {
                                     250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,
                                               250, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,250,
                                               250, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,250,
                                               250, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,250,
                                               250, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,250,
                                               250, 1 , 1 , 1 , 1,  1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,250,
                                               250, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,250,
                                               250, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,250,
                                               250, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,250,
                                               250, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,250,
                                               250, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,250,
                                               250, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,250, 
                                      250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,
                                        };//initial grid


void setup()
{
    pinMode(R1,OUTPUT);
    pinMode(R2,OUTPUT);
    pinMode(L1,OUTPUT);
    pinMode(L2,OUTPUT);
    pinMode(pwmR_pin,OUTPUT);
    pinMode(pwmL_pin,OUTPUT);
    pinMode(16,OUTPUT);
    grid[dx][dy]=i;
    //mouse.init();
  //attachInterrupt(digitalPinToInterrupt(10),finish,LOW);
  Serial.begin(9600);
 digitalWrite(16, HIGH);
 goFront();
// analogWrite(pwmR_pin, 200);
  //analogWrite(pwmL_pin, 200);
}

void loop()
{
  /*
  process_sensor();
  follow_line(); 
  trialrun();*/
  calculate_xy();
  //goFront();
}

