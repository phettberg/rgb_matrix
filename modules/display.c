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
#include "string.h"

#include "hal.h"

#define RED		0x01
#define GREEN	0x02
#define BLUE	0x04

typedef struct {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
} colBytes_t;

timer_var_t timer_display;;

colBytes_t colBytes;
uint16_t actRow = 0x0001;
uint8_t row = 0;

uint8_t matrixbuffer[2][HEIGHT][WIDTH];
uint8_t (*pBuffer)[HEIGHT][WIDTH] = matrixbuffer;
uint8_t backindex=0;
uint8_t swapBuffer=0;
uint8_t copy=0;

void display_drawPixel(int16_t x, int16_t y, uint8_t color) {
	if(!color) return;
	if(x <0 || x >= WIDTH || y < 0 || y >= HEIGHT) return;
	matrixbuffer[backindex][y][x]=color;
}

void display_drawPlane(uint8_t array[][WIDTH]) {
	memcpy(matrixbuffer[backindex], array, WIDTH * HEIGHT);
}

void display_clear(void) {
	memset(matrixbuffer[backindex], 0, WIDTH * HEIGHT);
}

void display_refresh(uint8_t cp) {
	copy=cp;
	swapBuffer=1;
}

void display_process() {
	if(!timer_display) {
		if(!row && swapBuffer) {
			backindex=1-backindex;
			if(copy) memcpy(matrixbuffer[backindex], matrixbuffer[1-backindex], WIDTH * HEIGHT);
			swapBuffer=0;
			copy=0;
		}
		for(int col=0;col<WIDTH;++col) {
			if(matrixbuffer[1-backindex][row][col]&RED)  colBytes.red   |= (1<<col);
			if(matrixbuffer[1-backindex][row][col]&GREEN)colBytes.green |= (1<<col);
			if(matrixbuffer[1-backindex][row][col]&BLUE) colBytes.blue  |= (1<<col);
		}
		highside_clearOutput(); /* Disable rows */
		lowside_writeOutput(colBytes.red, colBytes.green, colBytes.blue); /* Set column pixel for current row */
		highside_setOutput(row); /* Enable current row */
		colBytes.blue=0;
		colBytes.red =0;
		colBytes.green =0;
		row=(row+1)&15;
		timer_display=TIMER_100USEC(6);
	}
}

uint8_t *display_backbuffer() {
	return &matrixbuffer[backindex][0][0];
}
