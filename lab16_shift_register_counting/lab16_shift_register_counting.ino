// references: https://learn.sparkfun.com/tutorials/shift-registers
// Arduino workshop by Hohn boxall 2013
// 
#define DATA 6 // digital 6 to pin 14 on the 74HC595 - to send a binary number from arduino to shift register.
#define LATCH 8 // digital 8 to pin 12 on the 74HC595 - to latch the data
#define CLOCK 10 // digital 10 to pin 11 on the 74HC595 - connected to the clock of the arduino. 
void setup()
{
pinMode(LATCH, OUTPUT);
pinMode(CLOCK, OUTPUT);
pinMode(DATA, OUTPUT);
}
void loop()
{
int i;
for (i=0;i<255;i++) {
digitalWrite(LATCH, LOW);
shiftOut(DATA, CLOCK, MSBFIRST, i); // we are going to count to 256 with the LED
digitalWrite(LATCH, HIGH);
delay(1000);
}
while(1) {}
}
