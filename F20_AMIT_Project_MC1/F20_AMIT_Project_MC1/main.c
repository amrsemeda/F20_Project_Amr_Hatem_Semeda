#include "LCD.h"
#include "SPI.h"
#include "USART.h"
#include "OUTPUT_Module.h"

int main(void)
{	
	
	uint8_t dta;
	USART_Init();
	SPI_Master_Init();
	LCD_Init();
	LCD_CLEAR();
	
	while(1)
	{
		_delay_ms(10);
		dta=USART_Rec();
		if(dta!=0)
		{
			LCD_CLEAR();
			LCD_WRITE_DTA(dta);
			SPI_Trans(dta);
		}
		dta=0;
	}
	
}