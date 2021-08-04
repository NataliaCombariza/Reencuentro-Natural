//LIBRARIES
#include <FastLED.h>
#include <Wire.h>
#include "Adafruit_MPR121.h"

//CONSTANTS

#define FUZZY_LED_PIN     6
#define FUZZY_NUM_LEDS    25

#define STRIP_LED_PIN     8
#define STRIP_NUM_LEDS    28

#define UPDATES_PER_SECOND 100

#ifndef _BV
#define _BV(bit) (1 << (bit)) 
#endif

//VARIABLES

//Inicialize palettes
CRGBPalette16 flowersPalette;
CRGBPalette16 wetlandPalette;
CRGBPalette16 colibriPalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;

//Inicialize lights
CRGB fuzzy[FUZZY_NUM_LEDS];
CRGB strip[STRIP_NUM_LEDS];

//Touch sensor
// You can have up to 4 on one i2c bus but one is enough for testing!
Adafruit_MPR121 cap = Adafruit_MPR121();

// Keeps track of the last pins touched
// so we know when buttons are 'released'

uint16_t lasttouched = 0;
uint16_t currtouched = 0;

boolean section4IsRunning = false;
boolean section5IsRunning = false;

boolean s1Active = true;

unsigned long startMillis;  //some global variables available anywhere in the program
unsigned long currentMillis;
const unsigned long period = 100000;

void setup() {
  Serial.begin(9600);
  // Strip works with GRB color code
  LEDS.addLeds<WS2812, STRIP_LED_PIN, RGB>(strip, STRIP_NUM_LEDS).setCorrection( TypicalLEDStrip );
  // Fuzzy works with RGB color code
  LEDS.addLeds<WS2811, FUZZY_LED_PIN, RGB>(fuzzy, FUZZY_NUM_LEDS);
  
  LEDS.show();

  // needed to keep leonardo/micro from starting too fast!
  while (!Serial) {
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
  
  flowersPalette = RainbowColors_p;
  wetlandPalette = RainbowColors_p;
  colibriPalette = RainbowColors_p;
  currentBlending = LINEARBLEND; //Color blend mode

  startMillis = millis();
}

void loop() {
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; // motion speed 

 // Get the currently touched pads
  currtouched = cap.touched();
  
  //Directions for the sensors
    
  if((currtouched & _BV(5)) && !(lasttouched & _BV(5))){ //"if sensor 5 is touched"
    if(s1Active) {
      Serial.println("uno"); //Position of sensor on the physical world
      SetupFlowersPalette(); //Color palette for light animation
      FillFlowersLEDsFromPaletteColors(startIndex,0,5);
      FastLED.show();
      FastLED.delay(1000 / UPDATES_PER_SECOND);
      s1Active = false;
    }
  } 
  
  if((currtouched & _BV(2)) && !(lasttouched & _BV(2))){
    Serial.println("dos"); //Position of sensor on the physical world
    SetupFlowersPalette();//Color palette for light animation
    FillFlowersLEDsFromPaletteColors(startIndex,5,10);
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
  } 
  
  if((currtouched & _BV(3))&& !(lasttouched & _BV(3))){
    Serial.println("tres");//Position of sensor on the physical world
    SetupFlowersPalette();//Color palette for light animation
    FillFlowersLEDsFromPaletteColors(startIndex,10,15);
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
  } 
  
  if((currtouched & _BV(4))&& !(lasttouched & _BV(4))){
    Serial.println("cuatro");//Position of sensor on the physical world
    section4IsRunning = true;
    SetupFlowersPalette();//Color palette for light animation
    FillFlowersLEDsFromPaletteColors(startIndex,15,20);
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
  } 

  if (section4IsRunning) {
    SetupWetlandPalette();//Color palette for light animation
    FillWetlandLEDsFromPaletteColors(startIndex,0,15);
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
  }
  
  if((currtouched & _BV(1))&& !(lasttouched & _BV(1))){
    Serial.println("cinco");//Position of sensor on the physical world
    section5IsRunning = true;
    SetupFlowersPalette();//Color palette for light animation
    FillFlowersLEDsFromPaletteColors(startIndex,20,25);
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
  } 

  if (section5IsRunning) {
    SetupWetlandPalette();//Color palette for light animation
    SetupColibriPalette();//Color palette for light animation
    FillWetlandLEDsFromPaletteColors(startIndex,15,25);
    FillColibriLEDsFromPaletteColors(startIndex,25,29);
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
  }
  
  if((currtouched & _BV(0))&& !(lasttouched & _BV(0))){
    Serial.println("zero");
    section4IsRunning = false;
    section5IsRunning = false;
    s1Active = true;
    FastLED.clear();  // clear all pixel data
    FastLED.show();
  }

  // reset our state
  lasttouched = currtouched;
  currentMillis = millis();
  if (currentMillis - startMillis >= period) {
    Serial.println("zero");
    section4IsRunning = false;
    section5IsRunning = false;
    s1Active = true;
    FastLED.clear();  // clear all pixel data
    FastLED.show();
    startMillis = currentMillis;
  }
}

//PALETTES
void SetupFlowersPalette() {
    CRGB orange = CRGB( 140,150,10);
    CRGB golden  = CRGB::Goldenrod;
    CRGB yellow = CRGB( 190,170,20);
    
    flowersPalette = CRGBPalette16(
                                   orange,  golden,  golden,  yellow,
                                   golden,  orange,  golden,  yellow,
                                   orange,  golden,  golden,  yellow,
                                   golden,  orange,  golden,  yellow);
}

void SetupWetlandPalette(){
    CRGB green = CRGB( 150, 10, 40);
    CRGB blue  = CRGB( 60, 40, 200);
    CRGB aquamarine  = CRGB(160,20,150);
    CRGB purple  = CRGB(40,50,180);
    
    wetlandPalette = CRGBPalette16(
                                   aquamarine,  purple,  purple,  purple,
                                   aquamarine,  aquamarine,  aquamarine,  blue,
                                   blue, blue, blue,  blue,
                                   green, green, green,  aquamarine );
}

void SetupColibriPalette() {
    CRGB green = CRGB( 180,20,120);
    CRGB blue  = CRGB( 60, 40, 200);
    CRGB aquamarine  = CRGB(130,20,170);
    CRGB purple  = CRGB(40,60,180);
    
    colibriPalette = CRGBPalette16(
                                   aquamarine,  purple,  blue,  green,
                                   green,  blue,  purple,  aquamarine,
                                   aquamarine,  purple,  blue,  green,
                                   green,  blue,  purple,  aquamarine );
}

//Control LEDS functions for each palette
void FillFlowersLEDsFromPaletteColors( uint8_t colorIndex, int startIndex, int endIndex) {
    uint8_t brightness = 50;
    
    for( int i = startIndex; i < endIndex; ++i) {
        FastLED.delay(200);
        fuzzy[i] = ColorFromPalette( flowersPalette, colorIndex, brightness, currentBlending);
        if(i== 5 || i== 6 || i== 12 || i== 13)  {
          fuzzy[i] = CRGB( 30,180,30);
        }
        colorIndex += 3;
    }
}

void FillWetlandLEDsFromPaletteColors( uint8_t colorIndex, int startIndex, int endIndex) {
    uint8_t brightness = 250;
    
    for( int i = startIndex; i < endIndex; ++i) {
        strip[i] = ColorFromPalette( wetlandPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
}

void FillColibriLEDsFromPaletteColors( uint8_t colorIndex, int startIndex, int endIndex) {
    uint8_t brightness = 250;
    
    for( int i = startIndex; i < endIndex; ++i) {
        strip[i] = ColorFromPalette( colibriPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
}
