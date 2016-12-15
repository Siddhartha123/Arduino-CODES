   #define SENSORS 5
  #define THRESH 300
  #define R1 5
  #define R2 4
  #define pwmR 10                //Right Motor=M4
  #define L1 3
  #define L2 2
  #define pwmL 11            //Left Motor=M2
             
        
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
  readInput();
setValues();
processValues();
}
void readInput()
{
for(i=0;i<5;i++)
{
  inp_sensors[i]=analogRead(14+i);
  Serial.print(inp_sensors[i]);
  }
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
 
    
    
