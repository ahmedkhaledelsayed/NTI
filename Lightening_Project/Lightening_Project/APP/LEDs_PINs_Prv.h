   #ifndef LEDS_PINS_C_
   #define LEDS_PINS_C_
    #include "DIO_Interface.h"
	
	DIO_Pin_type PB_Pins[]= {
	    PIND0,
	    PIND1,
	    PIND2,
	    PIND3,
    };
    DIO_Pin_type LED_Pins[]= {
	    PIND4,
	    PIND5,
	    PIND6,
	    PIND7,
    };
	#endif