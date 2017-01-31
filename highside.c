/*
 * highside.c
 *
 *  Created on: Jan 31, 2017
 *      Author: patrick
 */

#include "hal.h"
#include "highside.h"

//TODO further abstraction

#define DRV1_CLR	0x01
#define DRV1_CLK	0x02
#define DRV2_CLR	0x04
#define DRV2_CLK	0x08

#define CONTROL_PINS	(DRV1_CLR | DRV1_CLK | DRV2_CLR | DRV2_CLK)

typedef struct {
	GPIO_t *dataPort;
	GPIO_t *ctrlPort;
} hsDriver_t;

hsDriver_t hsDriver;

void highside_init(void) {
	/* Data PORT */
	gpio_enable(PORTB);
	gpio_digitalEnable(GPIOB_AHB, 0xFF);
	gpio_direction(GPIOB_AHB, 0xFF);
	/* Control PORT */
	gpio_enable(PORTE);
	gpio_digitalEnable(GPIOE_AHB, CONTROL_PINS);
	gpio_direction(GPIOE_AHB, CONTROL_PINS);

	hsDriver.dataPort=(GPIO_t *)GPIOB_AHB;
	hsDriver.ctrlPort=(GPIO_t *)GPIOE_AHB;

	hsDriver.dataPort->DATA = 0x00; /* no output at start */
	hsDriver.ctrlPort->DATA = DRV1_CLR | DRV2_CLR; /* clr is active low */
}

static void _clk(GPIO_t *gpioCtrl, uint8_t pin) {
	gpioCtrl->DATA |= pin;
	gpioCtrl->DATA &= ~pin;
}

static void _clr(GPIO_t *gpioCtrl, uint8_t pin) {
	gpioCtrl->DATA &= ~pin;
	gpioCtrl->DATA |= pin;
}

void highside_setOutput(uint16_t bitfield) {
	if(bitfield&0x00FF) {
		hsDriver.dataPort->DATA = (uint8_t)bitfield&0x00FF;
		_clr(hsDriver.ctrlPort, DRV2_CLR);
		_clk(hsDriver.ctrlPort, DRV1_CLK);
	}
	else {
		hsDriver.dataPort->DATA = (uint8_t)((bitfield>>8)&0x00FF);
		_clr(hsDriver.ctrlPort, DRV1_CLR);
		_clk(hsDriver.ctrlPort, DRV2_CLK);
	}
}


