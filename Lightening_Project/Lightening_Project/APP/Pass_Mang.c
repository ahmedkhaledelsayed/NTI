#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"

#include "DIO_Interface.h"

#define  F_CPU  8000000
#include <util/delay.h>

#define SYSTEM_PASSWORD 1234

u32 Password_Scan(void)
{
	u16 Temp_Input = 0;
	u32 User_Input = 0;
	
	LCD_SetCursor(0,0);
	LCD_WriteString("   ENTER PASSOWRD");
	LCD_SetCursor(1,6);
	while (Temp_Input != '*')
	{
		Temp_Input = KEYPAD_GetKey();
		if (Temp_Input == '*' )
		{
			Password_Mangment(User_Input);
			return 0;
		}
		if (Temp_Input != 'T' && Temp_Input != '*')
		{
			User_Input *= 10;
			User_Input += Temp_Input;
			//LCD_SetCursor(1,0);
			LCD_WriteChar('*');
			//LCD_WriteNumber(User_Input);
		}
	}
}

void Password_Mangment(u32 User_Input)
{
	
	if (User_Input == SYSTEM_PASSWORD)
	{
		LCD_Clear();
		LCD_SetCursor(1,0);
		LCD_WriteString("  PASSWORD CORRECT");
		_delay_ms(1500);
		LCD_Welcome();
	}
	else
	{
		LCD_Clear();
		LCD_SetCursor(1,0);
		LCD_WriteString("  WRONG PASSWORD");
	}
}

void LCD_Welcome(void)
{
	LCD_Clear();
	LCD_SetCursor(1,5);
	LCD_WriteString("WELCOME TO");
	_delay_ms(1500);
	LCD_Clear();
	LCD_SetCursor(0,5);
	LCD_WriteString("lightening ");
	LCD_SetCursor(1,9);
	LCD_WriteString("&");
	LCD_SetCursor(2,5);
	LCD_WriteString("Visibility");
	LCD_SetCursor(3,6);
	LCD_WriteString("Project");
	_delay_ms(1500);

	LCD_Clear();
	
}
