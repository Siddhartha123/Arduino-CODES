#define el analogRead(A1)
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A1,INPUT_PULLUP);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  if(el==1)
   Serial.println("high");
   else Serial.println("low");
   Serial.println(el);

}
