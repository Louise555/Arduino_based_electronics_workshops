/*
 * reference: AVR programming - Elliot Wiiliams. 
 * code was modified to play the scale up. 
 */

#include <util/delay.h>
#include "organ.h"
#include "scale16.h"


#define NOTE_DURATION  0xF000   


  uint8_t i;
  
#define SPEAKER                 PD6                            /* OC0A */
#define SPEAKER_PORT            PORTD
#define SPEAKER_PIN             PIND
#define SPEAKER_DDR             DDRD

void playNote(uint16_t period, uint16_t duration) {
  uint16_t elapsed;
  uint16_t i;
  for (elapsed = 0; elapsed < duration; elapsed += period) {
                     /* For loop with variable delay selects the pitch */
    for (i = 0; i < period; i++) {
      _delay_us(1);
    }
    SPEAKER_PORT ^= (1 << SPEAKER);
  }
}

void rest(uint16_t duration) {
  do {
    _delay_us(1);
  } while (--duration);
}


                       /* used to store serial input */
  uint16_t currentNoteLength = NOTE_DURATION / 2;

  const uint16_t notes[] = { G4, Gx4, A4, Ax4, B4, C5, Cx5,
    D5, Dx5, E5, F5, Fx5, G5, Gx5,
    A5, Ax5, B5, C6
  };



int main(void) {
    SPEAKER_DDR |= (1 << SPEAKER);                 /* speaker for output */
 
  // put your main code here, to run repeatedly:
  while(1) {
  
    for (i = 0; i < 18; i++) {

        playNote(notes[i], currentNoteLength);
        _delay_ms(1000);
    }
  }

   return(0);

}
