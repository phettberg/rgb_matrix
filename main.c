/*
 * main.c
 */

#include "main.h"
#include "hal.h"
#include "timer.h"
#include "control.h"
#include "highside.h"
#include "lowside.h"

void wait2(void);


timer_var_t timer_display = TIMER_MSEC(1);
timer_var_t timer_data = TIMER_MSEC(500);

TIMER_CONFIG (timers,
		&timer_display,
		&timer_data
)

uint8_t data;


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

	while(1) {

		hal_process();
		if(downPressed()) data=0x18;
		if(leftPressed()) data=0x03;
		if(rightPressed()) data=0xC0;
		if(buttonPressed()) data=0xAA;
		if(centerPressed()) data=0x55;
		if(!timer_display) {
			timer_display=TIMER_100USEC(5);
			lowside_writeOutput(data, 0, data);
			highside_setOutput(row);
			row = (row << 1) | (row >> (15));
			GPIOF->DATA ^= (1<<2);
		}
		if(!timer_data) {
		  timer_data=TIMER_SEC(1);
		  data = (data << 1) | (data >> (7));
		  GPIOF->DATA ^= (1<<3);
		}
	}

}
