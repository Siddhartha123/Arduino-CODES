const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT);
  attachInterrupt(interruptPin, blink, CHANGE);
}

void loop() {
  
}

void blink() {
  state = !state;
  digitalWrite(ledPin, state);
}
