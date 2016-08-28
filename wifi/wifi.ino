void setup() {
  // put your setup code here, to run once:
  delay(1000);
Serial.begin(115200);
delay(100);
Serial.write("AT+CIPMUX=1\r\n");
  delay(1000);
Serial.write("AT+CIPSERVER=1,1080\r\n");
delay(100);
Serial.write("AT+CIOWRITE=1,0\r\n");
delay(1000);
}

void loop() {
  
}
