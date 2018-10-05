#ifndef __BEEP_H
#define __BEEP_H	 
#include "stm32f10x.h"


//beep端口定义

#define BEEP PDout(2)// PD2	
void BEEP_Init(void);//初始化

		 				    
#endif
