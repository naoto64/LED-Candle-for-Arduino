/*
 * Candle.h
 */
#ifndef CANDLE_LIBRARY
#define CANDLE_LIBRARY
#include <Arduino.h>

class Candle {
public:
  Candle(uint8_t pin, int brightness=100, int rate=100, int ratio=100);
  reset();
  shuffle(int min, int max);
  pin(uint8_t pin);
  brightness(int _brightness);
  rate(float rate);
  ratio(int ratio);
  refresh();

private:
  uint8_t _pin;
  float _led_n = 2.2904;
  float _led_x = 0;
  float _brightness = 1.0;
  float _rate = 0.005;
  int _ratio = 100;
};

#endif
