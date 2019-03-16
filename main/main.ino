#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 240

// Define the array of leds
CRGB leds[NUM_LEDS];

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 3
#define CLOCK_PIN 13

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

  resetStream();

  Serial.begin(9600); // set the baud rate
  Serial.println("Ready"); // print "Ready" once

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  
  char inByte = ' ';
  if(Serial.available()){ // only send data back if data has been sent
    char inByte = Serial.read(); // read the incoming data

    // Pick One
    //testOnboardLight(inByte);
    //testLEDStripBlink(inByte);
    testLEDStripTraverse(inByte);
    //stream(1);

    Serial.println(inByte); // send the data back in a new line so that it is not all one long line
  }
  delay(100); // delay for 1/10 of a second
}

void testOnboardLight(char inByte) {
  if(inByte == '0') {
    // Turn the LED off, then pause
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);                       // wait for a second
  }

  if(inByte == '1'){
    // Turn the LED on, then pause
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
   }
}

void testLEDStripBlink(char inByte) {
  if(inByte == '0') {
    // Turn the LED off, then pause
    leds[0] = CRGB::Black;
    FastLED.show();
    delay(500);
  }

  if(inByte == '1'){
    // Turn the LED on, then pause
    leds[0] = CRGB::Red;
    FastLED.show();
    delay(500);
  }
}

void testLEDStripTraverse(char inByte) {
  if(inByte == '0') {
    // Turn the LED off, then pause
    for(int i=0; i<100; i++) {
      leds[i] = CRGB::Blue;
      FastLED.show();
      delay(100);
    }
  }

  if(inByte == '1') {
    // Turn the LED on, then pause
    for(int i=0; i<100; i++) {
      leds[i] = CRGB::Red;
      FastLED.show();
      delay(100);
    }
  }
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

