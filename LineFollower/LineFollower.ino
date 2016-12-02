   #define SENSORS 5
 #define s6 A5
  #define s1 A4
  #define s2 A3
  #define s3 A2
  #define s4 A1
  #define s5 A0
  #define THRESH 300
  #define R1 8
  #define R2 10
  #define pwmR 5                //Right Motor=M4
  #define L1 9
  #define L2 4
  #define pwmL 3            //Left Motor=M2
             
        
  int inp_sensors[SENSORS], i;
  String pins[5];
  String cmp;
  void setup() 
  {
      Serial.begin(9600); 
    cmp="";
    pinMode(R1, OUTPUT);
    pinMode(R2, OUTPUT);
    pinMode(L1, OUTPUT);
    pinMode(L2, OUTPUT);
    pinMode(pwmR, OUTPUT);
    pinMode(pwmL, OUTPUT);
  }

void loop() 
{
  
/*readInput();
setValues();
processValues();
*/
goRight();
delay(1000);
goLeft();
delay(1000);
}
void readInput()
{
  inp_sensors[0] = analogRead(s1);
  inp_sensors[1] = analogRead(s2);
  inp_sensors[2] = analogRead(s3);
  inp_sensors[3] = analogRead(s4);
  inp_sensors[4] = analogRead(s5);
  //  inp_sensors[4] = analogRead(s5);
  int x0= analogRead(A0);
int x1= analogRead(A1);
int x2= analogRead(A2);
int x3= analogRead(A3);
int x4= analogRead(A4);

//int x5= analogRead(A5);
Serial.print(x0);
Serial.print('\t');
Serial.print(x1);
Serial.print('\t');
Serial.print(x2);
Serial.print('\t');
Serial.print(x3);
Serial.print('\t');
Serial.print(x4);
Serial.print('\t');
/*Serial.print(x5);
Serial.print('\t');*/
Serial.println(); 

}
void setValues()
{
  cmp="";
  for(i=0;i<SENSORS;i++)
  {
    
    if(inp_sensors[i]<THRESH)
    {
      cmp+="B";
    }
    else
    {
      cmp+="W";
    }
  }
  Serial.println(cmp+" ");
}
void processValues()
{
  
  if(cmp=="BWWWB")
  {
    goFront();
  }
  else if(cmp=="BWBBB"||cmp=="BBBWB")
  {
    goSlow();
  }
  else if(cmp=="BBBBB")
  {
    //goReverse();
    halt();
  }
  else if(cmp=="WWWWB")
  {
    hardLeft();
  }
  else if(cmp=="BWWWW")
  {
    hardRight();
  }
  else if(cmp=="BWWBB")
  {
    goLeft();
  }
  else if(cmp=="BBWWB")
  {
    goRight();
  }
  else if(cmp=="WWWWW")
  {
    goFront();
  }
  else if(cmp=="BBBWW"||cmp=="BBBBW"||cmp=="BBWWW")
  {
    softRight();
  }
  else if(cmp=="WWBBB"||cmp=="WBBBB"||cmp=="WWWBB")
  {
    softLeft();
  }
  else
   halt();
}
void softLeft()
  {
    analogWrite(pwmR, 230);
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
    analogWrite(pwmL, 100);
    digitalWrite(L1, HIGH);
    digitalWrite(L2, LOW);
    Serial.print("soft Left ");
    delay(150);  
}
  void softRight()
  {
    analogWrite(pwmR, 147);
    digitalWrite(L1, HIGH);
    digitalWrite(L2, LOW);
    analogWrite(pwmL, 240);
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
   Serial.print("soft Right ");
    delay(150);
  }
void goLeft()
  {
    analogWrite(pwmR, 100);
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
    analogWrite(pwmL, 0);
    digitalWrite(L1, LOW);
    digitalWrite(L2, HIGH);
    Serial.print("left ");
    delay(100);
  }
  void goRight()
  {
    analogWrite(pwmR, 0);
    digitalWrite(L1, HIGH);
    digitalWrite(L2, LOW);
    analogWrite(pwmL,100);
    digitalWrite(R1, LOW);
    digitalWrite(R2, HIGH);
   Serial.print("Right ");
    delay(100);
  }
  void hardRight()
  {
    analogWrite(pwmR, 147);
    digitalWrite(L1, HIGH);
    digitalWrite(L2, LOW);
    analogWrite(pwmL, 150);
    digitalWrite(R1, LOW);
    digitalWrite(R2, HIGH);
    Serial.print("hardright ");
    delay(300);
  }
  void hardLeft()
  {
    analogWrite(pwmR, 147);
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
    analogWrite(pwmL, 150);
    digitalWrite(L1, LOW);
    digitalWrite(L2, HIGH);
   Serial.print("hardleft ");
    delay(300);
  }
  void goFront()
  {
    analogWrite(pwmR, 147);
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
    analogWrite(pwmL, 150);
    digitalWrite(L1, HIGH);
    digitalWrite(L2, LOW);
   Serial.print("front ");
    delay(200);
  }
  void goReverse()
  {
    analogWrite(pwmR, 147);
    digitalWrite(R2, HIGH);
    digitalWrite(R1, LOW);
    analogWrite(pwmL, 150);
    digitalWrite(L2, HIGH);
    digitalWrite(L1, LOW);
    Serial.print("front ");
    delay(50);
  }
  void goSlow()
  {
    analogWrite(pwmR, 180);
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
    analogWrite(pwmL, 180);
    digitalWrite(L1, HIGH);
    digitalWrite(L2, LOW);
    Serial.print("slow ");
    delay(120);
  }
  void halt()
  {
    analogWrite(pwmR, 0);
    digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);
    analogWrite(pwmL, 0);
    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
    Serial.print("halt ");
    delay(200);
  }
 
    
    
