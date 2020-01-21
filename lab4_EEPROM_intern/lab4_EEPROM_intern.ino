// this sketch is to write numbers in the built-in EEPROM memory
#include <EEPROM.h>
int values[10] = {10,20,30,40,50,60,70,80,90,100};
int val;
void setup() {
Serial.begin(9600);

}

void loop()
{
Serial.println("writing a series of numbers 10 to 100 in memory ");
Serial.print("at positions 0 to 9");
// positions are 0 to 9
for (int i = 0; i < 10; i++)
{
EEPROM.write(i,values[i]);
}
Serial.println();
Serial.println();
Serial.println(" Now reading the numbers saved at the positions 0 to 9");
for (int i = 0; i < 10; i++)
{ 
val=EEPROM.read(i);
Serial.print("at EEPROM position ");
Serial.print(i);
Serial.print(" ,I read ");
Serial.println(val);
}
while(1) {}
}
