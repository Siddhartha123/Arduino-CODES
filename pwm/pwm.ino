void setup() {
  // put your setup code here, to run once:
byte mode=0x06;
pinMode(3,OUTPUT);
TCCR2B=TCCR2B & 0b11111000 | mode;
analogWrite(3,128);
}

void loop() {
}
