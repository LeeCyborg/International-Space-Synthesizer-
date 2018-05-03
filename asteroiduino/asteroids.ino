#include <Adafruit_NeoPixel.h>
#define PIN 6
#define NUM_LEDS 60
struct asteroid {
  int diameter;
  float distance;
  bool danger;
};
struct asteroid Asteroids[101];

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
Asteroids[0] = {3.36409625,30,false};
Asteroids[1] = {71.248088,58,false};
Asteroids[2] = {60.742864,14,false};
Asteroids[3] = {66.671172,447,false};
Asteroids[4] = {46.240652,234,false};
Asteroids[5] = {6.304971,24,false};
Asteroids[6] = {61.5221,589,false};
Asteroids[7] = {6.4715005,37,false};
Asteroids[8] = {4.0150625,12,false};
Asteroids[9] = {70.333328,15,false};
Asteroids[10] = {36.745032,8,false};
Asteroids[11] = {49.806212,427,true};
Asteroids[12] = {55.80914,162,false};
Asteroids[13] = {49.237736,42,false};
Asteroids[14] = {17.185772,282,false};
Asteroids[15] = {22.069504,102,false};
Asteroids[16] = {18.029718,135,true};
Asteroids[17] = {49.79032,64,false};
Asteroids[18] = {17.388314,58,false};
Asteroids[19] = {4.4845545,20,false};
Asteroids[20] = {56.265044,89,false};
Asteroids[21] = {60.774016,6,false};
Asteroids[22] = {20.180434,162,false};
Asteroids[23] = {58.348476,3,false};
Asteroids[24] = {20.180402,155,false};
Asteroids[25] = {63.434788,234,false};
Asteroids[26] = {0.858962875,6,false};
Asteroids[27] = {19.765366,3,false};
Asteroids[28] = {63.520272,107,false};
Asteroids[29] = {8.236139,15,false};
Asteroids[30] = {7.3150095,155,true};
Asteroids[31] = {71.934192,58,true};
Asteroids[32] = {26.356874,10,false};
Asteroids[33] = {28.340842,74,false};
Asteroids[34] = {61.187136,56,false};
Asteroids[35] = {17.623464,7,false};
Asteroids[36] = {72.993432,32,false};
Asteroids[37] = {72.098048,123,false};
Asteroids[38] = {33.094146,117,true};
Asteroids[39] = {10.330725,148,true};
Asteroids[40] = {47.133516,141,true};
Asteroids[41] = {41.186056,117,false};
Asteroids[42] = {49.123172,102,true};
Asteroids[43] = {61.0945,29,false};
Asteroids[44] = {73.509856,117,false};
Asteroids[45] = {0.49651809375,1,false};
Asteroids[46] = {17.914866,22,false};
Asteroids[47] = {16.37082,22,false};
Asteroids[48] = {5.203894,30,false};
Asteroids[49] = {42.035476,74,false};
Asteroids[50] = {46.22746,33,false};
Asteroids[51] = {62.829088,324,false};
Asteroids[52] = {60.338772,324,false};
Asteroids[53] = {2.032078875,12,false};
Asteroids[54] = {24.408638,148,false};
Asteroids[55] = {18.11595,5,false};
Asteroids[56] = {0.5617356875,7,false};
Asteroids[57] = {43.456848,97,false};
Asteroids[58] = {28.538968,53,false};
Asteroids[59] = {52.12696,195,true};
Asteroids[60] = {44.745092,33,false};
Asteroids[61] = {25.00344,97,false};
Asteroids[62] = {14.262426,13,false};
Asteroids[63] = {52.127124,195,true};
Asteroids[64] = {53.854448,12,false};
Asteroids[65] = {23.390894,28,false};
Asteroids[66] = {1.287929625,30,false};
Asteroids[67] = {68.97476,30,false};
Asteroids[68] = {70.510224,155,false};
Asteroids[69] = {10.678442,23,false};
Asteroids[70] = {1.080875375,8,false};
Asteroids[71] = {43.17192,141,false};
Asteroids[72] = {25.085858,35,false};
Asteroids[73] = {69.10784,204,false};
Asteroids[74] = {53.762484,8,false};
Asteroids[75] = {0.0163682958984375,0,false};
Asteroids[76] = {74.594712,102,false};
Asteroids[77] = {38.652964,117,false};
Asteroids[78] = {36.140236,257,true};
Asteroids[79] = {3.262709,70,true};
Asteroids[80] = {15.440285,141,false};
Asteroids[81] = {74.725216,17,false};
Asteroids[82] = {57.63786,20,false};
Asteroids[83] = {37.578444,1415,true};
Asteroids[84] = {1.696962875,7,false};
Asteroids[85] = {39.762784,107,false};
Asteroids[86] = {10.789576,33,false};
Asteroids[87] = {64.932468,112,false};
Asteroids[88] = {74.191224,40,false};
Asteroids[89] = {32.340932,64,false};
Asteroids[90] = {30.719376,70,false};
Asteroids[91] = {20.567334,1025,true};
Asteroids[92] = {34.277536,13,false};
Asteroids[93] = {11.930733,13,false};
Asteroids[94] = {6.483987,40,false};
Asteroids[95] = {29.589722,56,false};
Asteroids[96] = {28.633204,35,false};
Asteroids[97] = {62.655036,9,false};
Asteroids[98] = {1.75811625,51,false};
Asteroids[99] = {0.01649784765625,0,false};
Asteroids[100] = {20.180434,162,false};

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

// *** REPLACE FROM HERE ***
void loop() {
  for (int i = 0; i < 100; i++) {
    if (Asteroids[i].danger) {
      meteorRain(Asteroids[i].diameter, 0, 0, 10, 64, true, Asteroids[i].diameter/2);
    } else {
      meteorRain(Asteroids[i].diameter, Asteroids[i].distance, random(0, 10), 10, 64, true, Asteroids[i].diameter/2);

    }
  }
}

void meteorRain(byte red, byte green, byte blue, byte meteorSize, byte meteorTrailDecay, boolean meteorRandomDecay, int SpeedDelay) {
  setAll(0, 0, 0);

  for (int i = 0; i < NUM_LEDS + NUM_LEDS; i++) {
    // fade brightness all LEDs one step
    for (int j = 0; j < NUM_LEDS; j++) {
      if ( (!meteorRandomDecay) || (random(10) > 5) ) {
        fadeToBlack(j, meteorTrailDecay );
      }
    }
    // draw meteor
    for (int j = 0; j < meteorSize; j++) {
      if ( ( i - j < NUM_LEDS) && (i - j >= 0) ) {
        setPixel(i - j, red, green, blue);
      }
    }
    showStrip();
    delay(SpeedDelay);
  }
}

void fadeToBlack(int ledNo, byte fadeValue) {
#ifdef ADAFRUIT_NEOPIXEL_H
  // NeoPixel
  uint32_t oldColor;
  uint8_t r, g, b;
  int value;

  oldColor = strip.getPixelColor(ledNo);
  r = (oldColor & 0x00ff0000UL) >> 16;
  g = (oldColor & 0x0000ff00UL) >> 8;
  b = (oldColor & 0x000000ffUL);

  r = (r <= 10) ? 0 : (int) r - (r * fadeValue / 256);
  g = (g <= 10) ? 0 : (int) g - (g * fadeValue / 256);
  b = (b <= 10) ? 0 : (int) b - (b * fadeValue / 256);

  strip.setPixelColor(ledNo, r, g, b);
#endif
#ifndef ADAFRUIT_NEOPIXEL_H
  // FastLED
  leds[ledNo].fadeToBlackBy( fadeValue );
#endif
}
// *** REPLACE TO HERE ***

void showStrip() {
#ifdef ADAFRUIT_NEOPIXEL_H
  // NeoPixel
  strip.show();
#endif
#ifndef ADAFRUIT_NEOPIXEL_H
  // FastLED
  FastLED.show();
#endif
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
#ifdef ADAFRUIT_NEOPIXEL_H
  // NeoPixel
  strip.setPixelColor(Pixel, strip.Color(red, green, blue));
#endif
#ifndef ADAFRUIT_NEOPIXEL_H
  // FastLED
  leds[Pixel].r = red;
  leds[Pixel].g = green;
  leds[Pixel].b = blue;
#endif
}

void setAll(byte red, byte green, byte blue) {
  for (int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue);
  }
  showStrip();
}

