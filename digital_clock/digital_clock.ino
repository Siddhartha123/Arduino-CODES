const PROGMEM uint8_t digits[10][7]={
      {1,1,1,1,1,1,0},
      {0,1,1,0,0,0,0},
      {1,1,0,1,1,0,1},
      {1,1,1,1,0,0,1},
      {0,1,1,0,0,1,1},
      {1,0,1,1,0,1,0},
      {1,0,1,1,1,1,1},
      {1,1,1,0,0,0,0},
      {1,1,1,1,1,1,1},
      {1,1,1,1,0,1,1}
};
int i,j;
void setup() {
  // put your setup code here, to run once:
for(i=0;i<14;i++)
{
pinMode(i,OUTPUT);
digitalWrite(i,LOW);
}
}

void loop() {
  // put your main code here, to run repeatedly:
for(j=0;j<10;j++)
display_digit(j,0);
}

void display_digit(int digit,int pos)
{
  digitalWrite(pos,LOW);
  for(i=0;i<7;i++)
  {
    digitalWrite(i+6,1-digits[digit][i]);
  }
}

