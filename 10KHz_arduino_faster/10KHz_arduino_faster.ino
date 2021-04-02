// sketch_04_05_square
// trying to find the frequency with oscilloscope
// with the first version we get : 
//we get a frequency of 100KHz or 0.1 MHz. the period is 10us. 
// now we get a frequency of 114KHz and period of 8.7us. 
// we removed the loop() because inside they check for serial communication and we replaced int by byte.
// the sketches uses 448 bytes of storage. and variables use 1 byte. 
//// instead of before uses 772 bytes of program space and 11 bytes for variables.



const byte outPin = 8;
byte state = 0;

int main(void) {

  pinMode(outPin, OUTPUT);


 while(1) {
  digitalWrite(outPin, state);
  delayMicroseconds(40);
  state = ! state;
 }

  return(0);

}
