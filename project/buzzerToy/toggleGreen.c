#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"


char toggle_green(){
  char changed=0;
  if (red_on){
    green_on ^= 1;
    //    buzzer_set_period(1000);
    changed = 1;
  }
 return changed;

}
