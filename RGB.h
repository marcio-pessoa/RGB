/* RGB.h - Tri color LED Management Library
 *
 * Author: Márcio Pessoa <marcio.pessoa@gmail.com>
 * Contributors: none
 *
 * Change log
 * 2023-04-18
 *         * all
 *         Refactor: Rename variables
 *         Fix: change variables type from byte to unsigned char
 *
 * 2015-09-04
 *         * refresh
 *         Optimized code on inverse method.
 *
 * 2015-07-04
 *         * inverse
 *         Fixed bug on inverse method.
 *         Finnaly all is working fine.
 *
 * 2015-07-03
 *         * refresh
 *         Added refresh private method to update LED after some operations.
 *         * brightness
 *         brightness method now refrsh LED status.
 *         * set
 *         set mothod uses refresh method to update LED status.
 *
 * 2015-06-13
 *         * set
 *         Added bright variable to control led bright.
 *
 * 2015-02-22
 *         * set
 *         Added set(unsigned long value) to use color name definitions and to
 *         overload set(unsigned char R, unsigned char G, unsigned char B).
 *
 * 2015-02-21
 *         Experimental version.
 */

#ifndef RGB_h
#define RGB_h

#include "Arduino.h"

class RGB {
 public:
  RGB(unsigned char red_pin, unsigned char green_pin, unsigned char blue_pin);
  void inverse();
  void set(unsigned char red, unsigned char green, unsigned char blue);
  void brightness(float brightness = 1);

 private:
  void refresh();
  unsigned char _red_pin;
  unsigned char _green_pin;
  unsigned char _blue_pin;
  unsigned char _red;
  unsigned char _green;
  unsigned char _blue;
  float _brightness;
  bool _inverse;
};

#endif
