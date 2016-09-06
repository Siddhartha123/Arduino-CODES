#include <ps2.h>
/*
 * Pin 5 is the mouse data pin, pin 6 is the clock pin
 * Feel free to use whatever pins are convenient.
 */
PS2 mouse(6, 5);
int newmx=0;
int newmy=0;
int zeroPin=7; // to zero the counter
int calib=1; // calibration factor
 
/*
 * initialize the mouse. Reset it, and place it into remote
 * mode, so we can get the encoder data on demand.
 */


void setup()
{
  pinMode(zeroPin, INPUT_PULLUP);
  Serial.begin(115200);
  mouse.init();
}
/*
* get a reading from the mouse and report it back to the
* host via the serial bluetooth.
*/
void loop()
{
  char mstat;
  char mx;
  char my;
 
  /* get a reading from the mouse */
  mouse.write(0xeb);  // give me data!
  mouse.read();      // ignore ack
  mstat = mouse.read();
  mx = mouse.read();
  my = mouse.read();


if (Serial.read()==('z')) {
     newmy=0;
     newmx=0;
}
  if ( digitalRead(zeroPin) == LOW)
   {
     newmy=0;
     newmx=0;
     
   } 
   else {
     newmx=newmx+ mx;
     newmy=newmy+my;
    

   Serial.print("Y=  ");
   Serial.println(newmy)/calib;
   Serial.print("?");
   Serial.print("X=  ");
   Serial.println(newmx)/calib;
   
  
  delay(1);
  
 
   }
}
