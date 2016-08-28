#pragma pack(1)

int a[9],b[9];
int read_sensor();
String cmp;
void setValues();
void processValues();

int topelement();
void push(int data);
int pop();
boolean empty();
void display();
void stack_count();

void setup()
{
  Serial.begin(9600);
}

void loop()
{
      read_sensor();//read the sensor values to locate paths ahead
      move_along_path();
}

int read_sensor()
{
  int i,c=0;
  for(i=0;i<9;i++)
  {
    a[i]=analogRead(i);
    if(a[i]>512)
            b[i]=1;
    else
            b[i]=0;
    if(b[i-1]!=b[i])
            c++;
  }
  if(c>2)
    return 1;
  else
    return 0;
}
void move_along_path()
{
switch(read_sensor())
{
 case 0:        //normal path
  setValues();
  processValues();
   break;
 case 1:       //multiple paths
  if(empty())
       {
        //take the one that requires least turning and push to stack right or left
       }   
    else 
    {
      // pop from stack
       //go in opposite direction {e.g. if right pops go left}
    }
/*   
if(dead end)
  turn 180;
*/
 break;
 }
}

