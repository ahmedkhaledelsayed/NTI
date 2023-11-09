#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"

#include "DIO_Interface.h"

#include "PB_Mang.h"
#include "PB_Mang_Prv.h"

/*
typedef struct{
	u8 PB_Select;
	u8 PB_Counter;
	u32 Timer_Value;
}PB_stat;*/

//extern volatile u8 PB_SelectFlag_Arr[4];
extern u8 FlashingSpeed_flag[4];
extern u8 PB_TimeCounter [4];
extern u8 ON_flag_Index[4];
void LEDs_Mang(u8 Index)
{
	LEDS_Arr[Index]();
	//PB_SelectFlag_Arr[Index] = 1;
}

void Yellow_left (void)
{
	static u8 press_status = 0, press_count = 0;
	while(!DIO_ReadPin(PIND0));
	if (press_status == 0)
	{
		DIO_WritePin(PIND4,HIGH);
		press_status = 1;
			
	}

	else if (press_count == 1)
	{
		DIO_WritePin(PIND4,LOW);
		press_count = 0;
		press_status = 0;
			FlashingSpeed_flag[0] =  0;
			PB_TimeCounter [0] =  0;
			ON_flag_Index[0] =  0;
			
	}
	else
	{
		press_count++;
	}
}
void Yellow_Right (void)
{
	static u8 press_status = 0, press_count = 0;
	while(!DIO_ReadPin(PIND1));
	if (press_status == 0)
	{
		DIO_WritePin(PIND5,HIGH);
		press_status = 1;
			
	}

	else if (press_count == 1)
	{
		DIO_WritePin(PIND5,LOW);
		press_count = 0;
		press_status = 0;
			FlashingSpeed_flag[1] =  0;
			PB_TimeCounter [1] =  0;
			ON_flag_Index[1] =  0;
	}
	else
	{
		press_count++;
	}
}
void Red_Front (void)
{
	static u8 press_status = 0, press_count = 0;
	while(!DIO_ReadPin(PIND2));
	if (press_status == 0)
	{
		DIO_WritePin(PIND6,HIGH);
		press_status = 1;
			
	}

	else if (press_count == 1)
	{
		DIO_WritePin(PIND6,LOW);
		press_count = 0;
		press_status = 0;
			FlashingSpeed_flag[2] =  0;
			PB_TimeCounter [2] =  0;
			ON_flag_Index[2] =  0;
	}
	else
	{
		press_count++;
	}
}
void Red_Back (void)
{
	static u8 press_status = 0, press_count = 0;
	while(!DIO_ReadPin(PIND3));
	if (press_status == 0)
	{
		DIO_WritePin(PIND7,HIGH);
		press_status = 1;
			
	}

	else if (press_count == 1)
	{
		DIO_WritePin(PIND7,LOW);
		press_count = 0;
		press_status = 0;
			FlashingSpeed_flag[3] =  0;
			PB_TimeCounter [3] =  0;
			ON_flag_Index[3] =  0;
	}
	else
	{
		press_count++;
	}
}
	
	
