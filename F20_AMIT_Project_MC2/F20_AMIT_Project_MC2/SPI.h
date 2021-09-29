/*
 * SPI.h
 *
 * Created: 9/4/2021 8:22:15 PM
 *  Author: AMR
 */ 

#include "SPI_Config.h"
#ifndef SPI_H_
#define SPI_H_

void SPI_Master_Init(void);
void SPI_Slave_Init(void);
void SPI_Trans(uint8_t data);
uint8_t SPI_Rec(void);




#endif /* SPI_H_ */