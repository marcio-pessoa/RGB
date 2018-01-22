/* RGB.h - Manage a tri color LED
 * 
 * Author: Márcio Pessoa <marcio.pessoa@sciemon.com>
 * Contributors: none
 * 
 * Change log
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
 *         overload set(byte R, byte G, byte B).
 * 
 * 2015-02-21
 *         Experimental version.
 */

#ifndef RGB_h
#define RGB_h

#include "Arduino.h"

class RGB
{
  public:
    RGB(byte Rpin, byte Gpin, byte Bpin);
    void inverse();
    void set(byte R, byte G, byte B);
    void brightness(float brightness = 1);
  private:
    void refresh();
    byte _Rpin;
    byte _Gpin;
    byte _Bpin;
    byte _R;
    byte _G;
    byte _B;
    float _brightness;
    bool _inverse;
};

#endif
