/*
 * DIO_Private.h
 *
 * Created: 24/03/2023 15:05:00
 *  Author: lenovo
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


static void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status);

extern const DIO_PinStatus_type  PinsStatusArray[TOTAL_PINS];


#endif /* DIO_PRIVATE_H_ */