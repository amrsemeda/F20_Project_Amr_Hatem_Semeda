/*
 * KEYPAD.h
 *
 * Created: 1/22/2021 10:06:46 PM
 *  Author: karim
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "KEYPAD_CONFIG.h"

void KEYPAD_Init(void);/*Initialize keypad*/

uint8_t KEYPAD_READ(void);/*Read keypad value*/




#endif /* KEYPAD_H_ */