/*
 * main.c
 */

#include "main.h"
#include "hal.h"
#include "timer.h"
#include "control.h"
#include "highside.h"
#include "lowside.h"
#include "display.h"
#include "game.h"


TIMER_CONFIG (timers,
		&timer_display,
		&timer_debounce,
		&timer_fps,
		&timer_falling
)

int main(void) {
	hal_init();
	control_init();
	highside_init();
	lowside_init();
	game_init();
	display_clear();

	while(1) {
		hal_process();
		control_process();
		display_process();
		if(!game_process()) {
			if(buttonPressed()) game_restart();
		}
	}
}
