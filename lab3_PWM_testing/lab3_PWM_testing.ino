/* http://playground.arduino.cc/Code/PwmFrequency
 * from the arduino website - to change the frequency of the PWM pins
 * To set pin 3's PWM frequency to 3921 Hz (31372/8 = 3921) you write: setPwmFrequency(3, 8);
 Note that the base frequency for pins 3, 9, 10, and 11 is 31372 Hz
 For pin 3 you can  use the divisors: 1,8,32,64,128,256,1024
 so if the divisor is 1024 then the frequency is about 31372/1024=30Hz.
 Try different divisors. Here we use the divisor 1024 and we should get a frequency of 30Hz.

 */
byte PinPwm=3; // PWM pin number
void setup() {
  // initialize pwm pins are output
  pinMode(PinPwm, OUTPUT);
  setPwmFrequency(PinPwm,1024); // to get a frequency of about 30Hz
  // we use the timer 2 so you can not use the function tone() when you change the frequency.
}
void loop() {
  analogWrite(PinPwm,100);  // create a rectangular wave of frequency 30Hz and with a max of 2V
  // so the average value of the square wave is 2V. 
  }
  // the sketch below is from the website playground.arduino.cc 
  // the use the base frequency 31250 in their comments but it is actually 31372Hz to be precise.
  
  /**
 * Divides a given PWM pin frequency by a divisor.
 *
 * The resulting frequency is equal to the base frequency divided by
 * the given divisor:
 *   - Base frequencies:
 *      o The base frequency for pins 3, 9, 10, and 11 is 31250 Hz.
 *      o The base frequency for pins 5 and 6 is 62500 Hz.
 *   - Divisors:
 *      o The divisors available on pins 5, 6, 9 and 10 are: 1, 8, 64,
 *        256, and 1024.
 *      o The divisors available on pins 3 and 11 are: 1, 8, 32, 64,
 *        128, 256, and 1024.
 *
 * PWM frequencies are tied together in pairs of pins. If one in a
 * pair is changed, the other is also changed to match:
 *   - Pins 5 and 6 are paired on timer0
 *   - Pins 9 and 10 are paired on timer1
 *   - Pins 3 and 11 are paired on timer2
 *
 * Note that this function will have side effects on anything else
 * that uses timers:
 *   - Changes on pins 3, 5, 6, or 11 may cause the delay() and
 *     millis() functions to stop working. Other timing-related
 *     functions may also be affected.
 *   - Changes on pins 9 or 10 will cause the Servo library to function
 *     incorrectly.
 *
 * Thanks to macegr of the Arduino forums for his documentation of the
 * PWM frequency divisors. His post can be viewed at:
 *   http://forum.arduino.cc/index.php?topic=16612#msg121031
 */
void setPwmFrequency(int pin, int divisor) {
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x7; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}
