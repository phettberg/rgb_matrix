/*
 * control.h
 *
 *  Created on: Jan 31, 2017
 *      Author: patrick
 */

#ifndef CONTROL_H_
#define CONTROL_H_

#include "timer.h"

//typedef struct {
//	uint8_t left;
//	uint8_t right;
//	uint8_t down;
//	uint8_t center;
//	uint8_t button;
//} input_t;

extern timer_var_t timer_debounce;

void control_init(void);
uint8_t downPressed(void);
uint8_t leftPressed(void);
uint8_t rightPressed(void);
uint8_t buttonPressed(void);
uint8_t centerPressed(void);

#endif /* CONTROL_H_ */
