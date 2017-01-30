/*
 * main.c
 */

#include "main.h"
#include "TM4C123GH6PM.h"
#include "hal.h"
#include "timer.h"
#include "control.h"

void wait(void);
void wait2(void);

#define FLAG_NONE 0x00000000
#define FLAG_TOGGLE_LED 0x00000001

volatile uint32_t flags = FLAG_NONE;

timer_var_t timer_display = TIMER_MSEC(1);
timer_var_t timer_data = TIMER_MSEC(500);

TIMER_CONFIG (timers,
		&timer_display,
		&timer_data
)

uint8_t data;

void writeSPI(uint8_t data) {
	SSI3->DR = data;
	while( (SSI3->SR & (1<<0))==0);
}

void clk_1(void) {
	GPIOE->DATA |= 0x02;
	GPIOE->DATA &= ~0x02;
}

void clk_2(void) {
	GPIOE->DATA |= 0x08;
	GPIOE->DATA &= ~0x08;
}

void clr_1(void) {
	GPIOE->DATA &= ~0x01;
	GPIOE->DATA |= 0x01;
}

void clr_2(void) {
	GPIOE->DATA &= ~0x04;
	GPIOE->DATA |= 0x04;
}

void write(uint8_t data) {
//	GPIOD->DATA &= ~(1<<1);
//	GPIOD->DATA |= (1<<6);
	writeSPI(data);
	writeSPI(0);
	writeSPI(data);
	writeSPI(0);
	writeSPI(data);
	writeSPI(data);
	wait2();
	GPIOD->DATA |= (1<<1);
	GPIOD->DATA &= ~(1<<1);
	//wait2();
	GPIOD->DATA &= ~(1<<6);
}





int main(void) {
	// LED
	SYSCTL->RCGCGPIO = PORTF;
	GPIOF->AFSEL &= ~((1<<2)|(1<<3));
	GPIOF->DIR = (1<<2)|(1<<3);
	GPIOF->DEN = (1<<2)|(1<<3);
	GPIOF->DATA |= (1<<3);


	hal_init();
	control_init();



	// High Side Control
	SYSCTL->RCGCGPIO |= PORTB | PORTE;
	GPIOB->DEN |= 0xFF;
	GPIOB->DIR |= 0xFF;
	GPIOE->DEN |= 0x0F;
	GPIOE->DIR |= 0x0F;

	GPIOD->DATA &= ~(1<<1);
	GPIOD->DATA |= (1<<1);
	GPIOD->DATA |= (1<<6);

	//SPI Byte
	data=0x03;



	uint16_t row = 0x0001;
	GPIOB->DATA = (uint8_t)row;

	GPIOE->DATA |= 0x05; // Set clr to high

	write(0);

	while(1) {
		hal_process();
		if(downPressed()) data=0x18;
		if(leftPressed()) data=0x03;
		if(rightPressed()) data=0xC0;
		if(buttonPressed()) data=0xAA;
		if(centerPressed()) data=0x55;
		if(!timer_display) {
			timer_display=TIMER_100USEC(1);
			write(data);
			if(row&0x00FF) {
				GPIOB->DATA = (uint8_t)row&0x00FF;
				clr_2();
				clk_1();
			}
			else {
				GPIOB->DATA = (uint8_t)((row>>8)&0x00FF);
				clr_1();
				clk_2();
			}

//			row = (row << 1) | (row >> (7));
			row = (row << 1) | (row >> (15));
			GPIOF->DATA ^= (1<<2);
			flags = FLAG_NONE;
		}
		if(!timer_data) {
		  timer_data=TIMER_SEC(1);
		  data = (data << 1) | (data >> (7));
		  GPIOF->DATA ^= (1<<3);
		}
	}

}

void wait() {
	int clockCounter=0;
	while(clockCounter++ < 1000000);
}

void wait2() {
	int clockCounter=0;
	while(clockCounter++ < 10);
}
