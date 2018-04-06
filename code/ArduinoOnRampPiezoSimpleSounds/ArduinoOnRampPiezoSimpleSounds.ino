#include "pitches.h"

#define PIEZO_PIN 3
#define numTones  (sizeof(tones)/sizeof(int))

int tones[] = { NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4 };

void setup() {
  for (int i = 0; i < numTones; i++) {
    tone(PIEZO_PIN, tones[i]);
    delay(500);
  }
  noTone(PIEZO_PIN);
}

void loop() {
}
