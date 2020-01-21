// To work with the IC SN74175 which has 4 D-data flip flop.
//// first in set up we set the pin " clear" (pin7)  to 0 to clear the memory. then to set it to HIGH (set)
// Then in loop  we start a clock (pin8) with a peiod of 5 second to clock the data. The input is entered by hand
// by connecting the input to 5V or Gnd. The input is clocked in only when the clock is rising.
// we can work with only one flip flop or we can connect the 4 flip flops.  

 

byte pinClear=7;
byte pinClock=8;

void setup() {
pinMode(pinClear,OUTPUT);
pinMode(pinClock,OUTPUT);
Serial.begin(9600);
Serial.println("clearing the flip fop then waiting 1s" );
digitalWrite(pinClear,0);
delay(1000);
Serial.println();
Serial.println(" turning on the flip flop " );
digitalWrite(pinClear,1);
delay(1000);
Serial.println("starting the clock with off  with a period 5 ");
}

void loop() {
Serial.println("OFF");
digitalWrite(pinClock,0);
delay(5000);
Serial.println("ON we clock in the D data ");
digitalWrite(pinClock,1);
delay(5000);
Serial.println();
}

