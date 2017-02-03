/*
 * game.h
 *
 *  Created on: Feb 1, 2017
 *      Author: patrick
 */

#ifndef GAME_H_
#define GAME_H_

#include "timer.h"

extern timer_var_t timer_fps;
extern timer_var_t timer_falling;

void game_init(void);
uint8_t game_process(void);
void game_restart(void);


#endif /* GAME_H_ */
