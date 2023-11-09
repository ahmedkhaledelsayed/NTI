#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"

#include "DIO_Interface.h"


#include "LEDs_Mangment.h"
#include "LEDs_PINs_Prv.h"

#include "PB_Mang.h"

#define  F_CPU  8000000
#include <util/delay.h>

volatile u8 ON_flag_Index[4] = {0};
	
void LEDs_PeriodicCheck (void)
{
	u8 Index;
	
	for(Index = 0; PB_Pins[Index] <= PIND3; Index++)
	{
		if(!DIO_ReadPin(PB_Pins[Index]))
		{
			ON_flag_Index[Index] = 1;
			LEDs_Mang(Index);
			
		}
	}

}
