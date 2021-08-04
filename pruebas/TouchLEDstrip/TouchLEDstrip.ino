//Capacitive sensor and LED strip
//Libraries
#include <FastLED.h>

//Initialize Strips
#define LED_PIN     6
#define NUM_LEDS    25
#define BRIGHTNESS  255

#define LED_PIN2     8
#define NUM_LEDS2    29
#define BRIGHTNESS2  255


#define UPDATES_PER_SECOND 100

CRGB fuzzy[NUM_LEDS];
CRGB strip[NUM_LEDS2];

//Capacitive sensor initialization
#include <Wire.h>
#include "Adafruit_MPR121.h"

#ifndef _BV
#define _BV(bit) (1 << (bit)) 
#endif

// You can have up to 4 on one i2c bus but one is enough for testing!
Adafruit_MPR121 cap = Adafruit_MPR121();

// Keeps track of the last pins touched
// so we know when buttons are 'released'
uint8_t br[2];// brightness 
uint16_t lasttouched = 0;
uint16_t currtouched = 0;

void setup() {
  Serial.begin(9600);
  // GRB color code for strip
  LEDS.addLeds<WS2812, LED_PIN2, RGB>(strip, NUM_LEDS2);
  // RGB color code for fuzzy leds
  LEDS.addLeds<WS2811, LED_PIN, RGB>(fuzzy, NUM_LEDS);

//To give different values of brightness for both strips
br[0]= 250;
br[1]= 50;
  
LEDS.show();

   while (!Serial) { // needed to keep leonardo/micro from starting too fast!
    delay(10);
  }
  
  Serial.println("Adafruit MPR121 Capacitive Touch sensor test"); 
  
  // Default address is 0x5A, if tied to 3.3V its 0x5B
  // If tied to SDA its 0x5C and if SCL then 0x5D
  if (!cap.begin(0x5A)) {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 found!");
  
}

void loop() {

  //Brightness initialization
  LEDS[0].setCorrection(CRGB(br[0],br[0],br[0]));
  LEDS[1].setCorrection(CRGB(br[1],br[1],br[1]));

 // Get the currently touched pads
  currtouched = cap.touched();
  
  for (uint8_t i=0; i<12; i++) {
    // it if *is* touched and *wasnt* touched before, alert!
    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)) ) {
      Serial.print(i); Serial.println(" released");
    }
  }

  //Commands for every sensor when is touched
  if(currtouched & _BV(5)){
    Serial.println("uno");
    fuzzy[0] = CRGB ::Goldenrod;
    FastLED.show();
    fuzzy[1] = CRGB::Goldenrod;
    FastLED.show();
    fuzzy[2] = CRGB::Goldenrod;
    FastLED.show();
    fuzzy[3] = CRGB::Goldenrod;
    FastLED.show();
    fuzzy[4] = CRGB( 190,170,20);
    FastLED.show();
  } 
  
  if(currtouched & _BV(2)){
    Serial.println("dos");
    fuzzy[5] = CRGB::Goldenrod;
    FastLED.show();
     fuzzy[6] = CRGB( 190,170,20);
    FastLED.show();
    fuzzy[7] = CRGB( 140,150,10);
    FastLED.show();
    fuzzy[8] = CRGB::Goldenrod;
    FastLED.show();
    fuzzy[9] = CRGB( 140,150,10);
    FastLED.show();
  } 
  
  if(currtouched & _BV(3)){
    Serial.println("tres");
    fuzzy[10] = CRGB::Goldenrod;
    FastLED.show();
    fuzzy[11] = CRGB( 140,150,10);
    FastLED.show();
    fuzzy[12] = CRGB( 190,170,20);
    FastLED.show();
    fuzzy[13] = CRGB::Goldenrod;
    FastLED.show();
    fuzzy[14] = CRGB( 190,170,20);
    FastLED.show();
  } 
  
  if(currtouched & _BV(4)){
    Serial.println("cuatro");
      fuzzy[15] = CRGB( 190,170,20);
    FastLED.show();
    fuzzy[16] = CRGB( 190,170,20);
    FastLED.show();
    fuzzy[17] = CRGB::Goldenrod;
    FastLED.show();
     fuzzy[18] = CRGB( 190,170,20);
    FastLED.show();
    fuzzy[19] = CRGB::Goldenrod;
  
   //Cinta
    strip[0] = CRGB(160,20,150);
    FastLED.show();
    strip[1] = CRGB( 150, 10, 40);
    FastLED.show();
    strip[2] = CRGB(40,50,180);
    FastLED.show();
    strip[3] = CRGB(160,20,150);
    FastLED.show();
    strip[4] = CRGB( 150, 10, 40);
    FastLED.show();
    strip[5] = CRGB(160,10,150);
    FastLED.show();
     strip[6] = CRGB( 150, 10, 40);
    FastLED.show();
    strip[7] = CRGB(160,10,150);
    FastLED.show();
    strip[8] = CRGB(40,50,180);
    FastLED.show();
    strip[9] = CRGB( 60, 40, 200);
    FastLED.show();
    strip[10] = CRGB( 150, 10, 40);
    FastLED.show();
  } 
  if(currtouched & _BV(1)){
    Serial.println("cinco");

    fuzzy[20] = CRGB( 190,170,20);
    FastLED.show();
    fuzzy[21] = CRGB::Goldenrod;
    FastLED.show();
    fuzzy[22] = CRGB::Goldenrod;
    FastLED.show();
    fuzzy[23] = CRGB( 190,170,20);
    FastLED.show();
    fuzzy[24] = CRGB::Goldenrod;
    FastLED.show();

  
   //Cinta
    strip[18] = CRGB(40,50,180);
    FastLED.show();
    strip[19] = CRGB( 60, 50, 200);
    FastLED.show();
    strip[20] = CRGB( 150, 10, 40);
    FastLED.show();
    strip[11] = CRGB( 60, 40, 200);
    FastLED.show();
    strip[12] = CRGB(160,20,150);
    FastLED.show();
    strip[13] = CRGB(160,20,150);
    FastLED.show();
    strip[14] = CRGB( 150, 100, 40);
    FastLED.show();
    strip[15] = CRGB(160,20,150);
    FastLED.show();
    strip[16] = CRGB( 60, 40, 200);
    FastLED.show();
    strip[17] = CRGB( 150, 10, 40);
    FastLED.show();
  
    //colibri
    strip[27] = CRGB( 180,20,120);
    FastLED.show();
    strip[26] = CRGB( 130,20,170);
    FastLED.show();
    strip[25] = CRGB(40,60,180);
    FastLED.show();
    strip[28] = CRGB(130,20,170);
    FastLED.show();
    strip[29] = CRGB( 180,20,120);
    FastLED.show();
    
  } 
  
  if(currtouched & _BV(0)){
    FastLED.clear();  // clear all pixel data
    FastLED.show();

  }

  }
