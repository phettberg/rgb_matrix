/** \file timer.h
 *  \brief Simple timer module
 *  \details Use this module to process several timers with one function call.
 *  Therefore define some timer variables of type timer_var_t,
 *  and use the TIMER_CONFIG macro to create a timer configuration.
 *  All timers are then processed calling the timer_tick function.
 *  \author Ruedisser Christoph (ruc)
 *  \copyright All rights belong to High Q Laser
 *  \version 1.3.0 (338)
 */

#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>


/**Type definition for timer variables (used unit: microseconds) */
typedef uint32_t timer_var_t;
typedef timer_var_t * const timer_array_t[];

#define TIMER_DISABLED ((timer_var_t)-1)

/**Function to process the timer tick.
 * This function processes all timers listed in the given timer configuration.
 * \param timers pointer to a timer configuration.
 * This timer configuration can be created using the TIMER_CONFIG macro
 * \param tick_interval interval between timer ticks in us
 */
void timer_tick(timer_array_t timers, uint32_t tick_interval);

/**Macro to create a timer configuration.
 * (a timer configuration is just an array with pointers to timer variables, the last element of the array has to be NULL)
 * \param name name of the configuration
 * \param ... pointers to timer variables (timer_var_t*)
 * \returns timer value in us
 */
#define TIMER_CONFIG(name, ...) \
            timer_array_t name = {__VA_ARGS__, 0};

#define TIMER_100USEC(h_us) ((timer_var_t)(100l*(h_us)))

/**Macro to compute a timer-value from milliseconds.
 * \param ms time in milliseconds
 * \returns timer value in microseconds
 */
#define TIMER_MSEC(ms) ((timer_var_t)(1000l*(ms)))

/**Macro to compute a timer-value from seconds.
 * \param sec time in seconds
 * \returns timer value in microseconds
 */
#define TIMER_SEC(sec) ((timer_var_t)(1000000l*(sec)))

/**Macro to compute a timer-value from minutes.
 * \param min time in minutes
 * \returns timer value in microseconds
 */
#define TIMER_MIN(min) ((timer_var_t)(60000000l*(min)))
/**Macro to check if timer is running (is not disabled and value greater 0)
 * \param timer timer variable to be checked
 */
#define TIMER_IS_RUNNING(timer) ((timer)!=TIMER_DISABLED && (timer)>0)

/**Macro to check if timer is disabled
 * \param timer timer variable to be checked
 */
#define TIMER_IS_DISABLED(timer) ((timer)==TIMER_DISABLED)

/**Macro to check if timer is expired (value is 0)
 * \param timer timer variable to be checked
 */
#define TIMER_IS_EXPIRED(timer) ((timer)==0)


#endif
