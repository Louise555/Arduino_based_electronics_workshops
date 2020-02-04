//
//Ramp up
//by Amanda Ghassaei
//http://www.instructables.com/id/Arduino-Audio-Output/
//Sept 2012
 
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
*/
 
void setup(){
  //set digital pins 0-7 as outputs
  for (int i=0; i<8; i++){
    pinMode(i,OUTPUT);
  }
  pinMode(A0,INPUT);
  Serial.begin(9600);                        // Output to Serial
  while (! Serial); // Wait untilSerial is ready
  Serial.println("Waveform generation!");
}
 
void loop(){
  /*
    The waveform is produced by sending values 0 to 255 to PORTD 
    in sequence. We need a delay between these values. If using
    an oscilloscope use a delay of 50 microsecs. If using the 
    Serial Monitor increase this to 100 ms.
  */
  for (int a=0;a<256;a++){
    PORTD = a;    //send out ramp to digital pins 0-7
    // delayMicroseconds(50); //wait 50us if using an oscilloscope
    delay(100); //wait 100ms if using the serial port
 
    if (Serial.available())
    {
      int DACout = analogRead(A0); 
      Serial.println(DACout);
    }
  }
}
