#include <VirtualWire.h>
char *controller;
void setup() {
  pinMode(13,OUTPUT);
vw_set_ptt_inverted(true); //
vw_set_tx_pin(12);
vw_setup(1000);// speed of data transfer Kbps
}

void loop(){
controller="hello"  ;
vw_send((uint8_t *)controller, strlen(controller));
vw_wait_tx(); // Wait until the whole message is gone
}


