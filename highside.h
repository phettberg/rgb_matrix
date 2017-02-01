/*
 * highside.h
 *
 *  Created on: Jan 31, 2017
 *      Author: patrick
 */

#ifndef HIGHSIDE_H_
#define HIGHSIDE_H_

#include <stdint.h>

void highside_init(void);
//void highside_setOutput(uint16_t bitfield);
void highside_setOutput(uint8_t);
void highside_clearOutput(void);


#endif /* HIGHSIDE_H_ */
