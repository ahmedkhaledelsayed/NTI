
#include "StdTypes.h"
#include "DIO_Interface.h"
#include "KeyPad_Cfg.h"
#include "KeyPad_Interface.h"


void KEYPAD_Init(void)
{
	DIO_WritePin(FIRST_OUTPUT,HIGH);
	DIO_WritePin(FIRST_OUTPUT+1,HIGH);
	DIO_WritePin(FIRST_OUTPUT+2,HIGH);
	DIO_WritePin(FIRST_OUTPUT+3,HIGH);
}

/*
u8 KEYPAD_GetKey(void)
{
	u8 r,c,key=NO_KEY;
	for (r=0;r<ROWS;r++)
	{
		DIO_WritePin(FIRST_OUTPUT+r,LOW);
		for (c=0;c<COLS;c++)
		{
			if (DIO_ReadPin(FIRST_INPUT+c)==LOW)
			{
				key=KeysArray[r][c];
				while(DIO_ReadPin(FIRST_INPUT+c)==LOW);
			}
		}
		DIO_WritePin(FIRST_OUTPUT+r,HIGH);
	}
	
	return key;
	
}*/

u8 KEYPAD_GetKey(void)
{
	u8 Row_Index,Column_Index,key=NO_KEY;
	for (Row_Index=0;Row_Index<ROWS;Row_Index++)
	{
		DIO_WritePin(FIRST_OUTPUT+Row_Index,LOW);
		for (Column_Index=0;Column_Index<COLS;Column_Index++)
		{
			if (DIO_ReadPin(FIRST_INPUT+Column_Index)==LOW)
			{
				key=KeysArray[Column_Index][Row_Index];
				while(DIO_ReadPin(FIRST_INPUT+Column_Index)==LOW);
			}
		}
		DIO_WritePin(FIRST_OUTPUT+Row_Index,HIGH);
	}
	
	return key;
	
}