/*
 * How to save data in the flassh variable.
 * reference: Elliot Williams - AVR programming. 
 */


#include <avr/pgmspace.h>

const uint16_t myValue PROGMEM = 1023;// saving 1023 in myValue in the flash memory . It is a 2 bytes value
const char myChar PROGMEM = 'c'; //  one byte value. 
  uint16_t x;
  char c;
  
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   x=pgm_read_word(&myValue); // We need to give the address of the value saved in the flash memory. We use the command pgm_read_word() from AVR to read 2 bytes. 
  Serial.print(" int  from flash "); // printing out the variable x  = 2 bytes
  Serial.println(x);
  c=pgm_read_byte(&myChar); // getting back a byte = character by giving its address.
  Serial.print("character from flash "); // printing out one the character 
  Serial.println(c);
  Serial.println();
  delay(1000);
}
