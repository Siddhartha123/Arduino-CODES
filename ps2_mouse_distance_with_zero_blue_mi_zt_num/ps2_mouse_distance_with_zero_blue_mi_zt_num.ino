#include <ps2.h>

PS2 mouse(9, 8); //(clock_pin, data_pin) any pin can be used
int newmx=0;
int newmy=0;
 
/*
 * initialize the mouse. Reset it, and place it into remote
 * mode, so we can get the encoder data on demand.
 */
void setup()
{
  Serial.begin(9600);
  mouse.init();
}
/*
* get a reading from the mouse and report it back to the
* host via the serial bluetooth.
*/
void loop()
{
  char mouse_x,mouse_y;
  int change_x;
  int change_y;
 
  /* get a reading from the mouse */
  mouse.write(0xeb);  // give me data!
  mouse.read();      // ignore ack
  mouse.read();    //status byte
  mouse_x = mouse.read();
  mouse_y = mouse.read();
  change_x=(int)mouse_x;
  change_y=(int)mouse_y;
  newmx=newmx+ change_x;
  newmy=newmy+change_y;
  Serial.print(newmx);
  Serial.print("   ");
  Serial.println(newmy);
  delay(1);
}
