/*
 * ADC_Address.h
 *
 * Created: 8/21/2021 9:17:13 PM
 *  Author: karim
 */ 


#ifndef ADC_ADDRESS_H_
#define ADC_ADDRESS_H_


#include "CPU_Configurations.h"
/************************************** ADC-Registers *******************************************/
/*
#define ADMUX   (*(volatile Uint8t*) (0x27))
#define ADCSRA  (*(volatile Uint8t*) (0x26))
#define ADCH    (*(volatile Uint8t*) (0x25))
#define ADCL    (*(volatile Uint8t*) (0x24))
*/
#define ADC_DTA (*(volatile uint16_t*)(0x24))

#define ADC_AVCC    0
#define ADC_AREF    1
#define ADC_INteral 2

#define ADC_Vref ADC_AVCC

#endif /* ADC_ADDRESS_H_ */