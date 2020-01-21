//This sketch is to test the IC SN7404 which has 4 inverters. 
// connect Vcc to 5V powered by Arduino. Connect pin 7 of the IC to Gnd
// The input is pin 13 of the IC . Connect this pin to digital pin 7 of Arduino
// The output is pin 12 of the IC and is connected to an LED protected by a 330 ohms.
// The Arduino generates 0 and 1. 

 

byte pin=7;

void setup() {
pinMode(pin,OUTPUT);
Serial.begin(9600);

}

void loop() {

Serial.println("input is 0 or LOW" );
Serial.println(" What is the output ?" );
digitalWrite(pin,0);
delay(5000);
Serial.println();
Serial.println(" input is 1 or HIGH " );
Serial.println(" What is the output ?" );
digitalWrite(pin,1);
delay(5000);
Serial.println();
Serial.println();
}

