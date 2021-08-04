#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    25
#define BRIGHTNESS  205

#define LED_PIN2     8
#define NUM_LEDS2    28
#define BRIGHTNESS2  255

CRGB leds[NUM_LEDS];
CRGB leds2[NUM_LEDS2];

/*const int pResistor1 = A0;
const int pResistor2 = A1;
const int pResistor3 = A2;
const int pResistor4 = A3;

int value1;
int value2;
int value3;
int value4;*/


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
  FastLED.setBrightness(BRIGHTNESS );

  // para los leds difusos es RGB
  FastLED.addLeds<WS2811, LED_PIN, RGB>(leds, NUM_LEDS);
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

  
  /*pinMode(pResistor1, INPUT);// Set pResistor - A0 pin as an input (optional)
  pinMode(pResistor2, INPUT);// Set pResistor - A0 pin as an input (optional)
  pinMode(pResistor3, INPUT);// Set pResistor - A0 pin as an input (optional)
  pinMode(pResistor4, INPUT);// Set pResistor - A0 pin as an input (optional)*/
/*
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
  Serial.println("MPR121 found!");*/
  
}

void loop() {
  /*value1 = analogRead(pResistor1);
  value2 = analogRead(pResistor2);
  value3 = analogRead(pResistor3);
  value4 = analogRead(pResistor4);

  Serial.println(value1);
Serial.println(value2);
Serial.println(value3);
Serial.println(value4);*/

  

 /*// Get the currently touched pads
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
        if(currtouched & _BV(6) || currtouched & _BV(7)){
  leds[0] = CRGB(120, 25, 255);
  FastLED.show();
  delay(100);
  leds[1] = CRGB(100, 25, 255);
  FastLED.show();
  delay(100);
  leds[2] = CRGB(60, 25, 255);
  FastLED.show();
  delay(100);
  leds[3] = CRGB(10, 105, 255);
  FastLED.show();
  delay(100);
  leds[4] = CRGB(150, 25, 255);
  FastLED.show();
  delay(100);
  leds[5] = CRGB(10, 120, 255);
  FastLED.show();
  delay(100);
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
  if(currtouched & _BV(6) && currtouched & _BV(7)){
  leds[0] = CRGB(120, 25, 255);
  FastLED.show();
  leds[1] = CRGB(100, 25, 255);
  FastLED.show();
  leds[2] = CRGB(60, 25, 255);
  FastLED.show();
  leds[3] = CRGB(10, 105, 255);
  FastLED.show();
  leds[4] = CRGB(150, 25, 255);
  FastLED.show();
  leds[5] = CRGB(10, 120, 255);
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
  }*/
  /*if(currtouched & _BV(7)){
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

  // comment out this line for detailed data from the sensor!
  return;
  
  // debugging info, what
  Serial.print("\t\t\t\t\t\t\t\t\t\t\t\t\t 0x"); Serial.println(cap.touched(), HEX);
  Serial.print("Filt: ");
  for (uint8_t i=0; i<12; i++) {
    Serial.print(cap.filteredData(i)); Serial.print("\t");
  }
  Serial.println();
  Serial.print("Base: ");
  for (uint8_t i=0; i<12; i++) {
    Serial.print(cap.baselineData(i)); Serial.print("\t");
    
  }
  Serial.println();
  
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
  /*leds[6] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);
  leds[7] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);
  leds[8] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);
  leds[9] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);
  leds[10] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);
  leds[11] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);
  leds[12] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);
  leds[13] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);
  leds[14] = CRGB(190, 205, 20);
  FastLED.show();
  delay(500);
  leds[15] = CRGB(220, 205, 20);
  FastLED.show();
  delay(500);
  leds[16] = CRGB(250, 255, 20);
  FastLED.show();
  delay(500);
  leds[17] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);
  leds[18] = CRGB(50, 205, 180);
  FastLED.show();
  delay(500);
  leds[19] = CRGB(150, 205, 20);
  FastLED.show();
  delay(500);
  

  
  leds[20] = CRGB(250, 205, 20);
  FastLED.show();
  delay(500);
  leds[21] = CRGB(150, 255, 120);
  FastLED.show();
  delay(500);
  leds[22] = CRGB(180, 125, 80);
  FastLED.show();
  delay(500);
  leds[23] = CRGB(220, 200, 20);
  FastLED.show();
  delay(500);
  leds[24] = CRGB(40, 40, 250);
  FastLED.show();
  delay(500);
 
 /*for (int i = 0; i <= 6; i++) {
    FastLED.setBrightness(150);
    leds[i] = CRGB ( 255, 100, 20);
    FastLED.show();
    delay(80);
  }
  delay(500);
  for (int i = 6; i >= 0; i--) {
    leds[i] = CRGB ( 0, 150, 255);
    FastLED.show();
    delay(80);
  }
  delay(500);*/
  }
