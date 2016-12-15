#define R1 8
#define R2 10
#define pwmR_pin 5                //Right Motor=M4
uint8_t PWM_Right;
 
#define L1 9
#define L2 4
#define pwmL_pin 3            //Left Motor=M2
uint8_t PWM_Left;

void setup() {
  // put your setup code here, to run once:
pinMode(R1,OUTPUT);
pinMode(R2,OUTPUT);
pinMode(L1,OUTPUT);
pinMode(L2,OUTPUT);
pinMode(PWM_Right,OUTPUT);
pinMode(PWM_Left,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(R1,HIGH);
digitalWrite(L1,HIGH);
digitalWrite(R2,LOW);
digitalWrite(L2,LOW);
analogWrite(PWM_Right,255);
analogWrite(PWM_Left,255);
delay(500);
digitalWrite(R2,HIGH);
digitalWrite(L2,HIGH);
digitalWrite(R1,LOW);
digitalWrite(L1,LOW);

}
