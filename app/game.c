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
#include "string.h"
#include "time.h"

typedef enum {LEFT, DOWN, RIGHT} direction_t;

#define FPS	100

#define PIECEWIDTH 	 4
#define PIECEHEIGHT	 4

typedef enum {OO=0, ZZ, SS, II, JJ, LL, TT } shape_t;

typedef struct {
	uint8_t active;
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

timer_var_t fallingTime_ms;

uint8_t game_start=0;


uint8_t plane[HEIGHT][WIDTH];

#include "tetrominos.h"
uint8_t pieces[7][4][PIECEHEIGHT][PIECEWIDTH] = {O, Z, S, I, J, L, T}; /* TODO move to flash? */


static void getNewPiece(piece_t *piece) {
	uint8_t number;
	number=rand()%(TT+1);

	piece->shape=(shape_t)number;
	piece->rotation=0;
	switch(piece->shape) {
		default:
		case OO: piece->maxrot=0; break;
		case ZZ:
		case SS:
		case II: piece->maxrot=1; break;
		case JJ:
		case LL:
		case TT: piece->maxrot=3; break;
	}
	piece->x=2;
	piece->y=-2;
	piece->active=1;
}

static void addToPlane(piece_t *piece) {
	for(int x=0; x<PIECEWIDTH; ++x) {
		for(int y=0; y<PIECEHEIGHT; ++y) {
			if(pieces[piece->shape][piece->rotation][y][x] != 0) {
				plane[y + piece->y][x + piece->x]=pieces[piece->shape][piece->rotation][y][x];
			}
		}
	}
}

static uint8_t isOnPlane(int16_t x, int16_t y) {
	return (x >= 0 && x < WIDTH && y < HEIGHT);
}

static uint8_t isValidPosition(piece_t *piece, int16_t adjX, int16_t adjY) {
	for(int x=0; x<PIECEWIDTH; ++x) {
		for(int y=0; y<PIECEHEIGHT; ++y) {
			if((y + piece->y + adjY) < 0 || pieces[piece->shape][piece->rotation][y][x] == 0)
				continue;
			if(!isOnPlane(x + piece->x + adjX, y + piece->y + adjY))
				return 0;
			if(plane[y + piece->y + adjY][x + piece->x + adjX] != 0) {
					return 0;
			}
		}
	}
	return 1;
}

static uint8_t isCompleteLine(int16_t y) {
	for(int x=0;x<WIDTH;++x) {
		if(plane[y][x] == 0)
			return 0;
	}
	return 1;
}

static uint8_t removeCompleteLines() {
	uint8_t numLinesRemoved = 0;
	int16_t actY=HEIGHT-1;
	while(actY>=0) {
		if (isCompleteLine(actY)) {
			for(int y=actY;y>=0;y--) {
				for(int x=0;x<WIDTH;++x) {
					plane[y][x] = plane[y-1][x];
				}
			}
			for(int x=0;x<WIDTH;++x) {
				plane[0][x] = 0;
			}
		}
		else actY--;
	}
	return numLinesRemoved;
}

static void drawPiece(piece_t *piece) {
	for(int x=0; x<PIECEWIDTH; ++x) {
		for(int y=0; y<PIECEHEIGHT; ++y) {
			display_drawPixel(piece->x + x, piece->y +y, pieces[piece->shape][piece->rotation][y][x]);
		}
	}
}


void game_init(void) {
	srand(time(NULL));
	fallingTime_ms=1000;
}

void game_restart(void) {
	memset(plane, 0, WIDTH * HEIGHT);
	getNewPiece(&fallingPiece);
	game_start=1;
}

uint8_t game_process(void) {
	if(!game_start) return 0;

	if(!fallingPiece.active) {
		getNewPiece(&fallingPiece);
	}
	if(!isValidPosition(&fallingPiece, 0, 0)) return 0;

	if(leftPressed() && isValidPosition(&fallingPiece, -1, 0)) {
		fallingPiece.x-=1;
	}
	else if(rightPressed() && isValidPosition(&fallingPiece, 1, 0)) {
		fallingPiece.x+=1;
	}
	else if(downPressed() && isValidPosition(&fallingPiece, 0, 1)) {
		fallingPiece.y+=1;
	}
	else if(buttonPressed()) {
		fallingPiece.rotation = (fallingPiece.rotation+1)&fallingPiece.maxrot;
		if(!isValidPosition(&fallingPiece, 0, 0)) {
			fallingPiece.rotation = (fallingPiece.rotation-1)&fallingPiece.maxrot;
		}
	}
	else if(centerPressed()) {
		int16_t yPos;
		for(yPos=1;yPos<HEIGHT;++yPos) {
			if(!isValidPosition(&fallingPiece, 0, yPos)) break;
		}
		fallingPiece.y+=yPos-1;
	}


	if(!timer_falling) {
		if(isValidPosition(&fallingPiece, 0, 1))
			fallingPiece.y++;
		else {
			addToPlane(&fallingPiece);
			removeCompleteLines();
			fallingPiece.active=0;
		}
		timer_falling=TIMER_MSEC(fallingTime_ms);
	}
	display_clear();
	display_drawPlane(plane);
	if(fallingPiece.active) drawPiece(&fallingPiece);
	display_refresh(0);

	if(!timer_fps) {

		timer_fps=TIMER_MSEC((timer_var_t)(1000.0/FPS));
	}
	return 1;
}
