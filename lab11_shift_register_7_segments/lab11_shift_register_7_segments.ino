// displaying a digit between 0 and 9 with shift register and 7 segments LED module - common cathode. 
// Reference: arduino workshop by Hohn boxall p.121
// http://www.cs.uregina.ca/Links/class-info/207/Lab8/
//http://pdf1.alldatasheet.com/datasheet-pdf/view/228839/ETC2/FND500.html
// A is Q0  B is Q1   C is Q2   D is Q3    E is Q4  F is Q5   G is Q6    DP is Q7
#define DATA 6 // connect to pin 14 on the 74HC595
#define LATCH 8 // connect to pin 12 on the 74HC595
#define CLOCK 10 // connect to pin 11 on the 74HC595
// Below are the decimal forms of the binay numbers to be shifted in the memory register.
// 252 is B11111100 and is therefore the digit 1. the first bit is the decimal point. 
// the byts matches A, B, C, D, E, F, G, DP respectively. 
int digits[] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246, 238, 62, 156,
122, 158, 142};
void setup()
{
pinMode(LATCH, OUTPUT);
pinMode(CLOCK, OUTPUT);
pinMode(DATA, OUTPUT);
}
void loop()
{
int i;

for ( i = 0 ; i < 10 ; i++ ) // display digits 0-9, 
{
digitalWrite(LATCH, LOW);
shiftOut(DATA, CLOCK, LSBFIRST, digits[i]+1); // + 1 to turn the DP on. If you + 0 then DP is off
// B11111100 + 1 =B11111101
digitalWrite(LATCH, HIGH);
delay(2000);
}
}
