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

timer_var_t timer_data = TIMER_MSEC(500);

TIMER_CONFIG (timers,
		&timer_display,
		&timer_data,
		&timer_debounce,
		&timer_fps,
		&timer_falling,
		&timer_moveSideways,
		&timer_moveDown
)

int16_t x=0;
int16_t y=0;


int main(void) {
	// LED
	SYSCTL->RCGCGPIO = PORTF;
	GPIOF->AFSEL &= ~((1<<2)|(1<<3)|(1<<1));
	GPIOF->DIR = (1<<2)|(1<<3)|(1<<1);
	GPIOF->DEN = (1<<2)|(1<<3)|(1<<1);
	GPIOF->DATA |= (1<<3);


	hal_init();
	control_init();
	highside_init();
	lowside_init();
	game_init();

	display_clear();
//	display_drawPixel(0, 0, 0x01);
//	display_drawPixel(1, 0, 0x02);
//	display_drawPixel(2, 0, 0x04);
//	display_drawPixel(3, 0, 0x01);
//	display_drawPixel(4, 0, 0x02);
//	display_drawPixel(5, 0, 0x04);
//	display_drawPixel(6, 0, 0x01);
//	display_drawPixel(7, 0, 0x02);
//
//	display_drawPixel(0, 15, 0x03);
//	display_drawPixel(1, 15, 0x05);
//	display_drawPixel(2, 15, 0x06);
//	display_drawPixel(3, 15, 0x07);
//	display_drawPixel(4, 15, 0x03);
//	display_drawPixel(5, 15, 0x05);
//	display_drawPixel(6, 15, 0x06);
//	display_drawPixel(7, 15, 0x07);
//
//	display_drawPixel(0, 8, 0x01);
//	display_drawPixel(1, 8, 0x02);
//	display_drawPixel(2, 8, 0x04);
//	display_drawPixel(3, 8, 0x01);
//	display_drawPixel(4, 8, 0x02);
//	display_drawPixel(5, 8, 0x04);
//	display_drawPixel(6, 8, 0x01);
//	display_drawPixel(7, 8, 0x02);
//	display_refresh();

	while(1) {

		hal_process();
		control_process();
		display_process();
		game_process();

//		if(downPressed()) {
//			y=(y<15) ? ++y : y;
//			display_drawPixel(x, y, 0x03);
//			display_refresh();
//		}
//		if(leftPressed()) {
//			x=(x>0) ? --x : x;
//			display_drawPixel(x, y, 0x03);
//			display_refresh();
//		}
//		if(rightPressed()) {
//			x=(x<7) ? ++x : x;
//			display_drawPixel(x, y, 0x03);
//			display_refresh();
//		}
//		if(buttonPressed()) {
//			x=3;y=0;
//			display_clear();
//		}
//		if(centerPressed()) {
//			y=(y>0) ? --y : y;
//			display_drawPixel(x, y, 0x03);
//			display_refresh();
//		}
//
		if(!timer_data) {
		  timer_data=TIMER_SEC(1);
		  GPIOF->DATA ^= (1<<3);
		}
	}
}
