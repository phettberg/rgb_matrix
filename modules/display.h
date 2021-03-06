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

#define WIDTH	8
#define HEIGHT	16

extern timer_var_t timer_display;

void display_drawPixel(int16_t x, int16_t y, uint8_t color);
void display_drawPlane(uint8_t array[][WIDTH]);
void display_process(void);
void display_refresh(uint8_t cp);
void display_clear(void);
uint8_t *display_backbuffer(void);


#endif /* DISPLAY_H_ */
