/*
 * display.h
 *
 *  Created on: Jan 31, 2017
 *      Author: patrick
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <stdint.h>
#include "timer.h"

extern timer_var_t timer_display;
void display_drawPixel(int16_t x, int16_t y, uint8_t color);
void display_process(void);
void display_refresh(void);
void display_clear(void);



#endif /* DISPLAY_H_ */
