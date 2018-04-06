#define PIEZO_PIN 3

float sinVal;
int toneVal;
void setup() {
//  pinMode(PIEZO_PIN, OUTPUT);
}



void play_alarm(int lowFreq, int highFreq, int wait) {
  for (int x=0; x<180; x++) {
    // convert degrees to radians then obtain sin value (from 0 to 1 back to 0)
    sinVal = (sin(x*(3.1412/180)));
    // generate a frequency from the sin value
    toneVal = lowFreq+(int(sinVal*(highFreq-lowFreq)));
    tone(PIEZO_PIN, toneVal);
    delay(wait);
  }
}

void loop() {
  play_alarm(2000, 3000, 2);
  delay(100);
}
