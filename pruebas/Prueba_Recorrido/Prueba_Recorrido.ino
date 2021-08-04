//Touch and LEDs strip

//Libraries
#include <FastLED.h>

//initialization of strips
#define LED_PIN     8
#define NUM_LEDS    25
#define BRIGHTNESS  255

#define LED_PIN2     6
#define NUM_LEDS2    28
#define BRIGHTNESS2  255

CRGB leds[NUM_LEDS];
CRGB leds2[NUM_LEDS2];


#include <Wire.h>
#include "Adafruit_MPR121.h"

#ifndef _BV
#define _BV(bit) (1 << (bit)) 
#endif

// You can have up to 4 on one i2c bus but one is enough for testing!
Adafruit_MPR121 cap = Adafruit_MPR121();

// Keeps track of the last pins touched
// so we know when buttons are 'released'
uint16_t lasttouched = 0;
uint16_t currtouched = 0;

void setup() {
  Serial.begin(9600);
  // para la cinta led es GRB
  FastLED.addLeds<WS2812, LED_PIN2, GRB>(leds2, NUM_LEDS2);
  FastLED.setBrightness(BRIGHTNESS);

  // para los leds difusos es RGB
  FastLED.addLeds<WS2811, LED_PIN, RGB>(leds, NUM_LEDS);
  //initial state of leds
  leds[i] = CRGB::Black;
  FastLED.show();
  leds2[i] = CRGB::Black;
  FastLED.show();

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
  //Commands for every touchsensor
  if(currtouched & _BV(1)){
    Serial.println("uno");
  leds[0] = CRGB(0, 200, 255);
  FastLED.show();
  leds[1] = CRGB(0, 200, 255);
  FastLED.show();
  leds[2] = CRGB(0, 200, 255);
  FastLED.show();
  leds[3] = CRGB(0, 200, 255);
  FastLED.show();
  leds[4] = CRGB(0, 200, 255);
  FastLED.show();
  leds[5] = CRGB(0, 200, 255);
  FastLED.show();
  } 
  if(currtouched & _BV(2)){
    Serial.println("dos");
   leds[6] = CRGB(0, 200, 255);
  FastLED.show();
  leds[7] = CRGB(0, 200, 255);
  FastLED.show();
  leds[8] = CRGB(0, 200, 255);
  FastLED.show();
  leds[9] = CRGB(0, 200, 255);
  FastLED.show();
  leds[10] = CRGB(0, 200, 255);
  FastLED.show();
  leds[11] = CRGB(0, 200, 255);
  FastLED.show();
  } 
  if(currtouched & _BV(3)){
    Serial.println("tres");
   leds[12] = CRGB(0, 200, 255);
  FastLED.show();
  leds[13] = CRGB(0, 200, 255);
  FastLED.show();
  leds[14] = CRGB(0, 200, 255);
  FastLED.show();
  leds[15] = CRGB(0, 200, 255);
  FastLED.show();
  leds[16] = CRGB(0, 200, 255);
  FastLED.show();
  leds[17] = CRGB(0, 200, 255);
  FastLED.show();
  } 
  if(currtouched & _BV(4)){
    Serial.println("cuatro");
   leds[18] = CRGB(0, 200, 255);
  FastLED.show();
  leds[19] = CRGB(0, 200, 255);
  FastLED.show();
  leds[20] = CRGB(0, 200, 255);
  FastLED.show();
  leds[21] = CRGB::Goldenrod;
  FastLED.show();
  leds[22] = CRGB::Goldenrod;
  FastLED.show();
  leds[23] = CRGB::Goldenrod;
  FastLED.show();
   //Cinta
  leds2[0] = CRGB::Goldenrod;
  FastLED.show();
  leds2[1] = CRGB::Goldenrod;
  FastLED.show();
  leds2[2] = CRGB::Goldenrod;
  FastLED.show();
  leds2[3] = CRGB::Goldenrod;
  FastLED.show();
  leds2[4] = CRGB::Goldenrod;
  FastLED.show();
  leds2[5] = CRGB::Goldenrod;
  FastLED.show();
  } 
  if(currtouched & _BV(5)){
    Serial.println("cinco");
  leds[24] = CRGB::Goldenrod;
  FastLED.show();
  leds[25] = CRGB::Goldenrod;
  FastLED.show();
  leds[2] = CRGB::Goldenrod;
  FastLED.show();
  leds[3] = CRGB::Goldenrod;
  FastLED.show();
  leds[4] = CRGB::Goldenrod;
  FastLED.show();
  leds[5] = CRGB::Goldenrod;
  FastLED.show();
   //Cinta
  leds2[6] = CRGB::Goldenrod;
  FastLED.show();
  leds2[7] = CRGB::Goldenrod;
  FastLED.show();
  leds2[8] = CRGB::Goldenrod;
  FastLED.show();
  leds2[9] = CRGB::Goldenrod;
  FastLED.show();
  leds2[10] = CRGB::Goldenrod;
  FastLED.show();
  leds2[11] = CRGB::Goldenrod;
  FastLED.show();
  } 
  if(currtouched & _BV(0)){
  leds[0] = CRGB::Black;
  FastLED.show();
  leds[1] = CRGB::Black;
  FastLED.show();
  leds[2] = CRGB::Black;
  FastLED.show();
  leds[3] = CRGB::Black;
  FastLED.show();
  leds[4] = CRGB::Black;
  FastLED.show();
  leds[5] = CRGB::Black;
  FastLED.show();
  }
  
  if(currtouched & _BV(7)){
  leds[21] = CRGB(100, 25, 20);
  FastLED.show();
  delay(100);
  }
  
  if(currtouched & _BV(8)){
  leds[22] = CRGB(200, 250, 100);
  FastLED.show();
  delay(100);
  }
  if(currtouched & _BV(11)){
  leds[23] = CRGB(250, 55, 200);
  FastLED.show();
  delay(100);
  }
    if(currtouched & _BV(10)){
  leds[24] = CRGB(250, 255, 20);
  FastLED.show();
  delay(100);
  }
  
    if(currtouched & _BV(2)){
  leds[20] = CRGB::Black;
  FastLED.show();
  leds[21] = CRGB::Black;
  FastLED.show();
  leds[22] = CRGB::Black;
  FastLED.show();
  leds[23] = CRGB::Black;
  FastLED.show();
  leds[24] = CRGB::Black;
  FastLED.show();
    }
  }

  // reset our state
  lasttouched = currtouched;
  
  // put a delay so it isn't overwhelming
  delay(100);*/
   FastLED.setBrightness(100 );
  
  leds[3] = CRGB(255,255,255);
  FastLED.show();
  delay(200);  
  leds[4] = CRGB(255,255,255);
  FastLED.show();
  delay(200);
  leds[5] = CRGB(255,255,255);
  FastLED.show();
  delay(200);
  leds[6] = CRGB(220, 200, 20);
  FastLED.show();
  delay(200);
  leds[7] = CRGB::Goldenrod;
  FastLED.show();
  delay(200);
  leds[8] = CRGB(220, 200, 20);
  FastLED.show();
  delay(200);
  
  
  leds[9] = CRGB(220, 200, 20);
  FastLED.show();
  delay(200);  
  leds[10] = CRGB(220, 200, 20);
  FastLED.show();
  delay(200);
  leds[11] = CRGB(220, 200, 20);
  FastLED.show();
  delay(200);
  leds[12] = CRGB(220, 200, 20);
  FastLED.show();
  delay(200);
  leds[13] = CRGB::Goldenrod;
  FastLED.show();
  delay(200);
  leds[14] = CRGB(50, 255, 50);
  FastLED.show();
  delay(200);

   leds[15] = CRGB::Goldenrod;
  FastLED.show();
  delay(200);  
  leds[16] = CRGB::Goldenrod;
  FastLED.show();
  delay(200);
  leds[17] = CRGB(220, 200, 20);
  FastLED.show();
  delay(200);
  leds[18] = CRGB::Goldenrod;
  FastLED.show();
  delay(200);
  leds[19] = CRGB::Goldenrod;
  FastLED.show();
  delay(200);
  leds[20] = CRGB(220, 200, 20);
  FastLED.show();
  delay(200);

  
  leds[20] = CRGB(220, 200, 20);
  FastLED.show();
  delay(200);  
  leds[21] = CRGB::Goldenrod;
  FastLED.show();
  delay(200);
  leds[22] = CRGB(220, 200, 20);
  FastLED.show();
  delay(200);
  leds[23] = CRGB(220, 200, 20);
  FastLED.show();
  delay(500);
  leds[24] = CRGB::Goldenrod;
  FastLED.show();
  delay(200);
  leds[25] = CRGB::LimeGreen;
  FastLED.show();
  delay(200);

  leds2[20] = CRGB(0, 200, 255);
  FastLED.show();
  delay(200);  
  leds2[21] = CRGB(2, 20, 200);
  FastLED.show();
  delay(200);
  leds2[22] = CRGB(0, 200, 20);
  FastLED.show();
  delay(200);
  leds2[23] = CRGB(2, 200, 20);
  FastLED.show();
  delay(500);
  leds2[24] = CRGB(2, 20, 255);
  FastLED.show();
  delay(200);
  leds2[25] = CRGB(0, 200, 20);
  FastLED.show();
  delay(200);
  leds2[19] = CRGB(0, 20, 200);
  FastLED.show();
  delay(200);
  leds2[18] = CRGB(0, 20, 250);
  FastLED.show();
  delay(200);
  leds2[17] = CRGB(0, 20, 250);
  FastLED.show();
  delay(200);
  leds2[26] = CRGB(0, 20, 200);
  FastLED.show();
  delay(200);
  leds2[27] = CRGB(0, 20, 250);
  FastLED.show();
  delay(200);
  leds2[28] = CRGB(0, 100, 250);
  FastLED.show();
  delay(200);
 
  delay(500);
  }
