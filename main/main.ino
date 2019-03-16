#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 240

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 3
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];


void setup() {
  // Uncomment/edit one of the following lines for your leds arrangement.
  // FastLED.addLeds<TM1803, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<TM1804, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<TM1809, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  // FastLED.addLeds<APA104, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<UCS1903, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<UCS1903B, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<GW6205, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<GW6205_400, DATA_PIN, RGB>(leds, NUM_LEDS);
  
  // FastLED.addLeds<WS2801, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<SM16716, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<LPD8806, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<P9813, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<APA102, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<DOTSTAR, RGB>(leds, NUM_LEDS);

  // FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<SM16716, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<LPD8806, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<P9813, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<DOTSTAR, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);

  resetStream();

  Serial.begin(9600); // set the baud rate
  Serial.println("Ready"); // print "Ready" once
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  
  char inByte = ' ';
  if(Serial.available()){ // only send data back if data has been sent
    char inByte = Serial.read(); // read the incoming data
    Serial.println(inByte); // send the data back in a new line so that it is not all one long line
    stream(1);
    if(inByte == '0') {
//      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
//      delay(1000);                       // wait for a second

      // Now turn the LED off, then pause
//      leds[0] = CRGB::Black;
//      FastLED.show();
//      delay(500);

    }

    if(inByte == '1'){
      // Turn the LED on, then pause
//      leds[0] = CRGB::Red;
//      FastLED.show();
//      delay(500);

//      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
//      delay(1000);                       // wait for a second
    }
  }
  delay(100); // delay for 1/10 of a second
}

void testStream() {
  int amounts[1];
  amounts[0] = 1;
  for (int i = 0; i < 1; i++) {
    stream(amounts[i]);
  }
}
void stream(int amount) {
  for (int index = 0; index < NUM_LEDS; index++) {
    for (int i = 0; i < amount; i++) {
      setColor(index+i, amount);
    }
    FastLED.show();
    delay(10);
    for (int i = 0; i < amount; i++) {
      leds[index+i] = CRGB::Black;
    }
  }
}

void resetStream(){
  for (int i = 0; i < 240; i++) {
    leds[i] = CRGB::Black;
}
}

void setColor(int dot, int color) {
  if (color == 1) {
    leds[dot] = CRGB(255,35,0);
  }
  if (color == 2) {
    leds[dot] = CRGB::Blue;
  }
  if (color == 3) {
    leds[dot] = CRGB::Green;
  }
  if (color == 4) {
    leds[dot] = CRGB::Red;
  }
  if (color == 5) {
    leds[dot] = CRGB::Purple;
  }
  else {
    leds[dot] = CRGB(255,35,0);
  }
}

