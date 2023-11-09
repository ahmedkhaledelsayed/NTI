

#ifndef TIMER_MANG_PRV_H_
#define TIMER_MANG_PRV_H_
 
volatile u8 PB_SelectFlag_Arr[4] = {0};
static volatile u8 PB_TimeCounter_Arr[4] = {0};
static volatile u8 PB_Routine_Arr[4] = {0};
	
extern DIO_Pin_type LED_Pins[];
extern DIO_Pin_type PB_Pins[];

#endif /* TIMER_MANG_PRV_H_ */