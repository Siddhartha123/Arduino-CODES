int R1,R2,L1,L2,pwmR,pwmL;
void softLeft()
  {
    Serial.println("softLeft");
    analogWrite(pwmR, 230);
    digitalWrite(R2, HIGH);
    digitalWrite(R1, LOW);
    analogWrite(pwmL, 50);
    digitalWrite(L2, HIGH);
    digitalWrite(L1, LOW);
    delay(150);  
}
  void softRight()
  {
    Serial.println("softRight");
    analogWrite(pwmR, 50);
    digitalWrite(L2, HIGH);
    digitalWrite(L1, LOW);
    analogWrite(pwmL, 240);
    digitalWrite(R2, HIGH);
    digitalWrite(R1, LOW);
    delay(150);
  }

void goLeft()
  {
    analogWrite(pwmR, 255);
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
    analogWrite(pwmL, 70);
    digitalWrite(L1, LOW);
    digitalWrite(L2, HIGH);
    Serial.print("left ");
    delay(100);
  }
  void goRight()
  {
    analogWrite(pwmR, 70);
    digitalWrite(L1, HIGH);
    digitalWrite(L2, LOW);
    analogWrite(pwmL, 255);
    digitalWrite(R1, LOW);
    digitalWrite(R2, HIGH);
    Serial.print("Right ");
    delay(100);
  }
  void hardRight()
  {
    analogWrite(pwmR, 255);
    digitalWrite(L1, HIGH);
    digitalWrite(L2, LOW);
    analogWrite(pwmL, 255);
    digitalWrite(R1, LOW);
    digitalWrite(R2, HIGH);
    Serial.print("hardright ");
    delay(350);
  }
  void hardLeft()
  {
    analogWrite(pwmR, 255);
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
    analogWrite(pwmL, 255);
    digitalWrite(L1, LOW);
    digitalWrite(L2, HIGH);
    Serial.print("hardleft ");
    delay(350);
  }
  void goFront()
  {
    analogWrite(pwmR, 255);
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
    analogWrite(pwmL, 255);
    digitalWrite(L1, HIGH);
    digitalWrite(L2, LOW);
    Serial.print("front ");
    delay(200);
  }
  void goReverse()
  {
    analogWrite(pwmR, 200);
    digitalWrite(R2, HIGH);
    digitalWrite(R1, LOW);
    analogWrite(pwmL, 200);
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
