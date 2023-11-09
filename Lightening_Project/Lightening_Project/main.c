#define  F_CPU  8000000
#include <util/delay.h>

#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"

#include "DIO_Interface.h"
#include "Timers.h"

#include "LCD_Interface.h"
#include "KeyPad_Interface.h"

#include "LEDs_Mangment.h"
#include "Timer_Mang.h"
#include "Pass_Mang.h"
#include "LCD_Mang.h"

int main(void)
{
	DIO_Init();
	LCD_Init();
	KEYPAD_Init();
	
	Timer1_Init(TIMER1_CTC_OCRA_TOP_MODE,TIMER1_SCALER_8);
	Timer1_OCRA1Mode(OCRA_DISCONNECTED);
	Timer1_OCA_InterruptEnable();
	Timer1_OCA_SetCallBack(PB_Timer_Mang);
	OCR1A=50000;
	
	sei();
	Password_Scan();
    while (1) 
    {
		LEDs_PeriodicCheck ();
		LCD_Mang();
    }
}

