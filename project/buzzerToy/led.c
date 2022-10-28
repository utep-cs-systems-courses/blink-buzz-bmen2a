#include <msp430.h>

#include "led.h"

#include "stateMachines.h"



unsigned char red_on = 0,green_on = 0;

unsigned char led_changed = 0;

char switch2_state,switch3_state;

char switch_state_changed;

static char redVal[] = {0,LED_RED},greenVal[] = {0,LED_GREEN};


void led_init(){
  P2DIR |= LEDS;// bits attached to leds are output

  led_changed=1;
  switch_state_changed = 1;

  led_update();
}
void led_update(){
  char ledFlags;
  if(switch_state_changed){

    ledFlags = greenVal[green_on] | redVal[red_on]; /* by default, no LEDs on */



    //ledFlags |= switch_state_down ? LED_GREEN : 0;
    
    //    ledFlags |= switch_state_down ? 0 : LED_RED;



    P2OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds

    P2OUT |= ledFlags;         // set bits for on leds
    led_changed=0;

  }
  if (switch_state_changed && switch_state == 2){

    ledFlags |= switch2_state ? LED_GREEN : 0; //green then when pressed switch to red

    ledFlags |= switch2_state ? 0 : LED_RED;



    P2OUT &= (0xff^LEDS) | ledFlags;

    P2OUT |= ledFlags;

  }
  if (switch_state_changed && switch_state == 3){

    ledFlags |= switch3_state ? 0 : LED_GREEN; //red and when pressed goes off



    P2OUT &= (0xff^LEDS) | ledFlags;

    P2OUT |= ledFlags;

  }

  switch_state_changed = 0;
}
