//////////////////////////////////////////////////////////////////////////////////	 
//STM32灯带项目
//湖南大学 
//作者：黄宇栋 丁智	   
//////////////////////////////////////////////////////////////////////////////////
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "pwm.h"
#include "remote.h"
#include "beep.h"
#include <stdlib.h>
void ring(void);
void Sleep_Mode(void);
void Key1_Function(void);
void Key2_Function(void);
void Key3_Function(void);
void Key4_Function(void);
void Key5_Function(void);
void Key6_Function(void);
void Key7_Function(void);
void Key8_Function(void);
void Key9_Function(void);
void Key10_Function(void);
void Key11_Function(void);
void Key12_Function(void);
void Key13_Function(void);
void Key14_Function(void);
void Key15_Function(void);
void Key16_Function(void);
void Key17_Function(void);
void Key18_Function(void);
void Key19_Function(void);
void Key20_Function(void);
void Key21_Function(void);
void Key22_Function(void);
void Key23_Function(void);
void Key24_Function(void);
void Key25_Function(void);
void Key26_Function(void);
void Key27_Function(void);
void Key28_Function(void);
void Key29_Function(void);
void Key30_Function(void);
void Key31_Function(void);
void Key32_Function(void);
void Key33_Function(void);
void Key34_Function(void);
void Key35_Function(void);
void Key36_Function(void);
void Key37_Function(void);
void Key38_Function(void);
void Key39_Function(void);
void Key40_Function(void);
void Key41_Function(void);
void Key42_Function(void);
void Key43_Function(void);
void Key44_Function(void);
int Rpwmval=0;
int Gpwmval=0;	   //RGB三灯PWM初值	TIME2 ch4对应PA3,TIME3 ch1对应PA6,TIME4 ch2对应PB7
int Bpwmval=0;
int times;
extern u8 keynum;
extern u8 keyback;
extern u8 START;
extern u8 key;
u8 BASE=1;		   //亮度调节除以的基数
u8 PLAY=1;         //暂停继续按钮
u8 SPEED=5;


int main(void)
{
	

	SystemInit();
	delay_init(72);	     //延时初始化
	NVIC_Configuration();
 	uart_init(9600);
	BEEP_Init();
	Remote_Init();	    //初始化红外接收
	PWM_Init(900,0);	//不分频。PWM频率=72000/900=8Khz


	while(1)
	{
	   if(keynum==0)  Sleep_Mode();
	   if(keynum==2)  Key2_Function();
	   if(keynum==3)  Key3_Function();
   	   if(keynum==5)  Key5_Function();
	   if(keynum==6)  Key6_Function();
	   if(keynum==7)  Key7_Function();
	   if(keynum==8)  Key8_Function();
	   if(keynum==9)  Key9_Function();
	   if(keynum==10) Key10_Function();
	   if(keynum==11) Key11_Function();
	   if(keynum==12) Key12_Function();
	   if(keynum==13) Key13_Function();
	   if(keynum==14) Key14_Function();
	   if(keynum==15) Key15_Function();
	   if(keynum==16) Key16_Function();
	   if(keynum==17) Key17_Function();
	   if(keynum==18) Key18_Function();
	   if(keynum==19) Key19_Function();
	   if(keynum==20) Key20_Function();
	   if(keynum==21) Key21_Function();
	   if(keynum==22) Key22_Function();
	   if(keynum==23) Key23_Function();
	   if(keynum==24) Key24_Function();
	   if(keynum==25) Key25_Function();
	   if(keynum==26) Key26_Function();
	   if(keynum==27) Key27_Function();
	   if(keynum==28) Key28_Function();
	   if(keynum==29) Key29_Function();
	   if(keynum==30) Key30_Function();
	   if(keynum==31) Key31_Function();
	   if(keynum==32) Key32_Function();
	   if(keynum==34) Key34_Function();
	   if(keynum==35) Key35_Function();
	   if(keynum==36) Key36_Function();
	   if(keynum==37) Key37_Function();
	   if(keynum==38) Key38_Function();
	   if(keynum==39) Key39_Function();
	   if(keynum==40) Key40_Function();
	   if(keynum==41) Key41_Function();
	   if(keynum==42) Key42_Function();
	   if(keynum==43) Key43_Function();
	   if(keynum==44) Key44_Function();
 	}

}


void ring()
{	
    
    unsigned int t;
	for(t=1000;t>0;t--)		   //蜂鸣器
	{
		BEEP=0;
		delay_us(50);	
	}
	BEEP=1;
}


void Sleep_Mode()
{
	while(!START);
}

void Key1_Function()				 
{
	START=1;
	Key5_Function();
    ring();
	
}

void Key2_Function()
{
								  
}

void Key3_Function()
{

}

void Key4_Function()
{
    START=0;
	Rpwmval=0;		    //TIM_SetCompareX(TIMX,Rpwmval); 通过该函数设置PWM  X代表通道CHX。
    Gpwmval=0;	   		//TIME2 ch4对应PA3,TIME3 ch1对应PA6,TIME4 ch2对应PB7
    Bpwmval=0;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);
    ring();
}

void Key5_Function()
{

	Rpwmval=255;
    Gpwmval=0;	   
    Bpwmval=0;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);	
}

void Key6_Function()
{											 
	Rpwmval=0;
    Gpwmval=255;	   
    Bpwmval=0;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);	
}

void Key7_Function()
{
	Rpwmval=0;
    Gpwmval=0;	   
    Bpwmval=255;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);
}

void Key8_Function()
{
	Rpwmval=255;
    Gpwmval=255;	   
    Bpwmval=255;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);
}

void Key9_Function()
{
	Rpwmval=255;
    Gpwmval=20;	   
    Bpwmval=0;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);	
}

void Key10_Function()
{

	Rpwmval=255;
    Gpwmval=255;	   
    Bpwmval=80;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);	
}

void Key11_Function()
{
 
	Rpwmval=40;
    Gpwmval=0;	   
    Bpwmval=255;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);	
}

void Key12_Function()
{
	Rpwmval=255;
    Gpwmval=5;	   
    Bpwmval=0;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);
}

void Key13_Function()
{

	Rpwmval=255;
    Gpwmval=45;	   
    Bpwmval=20;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);	
}

void Key14_Function()
{

	Rpwmval=128;
    Gpwmval=255;	   
    Bpwmval=255;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);		
}

void Key15_Function()
{

	Rpwmval=80;
    Gpwmval=0;	   
    Bpwmval=255;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);		
}

void Key16_Function()
{
	Rpwmval=20;
    Gpwmval=230;	   
    Bpwmval=185;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);		
}

void Key17_Function()
{

	Rpwmval=255;
    Gpwmval=100;	   
    Bpwmval=20;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);		
}

void Key18_Function()
{

	Rpwmval=150;
    Gpwmval=180;	   
    Bpwmval=255;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);		
}

void Key19_Function()
{

	Rpwmval=150;
    Gpwmval=0;	   
    Bpwmval=255;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);		
}

void Key20_Function()
{
	Rpwmval=10;
    Gpwmval=40;	   
    Bpwmval=255;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);		
}

void Key21_Function()
{
 
    Rpwmval=255;
    Gpwmval=90;	   
    Bpwmval=0;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);		
}

void Key22_Function()
{		
    Rpwmval=150;
    Gpwmval=120;	   
    Bpwmval=255;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);
}

void Key23_Function()
{		
    Rpwmval=255;
    Gpwmval=80;	   
    Bpwmval=255;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);
}

void Key24_Function()
{
	
}

void Key25_Function()			  //红+
{
	Rpwmval  += 10;
	if(Rpwmval>255) Rpwmval=255;			 
	TIM_SetCompare4(TIM2,Rpwmval);
	keynum=0;					 //防止红色值一直加到255.下同
}

void Key26_Function()				   //绿+
{
	Gpwmval  += 10;
	if(Gpwmval>255) Gpwmval=255;
	TIM_SetCompare1(TIM3,Gpwmval);
	keynum=0;	
}

void Key27_Function()					//蓝+
{
	Bpwmval  += 10;
	if(Bpwmval>255) Bpwmval=255;	
	TIM_SetCompare2(TIM4,Bpwmval);
	keynum=0;		
}

void Key28_Function()					 //亮度+
{
	BASE--;
	if(BASE<1) BASE=1;
	TIM_SetCompare4(TIM2,Rpwmval/BASE);
	TIM_SetCompare1(TIM3,Gpwmval/BASE);
	TIM_SetCompare2(TIM4,Bpwmval/BASE);
	keynum=0;		
}

void Key29_Function()					  //红-
{	
	Rpwmval  -= 10;
	if(Rpwmval<0) Rpwmval=0;
	TIM_SetCompare4(TIM2,Rpwmval);
	keynum=0;	
}

void Key30_Function()					  //绿-
{
	Gpwmval  -= 10;
	if(Gpwmval<0) Gpwmval=0;
	TIM_SetCompare1(TIM3,Gpwmval);
	keynum=0;										
}

void Key31_Function()					  //蓝-
{
	Bpwmval  -= 10;
	if(Bpwmval<0) Bpwmval=0;
	TIM_SetCompare2(TIM4,Bpwmval);
	keynum=0;	
}

void Key32_Function()					   //亮度-
{
	BASE++;
	if(BASE>10) BASE=10;
	TIM_SetCompare4(TIM2,Rpwmval/BASE);
	TIM_SetCompare1(TIM3,Gpwmval/BASE);
	TIM_SetCompare2(TIM4,Bpwmval/BASE);
	keynum=0;	
}

void Key33_Function()					 //暂停继续
{

	keynum=keyback;
	if(keyback>36) PLAY = !PLAY;
	
}

void Key34_Function()				   //减速
{
	if(keyback>36)
	{
		keynum=keyback;
		SPEED--;
		if(SPEED<1) SPEED=1;	
	} 
}

void Key35_Function()
{										//加速
	if(keyback>36)
	{
	   	keynum=keyback;
		SPEED++;
		if(SPEED>10) SPEED=10;	
	} 
}

void Key36_Function()			 //恢复初始速度
{
	if(keyback>36)
	{
		keynum=keyback;
		SPEED=5;	
	} 
}

void Add_Sub(u8 color,u8 loop,u8 delay,u8 add_sub,u8 keyjump)
{	
    u8 i,j;
											//五个入口参数分别为颜色、
	for(i=loop;i>0;i--)						//循环次数（颜色变化多少）、
	{										//延迟时间（变化快慢）、
	    if(keynum != keyjump) break;		//加减、键位 。
		if(color==1)
		{
			if(add_sub)
			{
			  Rpwmval++;

			}  
			if(!add_sub)
			{
			  Rpwmval--;

			}	
		}
		if(color==2)
		{	
			if(add_sub)
			{
			  Gpwmval++;

			}  
			
			if(!add_sub)
			{
			  Gpwmval--;

			}
				
		}
		if(color==3)
		{
			if(add_sub)
			{
			  Bpwmval++;

			}  
			
			if(!add_sub)
			{
			  Bpwmval--;

			}	
		}
		for(j=SPEED*20;j>0;j--)
		delay_us(delay);
		TIM_SetCompare4(TIM2,Rpwmval);
		TIM_SetCompare1(TIM3,Gpwmval);
		TIM_SetCompare2(TIM4,Bpwmval);
		while(!PLAY) ;
		
		
		
	}
}

void Key37_Function()		   //RGB渐变
{
    Rpwmval=1;
    Gpwmval=1;	   
    Bpwmval=1;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);
    while(keynum==37)
	{

		Add_Sub(1,250,100,1,37);//红+
		Add_Sub(2,250,100,1,37);//绿+
		Add_Sub(1,250,100,0,37);//红-
		Add_Sub(3,250,100,1,37);//蓝+
		Add_Sub(2,250,100,0,37);//绿-
		Add_Sub(3,250,100,0,37);//蓝-

	}
}

void Key38_Function()			//GBR
{
    Rpwmval=1;
    Gpwmval=1;	   
    Bpwmval=1;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);
    while(keynum==38)
	{

		Add_Sub(2,250,100,1,38);//绿+
		Add_Sub(3,250,100,1,38);//蓝+
		Add_Sub(2,250,100,0,38);//绿-
		Add_Sub(1,250,100,1,38);//红+
		Add_Sub(3,250,100,0,38);//蓝-
		Add_Sub(1,250,100,0,38);//红-

	}
}

void Key39_Function()				 //BRG
{
    Rpwmval=1;
    Gpwmval=1;	   
    Bpwmval=1;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);
    while(keynum==39)
	{

		Add_Sub(3,250,100,1,39);//蓝+
		Add_Sub(1,250,100,1,39);//红+
		Add_Sub(3,250,100,0,39);//蓝-
		Add_Sub(2,250,100,1,39);//绿+
		Add_Sub(1,250,100,0,39);//红-
		Add_Sub(2,250,100,0,39);//绿-
		
	}
}

void Key40_Function()					 //跳变
{
    while(keynum==40)
	{

		Rpwmval=rand()%255;
		TIM_SetCompare4(TIM2,Rpwmval);
		Gpwmval=rand()%255;
		TIM_SetCompare1(TIM3,Gpwmval);
		Bpwmval=rand()%255;
		TIM_SetCompare2(TIM4,Bpwmval);
		for(times=SPEED;times>0;times--) delay_ms(600);
		
		while(!PLAY)
		
		
		if(keynum != 40) break;		
	}
}

void Key41_Function()					  //RBG
{
    Rpwmval=1;
    Gpwmval=1;	   
    Bpwmval=1;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);
    while(keynum==41)
	{
		
		Add_Sub(1,250,100,1,41);//红+
		Add_Sub(3,250,100,1,41);//蓝+
		Add_Sub(1,250,100,0,41);//红-
		Add_Sub(2,250,100,1,41);//绿+
		Add_Sub(3,250,100,0,41);//蓝-
		Add_Sub(2,250,100,0,41);//绿-
		

	}
}

void Key42_Function()			  //GRB
{
    Rpwmval=1;
    Gpwmval=1;	   
    Bpwmval=1;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);
    while(keynum==42)
	{
		
		Add_Sub(2,250,100,1,42);//绿+
		Add_Sub(1,250,100,1,42);//红+
		Add_Sub(2,250,100,0,42);//绿-
		Add_Sub(3,250,100,1,42);//蓝+
		Add_Sub(1,250,100,0,42);//红-	
		Add_Sub(3,250,100,0,42);//蓝-		

	}
}

void Key43_Function()		   //BGR
{
    Rpwmval=1;
    Gpwmval=1;	   
    Bpwmval=1;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);
    while(keynum==43)
	{
		
		Add_Sub(3,250,100,1,43);//蓝+
		Add_Sub(2,250,100,1,43);//绿+
		Add_Sub(3,250,100,0,43);//蓝-
		Add_Sub(1,250,100,1,43);//红+
		Add_Sub(2,250,100,0,43);//绿-		
		Add_Sub(1,250,100,0,43);//红-	
				

	}
}


void Key44_Function()				  //七彩
{

    Rpwmval=1;
    Gpwmval=1;	   
    Bpwmval=1;
	TIM_SetCompare4(TIM2,Rpwmval);
	TIM_SetCompare1(TIM3,Gpwmval);
	TIM_SetCompare2(TIM4,Bpwmval);
    while(keynum==44)
	{
	

	    Add_Sub(3,250,50,1,44);
		Add_Sub(1, 250,50,1,44);
		Add_Sub(3,250,50,0,44);
		Add_Sub(2,100,100,1,44);
		Add_Sub(1, 250,50,0,44);
		Add_Sub(3,250,50,1,44);
		Add_Sub(2,100,100,0,44);
		Add_Sub(2,100,100,1,44);
		Add_Sub(3,250,50,0,44);
		Add_Sub(1, 250,50,1,44);
		Add_Sub(2,100,100,0,44);
		Add_Sub(3,250,50,1,44);
		Add_Sub(1, 250,50,0,44);
		Add_Sub(3,250,50,0,44);
	}
}
