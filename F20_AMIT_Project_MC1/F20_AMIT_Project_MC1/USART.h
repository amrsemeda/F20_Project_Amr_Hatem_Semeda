/*
 * USART.h
 *
 * Created: 9/3/2021 9:40:23 PM
 *  Author: AMR
 */ 


#ifndef USART_H_
#define USART_H_

#include "USART_Config.h"

void USART_Init(void);
void USART_Trans(uint8_t data);
uint8_t USART_Rec(void);



#endif /* USART_H_ */