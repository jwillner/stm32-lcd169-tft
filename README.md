# stm32-lcd169-tft

Ansteuerung des **Waveshare 1.69\" LCD Moduls (ST7789V2, 240×280)** mit einem  
**STM32F103C8 \"Blue Pill\"** über **PlatformIO (Arduino-Framework)**.

Das Projekt zeigt einen minimalen, stabilen Startpunkt inkl. Textausgabe
und Backlight-Steuerung.

---

## Hardware

- MCU: STM32F103C8T6 (Blue Pill)
- Display: Waveshare 1.69\" LCD Module
- Controller: ST7789V2
- Interface: SPI (4-Wire)

---

## Verdrahtung

| LCD | Blue Pill |
|----|-----------|
| VCC | 3.3 V |
| GND | GND |
| DIN (MOSI) | PA7 |
| CLK (SCK) | PA5 |
| CS | PB6 |
| DC | PA8 |
| RST | PA9 |
| BL | PB0 (PWM, optional) |

> Hinweis: MISO wird nicht benötigt.

---

## Software-Setup

### platformio.ini
```ini
[env:bluepill_f103c8]
platform = ststm32
board = bluepill_f103c8
framework = arduino

monitor_speed = 115200

lib_deps =
  adafruit/Adafruit GFX Library
  adafruit/Adafruit ST7735 and ST7789 Library
```

---

## Beispielausgabe

```
company: twopounds
device: helios
date: <Compile Date>
time: <Compile Time>
```

Datum und Uhrzeit stammen aus `__DATE__` und `__TIME__`.

---

## Projektstruktur

```
stm32-lcd169-tft/
├── platformio.ini
├── src/
│   └── main.cpp
└── README.md
```

---

## Status

- ✅ Display initialisiert
- ✅ Textausgabe korrekt
- ✅ PlatformIO Build & Upload stabil

---

## Lizenz

MIT (oder nach Wunsch anpassen)
