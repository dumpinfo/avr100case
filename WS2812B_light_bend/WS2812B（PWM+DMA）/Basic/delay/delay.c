#include "delay.h"


#define AHB_INPUT  64 //请按RCC中设置的AHB时钟频率填写到这里（单位MHz）


void delay_us(u32 uS){ //uS微秒级延时程序（参考值即是延时数，72MHz时最大值233015）	
	SysTick->LOAD=AHB_INPUT*uS;      //重装计数初值（当主频是72MHz，72次为1微秒）
	SysTick->VAL=0x00;        //清空定时器的计数器
	SysTick->CTRL=0x00000005;//时钟源HCLK，打开定时器
	while(!(SysTick->CTRL&0x00010000)); //等待计数到0
	SysTick->CTRL=0x00000004;//关闭定时器
}

void delay_ms(u16 ms){ //mS毫秒级延时程序（参考值即是延时数，最大值65535）	 		  	  
	while( ms-- != 0){
		delay_us(1000);	//调用1000微秒的延时
	}
}
 
void delay_s(u16 s){ //S秒级延时程序（参考值即是延时数，最大值65535）	 		  	  
	while( s-- != 0){
		delay_ms(1000);	//调用1000毫秒的延时
	}
} 

//软件延时函数
void my_delay_ns(u16 ns)
{		
	while(ns--);
}
void my_delay_us(u16 us)
{		
	 u8 i=0;
	while(us--)
	{
		i = 10;
		while(i--);
	}
}
void my_delay_ms(u16 us)
{		
	 u16 i = 0;
	while(us--)
	{
		i = 12000;
		while(i--);
	}
}
































