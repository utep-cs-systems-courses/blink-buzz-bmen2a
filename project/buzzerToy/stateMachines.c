#include <msp430.h>

#include "stateMachines.h"

#include "led.h"

#include "switches.h"

#include "buzzer.h"

#include "toggleGreen.c"
char toggle_red(){ //toggle methods for the state machine, alwayys toggle

  static char state = 0;



  switch (state){

  case 0:
    red_on = 1;
    state = 1;
    buzzer_set_period(3000);
    break;

  case 1:
    red_on = 0;
    state = 0;
    //buzzer_set_period(1000);
    
    break;
  }
  return 1;  //led always changes

}
void led_state_advance(){

  char changed = 0;



  static enum {R=0,G=1} color = G;

  switch (color){      //state machine for led to blink back and forth

  case R: changed = toggle_red(); color = G; break;

  case G: changed = toggle_green(); color = R; break;

  }



  led_changed = changed;

  led_update();

}


void switch_state_advance(){

  switch (switch_state){
  case 1:
    //buzzer_set_period(1200); //buzzer is set to a input when a certain button is pressed
    break;
  case 2:
    //buzzer_set_period(500);
    break;
  case 3:
    //buzzer_set_period(900);
    break;
  case 4:
   
    break;
  }
  led_update(); //after the state is set it will update the leds accordingly

}
