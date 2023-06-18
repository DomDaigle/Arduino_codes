#include <FastLED.h>

#define LED_PIN   7
#define NUM_LEDS  169

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  // put your main code here, to run repeatedly:
  leds[0] = CRGB(255, 0, 0);
  FastLED.show();
  delay(500);
  leds[1] = CRGB(0, 255, 0);
  FastLED.show();
  delay(500);
  leds[2] = CRGB(0, 0, 255);
  FastLED.show();
  delay(500);
  leds[5] = CRGB(150, 0, 255);
  FastLED.show();
  delay(500);
  leds[9] = CRGB(255, 200, 20);
  FastLED.show();
  delay(500);
  leds[14] = CRGB(85, 60, 180);
  FastLED.show();
  delay(500);
  leds[19] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);
  leds[25] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);
  leds[23] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);
  leds[32] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);
  leds[45] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);
  leds[58] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);
  leds[71] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);
  leds[84] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);
  leds[97] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);
  leds[110] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);
  leds[123] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);
  leds[136] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);
  leds[149] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);
  leds[162] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);  
}
