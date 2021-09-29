/*
* EXT_INT.c
*
* Created: 1/23/2021 8:41:11 PM
*  Author: karim
*/

#include "EXT_INT.h"

void GLOBAL_INTERRUPT_Init(void)
{
	#if GLOBAL_INTERRUPT_STATE == GLOBAL_INTERRUPT_EN
	SET_BIT(SREG, 7);//Enable global interrupt
	#elif GLOBAL_INTERRUPT_STATE == GLOBAL_INTERRUPT_DS
	CLR_BIT(SREG, 7);//Disable global interrupt
	#endif
}
void EXT_INTERRUPT0_Init(void)
{
	/*Enable global interrupt*/
	GLOBAL_INTERRUPT_Init();//Apartment door
	/*Enable External Interrupt 0*/
	SET_BIT(GICR, INT0);//Room door
	//SET_BIT(GICR, 6);
	/*How to trigger an interrupt*/
	#if EXT_INT0_TRIGGER == EXT_INT_TRG_LOW
	
	CLR_BIT(MCUCR, ISC01);CLR_BIT(MCUCR, ISC00);//0-0
	#elif EXT_INT0_TRIGGER == EXT_INT_TRG_ANY_LOGICAL
	CLR_BIT(MCUCR, ISC01);SET_BIT(MCUCR, ISC00);//0-1
	#elif EXT_INT0_TRIGGER == EXT_INT_TRG_FALLING_EDGE
	SET_BIT(MCUCR, ISC01);CLR_BIT(MCUCR, ISC00);//1-0
	#elif EXT_INT0_TRIGGER == EXT_INT_TRG_RISING_EDGE
	SET_BIT(MCUCR, ISC01);SET_BIT(MCUCR, ISC00);//1-1
	#endif
}
void EXT_INTERRUPT1_Init(void)
{
	/*Enable global interrupt*/
	GLOBAL_INTERRUPT_Init();//Apartment door
	/*Enable External Interrupt 1*/
	SET_BIT(GICR, INT1);//Room door
	//SET_BIT(GICR, 7);
	/*How to trigger an interrupt*/
	#if EXT_INT1_TRIGGER == EXT_INT_TRG_LOW
	CLR_BIT(MCUCR, ISC11);CLR_BIT(MCUCR, ISC10);//0-0
	#elif EXT_INT1_TRIGGER == EXT_INT_TRG_ANY_LOGICAL
	CLR_BIT(MCUCR, ISC11);SET_BIT(MCUCR, ISC10);//0-1
	#elif EXT_INT1_TRIGGER == EXT_INT_TRG_FALLING_EDGE
	SET_BIT(MCUCR, ISC11);CLR_BIT(MCUCR, ISC10);//1-0
	#elif EXT_INT1_TRIGGER == EXT_INT_TRG_RISING_EDGE
	SET_BIT(MCUCR, ISC11);SET_BIT(MCUCR, ISC10);//1-1
	#endif
}
void EXT_INTERRUPT2_Init(void)
{
	/*Enable global interrupt*/
	GLOBAL_INTERRUPT_Init();//Apartment door
	/*Enable External Interrupt 1*/
	SET_BIT(GICR, INT2);//Room door
	//SET_BIT(GICR, 5);
	/*How to trigger an interrupt*/
	#if EXT_INT2_TRIGGER == EXT_INT_TRG_ANY_LOGICAL
	SET_BIT(MCUCSR,INT2);
	#elif EXT_INT2_TRIGGER == EXT_INT_TRG_LOW
	CLR_BIT(MCUCSR,INT2);
	#endif
}