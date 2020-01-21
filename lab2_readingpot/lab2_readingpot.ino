/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0
 http://www.arduino.cc/en/Tutorial/AnalogInput
 We use a 10K pot and we read the voltage at the middle leg. 

 */

byte sensorPin = A0;    // select the input pin for the potentiometer
unsigned int sensorValue = 0;  // variable to store the value coming from the pot 

void setup() {
  // initialize serial communication at 9600 bits per second:
 Serial.begin(9600);
  // declare the A0 as an input. Althouth it is not necessary. Since A0 is only for input. 
  pinMode(sensorPin,INPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // converting to voltage
  Serial.println(5.*sensorValue/1023.);
  delay(1000);

}
