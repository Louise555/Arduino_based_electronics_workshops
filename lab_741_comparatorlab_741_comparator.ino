//This sketch is to test the op amp 741 as a comparator. 
// We connect mannualy V+ and V- to (5,0) or (0,0) or (3.3,5) or (5,0) if V+ > Vi we get a HIGH at output otherwise we get a one.
// We connect the output (HIGH or LOW) to pin 7 from arduino. 


 

byte pin=7;

void setup() {
pinMode(pin,INPUT);
Serial.begin(9600);

}

void loop() {

Serial.println("reading pin 7" );
Serial.println(digitalRead(pin));
delay(3000);
Serial.println();
Serial.println();
}

