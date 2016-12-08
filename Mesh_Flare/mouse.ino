

void calculate_xy()
{
mouse.write(0xeb);  // give me data!
  mouse.read();      // ignore ack
  mouse.read();    //status byte
  mouse_x = mouse.read();
  mouse_y = mouse.read();
  change_x=(uint8_t)mouse_x;
  change_y=(uint8_t)mouse_y;
  current_x=current_x+ change_x;
  current_y=current_y+change_y;
  Serial.print(current_x);
  Serial.print("   ");
  Serial.println(current_y);
  delay(1);
}
