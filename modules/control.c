/*
 * control.c
 *
 *  Created on: Jan 31, 2017
 *      Author: patrick
 */

//TODO debounce

#include "hal.h"
#include "control.h"

timer_var_t timer_debounce;

#define DOWN 	0x04
#define LEFT 	0x08
#define RIGHT 	0x10
#define BUTTON 	0x20
#define CENTER 	0x40

#define PINS  		( DOWN | LEFT | RIGHT | BUTTON | CENTER )
#define DIRECTIONS  ~PINS

uint8_t inputFlags = 0;
uint8_t debounceFlags = 0;
uint8_t debounce = 0;

uint8_t downPressed(void) {
	if(!(inputFlags & DOWN)) return 0;
	inputFlags &= ~DOWN;
	return 1;
}

uint8_t leftPressed(void) {
	if(!(inputFlags & LEFT)) return 0;
	inputFlags &= ~LEFT;
	return 1;
}

uint8_t rightPressed(void) {
	if(!(inputFlags & RIGHT)) return 0;
	inputFlags &= ~RIGHT;
	return 1;
}

uint8_t buttonPressed(void) {
	if(!(inputFlags & BUTTON)) return 0;
	inputFlags &= ~BUTTON;
	return 1;
}

uint8_t centerPressed(void) {
	if(!(inputFlags & CENTER)) return 0;
	inputFlags &= ~CENTER;
	return 1;
}

void _callback(uint8_t pin) {
	debounceFlags |= (1<<pin);
	if(!debounce) timer_debounce=TIMER_MSEC(170);
	debounce=1;

}

void control_process(void) {
	if(!timer_debounce && debounce==1) {
		inputFlags = debounceFlags;
		debounceFlags=0x00;
		debounce=0;
	}
}

void control_init(void) {
	gpio_enable(PORTA);
	gpio_direction(GPIOA_AHB, DIRECTIONS);
	gpio_setPullups(GPIOA_AHB, PINS);
	gpio_digitalEnable(GPIOA_AHB, PINS);
	gpio_enableInterrupt(GPIOA_AHB, 2, _callback);
	gpio_enableInterrupt(GPIOA_AHB, 3, _callback);
	gpio_enableInterrupt(GPIOA_AHB, 4, _callback);
	gpio_enableInterrupt(GPIOA_AHB, 5, _callback);
	gpio_enableInterrupt(GPIOA_AHB, 6, _callback);
}


