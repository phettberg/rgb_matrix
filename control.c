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

//void (*moveDown_cb) (void);
//void (*moveLeft_cb) (void);
//void (*moveRight_cb) (void);
//void (*button_cb) (void);
//void (*center_cb) (void);

//void callback(uint8_t pin) {
//	if (pin == 2 && moveDown_cb) {
//		moveDown_cb();
//	}
//	if (pin == 3 && moveLeft_cb) {
//			moveLeft_cb();
//	}
//	if (pin == 4 && moveRight_cb) {
//			moveRigth_cb();
//	}
//	if (pin == 5 && button_cb) {
//			button_cb();
//	}
//	if (pin == 6 && center_cb) {
//			center_cb();
//	}
//}

static uint8_t debounce(uint8_t pin) {
  static uint8_t button_state;
  static uint8_t button_cnt;

  if(!timer_debounce) {
	uint8_t input=pin;
    if(input != button_state) {
      button_cnt--;
      if(button_cnt ==  255) {
        button_cnt=3;
        button_state=input;
        if(input) return 1;
      }
    }
    else button_cnt=3;
    timer_debounce=TIMER_MSEC(2);

  }
  return 0;
}

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
//	if(debounce(pin)) inputFlags |= (1<<pin);
	inputFlags |= (1<<pin);
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
//	gSW1Callback = cb;
}


