//This sketch is to test a transistor as an inverter. When the base is HIGH (pin7) then output put is low
// and vice versa. The setup uses a NPN (2N222)  transistor. base is input. there is a 33K resistor at base.
// collector is connected to 5V with resistor of 1K. emitter is connected to Gnd. 
// collector is the output connected to LED and 320 ohms resistor.  
// we also read the tension at pin A0. The pin A0 is  placed at the emitter to read the voltage.
// pin A0 reads the output. 
// When the transistor is off (input off) Vce is HIGH . When the transistor is on (HIGH) the Vce is off. 

 

byte pin=7;
byte pinAnalog=A0;

void setup() {
pinMode(pin,OUTPUT);
pinMode(pinAnalog,INPUT);
Serial.begin(9600);

}

void loop() {

Serial.println("input is 0 or LOW" );
digitalWrite(pin,0);
Serial.println("voltage across Vce");
Serial.println(5.*float(analogRead(pinAnalog))/1023);
delay(5000);
Serial.println();
Serial.println(" input is 1 or HIGH " );
digitalWrite(pin,1);
Serial.println("voltage across Vce");
Serial.println(5.*float(analogRead(pinAnalog))/1023);
delay(5000);
Serial.println();
Serial.println();
}

