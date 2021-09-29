/*
 * USART.c
 *
 * Created: 9/3/2021 9:39:54 PM
 *  Author: AMR
 */ 
#include "USART.h"
void USART_Init(void)
{	
	
	/*Baud rate value variable*/
	uint16_t UBRR_Val = 0;
	/*Enable Transmitter and Receiver bits*/
	UCSRB = (1 << RXEN) | (1 << TXEN);
	/*Full configuration for UART*/
	UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
	/*Baud Rate Calculations*/
	UBRR_Val = (CLK/((baud_rate*16)-1));//11110101 00111001
	UBRRL = UBRR_Val;     //00000000 00111001
	UBRRH = UBRR_Val >> 8;//00000000 11110101
	
}

void USART_Trans(uint8_t data)
{	UDR=data;
	while(GET_BIT(UCSRA,TXC)!=1);
	
}
uint8_t USART_Rec(void)
{	
	
	while(GET_BIT(UCSRA,RXC)!=1);
	return UDR;
	
}
