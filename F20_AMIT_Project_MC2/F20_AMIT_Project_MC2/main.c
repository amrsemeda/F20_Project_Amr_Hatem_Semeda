#include "SPI.h"
#include "LCD.h"
#include "OUTPUT_Module.h"


int main(void)
{
	uint8_t dta;
	
	LCD_Init();
	LCD_CLEAR();
	SPI_Slave_Init();
	LED0_Initialize();
	LED1_Initialize();
	LED2_Initialize();
	
	while(1){
		
		dta=SPI_Rec();
		if(dta!=0)
		{
			LCD_CLEAR();
			if(dta=='0')
				{	
					LCD_WRITE_STR((uint8_t*)"LED ");
					LCD_WRITE_DTA(dta);
					LED0_Toggle();
				}
				else if(dta=='1')
				{
					LCD_WRITE_STR((uint8_t*)"LED ");
					LCD_WRITE_DTA(dta);
					LED1_Toggle();
				}
				else if(dta=='2')
				{	
					LCD_WRITE_STR((uint8_t*)"LED ");
					LCD_WRITE_DTA(dta);
					LED2_Toggle();
				}
				else
				{
					LCD_WRITE_STR((uint8_t*)"Enter valid LED");
				}
				
			dta=0;
		}
	}
}