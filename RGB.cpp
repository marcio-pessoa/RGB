/* RGB.cpp - Tri color LED Management Library
 *
 */

#include "RGB.h"
#include "Arduino.h"

/* RGB
 *
 * Description
 *   Manage a tri color LED.
 *
 *   RGB(unsigned char Rpin, unsigned char Gpin, unsigned char Bpin)
 *
 * Parameters
 *   Rpin: Arduino red LED pin
 *   Gpin: Arduino green LED pin
 *   Bpin: Arduino blue LED pin
 *
 * Returns
 *   void
 */
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

/* inverse
 *
 * Description
 *   Set LED color.
 *
 *   a_led.inverse()
 *
 * Parameters
 *   inverse: true of false
 *
 * Returns
 *   void
 */
void RGB::inverse() { _inverse = !_inverse; }

/* set
 *
 * Description
 *   Set LED color.
 *
 *   a_led.set(unsigned char R, unsigned char G, unsigned char B)
 *
 * Parameters
 *   Rvalue: Set red led intensity
 *   Gvalue: Set green led intensity
 *   Bvalue: Set blue led intensity
 *
 * Returns
 *   void
 */
void RGB::set(unsigned char red, unsigned char green, unsigned char blue) {
  _red = red;
  _green = green;
  _blue = blue;
  refresh();
}

/* brightness
 *
 * Description
 *   Set LED brightness.
 *
 *   a_led.set(float brightness)
 *
 * Parameters
 *   brightness: Brightness value (0 to 1)
 *
 * Returns
 *   void
 */
void RGB::brightness(float brightness) {
  _brightness = brightness;
  refresh();
}

/* refresh
 *
 * Description
 *   Refresh LED.
 *
 *   a_led.refresh()
 *
 * Parameters
 *   none
 *
 * Returns
 *   void
 */
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
