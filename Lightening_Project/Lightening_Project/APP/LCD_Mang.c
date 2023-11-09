#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"

#include "DIO_Interface.h"

extern DIO_Pin_type LED_Pins[];
extern DIO_Pin_type PB_Pins[];

extern volatile u8 ON_flag_Index[4];
extern u8 FlashingSpeed_flag[4];

void LCD_Mang(void)
{
	u8 Index;
	
	for(Index = 0; PB_Pins[Index] <= PIND3; Index++)
	{
		LCD_SetCursor(Index,0);
		LCD_WriteString("LED ");
		LCD_WriteNumber((u32)Index);
		if (ON_flag_Index[Index] == 0)
		{

			LCD_WriteString(" : OFF           ");
			continue;
			
		}
		if (ON_flag_Index[Index] == 1)
		{
			if (FlashingSpeed_flag[Index] == 0)
			{
				LCD_WriteString(" : ON  ");
			}			
			else if (FlashingSpeed_flag[Index] == 1)
			{
				LCD_WriteString(" : Flash Slow");
			}
			else if (FlashingSpeed_flag[Index] == 2)
			{
				LCD_WriteString(" : Flash Fast");
			}
/*
			if (!DIO_ReadPin(LED_Pins[Index]))
			{

				LCD_WriteString(" : OFF      ");
				return;
				
			}*/
		}


	}
}
