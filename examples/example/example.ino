#include <RGB.h>
#include <SigGen.h>

RGB led(10, 11, 13);
SigGen wave;

void setup() {
  Serial.begin(9600);
  led.inverse();
  led.set(255, 0, 0);
}

void loop() {
  led.brightness(wave.sine());
}
