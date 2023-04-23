/* RGB.cpp - Tri color LED Management Library
 *
 */

#include "RGB.h"
#include "Arduino.h"

/// @brief Manage a tri color LED.
/// @param red_pin  Arduino red LED pin
/// @param green_pin  Arduino green LED pin
/// @param blue_pin  Arduino blue LED pin
RGB::RGB(unsigned char red_pin, unsigned char green_pin,
         unsigned char blue_pin) {
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
  _red_pin = red_pin;
  _green_pin = green_pin;
  _blue_pin = blue_pin;
  _brightness = 1;
  _inverse = false;
}

/// @brief Set LED color inverse mode.
void RGB::inverse() { _inverse = !_inverse; }

/// @brief Set LED color.
/// @param red Set red led intensity
/// @param green Set green led intensity
/// @param blue Set blue led intensity
void RGB::set(unsigned char red, unsigned char green, unsigned char blue) {
  _red = red;
  _green = green;
  _blue = blue;
  refresh();
}

/// @brief Set LED brightness.
/// @param brightness Brightness value (0 to 1)
void RGB::brightness(float brightness) {
  _brightness = brightness;
  refresh();
}

/// @brief Refresh LED.
void RGB::refresh() {
  unsigned char red = _red * _brightness;
  unsigned char green = _green * _brightness;
  unsigned char blue = _blue * _brightness;
  if (_inverse) {
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  }
  analogWrite(_red_pin, red);
  analogWrite(_green_pin, green);
  analogWrite(_blue_pin, blue);
}
