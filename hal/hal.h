/*
 * hal.h
 *
 *  Created on: Jan 30, 2017
 *      Author: patrick
 */

#ifndef HAL_HAL_H_
#define HAL_HAL_H_

#include "TM4C123GH6PM.h"

typedef void(*Callback_t)(uint8_t pin);

void gpio_enable(uint8_t port);
void gpio_direction(GPIOA_Type *gpio, uint8_t pins);
void gpio_digitalEnable(GPIOA_Type *gpio, uint8_t pins);
void gpio_setPullups(GPIOA_Type *gpio, uint8_t pins);
void gpio_alternateFunctions(GPIOA_Type *gpio, uint8_t pins);
void gpio_enableInterrupt(GPIOA_Type *gpio, uint8_t pin, Callback_t callback);



void hal_init();
void hal_process();
void spi_init();
void timer_init();
void TIMER0A_Handler(void);



#endif /* HAL_HAL_H_ */
