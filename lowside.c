/*
 * lowside.c
 *
 *  Created on: Jan 31, 2017
 *      Author: patrick
 */

//TODO UGLY... abstraction pls ;(

#include "hal.h"
#include "lowside.h"

#define LATCH_EN		0x02
#define OUT_EN			0x40
#define CONTROL_PINS	(LATCH_EN | OUT_EN)

GPIO_t *ctrlPort;

void lowside_init(void) {
	gpio_enable(PORTD);
	gpio_digitalEnable(GPIOD_AHB, CONTROL_PINS);
	gpio_direction(GPIOD_AHB, CONTROL_PINS);

	ctrlPort=(GPIO_t *)GPIOD_AHB;
	ctrlPort->DATA &= ~OUT_EN;  /* out enable is active low */
}


static void _clk(GPIO_t *gpioCtrl, uint8_t pin) {
	gpioCtrl->DATA |= pin;
	gpioCtrl->DATA &= ~pin;
}

//TODO UGLY... do it the right way if time is left...
static void _wait() {
	int clockCounter=0;
	while(clockCounter++ < 10);
}


void lowside_writeOutput(uint8_t byte_r, uint8_t byte_g, uint8_t byte_b) {
	writeSPI(byte_b);
	writeSPI(byte_g);
	writeSPI(byte_r);
	writeSPI(byte_b);
	writeSPI(byte_g);
	writeSPI(byte_r);
	_wait();
	_clk(ctrlPort, LATCH_EN);
}


