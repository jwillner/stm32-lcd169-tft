#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

// ===== Blue Pill Pins =====
#define TFT_CS   PB6
#define TFT_DC   PA8
#define TFT_RST  PA9
#define TFT_BL   PB0

Adafruit_ST7789 tft(TFT_CS, TFT_DC, TFT_RST);

static void backlight(uint8_t val) { analogWrite(TFT_BL, val); }

void setup() {
  Serial.begin(115200);
  delay(200);

  pinMode(TFT_BL, OUTPUT);
  backlight(255);

  SPI.begin();

  tft.init(240, 280);
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);

  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);

  // 4 Zeilen Text
  int x = 10;
  int y = 10;
  int lh = 22; // line height (bei TextSize(2) gut passend)

  tft.setCursor(x, y + 1 * lh);
  tft.print("company: twopounds");

  tft.setCursor(x, y + 2 * lh);
  tft.print("device: helios");

  tft.setCursor(x, y + 3 * lh);
  tft.print("date: ");
  tft.print(__DATE__);   // Compile-Datum

  tft.setCursor(x, y + 4 * lh);
  tft.print("time: ");
  tft.print(__TIME__);   // Compile-Zeit
}

void loop() {
  // nichts
}
