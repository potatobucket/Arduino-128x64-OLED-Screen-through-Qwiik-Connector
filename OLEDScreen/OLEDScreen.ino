// Libraries
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3D
#define OLED_RESET 13

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire1, OLED_RESET);

const int COLOR = 1;
const String TEST_STRING = "Successful test!";
const unsigned char PROGMEM POTATO_BMP[] = {
  0x0,0x0,0x0,0x0,0xb5,0x55,0x55,0xad,0xbe,0xda,0xaa,0xaa,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xad,0xaa,0xae,0xde,0xfb,0xaa,0xd5,0x5b,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x6a,0xb5,0x55,0x7f,0xdf,0xf6,0xb6,0xaa,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  0x0,0xad,0x55,0x5b,0xf0,0xf,0xda,0xaa,0xd6,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x55,0xaa,0xaf,0xc0,0x1,0xeb,0x55,0x6b,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xad,0x5a,0xff,0x81,0x50,0x7a,0xda,0xad,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x55,0x6d,
  0x5f,0xe,0xec,0x3b,0x57,0x75,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xab,0x57,0x7e,0x15,0x57,0x3d,0x6a,0xaa,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x55,0x6a,0xfc,0x2b,0xba,0x9e,0xb5,0xb6,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x92,0xbd,0xf8,0x55,
  0x6b,0xf,0xda,0xdb,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x55,0x57,0xc0,0xdb,0x5a,0x87,0x56,0xaa,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xaa,0xab,0x0,0x55,0xad,0x43,0xfa,0xb6,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x55,0x77,0x0,0x3e,0xeb,0xb1,
  0xcd,0x5b,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x49,0x5f,0x0,0x2a,0xad,0xf9,0xf7,0x6c,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xaa,0xae,0x0,0x16,0xd7,0xef,0xfa,0xb5,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x55,0x7e,0x10,0x1b,0x6b,0x40,0x6f,0xaa,
  0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x92,0xbd,0x38,0x35,0xb7,0x80,0x3e,0xaa,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x55,0xbd,0xe0,0x1e,0xaf,0x0,0x3f,0x55,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xaa,0xfd,0xc0,0x75,0x6e,0x0,0x3f,0xaa,0x0,0x0,0x0,
  0x0,0x0,0x0,0x0,0x0,0x55,0x5b,0x80,0xf8,0x17,0x0,0x1b,0x55,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xaa,0xfc,0xf5,0xd4,0x56,0x18,0x1f,0x6a,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xb6,0xba,0xff,0xef,0x56,0x70,0xf,0xaa,0x0,0x0,0x0,0x0,0x0,0x0,
  0x0,0x0,0xdb,0x78,0x3f,0xb5,0x6b,0x60,0x1f,0x55,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x55,0xf4,0x84,0xab,0x55,0xc0,0xf,0x5a,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xbb,0x78,0xa8,0x5a,0xaa,0xc0,0x4f,0xaa,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xd6,
  0xf0,0xd7,0xab,0x6a,0x40,0x47,0x6b,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x5b,0xf9,0x55,0x5a,0x95,0x12,0xa7,0xa9,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xad,0xe8,0xb5,0x6a,0xaa,0xc9,0x47,0xae,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xf6,0xf0,0xaa,
  0xaa,0xa9,0x35,0x47,0x75,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x2b,0xf0,0xaa,0xaa,0x95,0x4a,0xa7,0xaa,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xad,0xe8,0xaa,0xaa,0x55,0x55,0x47,0xdd,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x55,0xf0,0xaa,0xaa,0xaa,
  0xa5,0x47,0x6a,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xad,0xe0,0xa5,0x52,0xa4,0x95,0x4f,0x55,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x57,0xc1,0x54,0x8a,0x95,0x55,0x4e,0xed,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xa9,0xe1,0x52,0x69,0x54,0x8a,0x97,
  0xb6,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x57,0xe1,0x2a,0x95,0x25,0x54,0x9f,0xab,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xab,0xe2,0x92,0x4a,0xaa,0xa8,0xf,0xfc,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x5b,0x60,0x55,0x75,0xf6,0xdf,0xcf,0xd7,0x0,0x0,
  0x0,0x0,0x0,0x0,0x0,0x0,0xad,0xef,0xff,0xff,0x0,0x0,0x53,0xea,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x57,0xf0,0x12,0x80,0x55,0x55,0x48,0xfa,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0x82,0xa4,0x2a,0xaa,0xaa,0x8e,0x7a,0x0,0x0,0x0,0x0,0x0,
  0x0,0x0,0x0,0x5e,0x31,0x52,0x55,0x24,0x92,0x97,0x7b,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xf6,0xf2,0x49,0x49,0x52,0xaa,0x9e,0x3a,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x5e,0xf1,0x28,0xa5,0x2a,0x45,0xe,0xba,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  0xde,0x19,0x4a,0x54,0xa5,0x52,0x96,0xbd,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xbe,0x15,0x29,0x4a,0x95,0x5,0x1c,0x7a,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xdc,0x14,0xaa,0xa9,0x52,0xd2,0x0,0x1a,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x68,0x52,0x4,
  0x12,0x8,0x0,0x1,0x3a,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xbe,0x9,0x69,0x40,0x20,0x8,0x90,0x55,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xd7,0x0,0x0,0x2a,0xd4,0xa0,0x0,0x3a,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x5f,0x8a,0xaa,0x80,0x0,0xa,0x48,
  0xd5,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xaf,0x80,0x0,0x4,0x8a,0x40,0x1,0xea,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x6b,0x85,0x54,0x90,0x0,0x11,0x24,0xf5,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xab,0x80,0x1,0x2,0x51,0x4,0x1,0xea,0x0,0x0,0x0,0x0,
  0x0,0x0,0x0,0x0,0x57,0x85,0x54,0x48,0x4,0x50,0x91,0xfa,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xab,0x80,0x1,0x1,0x10,0x2,0x1,0xcd,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x57,0x85,0x54,0x24,0x41,0x20,0x49,0xf6,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  0xab,0xc0,0x80,0x80,0x4,0x9,0x1,0xd5,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x57,0x82,0x2a,0x11,0x10,0x82,0x23,0xda,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xab,0xc0,0x80,0x84,0x40,0x28,0x11,0xab,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x4b,0xc1,0x2a,
  0x0,0x4,0x81,0x43,0xed,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xaf,0x80,0x80,0x52,0x20,0x10,0x13,0xaa,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x56,0xc0,0x55,0x0,0x84,0x85,0x23,0xd5,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xab,0xc1,0x0,0x8,0x10,0x20,
  0x3,0xaa,0x0,0x0,0x0,0x0
};

void displayText(String string){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(string);
  display.display();
};

void displayBitmap(const unsigned char *BITMAP_IMAGE){
  display.clearDisplay();
  display.drawBitmap(0, 0, BITMAP_IMAGE, SCREEN_WIDTH, SCREEN_HEIGHT, COLOR);
  display.display();
};

void setup() {
  Serial.begin(115200);
  display.begin();
}

void loop() {
  displayText(TEST_STRING);
  delay(2000);
  displayBitmap(POTATO_BMP);
  delay(2000);
}
