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
