#define PIEZO_PIN 2

int numTones = 10;
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
//            mid C  C#   D    D#   E    F    F#   G    G#   A

void setup()
{
  for (int i = 0; i < numTones; i++)
  {
    tone(PIEZO_PIN, tones[i]);
    delay(500);
  }
  noTone(PIEZO_PIN);
}

void loop()
{
}
