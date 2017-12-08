/*
  This a simple example of the aREST Library for Arduino (Uno/Mega/Due/Teensy)
  using the Serial port. See the README file for more details.

  Written in 2014 by Marco Schwartz under a GPL license.
*/

// Libraries
#include <SPI.h>
#include <aREST.h>
#include <avr/wdt.h>

// Create aREST instance
aREST rest = aREST();

// Variables to be exposed to the API
int sc1,sc2,sc3;

void setup(void)
{
  // Start Serial
  Serial.begin(115200);

  // Init variables and expose them to REST API
  sc1 = rand() % 100;  
  sc2 = rand() % 100;  
  sc3=rand() % 100;  
  rest.variable("sc1",&sc1);
  rest.variable("sc2",&sc2);
 rest.variable("sc3",&sc3);

  // Give name and ID to device (ID should be 6 characters long)
  rest.set_id("2");
  rest.set_name("serial");

  // Start watchdog
  wdt_enable(WDTO_4S);
}

void loop() {
  sc1 = rand() % 100;  
  sc2 = rand() % 100;  
  sc3=rand() % 100; 
  // Handle REST calls
  rest.handle(Serial);
  wdt_reset();

}

