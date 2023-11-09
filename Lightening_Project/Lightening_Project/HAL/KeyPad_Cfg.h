


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_



#define  FIRST_OUTPUT   PINB4
#define  FIRST_INPUT   PINB0




#define  ROWS   3 /*OUTPUT*/
#define  COLS   4 /*INPUT*//*input must be column*/

#define  NO_KEY   'T'



const u8 KeysArray[COLS][ROWS]={
	{1,2,3},
	{4,5,6},
	{7,8,9},
	{'*',0,'#'},
};


#endif /* KEYPAD_CFG_H_ */