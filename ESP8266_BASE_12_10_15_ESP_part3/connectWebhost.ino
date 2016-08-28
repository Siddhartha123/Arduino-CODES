void connect_webhost(){
//we have changing variable here, so we need to first build up our URL packet
URL_withPacket = URL_webhost;//pull in the base URL
URL_withPacket += String(unit_id);//unit id value
URL_withPacket += "&sensor=";//unit id 1
URL_withPacket += String(sensor_value);//sensor value
URL_withPacket += payload_closer;
  
  
  /// This builds out the payload URL - not really needed here, but is very handy when adding different arrays to the payload
  counter=0;//keeps track of the payload size
  payload_size=0;
  for(int i=0; i<(URL_withPacket.length()); i++){//using a string this time, so use .length()
    payload[payload_size+i] = URL_withPacket[i];//build up the payload
    counter++;//increment the counter
  }//for int
  payload_size = counter+payload_size;//payload size is just the counter value - more on this when we need to build out the payload with more data
    //for(int i=0; i<payload_size; i++)//print the payload to the ESP
    //Serial.print(payload[i]);
   
  if(connect_ESP()){//this calls 'connect_ESP()' and expects a '1' back if successful
  //nice, we're in and ready to look for data
  //first up, we need to parse the returned data  _t1123##_d15##_d210##

  
    if(read_until_ESP(keyword_t1,sizeof(keyword_t1),5000,0)){//go find t1 then stop
      if(read_until_ESP(keyword_doublehash,sizeof(keyword_doublehash),5000,1)){//our data is next, so change mode to '1' and stop at ##
        //got our data, so quickly store it away in d1
        for(int i=1; i<=(scratch_data_from_ESP[0]-sizeof(keyword_doublehash)+1); i++)//go see 'setup' and how this was done with the ip address for more info
        t1_from_ESP[i] = scratch_data_from_ESP[i];
        t1_from_ESP[0] = (scratch_data_from_ESP[0]-sizeof(keyword_doublehash)+1);
    
        //we still have more data to get out of this stream, now we want d1
        if(read_until_ESP(keyword_d1,sizeof(keyword_d1),5000,0)){//same as before - first d1
          if(read_until_ESP(keyword_doublehash,sizeof(keyword_doublehash),5000,1)){//now ## and mode=1
            for(int i=1; i<=(scratch_data_from_ESP[0]-sizeof(keyword_doublehash)+1); i++)
              d1_from_ESP[i] = scratch_data_from_ESP[i];
             d1_from_ESP[0] = (scratch_data_from_ESP[0]-sizeof(keyword_doublehash)+1); 

        if(read_until_ESP(keyword_d2,sizeof(keyword_d2),5000,0)){//same as before - first d2
          if(read_until_ESP(keyword_doublehash,sizeof(keyword_doublehash),5000,1)){//now ## and mode=1
            for(int i=1; i<=(scratch_data_from_ESP[0]-sizeof(keyword_doublehash)+1); i++)
              d2_from_ESP[i] = scratch_data_from_ESP[i];
              d2_from_ESP[0] = (scratch_data_from_ESP[0]-sizeof(keyword_doublehash)+1);            
      
            //now that we have our data, go wait for the connection to disconnect - the ESP will eventually return 'Unlink'
            if(read_until_ESP(keyword_linkdisc,sizeof(keyword_linkdisc),5000,0)){
              // delay(10);
              Serial.println("FOUND DATA & DISCONNECTED");
              serial_dump_ESP();//now we can clear out the buffer and read whatever is still there
              //let's see how the data looks
              
               Serial.print("Time ");
               if(t1_from_ESP[0] > 3){
               Serial.print(t1_from_ESP[1]);
               Serial.print(t1_from_ESP[2]);
               Serial.print(":");
               Serial.print(t1_from_ESP[3]);
               Serial.print(t1_from_ESP[4]);  
               }
               else{
               Serial.print(t1_from_ESP[1]);
               Serial.print(":");
               Serial.print(t1_from_ESP[2]);
               Serial.print(t1_from_ESP[3]);  
               }
               Serial.print(" LED = ");//print out LED data and convert to integer
               LED_value = 0;
               for(int i=1; i<=d1_from_ESP[0]; i++){
               //Serial.print(d1_from_ESP[i]);
               LED_value = LED_value + ((d1_from_ESP[i] - 48) * multiplier[d1_from_ESP[0] - i]);
               }
               Serial.print(LED_value);
               
               Serial.print(" SENSOR = ");//print out Sensor data and convert to integer
               sensor_readBack = 0;
               for(int i=1; i<=d2_from_ESP[0]; i++){
               //Serial.print(d2_from_ESP[i]);
               sensor_readBack = sensor_readBack + ((d2_from_ESP[i] - 48) * multiplier[d2_from_ESP[0] - i]);
               }
               Serial.print(sensor_readBack);               
               Serial.println("");
               
              //that's it!!
                }//link
              }//##
            }//d2
          }//##
        }//d1       
      }//##
    }//t1
  }//connect ESP


}//connect web host

