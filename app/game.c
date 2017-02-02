/*
 * game.c
 *
 *  Created on: Feb 1, 2017
 *      Author: patrick
 */

#include "game.h"
#include "display.h"
#include "control.h"
#include "stdlib.h"
#include "time.h"

typedef enum {LEFT, DOWN, RIGHT} direction_t;

#define FPS	25

#define PIECEWIDTH 	 4
#define PIECEHEIGHT	 4

typedef enum {OO=0, ZZ, SS, II, JJ, LL, TT } shape_t;

typedef struct {
	shape_t shape;
	uint8_t rotation;
	uint8_t maxrot;
	int16_t x;
	int16_t y;
} piece_t;

direction_t direction;
piece_t fallingPiece;

timer_var_t timer_fps;
timer_var_t timer_falling;
timer_var_t timer_moveSideways;
timer_var_t timer_moveDown;

/* TODO move to flash? */
uint8_t pieces[7][4][PIECEHEIGHT][PIECEWIDTH] = {O, Z, S, I, J, L, T};


void getNewPiece(piece_t *piece) {
	uint8_t number;
	srand(time(NULL));
	number=rand()%TT+1;

	piece->shape=(shape_t)number;
	piece->rotation=0;
	switch(piece->shape) {
		case OO: piece->maxrot=0; break;
		case ZZ:
		case SS:
		case II: piece->maxrot=1; break;
		case JJ:
		case LL:
		case TT: piece->maxrot=3; break;
	}
//	piece.x=(int16_t)(WIDTH/2)-(int16_t)(PIECEWIDTH/2);
//	piece.y=-2;
	piece->x=2;
	piece->y=-2;
}

static void addToBoard(piece_t *piece) {
	for(int x=0; x<PIECEWIDTH; ++x) {
		for(int y=0; y<PIECEHEIGHT; ++y) {
			if(pieces[piece->shape][piece->rotation][y][x] != 0) {
				matrixbuffer[backindex][x + piece->x][y + piece->y]=pieces[piece->shape][piece->rotation][y][x];
			}
		}
	}
}

static uint8_t isOnBoard(int16_t x, int16_t y) {
	return (x >= 0 && x < WIDTH && y < HEIGHT);
}

static uint8_t isValidPosition(piece_t *piece, int16_t adjX, int16_t adjY) {
	for(int x=0; x<PIECEWIDTH; ++x) {
		for(int y=0; y<PIECEHEIGHT; ++y) {
			if((y + piece->y + adjY) < 0 || pieces[piece->shape][piece->rotation][y][x] == 0)
				continue;
			if(!isOnBoard(x + piece->x + adjX, y + piece->y + adjY))
				return 0;
			if(matrixbuffer[backindex][x + piece->x + adjX][y + piece->y + adjY] != 0)
				return 0;
		}
	}
	return 1;
}

//static uint8_t isValidPosition(piece_t *piece, int16_t adjX, int16_t adjY) {
//	for(int x=0; x<PIECEWIDTH; ++x) {
//		for(int y=0; y<PIECEHEIGHT; ++y) {
//			if((y + piece->y + adjY) < 0 || pieces[piece->shape][piece->rotation][y][x] == 0)
//				continue;
//			if(!isOnBoard(x + piece->x + adjX, y + piece->y + adjY))
//				return 0;
//			if(matrixbuffer[backindex][x + piece->x + adjX][y + piece->y + adjY] != 0)
//				return 0;
//		}
//	}
//	return 1;
//}

uint8_t isCompleteLine(int16_t y) {
	for(int x=0;x<WIDTH;++x) {
		if(matrixbuffer[backindex][x][y] == 0)
			return 0;
	return 1;
	}
}

uint8_t removeCompleteLines() {
	uint8_t numLinesRemoved = 0;
	uint8_t y=HEIGHT - 1;
	while(y>=0) {
		if (isCompleteLine(y)) {
			for(int z=y;z>=0;--z){
				for(int x=0;x<WIDTH;++x) {
					matrixbuffer[backindex][x][z] = matrixbuffer[backindex][x][z-1];
				}
			}
			for(int x=0;x<WIDTH;++x) {
				matrixbuffer[backindex][x][0] = 0;
			}
			numLinesRemoved++;
		}
		else {
			y--;
		}
	}
	return numLinesRemoved;
}

void drawPiece(piece_t *piece) {
	for(int x=0; x<PIECEWIDTH; ++x) {
		for(int y=0; y<PIECEHEIGHT; ++y) {
			display_drawPixel(piece->x + x, piece->y +y, pieces[piece->shape][piece->rotation][y][x]);
		}
	}
}




uint8_t movingDown = 0;
uint8_t movingLeft = 0;
uint8_t movingRight = 0;
uint8_t begin = 0;

void game_init(void) {
}

void game_process(void) {
	if(!begin) getNewPiece(&fallingPiece);
	begin=1;

	if(leftPressed() && isValidPosition(&fallingPiece, -1, 0)) {
		fallingPiece.x-=1;
		movingLeft = 1;
	}
	else if(rightPressed() && isValidPosition(&fallingPiece, 1, 0)) {
		fallingPiece.x+=1;
		movingRight = 1;
	}
	else if(buttonPressed()) {
		fallingPiece.rotation = (fallingPiece.rotation+1)&fallingPiece.maxrot;
		if(!isValidPosition(&fallingPiece, 0, 0)) {
			fallingPiece.rotation = (fallingPiece.rotation-1)&fallingPiece.maxrot;
		}
	}
	else if(downPressed() && isValidPosition(&fallingPiece, 0, 1)) {
		fallingPiece.y+=1;
		movingDown = 1;
	}

	if(!timer_falling) {
//		display_clear();
//		if(!isValidPosition(&fallingPiece, 0, 1)) {
////			addToBoard(&fallingPiece);
////			removeCompleteLines();
//			begin=0;
//		}
//		else {
//			fallingPiece.y++;
//		}
		fallingPiece.y++;
		if(fallingPiece.y==15) getNewPiece(&fallingPiece);
		timer_falling=TIMER_MSEC(600);
	}

	drawPiece(&fallingPiece);

	if(!timer_fps) {

		display_refresh();
		timer_fps=TIMER_MSEC((timer_var_t)(1000.0/FPS));
	}
}
