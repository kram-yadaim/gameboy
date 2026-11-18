// imports libs
#pragma once
#include <Arduino.h>
#include <TFT_eSPI.h>
#include <Adafruit_NeoPixel.h>


// define pins for the gameboy
// leds
#define LED1_PIN 0
#define LED2_PIN 0
#define LED3_PIN 0

// keys
#define PB0_PIN 0
#define PB1_PIN 0
#define PB2_PIN 0
#define PB3_PIN 0
#define PB4_PIN 0
#define PB5_PIN 0

// switches
#define SW_PIN 0

// joystick
#define JSPIN_VRX 0
#define JSPIN_VRY 0
#define JSPIN_SW 0

// tft screen
#define TFT_MISO_PIN 0
#define TFT_MOSI_PIN 0
#define TFT_SCLK_PIN 0
#define TFT_CS_PIN 0
#define TFT_DC_PIN 0
#define TFT_RST_PIN 0
#define TOUCH_CS_PIN 0

// buzzer
#define BUZZER_PIN 0


class init_gameboy {
  public:
    TFT_eSPI tft;

    void init_buttons() {
      const int buttons[] = {PB0_PIN, PB1_PIN, PB2_PIN, PB3_PIN, PB4_PIN, PB5_PIN};
      for (int pin : buttons) pinMode(pin, INPUT);

      pinMode(SW_PIN, INPUT);
    }

    void init_joystick() {
      pinMode(JSPIN_SW, INPUT_PULLUP);
    }

    void init_screen() {
      tft.init();
      tft.setRotation(1);
      tft.fillScreen(TFT_BLACK);
    }

    void init_buzzer() {
      pinMode(BUZZER_PIN, OUTPUT);
    }

    void init_leds() {
      Adafruit_NeoPixel led1{1, LED1_PIN, NEO_GRB + NEO_KHZ800};
      Adafruit_NeoPixel led2{1, LED2_PIN, NEO_GRB + NEO_KHZ800};
      Adafruit_NeoPixel led3{1, LED3_PIN, NEO_GRB + NEO_KHZ800};
      led1.begin(); 
      led2.begin();
      led3.begin();
    }

    void init_ESP1(){
      init_buttons();
      init_joystick();
      init_buzzer();
      init_screen();
    }

    void init_ESP2(){
      init_leds();
    }
};