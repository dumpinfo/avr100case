#include "dma.h"
#include "pwm.h"
#include "delay.h"
#include "ws2812b.h"
#include "stm32f10x.h"


int main (void){
	RCC_Configuration();//ϵͳʱ�ӳ�ʼ��
	TIM2_PWM_Init(77,0);	//��ʼ��PWM
	TIM2_DMA_Init();		//��ʼ��DMA
	while(1){ 
		
			WS2812_Red_BLN();				//��ɫ������
			WS2812_Green_BLN();			//��ɫ������
			WS2812_Blue_BLN();			//��ɫ������
			//WS2812_Random();			//�������
	}

}




