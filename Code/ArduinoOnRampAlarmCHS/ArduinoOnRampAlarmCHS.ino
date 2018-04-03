/*
 * From ArduinoOnRampRed2.ino originally by Maureen Haley
 * This version times out the alarm and re-arms after 10 seconds.
 */
// #define DEBUG_CHS
// Define this macro if you have a range potentiometer on pin 4
// Hook the ends of the pot up to +5V and ground, and the dial or slider to pin A4.
// #define RANGE_POT

#include <NewPing.h>
#include <NewTone.h>
// include SPI, MP3, Servo and SD libraries
#include <SPI.h>             // We will use the hardware SPI pins: CLK (13), MISO (12), MOSI (11)
// #include "Adafruit_VS1053.h"
#include <SD.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
  
#endif
 
// Select which PWM-capable pins are to be used.
#define NEOPIXEL_PIN 8  // Control pin for neopixel strip
#define TRIGGER_PIN  6  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     7  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define ALARM_PIN 3     // Pin tied to piezo alarm
#define ALARM_POPPED_LED_PIN 13  // Pin 13 has an on-board LED on newer Arduino boards. We will
// light it if the alarm went off and the Arduino was not reset. You could hang a big phatt red LED
// off pin 13 and bring it to the outside of the box if you wanted to.

#ifdef RANGE_POT
#define RANGE_POT_PIN 4  // Pin for range potentiometer
#endif

// Maximum reading from range pot pin
// For a 10K slider pot, this is what I found experimentally.  YMMV. 
#define RANGE_POT_MAX 670   




int Pixels = 22;  // Number of pixels on LED strip -- int for calculations later

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

Adafruit_NeoPixel strip = Adafruit_NeoPixel(Pixels, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);
 
// Maximum distance we want to ping for (in centimeters).
#define MAX_DISTANCE 200

// Rough time before alarm goes silent and re-arms.
// The alarm takes about 7 seconds between time checks, so times less than 7 seconds here
// are sub-optimal.
#define ALARM_REARM_TIME 25L 

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
boolean triggered = false;
 
 

float sinVal;
int toneVal;
long MillisAtTriggered=-1;



// Setup -- run once
void setup(){
   
   strip.begin();
   strip.show(); //Initialize strip to all off

   pinMode(ALARM_POPPED_LED_PIN,OUTPUT);
   digitalWrite(ALARM_POPPED_LED_PIN,LOW);   
   pinMode(ALARM_PIN, OUTPUT);
#ifdef RANGE_POT   
   pinMode(RANGE_POT_PIN,INPUT);
#endif 
  delay(5000);
Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.  
 
 
}

 // Loop -- run always.
void loop()
{
    
    long secsSinceTriggered;
#ifdef RANGE_POT    
    int potValue;
#endif    
    int range;
    
    if(triggered == true) {
      digitalWrite(ALARM_POPPED_LED_PIN,HIGH);
      secsSinceTriggered=(millis() - MillisAtTriggered) / 1000;
#ifdef DEBUG_CHS      
      Serial.print("secsSinceTriggered: ");
      Serial.print(secsSinceTriggered);
      Serial.print(" millisAtTriggered: ");
      Serial.println(MillisAtTriggered);
#endif
      if(secsSinceTriggered >= ALARM_REARM_TIME) {
         triggered = false;
	 alert_off();	 
      }
      else
         alert();
    }    
    else {
      delay(50);// Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
      unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
      unsigned int distance = uS / US_ROUNDTRIP_CM;
#ifdef RANGE_POT      
      potValue=analogRead(RANGE_POT_PIN);
      range=map(potValue,0,RANGE_POT_MAX,1,MAX_DISTANCE);
#else
      range=10;
#endif


#ifdef DEBUG_CHS
      Serial.print("Distance: " );
      Serial.print(distance);
#ifdef RANGE_POT      
      Serial.print(" potValue: ");
      Serial.print(potValue);
#endif      
      Serial.print(" range: ");
      Serial.println(range);
#endif
      
      if( (distance) && (distance < range)) {
         triggered = true;
	 MillisAtTriggered=millis();
      }
   }
}

void alert_off() {
   colorWipe(strip.Color(0,0,0),50); // Turn strip off
   noNewTone(ALARM_PIN);
}

void alert(){
   colorWipe(strip.Color(255, 0, 0), 50); //red
   
   colorWipe(strip.Color(0, 0, 0), 50); //off
   colorWipeBack(strip.Color(255, 0, 0), 50); //redBack
   play_alarm();
   colorWipeBack(strip.Color(0,0,0), 50);// offBack
   colorWipe(strip.Color(0,0,255),50);  // Blue
   colorWipeBack(strip.Color(0,0,0),50); //off
   colorWipeBack(strip.Color(0,0,255),50); // blueBack
   
 }

void play_alarm(void) {
  for (int x=0; x<180; x++) {
    // convert degrees to radians then obtain sin value
    sinVal = (sin(x*(3.1412/180)));
    // generate a frequency from the sin value
    toneVal = 2000+(int(sinVal*1000));
    NewTone(ALARM_PIN, toneVal);
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
  for(uint16_t i=(Pixels - 1); i>0; i--) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

