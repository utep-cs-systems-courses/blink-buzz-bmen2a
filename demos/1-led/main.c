//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;
  P1OUT &= LED_GREEN;
  P1OUT |= ~LED_RED;
  //Modify combination of lights by using " ~" on the last line
  //with ~ both lights turn on
  //without only greens on
  //vice varse
  or_sr(0x18);		/* CPU off, GIE on */
}
