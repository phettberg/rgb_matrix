/*
 * hal.c
 *
 *  Created on: Jan 30, 2017
 *      Author: patrick
 */
#include "TM4C123GH6PM.h"
#include "main.h"
#include "hal.h"
#include "timer.h"
#include "display.h"


/* GPIO */
#define MAX_PINS (8)
static Callback_t PORTA_callbacks[MAX_PINS] = {0};

void GPIOA_Handler(void) {
	for (int pin = 0; pin < MAX_PINS; pin++) {
		if ((GPIOA_AHB->RIS & (1 << pin))  !=0) {
			if (PORTA_callbacks[pin] != 0) {
//				GPIOA_AHB->IM &= ~(1<<pin);
				PORTA_callbacks[pin](pin);
//				GPIOA_AHB->IM |= (1<<pin);
			}
			GPIOA_AHB->ICR |= (1 << pin);
		}
	}
}

void gpio_enable(uint8_t port) {
	SYSCTL->RCGCGPIO |= port;
	SYSCTL->GPIOHBCTL |= port;
}

void gpio_direction(GPIOA_Type *gpio, uint8_t pins) {
	gpio->DIR |= pins;
}

void gpio_digitalEnable(GPIOA_Type *gpio, uint8_t pins) {
	gpio->DEN |= pins;
}

void gpio_setPullups(GPIOA_Type *gpio, uint8_t pins) {
	gpio->PUR |= pins;
}

void gpio_alternateFunctions(GPIOA_Type *gpio, uint8_t pins) {
	gpio->AFSEL |= pins;
}

void _enableNVIC(GPIOA_Type* gpio){
	if(gpio == GPIOA_AHB){
		NVIC_EnableIRQ(GPIOA_IRQn);
	}else if(gpio == GPIOB_AHB){
		NVIC_EnableIRQ(GPIOB_IRQn);
	}else if(gpio == GPIOC_AHB){
		NVIC_EnableIRQ(GPIOC_IRQn);
	}else if(gpio == GPIOD_AHB){
		NVIC_EnableIRQ(GPIOD_IRQn);
	}else if(gpio == GPIOE_AHB){
		NVIC_EnableIRQ(GPIOE_IRQn);
	}else if(gpio == GPIOF_AHB){
		NVIC_EnableIRQ(GPIOF_IRQn);
	}
}

void gpio_enableInterrupt(GPIOA_Type *gpio, uint8_t pin, Callback_t callback) {
	_enableNVIC(gpio);
	gpio->IM &= ~(1<<pin);	// Disable Interrupts for GPIO-Pin of Button (GPIOIM)
	gpio->IS &= ~(1<<pin);	// Configure Interrupts for Falling Edges for GPIO-Pin of Button (GPIOIS, GPIOIBE, GPIOIEV)
	gpio->IBE &= ~(1<<pin);
	gpio->IEV &= ~(1<<pin);
	gpio->ICR |= (1<<pin);	// Clear Interrupts for GPIO-Pin of Button (GPIOICR)
	gpio->IM |= (1<<pin);	// Enable Interrupts for GPIO-Pin of Button (GPIOIM
	(void)callback;
	if(gpio == GPIOA_AHB) {
		PORTA_callbacks[pin] = callback;
	}
}


/* SPI - enable SSI3 */
void spi_init(void) {
	SYSCTL->RCGCSSI = (1<<3); // Enable SSI3 module
	gpio_enable(PORTD);
	gpio_alternateFunctions(GPIOD_AHB, 0x0D);
	gpio_digitalEnable(GPIOD_AHB, 0x0D);
	gpio_direction(GPIOD_AHB, 0x02);
	GPIOD_AHB->PCTL |= (1<<0) | (1<<8) | (1<<12); //SSI3 PortMux for PD0(SCK), PD2(SDI), PD3(SDO)
	SSI3->CR1 &= ~(1<<1);  // disable SPI - clear SSE bit
	SSI3->CR1 = 0x00000000; //Select SSI3 as master
	SSI3->CC = 0x00; // Use system clk as clk source
	SSI3->CPSR = 10; // Clk prescaler
	SSI3->CR0 = (0x7<<0); // 8 data bits, Freescale SPI mode (CPOL0, CPH0)
	SSI3->CR1 |= (1<<1); // enable SPI - set SSE bit
}

void writeSPI(uint8_t data) {
	SSI3->DR = data;
	while( (SSI3->SR & (1<<0))==0); // wait until fifo is empty
}

/* TIMER - Periodic timer module */
void timer_init(void) {
	SYSCTL->RCGCTIMER |= (1<<0); // Enable GPTM 0
	TIMER0->CTL &= ~(1<<0); // Disable timer (clear Timer A Enable)
	TIMER0->CFG = 0x00000000; // 16/32 bit timer
	TIMER0->TAMR |= (0x2<<0); // Mode register - 0x2 for periodic mode
	TIMER0->TAMR &= ~(1<<4); // Count direction - set to 0 for down counter
	TIMER0->TAILR = 1600; // start value in interrupt load register
	TIMER0->IMR |= (1<<0); // enable Timer A time-out interrupt mask
	//NVIC->ISER[0] |= (1<<19);
	NVIC_EnableIRQ(TIMER0A_IRQn); // NVIC interrupt set enable
	TIMER0->CTL |= (1<<0); // Enable timer
}

static uint8_t timer_100us=0;

void TIMER0A_Handler(void) {
	TIMER0->ICR |= (1<<0);  // clear interrupt
	timer_100us++;
}


void hal_init(void) {
	timer_init();
	spi_init();
}

void hal_process(void) {
	if(timer_100us) {
		TIMER0->IMR &= ~(1<<0); // make timer_tick interrupt-safe
		timer_tick(timers, timer_100us*100);
		timer_100us=0;
		TIMER0->IMR |= (1<<0);
	}

}
