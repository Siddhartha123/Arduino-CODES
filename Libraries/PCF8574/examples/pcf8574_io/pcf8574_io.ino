//
//    FILE: pcf8574_test.ino
//  AUTHOR: Rob Tillaart
//    DATE: 27-08-2013
//
// PUPROSE: demo 
//

#include "PCF8574.h"
#include <Wire.h>

// adjust addresses if needed
PCF8574 PCF_39(0x20);  // add leds to lines      (used as output)

void setup()
{
  Serial.begin(115200);
  Serial.println("\nTEST PCF8574\n");
   PCF_39.write8(255);
   delay(5000);
     PCF_39.write8(0);
}

void loop()
{
}
