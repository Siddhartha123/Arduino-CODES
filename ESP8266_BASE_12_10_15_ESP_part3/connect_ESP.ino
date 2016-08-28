boolean connect_ESP(){//returns 1 if successful or 0 if not

  Serial.println("CONNECTING");
  ESP8266.print("AT+CIOWRITE=1,0\r\n");//connect to your web server
  //read_until_ESP(keyword,size of the keyword,timeout in ms, data save 0-no 1-yes 'more on this later') 
  if(read_until_ESP(keyword_OK,sizeof(keyword_OK),5000,0)){//go look for 'OK' and come back
  serial_dump_ESP();//get rid of whatever else is coming
  Serial.println("CONNECTED");//yay, connected
  ESP8266.print("AT+CIPSEND=0,");//send AT+CIPSEND=0, size of payload
  ESP8266.print(payload_size);//the payload size
  serial_dump_ESP();//everything is echoed back, so get rid of it
  ESP8266.print("\r\n");//cap off that command with a carriage return and new line feed
  }
  
}// VOID CONNECT FUNCTION
