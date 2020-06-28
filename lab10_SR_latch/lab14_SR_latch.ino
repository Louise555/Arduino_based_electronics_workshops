// This program is to demonstrate a SR latch . Q' means NOT Q (the inverse)
// I used an IC 7402 NOR gates - ( I used the 2 gates NOR at [pins 11(connecteded to 6 of IC), 12(R) 13(Q)] of IC and at pins [4(Q'),5(S),6 (connected to 11)] of IC 
// See schematic to build a SR latch with NOR gates. we connect the output Q and Q' to 2 LED with 320 ohms resistors.
// On arduino diigial pin 7 is for S and digital pin 8 is for R. 
// The pins  will go (S, R) = (0,1)  then (Q,Q')=(0,1)
// then (S, R) = (1,0) then (Q,Q')=(1,0)
// then (S, R) = (1,1) then states does not change. 
 

byte PinS=7;
byte PinR=8;

void setup() {
pinMode(PinS,OUTPUT);
pinMode(PinR,OUTPUT);
Serial.begin(9600);

}

void loop() {

Serial.println(" S and R are 0 and 1" );
Serial.println(" 'Q  should lit and Q should be off");
digitalWrite(PinS,0);
digitalWrite(PinR,1);
delay(5000);
Serial.println();
Serial.println(" S and R are 1 and 0" );
Serial.println(" Q  should lit and Q' should be off");
digitalWrite(PinS,1);
digitalWrite(PinR,0);
delay(5000);
Serial.println();
Serial.println(" S and R are 0 and 0" );
Serial.println(" Q and Q' can not change. They are latched. ");
digitalWrite(PinS,0);
digitalWrite(PinR,0);
Serial.println();
Serial.println("done");
while(1){};
}
