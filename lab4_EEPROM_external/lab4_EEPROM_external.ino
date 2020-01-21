// reference: http://www.hobbytronics.co.uk/arduino-external-eeprom
#include <Wire.h>    
 
#define disk1 0x50    //Address of 24LC256 eeprom chip this is a 7-bits number 1010000 or 0x50
 
void setup(void)
{
  Serial.begin(9600);
  Wire.begin();  
 
  unsigned int address = 0; // this is the position in the memory. It varies between 0 and 65,535
  int data=123; // this is the data to write at the position address
  Serial.println(" Writing data .. ");
  Serial.print(" at position  ");
  Serial.println(address);
  writeEEPROM(disk1, address, data);// calling the function that writes the data at the given position
  Serial.println(" reading data  ");
  Serial.print(readEEPROM(disk1, address), DEC);// calling the function that reads the data at given position
 
}
 
void loop(){}
 
void writeEEPROM(int deviceaddress, unsigned int eeaddress, byte data ) 
{
  Wire.beginTransmission(deviceaddress);
  // we need to send the position to the device but you can only send 1 byte at a time and the position is
  // a 2 bytes number a 16-bits number. So we send the position in 2 parts. First the MSB and then the LSB
  Wire.write((int)(eeaddress >> 8));   // MSB most significant byte 
  Wire.write((int)(eeaddress & 0xFF)); // LSB least sigificant byte 
  Wire.write(data);
  Wire.endTransmission();
 
  delay(5);
}
 // reading the data. We need to give the address of the device and the position in the memory. 
byte readEEPROM(int deviceaddress, unsigned int eeaddress ) 
{
  byte rdata = 0xFF;
 
  Wire.beginTransmission(deviceaddress);
  Wire.write((int)(eeaddress >> 8));   // MSB
  Wire.write((int)(eeaddress & 0xFF)); // LSB
  Wire.endTransmission();
 
  Wire.requestFrom(deviceaddress,1);// The second argument is how many bytes(starting at this address) to send back; we’re only requesting one
 
  rdata = Wire.read();
 
  return rdata;
}

