// Libraries
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3D
#define OLED_RESET 13

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire1, OLED_RESET);

const String TEST_STRING = "Successful test!";

void displayText(String string){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(string);
  display.display();
};

void setup() {
  Serial.begin(115200);
  display.begin();
  displayText(TEST_STRING);
}

void loop() {
  // put your main code here, to run repeatedly:

}
