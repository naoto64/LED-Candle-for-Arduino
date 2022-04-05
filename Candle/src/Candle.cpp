/*
 * Candle.cpp
 */
#include <Arduino.h>
#include "Candle.h"

Candle::Candle(uint8_t pin, int brightness, int rate, int ratio) {
  _pin = pin;
  _brightness = float(brightness) / 100.0;
  _rate = float(rate) / 20000.0;
  _ratio = ratio;
}

Candle::reset() {
  pinMode(_pin, INPUT);
  _led_x = 0;
  _brightness = 1.0;
  _rate = 0.005;
  _ratio = 100;
}

Candle::shuffle(int min, int max) {
  _led_x += _rate * random(min, max);
}

Candle::pin(uint8_t pin) {
  pinMode(_pin, INPUT);
  _pin = pin;
}

Candle::brightness(int brightness) {
  _brightness = float(brightness) / 100.0;
}

Candle::rate(float rate) {
  _rate = rate / 20000.0;
}

Candle::ratio(int ratio) {
  _ratio = ratio;
}

Candle::refresh() {
  float led_y = 0;
  for(int i = 1; i <= 10; i++){
    led_y += sin(_led_x * pow(_led_n, i)) * pow(_led_n, -i);
  }
  _led_x += _rate;
  led_y += 1.75 + (100.0 - _ratio) / (_ratio / 2.0);
  led_y *= _ratio * _brightness;
  led_y = constrain(led_y, 0, 255);
  analogWrite(_pin, int(led_y));
  return led_y;
}
