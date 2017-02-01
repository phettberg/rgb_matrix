/*
 * display.c
 *
 *  Created on: Jan 31, 2017
 *      Author: patrick
 */

#include "display.h"
#include "highside.h"
#include "lowside.h"
#include "timer.h"

#include "hal.h"

#define WIDTH	8
#define HEIGHT	16

#define RED		0x01
#define GREEN	0x02
#define BLUE	0x04

typedef struct {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
} colBytes_t;

timer_var_t timer_display = TIMER_100USEC(5);

colBytes_t colBytes;
uint16_t actRow = 0x0001;
uint8_t row = 0;

uint8_t matrixbuffer[2][HEIGHT][WIDTH];
uint8_t (*pBuffer)[HEIGHT][WIDTH] = matrixbuffer;

void display_drawPixel(int16_t x, int16_t y, uint8_t color) {
	if(x >= WIDTH || y >= HEIGHT) return;
	matrixbuffer[0][y][x]=color;
}

void display_clear(void) {
	for(int i=0;i<HEIGHT;++i) {
		for(int j=0;j<WIDTH;++j) {
			matrixbuffer[0][i][j]=0;
		}
	}
}

void display_process() {
	if(!timer_display) {
		GPIOF->DATA ^= (1<<2);
		timer_display=TIMER_100USEC(5);
		for(int i=0;i<WIDTH;++i) {
			if(matrixbuffer[0][row][i]&RED) colBytes.red |= (1<<i);
			if(matrixbuffer[0][row][i]&GREEN) colBytes.green |= (1<<i);
			if(matrixbuffer[0][row][i]&BLUE) colBytes.blue |= (1<<i);
		}
		highside_setOutput(0);
		lowside_writeOutput(colBytes.red, colBytes.green, colBytes.blue);
//		highside_setOutput(actRow);
		highside_setOutput(row);
		colBytes.blue=0;
		colBytes.red =0;
		colBytes.green =0;
		actRow = (actRow << 1) | (actRow >> (15));
		row++;
		if(row==16) {
			row=0;
		}
//		row=(row+1)&15;
	}
}
