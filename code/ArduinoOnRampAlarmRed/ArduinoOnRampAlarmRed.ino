#include <NewPing.h>
#include <NewTone.h>
// include SPI, MP3, Servo and SD libraries
#include <SPI.h>             // We will use the hardware SPI pins: CLK (13), MISO (12), MOSI (11)
#include "Adafruit_VS1053.h"
#include <SD.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>

#endif

// Select which PWM-capable pins are to be used.
#define NEOPIXEL_PIN 8 // Control pin for neopixel strip
int PIXEL_COUNT = 22; // set the number of neopixels on the strip

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

#define TRIGGER_PIN  6  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     7  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters).

// Rough time before alarm goes silent and re-arms.
// The alarm takes about 7 seconds between time checks, so times less than 7 seconds here
// are sub-optimal.
#define ALARM_REARM_TIME 25L


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
boolean triggered = false;


#define PIEZO_PIN 3 // Arduino pin tied to piezo buzzer

#define ALARM_POPPED_LED_PIN 13  // Pin 13 has an on-board LED on newer Arduino boards. We will
// light it if the alarm went off and the Arduino was not reset. You could hang a big phatt red LED
// off pin 13 and bring it to the outside of the box if you wanted to.

float sinVal;
int toneVal;
long MillisAtTriggered=-1;

// Setup -- run once

void setup(){

   strip.begin();
   strip.show(); //Initialize strip to all off

   pinMode(PIEZO_PIN, OUTPUT);

   pinMode(ALARM_POPPED_LED_PIN, OUTPUT);
   digitalWrite(ALARM_POPPED_LED_PIN, LOW);


  delay(5000);
Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.


}



void loop(){

    long secsSinceTriggered;

    if(triggered == true){
      secsSinceTriggered=(millis() - MillisAtTriggered) / 1000;
      digitalWrite(ALARM_POPPED_LED_PIN, HIGH);

      if(secsSinceTriggered >= ALARM_REARM_TIME) {
        triggered = false;
        alert_off();
      } else {
        alert();

      }
    }
    else{
      delay(50);// Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
      unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
      unsigned int distance = uS / US_ROUNDTRIP_CM;
      Serial.println(distance);
      if(distance >0 &&  distance < 10){
         triggered = true;
         MillisAtTriggered=millis();
      }
   }
}

void alert_off(){
  colorWipe(strip.Color(0,0,0),50); //Turn strip off
  noNewTone(PIEZO_PIN);
}

void alert(){

   play_alarm(2000, 3000, 2);

   colorWipe(strip.Color(255, 0, 0), 50); //red

   colorWipe(strip.Color(0, 0, 0), 50); //off

   colorWipeBack(strip.Color(255, 0, 0), 50); //redBack

   colorWipeBack(strip.Color(0,0,0), 50);// offBack


  }


void play_alarm(int lowFreq, int highFreq, int wait) {
  for (int x=0; x<180; x++) {
    // convert degrees to radians then obtain sin value (from 0 to 1 back to 0)
    sinVal = (sin(x*(3.1412/180)));
    // generate a frequency from the sin value
    toneVal = lowFreq+(int(sinVal*(highFreq-lowFreq)));
    NewTone(PIEZO_PIN, toneVal);
    delay(wait);
  }
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

// Fill the dots one after the other with a color
void colorWipeBack(uint32_t c, uint8_t wait) {
  for(uint16_t i=(PIXEL_COUNT - 1); i>0; i--) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
