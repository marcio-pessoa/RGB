/* RGB.cpp - Manage a tri color LED
 * 
 */

#include "Arduino.h"
#include "RGB.h"

/* RGB
 * 
 * Description
 *   Manage a tri color LED.
 * 
 *   RGB(byte Rpin, byte Gpin, byte Bpin)
 * 
 * Parameters
 *   Rpin: Arduino red LED pin
 *   Gpin: Arduino green LED pin
 *   Bpin: Arduino blue LED pin
 * 
 * Returns
 *   void
 */
RGB::RGB(byte Rpin, byte Gpin, byte Bpin) {
  pinMode(Rpin, OUTPUT);
  pinMode(Gpin, OUTPUT);
  pinMode(Bpin, OUTPUT);
  _Rpin = Rpin;
  _Gpin = Gpin;
  _Bpin = Bpin;
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
void RGB::inverse() {
  _inverse = !_inverse;
}

/* set
 * 
 * Description
 *   Set LED color.
 * 
 *   a_led.set(byte R, byte G, byte B)
 * 
 * Parameters
 *   Rvalue: Set red led intensity
 *   Gvalue: Set green led intensity
 *   Bvalue: Set blue led intensity
 * 
 * Returns
 *   void
 */
void RGB::set(byte R, byte G, byte B) {
  _R = R;
  _G = G;
  _B = B;
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
  byte R = _R * _brightness;
  byte G = _G * _brightness;
  byte B = _B * _brightness;
  if (_inverse) {
    //~ R = map(R, 0, 255, 255, 0);
    //~ G = map(G, 0, 255, 255, 0);
    //~ B = map(B, 0, 255, 255, 0);
    R = 255 - R;
    G = 255 - G;
    B = 255 - B;
  }
  // Debug information
  //~ Serial.println(String(R) + "," + String(G) + "," + String(B) + "," + _brightness);
  analogWrite(_Rpin, R);
  analogWrite(_Gpin, G);
  analogWrite(_Bpin, B);
}
