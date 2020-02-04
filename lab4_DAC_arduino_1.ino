/*
  DAC: Single byte
  source: A. J. Misquitta
  https://app.ph.qmul.ac.uk/wiki/ajm:teaching:arduino-pi:projects:arduino:dac-audio:dac
  Building a DAC with an arduino using a R-2R circuit. We use digital pins 0 to 7
  pin 0 is for the least significant bit and bit 7 the most significant bit.
  So if you have the binary number 00100011 the decimal number is 35 
  35/255 * 5V = 0.68V so a voltmeter should read 0.68V at the output. 
  To measure the voltage the Gnd (COM) of the voltmeter should be plugged into the Gnd of the set up (common Gnd)
  Try if this work.The voltmeter measures the voltage beween the Vout and the Gnd.
*/ 
 
void setup(){
  //set digital pins 0-7 as outputs
  for (int i=0; i<8; i++){
    pinMode(i,OUTPUT);
  }
}
 
void loop(){
  digitalWrite(0, HIGH); // 1 : we start from the rightmost bit
  digitalWrite(1, HIGH);  // 1
  digitalWrite(2, LOW);  // 0
  digitalWrite(3, LOW);  // 0
  digitalWrite(4, LOW); // 0
  digitalWrite(5, HIGH); // 1
  digitalWrite(6, LOW);  // 0
  digitalWrite(7, LOW); // 0
}
