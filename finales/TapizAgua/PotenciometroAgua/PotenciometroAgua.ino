/*
For this code it was used a MIT software
MIT License
Copyright 2020 Michael Schoeffler (https://www.mschoeffler.de)
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/


#define PIN_SLIDE_POT_A A0 // input pin of the potenciometer
#define MAX_SLIDE_POT_ANALGOG_READ_VALUE 800 

#define PIN_POT_B A4 // input pin of the second potenciometer
#define MAX_POT_ANALGOG_READ_VALUE 800 // maximum voltage as analog-to-digital converted value, depends on the voltage level of the VCC pin. Examples: 5V = 1023; 3.3V ~700

#include "FastLED.h"

#define NUM_LEDS 45 // add number of LEDs of your RGB LED strip
#define PIN_LED 7 // digital output PIN that is connected to DIN of the RGB LED strip

CRGB strip[NUM_LEDS]; // color array of the LED RGB strip

#define UPDATES_PER_SECOND 50

//VARIABLES
//Paletter inizalitation
CRGBPalette16 flowersPalette;
CRGBPalette16 wetlandPalette;
CRGBPalette16 colibriPalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(PIN_SLIDE_POT_A, INPUT);
  pinMode(PIN_POT_B, INPUT);

  FastLED.addLeds<WS2812, PIN_LED>(strip, NUM_LEDS);  

  wetlandPalette = RainbowColors_p;
  currentBlending = LINEARBLEND;

}

void loop() {
  // put your main code here, to run repeatedly:
  // 1) Analog value of slide pot is read
  static uint8_t colorIndex = 0;
  colorIndex = colorIndex + 1; // motion speed 
  
  int value_slide_pot_a = analogRead(PIN_SLIDE_POT_A);

  int value_pot_b = analogRead(PIN_POT_B);

  int num_leds_switchedon = map(value_slide_pot_a, 150, MAX_SLIDE_POT_ANALGOG_READ_VALUE, 0, 24);  
  int num_leds_switchedonB = map(value_pot_b, MAX_POT_ANALGOG_READ_VALUE,100, 24, 45); 

  Serial.print(value_slide_pot_a);  // print sensor 1
  Serial.print(",");                // print ','
  Serial.print(value_pot_b);        // print sensor 2
  Serial.println(); 

  //Start the palettes and LEDs
  SetupWetlandPalette();
  FillWetlandLEDsFromPaletteColors(colorIndex, num_leds_switchedon);
  FillWetlandLEDsFromPaletteColors2(colorIndex, num_leds_switchedonB);

  FastLED.show();
  FastLED.delay(1000/UPDATES_PER_SECOND);
  
}

//Palette animation
void SetupWetlandPalette(){
    CRGB green = CRGB( 150, 10, 40);
    CRGB blue  = CRGB( 60, 40, 200);
    CRGB aquamarine  = CRGB(160,20,150);
    CRGB purple  = CRGB(40,50,180);
    
    wetlandPalette = CRGBPalette16(
                                   aquamarine,  purple,  purple,  green,
                                   aquamarine,  aquamarine,  aquamarine,  blue,
                                   blue, blue, blue,  blue,
                                   green, purple, green,  aquamarine );
}

//Palette control section 1
void FillWetlandLEDsFromPaletteColors( uint8_t colorIndex, int num_leds_switchedon) {
    uint8_t brightness = 250;

    for (int i = 0; i < num_leds_switchedon/2; ++i) {
      strip[i] = ColorFromPalette( wetlandPalette, colorIndex, brightness, currentBlending);
      strip[20-i] = ColorFromPalette( wetlandPalette, colorIndex, brightness, currentBlending);
      colorIndex += 3;
    }
  
    // LEDs are switched off which correspond to the area right of the slide knob
      for (int i= num_leds_switchedon; i < 12; ++i) {
      //strip[i] = CRGB::Black;
      strip[22-i] = CRGB::Black;
      colorIndex += 3;
    } 
}


//Palette control section 2
void FillWetlandLEDsFromPaletteColors2( uint8_t colorIndex, int num_leds_switchedonB) {
    uint8_t brightness = 250;

   for (int i = 24; i < (num_leds_switchedonB/2 + 11); ++i) {
    strip[i+11] = ColorFromPalette( wetlandPalette, colorIndex, brightness, currentBlending);
    strip[56-i] = ColorFromPalette( wetlandPalette, colorIndex, brightness, currentBlending);
    colorIndex += 3;
   
  }  
  // LEDs are switched off which correspond to the area right of the slide knob
  for (int i = num_leds_switchedonB; i < 34; ++i) {
    strip[i+11] = CRGB::Black;
    strip[56-i] = CRGB::Black;
    colorIndex += 3;
  }
}
