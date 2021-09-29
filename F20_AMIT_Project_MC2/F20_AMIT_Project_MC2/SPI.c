/*
 * SPI.c
 *
 * Created: 9/4/2021 9:34:15 PM
 *  Author: AMR
 */ 
#include "SPI.h"


void SPI_Master_Init(void)
{
	SET_BIT(DDRB,SS);
	SET_BIT(DDRB,MOSI);
	CLR_BIT(DDRB,MISO);
	SET_BIT(DDRB,SCK);
	
	/*
	//Enable SPI without interrupt
	SET_BIT(SPCR,SPE);
	
	//Transmit LSB first
	CLR_BIT(SPCR,DORD);
	
	//Master Select
	SET_BIT(SPCR,MSTR);
	
	//SCK on Rising Edge
	CLR_BIT(SPCR,CPOL);
	
	//set prescalar to 8 bit choose 101
	CLR_BIT(SPSR,SPI2X); SET_BIT(SPCR,SPR1); SET_BIT(SPCR,SPR0);
	*/
	SPCR=0b01010011;
}


void SPI_Slave_Init(void)
{
	CLR_BIT(DDRB,SS);
	CLR_BIT(DDRB,MOSI);
	SET_BIT(DDRB,MISO);
	CLR_BIT(DDRB,SCK);
	
	/*
	//Enable SPI without interrupt
	SET_BIT(SPCR,SPE);
	
	//Transmit LSB first
	CLR_BIT(SPCR,DORD);
	
	//Slave Select
	CLR_BIT(SPCR,MSTR);
	
	//SCK on Rising Edge
	CLR_BIT(SPCR,CPOL);
	
	//set prescalar to 8 bit choose 101
	 SET_BIT(SPCR,SPR1); SET_BIT(SPCR,SPR0);
	*/
	SPCR=0b01000011;
}

void SPI_Trans(uint8_t data)
{
	SPDR=data;
	while(!(SPSR & (1<<SPIF)));
}

uint8_t SPI_Rec(void)
{
	uint8_t data;
	while(GET_BIT(SPSR,SPIF)!=1);
	data=SPDR;
	return data;
}