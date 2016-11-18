const int AOUTpin= 0;//the AOUT pin of the CO sensor goes into analog pin A0 of the arduino
int value;

void setup() 

{
Serial.begin(57600);//sets the baud rate
pinMode(AOUTpin, INPUT);//sets the pin as an input to the arduino
}

void loop()
{
value= analogRead(AOUTpin);//reads the analaog value from the CO sensor's AOUT pin
Serial.print("CO value: ");
Serial.println(value);//prints the CO value
delay(60000);
}
