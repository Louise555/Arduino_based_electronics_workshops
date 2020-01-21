/*
V. Lankar Phys Dept MC

This simple code read the voltage at pin A0. If there is nothing connected to it
it will read static electricity (so random voltages usually less than 3V).
The reading is a digital number between 0 and 1023. To get the voltage you need
to contrain the value between 0 and 5V. But not done here. 
on the monitor we write index (i) and the value at A0 as strings.
Those value can be caught by a Python program for processing and graphing.
Note that the baudrate is larger
*/
int j=0;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(String(j)+";"+String(sensorValue));
  j++;
  Serial.flush();
  delay(250);        // delay in between reads for stability
}
