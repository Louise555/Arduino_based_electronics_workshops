// This is to demonstrate the truth table of a logic gate with 2 inputs and one output.
// example: NAND gate with 7400 or NOR 7402
// the inputs A and B are digital pins 7 and 8. The output is connected to a LED + resistor 330 ohms.
 

byte PinA=7;
byte PinB=8;

void setup() {
pinMode(PinA,OUTPUT);
pinMode(PinB,OUTPUT);
Serial.begin(9600);

}

void loop() {

Serial.println("A is 0 and B is 0");
Serial.println(" What is the output ?");
digitalWrite(PinA,0);
digitalWrite(PinB,0);
delay(5000);
Serial.println("A is 0 and B is 1");
Serial.println(" What is the output ?");
digitalWrite(PinA,0);
digitalWrite(PinB,1);
delay(5000);
Serial.println("A is 1 and B is 0");
Serial.println(" What is the output ?");
digitalWrite(PinA,1);
digitalWrite(PinB,0);
delay(5000);
Serial.println("A is 1 and B is 1");
Serial.println(" What is the output ?");
digitalWrite(PinA,1);
digitalWrite(PinB,1);
delay(5000);
Serial.println("done");
while(1) {}
}
