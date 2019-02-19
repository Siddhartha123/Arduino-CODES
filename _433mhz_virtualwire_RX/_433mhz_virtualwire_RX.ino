#include <VirtualWire.h>
void setup()
{
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_set_rx_pin(12);
    vw_setup(1000);  // Bits per sec
    pinMode(13, OUTPUT);
Serial.begin(115200);
    vw_rx_start();       // Start the receiver PLL running
}
    void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
          for(int i=0;i<buflen;i++)
            Serial.print(char(buf[i]));
            Serial.println();
     
    }
      

}
