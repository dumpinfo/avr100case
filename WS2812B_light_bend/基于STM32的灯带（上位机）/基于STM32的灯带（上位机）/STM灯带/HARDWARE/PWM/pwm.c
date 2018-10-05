#include "pwm.h"
////////////////////////////////////////////////////////////////////////////////////////////////	 
//三路PWM，分别用TIM2,3,4控制，分别控制RGB。(可改进之处：如用一个定时器的不同通道，该代码语句 //
//可精简。)																					  //
//////////////////////////////////////////////////////////////////////////////////////////////// 	  


//PWM输出初始化
//arr：自动重装值
//psc：时钟预分频数
void PWM_Init(u16 arr,u16 psc)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;


   //使能GPIO外设时钟使能 TIME2 ch4对应PA3,TIME3 ch1对应PA6,TIME4 ch2对应PB7
   //TIME2、3、4分别调制RED,GREEN,BLUE。
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2  | RCC_APB1Periph_TIM3  | RCC_APB1Periph_TIM4, ENABLE);			
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA  | RCC_APB2Periph_GPIOB  | RCC_APB2Periph_AFIO , ENABLE);          	 



   //设置该引脚输出TIM2 CH4的PWM脉冲波形
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3; //TIME2 ch4对应PA3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;  //复用开漏输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);


   //设置该引脚输出TIM3 CH1的PWM脉冲波形
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; //TIME3 ch1对应PA6
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;  //复用开漏输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	//GPIO_WriteBit(GPIOA, GPIO_Pin_7,Bit_SET); // PA7上拉	

   //设置该引脚输出TIM4 CH2的PWM脉冲波形
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7; //TIME4 ch2对应PB7
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;  //复用开漏输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 80K
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值  不分频
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIM2的时间基数单位
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIM3的时间基数单位
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIM4的时间基数单位
	
	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_Pulse = 0; //设置待装入捕获比较寄存器的脉冲值。  
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
	TIM_OC4Init(TIM2, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIM2
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIM3
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIM3
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);  //使能TIM2在CCR4上的预装载寄存器
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);  //使能TIM3在CCR2上的预装载寄存器
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);  //使能TIM4在CCR2上的预装载寄存器

	TIM_ARRPreloadConfig(TIM2, ENABLE); //使能TIM2在ARR上的预装载寄存器
	TIM_ARRPreloadConfig(TIM3, ENABLE); //使能TIM3在ARR上的预装载寄存器
	TIM_ARRPreloadConfig(TIM4, ENABLE); //使能TIM4在ARR上的预装载寄存器
	
	TIM_Cmd(TIM2, ENABLE);  //使能TIMx外设
	TIM_Cmd(TIM3, ENABLE);  //使能TIMx外设
	TIM_Cmd(TIM4, ENABLE);  //使能TIMx外设 
	

 

}
