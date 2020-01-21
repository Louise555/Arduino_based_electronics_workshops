// idea from the book " Arduino workshop" by John Boxall - 2013
// to see how arduino use the PWM mode to convert a digital number to an analog number.
byte PIEZO=3 ;// pin 3 is capable of PWM output to drive tones
int del = 1000;
void setup()
{
pinMode(PIEZO, OUTPUT);
}
void loop()
{
 // The number has to be between 0 and 255. 0 is 0V and 255 is 5V. Larger the voltage, louder the sound.

 analogWrite(PIEZO, 50); // 5 means (5/255) x5  volt or 2% dutycyle

}
