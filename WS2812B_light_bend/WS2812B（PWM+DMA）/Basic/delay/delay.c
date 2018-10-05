#include "delay.h"


#define AHB_INPUT  64 //�밴RCC�����õ�AHBʱ��Ƶ����д�������λMHz��


void delay_us(u32 uS){ //uS΢�뼶��ʱ���򣨲ο�ֵ������ʱ����72MHzʱ���ֵ233015��	
	SysTick->LOAD=AHB_INPUT*uS;      //��װ������ֵ������Ƶ��72MHz��72��Ϊ1΢�룩
	SysTick->VAL=0x00;        //��ն�ʱ���ļ�����
	SysTick->CTRL=0x00000005;//ʱ��ԴHCLK���򿪶�ʱ��
	while(!(SysTick->CTRL&0x00010000)); //�ȴ�������0
	SysTick->CTRL=0x00000004;//�رն�ʱ��
}

void delay_ms(u16 ms){ //mS���뼶��ʱ���򣨲ο�ֵ������ʱ�������ֵ65535��	 		  	  
	while( ms-- != 0){
		delay_us(1000);	//����1000΢�����ʱ
	}
}
 
void delay_s(u16 s){ //S�뼶��ʱ���򣨲ο�ֵ������ʱ�������ֵ65535��	 		  	  
	while( s-- != 0){
		delay_ms(1000);	//����1000�������ʱ
	}
} 

//�����ʱ����
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
































