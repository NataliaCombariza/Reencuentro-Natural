//Creation of palettes using fastLED libraries
//libraries
#include <FastLED.h>

//Initialization of Strip
#define LED_PIN     8
#define NUM_LEDS    45
#define BRIGHTNESS  200
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];


#define UPDATES_PER_SECOND 100


CRGBPalette16 currentPalette;
TBlendType    currentBlending;

void setup() {
    delay( 3000 ); // power-up safety delay
    //Led strip with RGB color mode
    FastLED.addLeds<WS2812, LED_PIN, RGB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
    currentBlending = LINEARBLEND;
}


void loop()
{
    SetupHumedalPalette();
    currentBlending = LINEARBLEND;
    
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; // motion speed 
    
    FillLEDsFromPaletteColors( startIndex);
    
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);

}

void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
    uint8_t brightness = 255;
    
    for( int i = 0; i < NUM_LEDS; ++i) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
}

//PALETTES

//Humedal
void SetupHumedalPalette()
{
    CRGB green = CRGB( 150, 10, 40);
    CRGB blue  = CRGB( 60, 40, 200);
    CRGB aquamarine  = CRGB(160,20,150);
    CRGB purple  = CRGB(40,50,180);
    
    currentPalette = CRGBPalette16(
                                   aquamarine,  purple,  purple,  purple,
                                   aquamarine,  aquamarine,  aquamarine,  blue,
                                   blue, blue, blue,  blue,
                                   green, green, green,  aquamarine );
}


//Colibri
void SetupColibriPalette()
{
    CRGB green = CRGB( 180,20,120);
    CRGB blue  = CRGB( 60, 40, 200);
    CRGB aquamarine  = CRGB(130,20,170);
    CRGB purple  = CRGB(40,60,180);
    
    currentPalette = CRGBPalette16(
                                   aquamarine,  purple,  blue,  green,
                                   green,  blue,  purple,  aquamarine,
                                   aquamarine,  purple,  blue,  green,
                                   green,  blue,  purple,  aquamarine );
}

//Ave
void SetupAvePalette()
{
    CRGB orange = CRGB( 110,120,50);
    CRGB red  = CRGB( 60, 190, 40);
    CRGB brown  = CRGB(100,120,60);
    CRGB purple  = CRGB(50,70,40);
    
    currentPalette = CRGBPalette16(
                                   orange,  orange,  orange,  orange,
                                   brown,  brown,  brown,  brown,
                                   red,  red,  red,  red,
                                   purple,  purple,  purple,  purple );
}
//flores
void SetupFloresPalette()
{
    CRGB orange = CRGB( 140,150,10);
    CRGB golden  = CRGB::Goldenrod;
    CRGB yellow = CRGB( 190,170,20);
    
    currentPalette = CRGBPalette16(
                                   orange,  orange,  golden,  golden,
                                   yellow,  yellow,  golden,  golden,
                                   orange,  orange,  yellow,  yellow,
                                   golden,  golden,  yellow,  yellow );
}


// Additional notes on FastLED compact palettes:
//
// Normally, in computer graphics, the palette (or "color lookup table")
// has 256 entries, each containing a specific 24-bit RGB color.  You can then
// index into the color palette using a simple 8-bit (one byte) value.
// A 256-entry color palette takes up 768 bytes of RAM, which on Arduino
// is quite possibly "too many" bytes.
//
// FastLED does offer traditional 256-element palettes, for setups that
// can afford the 768-byte cost in RAM.
//
// However, FastLED also offers a compact alternative.  FastLED offers
// palettes that store 16 distinct entries, but can be accessed AS IF
// they actually have 256 entries; this is accomplished by interpolating
// between the 16 explicit entries to create fifteen intermediate palette
// entries between each pair.
//
// So for example, if you set the first two explicit entries of a compact 
// palette to Green (0,255,0) and Blue (0,0,255), and then retrieved 
// the first sixteen entries from the virtual palette (of 256), you'd get
// Green, followed by a smooth gradient from green-to-blue, and then Blue.
