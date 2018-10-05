#include "dma.h"
#include "pwm.h"
#include "delay.h"
#include "ws2812b.h"
#include "stm32f10x.h"


int main (void){
	RCC_Configuration();//系统时钟初始化
	TIM2_PWM_Init(77,0);	//初始化PWM
	TIM2_DMA_Init();		//初始化DMA
	while(1){ 
		
			WS2812_Red_BLN();				//红色呼吸灯
			WS2812_Green_BLN();			//绿色呼吸灯
			WS2812_Blue_BLN();			//蓝色呼吸灯
			//WS2812_Random();			//随机闪灯
	}

}




