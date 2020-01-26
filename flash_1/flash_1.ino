
/*
  * reference: AVR programming by Elliot Williams.
  * So save an array of data (each component is 2 bytes =16 bits) in the flash memory.
  * In C size() returns the number of bytes. So if we have an array of int (16 bits) the size(array) = number of elements x 2
  * To find the number of elements -> size(array) / 2
  * Also. Consider the array myData[] The adress of the first element &myData[0] is the same thing as myData. myData is a pointer to the first element of the array. 
  * myData (the name of the array) is a pointer and contains the adress of the first element.
  * myData+1 is the address of the 2nd element (skipping 2 bytes). 
  */
#include <avr/pgmspace.h>

// by using the command  const .... .... PROGMEM we save the variable in the flash meomory 
const uint16_t myData[] PROGMEM =
    { 1111, 2222, 3333, 4444, 5555, 6666, 7777, 8888, 9999, 10000 };
const uint16_t myData2[] PROGMEM = { 123, 456, 789, 012, 345, 678, 999 };

void printData_Progmem(const uint16_t * dataPointer, uint8_t length) { // we are passing to the function a pointer = address of the first elemeent of the arrat. 
                                                                      // length is the number of elements in the array. 
    for (int j=0;j<length;j++) {
      uint16_t p = dataPointer; // adress of the element saved in p 
    Serial.print(p);            /* print out address */  // displaying the address contained in the pointer.  This is the adddress of the element of the array. 
    Serial.print(" ; ");
    Serial.println(pgm_read_word(dataPointer));           /* print out data */ // we are reading the variable in the flash memory at the given address
                                                            // and we are printint it out. 
    dataPointer++;                                /* move to next byte */ // moving on to the next element. 2 bytes later.
    delay(100); // delay 
    }
}

void setup() {
  Serial.begin(9600);
  

}

void loop() {
     printData_Progmem(myData, sizeof(myData) / 2); // calling the function to print out the array. The number of elements (length) of the array is the number of bytes 
                                                     // divided by 2. Because each element is 2 bytes. 
    Serial.println();
    delay(1000);
    printData_Progmem(myData2, sizeof(myData2) / sizeof(myData2[0])); // we can also get the number of elements by dividing the # of bytes used by the size of the first 
                                                                      // element which is also 2 bytes. 
    Serial.println();
    delay(1000);
    

}
