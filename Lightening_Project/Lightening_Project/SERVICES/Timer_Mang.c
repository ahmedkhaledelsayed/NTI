#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"

#include "DIO_Interface.h"
#include "LCD_Interface.h"

#include "Timer_Mang.h"

u8 FlashingSpeed_flag[4] ={0};
u8 PB_TimeCounter [4] = {0};

#define  F_CPU  8000000
#include <util/delay.h>

extern DIO_Pin_type LED_Pins[];
extern DIO_Pin_type PB_Pins[];

void PB_Timer_Mang(void)
{
	static u32 Global_TickTime_counter = 0, Routine_TickTime_counter = 0;

	if (Global_TickTime_counter== 20)
	{
		Global_TickTime_counter = 0;
		PB_TimeCounter_RoutineSelect();
	}
	Global_TickTime_counter++;
	
	if (Routine_TickTime_counter== 5)
	{
		Routine_TickTime_counter = 0;
		LED_Flashing_ExecuteRoutine2();
	}
	Routine_TickTime_counter++;
}


void PB_TimeCounter_RoutineSelect(void)
{
	u8 Index;
		
	for(Index = 0; PB_Pins[Index] <= PIND3; Index++)
	{
		if (!DIO_ReadPin(PB_Pins[Index]))
		{
			PB_TimeCounter[Index]++;
		}
		else if (DIO_ReadPin(PB_Pins[Index]))
		{
			if (PB_TimeCounter[Index] < 1)
			{
				return;
			}
			else if (PB_TimeCounter[Index] >= 1 && PB_TimeCounter[Index] < 3)
			{
				FlashingSpeed_flag[Index] = 1;
				//LED_Flashing_ExecuteRoutine(Index);
				
				
			}
			else if (PB_TimeCounter[Index] >= 3 )
			{
				FlashingSpeed_flag[Index] = 2;
				//LED_Flashing_ExecuteRoutine(Index);
				
			}
			//PB_TimeCounter[Index] = 0;
		}
	
		//PB_TimeCounter_Arr[Index] = 0;
	}

}
void LED_Flashing_ExecuteRoutine2(void)
{
	static u8 SlowFlash_delay[4]={0};
	u8 Index;
	
	for(Index = 0; PB_Pins[Index] <= PIND3; Index++)
	{
		if (FlashingSpeed_flag[Index] == 2) // slow routine
		{
			DIO_TogglePin(LED_Pins[Index]);
			//LCD_Stat(Index,flag);
		}
		else if (FlashingSpeed_flag[Index] == 1) // fast routine
		{
			if (SlowFlash_delay[Index] == 2)
			{
				DIO_TogglePin(LED_Pins[Index]);
				//LCD_Stat(Index,flag);
				SlowFlash_delay[Index] = 0;
			}
			SlowFlash_delay[Index]++;
		}
	}
}
/*
void LED_Flashing_ExecuteRoutine(u8 Index)
{
	static u8 SlowFlash_delay = 1;

	if (FlashingSpeed_flag[Index] == 2) // slow routine
	{
		DIO_TogglePin(LED_Pins[Index]);
		//LCD_Stat(Index,flag);
	}
	else if (FlashingSpeed_flag[Index] == 1) // fast routine
	{
		if (SlowFlash_delay == 2)
		{
			DIO_TogglePin(LED_Pins[Index]);
			//LCD_Stat(Index,flag);
			SlowFlash_delay = 0;
		}
		SlowFlash_delay++;
	}
}
*/

/*
void LED_Flashing_ExecuteRoutine(void)
{
	static u8 d = 1;

	if (flag == 2) // slow routine
	{
		DIO_TogglePin(PIND4);
	}
	else if (flag == 1) // fast routine
	{
		if (d == 2)
		{
			DIO_TogglePin(PIND4);
			d = 0;
		}
		d++;
	}

}*/
/*
void PB_Timer_Mang(void)
{
	static u32 Global_TickTime_counter = 0, Routine_TickTime_counter = 0;
	
	if (Global_TickTime_counter== 20)
	{
		Global_TickTime_counter = 0;
		PB_TimeCounter_RoutineSelect();	
	}
	Global_TickTime_counter++;
	
	if (Routine_TickTime_counter== 5)
	{
		Routine_TickTime_counter = 0;
		LED_Flashing_ExecuteRoutine();
	}
	Routine_TickTime_counter++;

}

void PB_TimeCounter_RoutineSelect(void)
{
	u8 Index;
	
	for(Index = 0; PB_Pins[Index] <= PIND3; Index++)
	{
		if ((PB_SelectFlag_Arr[Index] == 1) && (!DIO_ReadPin(PB_Pins[Index])))
		{
			PB_TimeCounter_Arr[Index]++;
		}
		else if ((PB_SelectFlag_Arr[Index] == 1) && (DIO_ReadPin(PB_Pins[Index])))
		{
			LED_Flashing_SetRoutine(PB_TimeCounter_Arr[Index], Index);
			
			PB_TimeCounter_Arr[Index] = 0;
		}
	}
}

void LED_Flashing_SetRoutine(u8 Counter, u8 Index)
{
	if (Counter < 2)
	{
		return;
	}
	else if (Counter >= 2 && Counter < 5)
	{
		PB_Routine_Arr[Index] = 1;
	}
	else if (Counter >= 5 && Counter < 7)
	{
		PB_Routine_Arr[Index] = 2;
	}
}

void LED_Flashing_ExecuteRoutine(void)
{
	u8 Index;
	static u8 flag = 0;
	
	for(Index = 0; PB_Pins[Index] <= PIND3; Index++)
	{
		if (PB_SelectFlag_Arr[Index] == 1) 
		{
			if (PB_Routine_Arr[Index] == 1) // slow routine
			{
				DIO_TogglePin(PIND0+Index);
			}
			else if (PB_Routine_Arr[Index] == 2) // fast routine
			{
				if (flag == 1)
				{
					DIO_TogglePin(PIND0+Index);
					flag = 0;
				}
				flag++;
			}
		}
	}
}

*/

void LCD_Stat(u8 Index,u8 Counter)
{
	LCD_SetCursor(0,0);
	LCD_WriteString("Index:");
	LCD_WriteNumber((u32)Index);
	LCD_SetCursor(1,0);
	LCD_WriteString("Flag");
	LCD_WriteNumber((u32)Counter);

}