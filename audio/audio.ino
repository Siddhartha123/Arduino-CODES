#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

void setup(){
tmrpcm.speakerPin = 9;
Serial.begin(9600);
if (!SD.begin(SD_ChipSelectPin)) {
Serial.println("SD fail");
return;
}

tmrpcm.setVolume(1);
tmrpcm.play("1.wav");
}

void loop(){
  if(Serial.available()){    
    switch(Serial.read()){
    case '+': tmrpcm.volume(1);                                        break;   // Volume up
    case '-': tmrpcm.volume(0);                                        break;   // Volume down
    default: break;
    }
  }
  }
