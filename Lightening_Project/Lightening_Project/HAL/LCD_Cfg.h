/*
 * LCD_Cfg.h
 *
 * Created: 31/03/2023 14:43:31
 *  Author: lenovo
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_




#define _4_BIT   0
#define _8_BIT   1

/* _4_BIT OR _8_BIT*/
#define  LCD_MODE  _4_BIT 	



#define  RS   PINC1
#define  EN   PINC2

#define  D7   PINC6
#define  D6   PINC5
#define  D5   PINC4
#define  D4   PINC3

#define LCD_PORT  PC





#endif /* LCD_CFG_H_ */