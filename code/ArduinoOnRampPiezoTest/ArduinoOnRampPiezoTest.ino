#define PIEZO_PIN 2
 
float sinVal;
int toneVal;
void setup() {
  pinMode(PIEZO_PIN, OUTPUT);
}
 
void loop() {
  for (int x=0; x<180; x++) {
    // convert degrees to radians then obtain sin value
    sinVal = (sin(x*(3.1412/180)));
    // generate a frequency from the sin value
    toneVal = 2000+(int(sinVal*1000));
    tone(PIEZO_PIN, toneVal);
  }
       
delay(100); }
