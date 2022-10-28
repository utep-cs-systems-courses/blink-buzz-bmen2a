#include <msp430.h>

#include "libTimer.h"

#include "switches.h"

#include "led.h"

#include "buzzer.h"

#include "stateMachines.h"



int main(void){

  configureClocks();

  switch_init();

  led_init();

  buzzer_init();
  // buzzer_set_period(1000);/* start buzzing!!! 2MHz/1000 = 2kHz*/
  enableWDTInterrupts();



  or_sr(0x18);

}
