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

//timer_var_t timer_display = TIMER_MSEC(1);
timer_var_t timer_data = TIMER_MSEC(500);

TIMER_CONFIG (timers,
		&timer_display,
		&timer_data,
		&timer_debounce
)

uint8_t data;
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


	//SPI Byte
	data=0x03;

	uint16_t row = 0x0001;
	display_clear();
	display_drawPixel(0, 0, 0x01);
	display_drawPixel(1, 0, 0x02);
	display_drawPixel(2, 0, 0x04);
	display_drawPixel(3, 0, 0x01);
	display_drawPixel(4, 0, 0x02);
	display_drawPixel(5, 0, 0x04);
	display_drawPixel(6, 0, 0x01);
	display_drawPixel(7, 0, 0x02);

	display_drawPixel(0, 5, 0x01);
	display_drawPixel(1, 5, 0x02);
	display_drawPixel(2, 5, 0x04);
	display_drawPixel(3, 5, 0x01);
	display_drawPixel(4, 5, 0x02);
	display_drawPixel(5, 5, 0x04);
	display_drawPixel(6, 5, 0x01);
	display_drawPixel(7, 5, 0x02);

	while(1) {

		hal_process();
//		if(downPressed()) data=0x18;
//		if(leftPressed()) data=0x03;
//		if(rightPressed()) data=0xC0;
//		if(buttonPressed()) data=0xAA;
//		if(centerPressed()) data=0x55;
		if(downPressed()) {
			y=(y<15) ? ++y : y;
			display_drawPixel(x, y, 0x03);
		}
		if(leftPressed()) {
			x=(x>0) ? --x : x;
			display_drawPixel(x, y, 0x03);
		}
		if(rightPressed()) {
			x=(x<7) ? ++x : x;
			display_drawPixel(x, y, 0x03);
		}
		if(buttonPressed()) {
			y=(y<15) ? ++y : y;
			display_drawPixel(x, y, 0x03);
//			display_clear();
		}
		if(centerPressed()) {
			y=(y>0) ? --y : y;
			display_drawPixel(x, y, 0x03);
		}


//		display_drawPixel(2, 4, 0x03);
		display_process();
//		if(!timer_display) {
//			timer_display=TIMER_100USEC(5);
//			lowside_writeOutput(data, 0, data);
//			highside_setOutput(row);
//			row = (row << 1) | (row >> (15));
//			GPIOF->DATA ^= (1<<2);
//		}
		if(!timer_data) {
		  timer_data=TIMER_SEC(1);
		  data = (data << 1) | (data >> (7));
		  GPIOF->DATA ^= (1<<3);
		}
	}

}
