/*
  ------------------------------
  Example of a simple LED candle
  LED Pin = Digital 5
  Use a pin that can output PWM.
  ------------------------------
*/

#include <Candle.h>

#define LED_PIN 5

Candle candle = Candle(LED_PIN);

void setup() {
}

void loop() {
  candle.refresh();
}
