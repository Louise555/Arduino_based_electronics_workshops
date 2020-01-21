// reference: Arduuino workshop -  John Boxall 2013
//https://www.arduino.cc/en/tutorial/ShiftOut
// testing the shift register . Sending the number B10001101 Most sigificant bit displayed @ Q7.

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
int i=B10001101;
digitalWrite(LATCH, LOW);
shiftOut(DATA, CLOCK, MSBFIRST, i);
digitalWrite(LATCH, HIGH);
delay(5000);

}
