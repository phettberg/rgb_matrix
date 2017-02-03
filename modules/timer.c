/** \file timer.c
 *  \brief Simple timer module
 *  \details Use this module to process several timers with one function call.
 *  Therefore define some timer variables of type timer_var_t,
 *  and use the TIMER_CONFIG macro to create a timer configuration.
 *  All timers are then processed calling the timer_tick function.
 *  \author Ruedisser Christoph (ruc)
 *  \copyright All rights belong to High Q Laser
 *  \version 1.3.0 (338)
 */

#include "timer.h"

void timer_tick(timer_array_t timers, uint32_t tick_interval) {
  uint8_t index = 0;
  while (timers[index] != 0) {
    if ((*(timer_var_t*)timers[index] != 0) && (*(timer_var_t*)timers[index] != (timer_var_t)-1)) {
      if (*(timer_var_t*)(timers[index]) <= tick_interval) {
        *(timer_var_t*)timers[index] = 0;
      }
      else {
        *(timer_var_t*)timers[index] -= tick_interval;
      }
    }
    index++;
  }
}
