//////////////////////////////////////////////////////////////////
//©2011 bildr
//Released under the MIT License - Please reuse change and share
//Simple code to output a PWM sine wave signal on pin 9
//////////////////////////////////////////////////////////////////

#define fadePin 3

void setup(){
  Serial.begin(9600);
  pinMode(fadePin, OUTPUT);  
  
}

void loop(){
  Serial.println(DEG_TO_RAD);
  for(int i = 0; i<360; i++){
    //convert 0-360 angle to radian (needed for sin function)
    float rad = DEG_TO_RAD * i;

    //calculate sin of angle as number between 0 and 255
    int sinOut = constrain((sin(rad) * 100) + 100, 0, 255); 

    analogWrite(fadePin, sinOut);

    delay(15);
  }


}
