#include "remote.h"
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 
//红外遥控接收 驱动代码		   
////////////////////////////////////////////////////////////////////////////////// 	  
 	  		  
u32 Remote_Odr=0;  	 //命令暂存处
u8 RRdy=0;
u8 keynum=0;
u8 keyback=0;	   //上一次键值
void Key1_Function(void);
void Key4_Function(void); 
void Key33_Function(void);
u8 key;
u8 START; 
void ring(void);
//初始化红外接收引脚的设置												
//开启中断,并映射 
void Remote_Init(void)
{							 
	GPIO_InitTypeDef GPIO_InitStructure;	//GPIO
	NVIC_InitTypeDef NVIC_InitStructure;	//中断
	EXTI_InitTypeDef EXTI_InitStructure;	//外部中断线
 		 
	RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE );	  
 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU ;  //上拉输入
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);  
 
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource1);  	//选择PA1所在的GPIO管脚用作外部中断线路EXIT1		
 
	EXTI_InitStructure.EXTI_Line = EXTI_Line1;	//外部线路EXIT1
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;			//设外外部中断模式:EXTI线路为中断请求  EXTI_Mode_Event ;//设置 EXTI线路为事件请求 
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  //外部中断触发沿选择:设置输入线路下降沿为中断请求
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;		//使能外部中断新状态
	EXTI_Init(&EXTI_InitStructure);		//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器	
 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn; //使能按键所在的外部中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; //先占优先级2级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; //从优先级1级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //使能外部中断通道
	NVIC_Init(&NVIC_InitStructure); //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器
}   
//检测脉冲宽度
//最长脉宽为5ms
//返回值:x,代表脉宽为x*20us(x=1~250);
u8 Pulse_Width_Check(void)
{
    u8 t=0;	 
    while(RDATA)
    {	 
		t++;delay_us(20);					 
        if(t==250)return t; //超时溢出
    }
    return t;
}			   
//处理红外接收  
/*-------------------------协议--------------------------
开始拉低9ms,接着是一个4.5ms的高脉冲,通知器件开始传送数据了
接着是发送4个8位二进制码,第一二个是遥控识别码(REMOTE_ID),第一个为
正码(0),第二个为反码(255),接着两个数据是键值,第一个为正码
第二个为反码.发送完后40ms,遥控再发送一个9ms低,2ms高的脉冲,
表示按键的次数,出现一次则证明只按下了一次,如果出现多次,则可
以认为是持续按下该键，同时出现该脉冲证明数据已经接收完毕.
---------------------------------------------------------*/		 
//外部中断服务程序	   
void EXTI1_IRQHandler(void)
{       
	u8 res=0;
    u8 OK=0; 
    u8 RODATA=0;
	   		 
	while(1)
    {        
        if(RDATA)//有高脉冲出现
        {
            res=Pulse_Width_Check();//获得此次高脉冲宽度       
            if(res==250)break;//非有用信号
            if(res>=200&&res<250)OK=1; //获得前导位(4.5ms)
            else if(res>=85&&res<200)  //按键次数加一(2ms)
            {  							    		 

				RRdy=1;	        //接受到数据
                break;
            }
            else if(res>=50&&res<85)RODATA=1;//1.5ms
            else if(res>=10&&res<50)RODATA=0;//500us
            if(OK)
            {
                Remote_Odr<<=1;
                Remote_Odr+=RODATA; 
            }   
        }			 						 
    } 	 	    
	EXTI_ClearITPendingBit(EXTI_Line1);  //清除EXTI1线路挂起位
//具体解码遥控器44键	
		if(RRdy==1)
		{
			 	 
			key=Remote_Process();
			if(key==58)
			{
				Key1_Function();
				keynum=1;
			} 
		    if(key==2)
			{
			 	Key4_Function();
				keynum=4;
			}  
			if(START)
		    {
                ring();								  
				keyback=keynum;						  //保存上次键值,执行特殊功能时返回用
				switch (key)                          //根据接收红外值，执行相应动作
			   {
				case 186: keynum=2;     break;
				case 130: keynum=3;     break;
				case 26:  keynum=5;     break;
				case 154: keynum=6;	    break;
				case 162: keynum=7;	    break;
				case 34:  keynum=8;     break;
				case 42:  keynum=9;     break;
				case 170: keynum=10;    break;
				case 146: keynum=11;    break;
				case 18:  keynum=12;    break;
				case 10:  keynum=13;	break;
				case 138: keynum=14;	break;
				case 178: keynum=15;    break;
				case 50:  keynum=16;    break;
				case 56:  keynum=17;    break;
				case 184: keynum=18;    break;
				case 120: keynum=19;    break;
				case 248: keynum=20;    break;
				case 24:  keynum=21;    break;
				case 152: keynum=22;    break;
				case 88:  keynum=23;    break;
				case 216: keynum=24;    break;
				case 40:  keynum=25;    break;
				case 168: keynum=26;    break;
				case 104: keynum=27;    break;
				case 232: keynum=28;    break;
				case 8:   keynum=29;    break;
				case 136: keynum=30;    break;
				case 72:  keynum=31;    break;
				case 200: keynum=32;    break;
				case 48:  keynum=33;
				          Key33_Function();    
						  break;
				case 176: keynum=34;    break;
				case 112: keynum=35;    break;
				case 240: keynum=36;    break;
				case 16:  keynum=37;    break;
				case 144: keynum=38;    break;
				case 80:  keynum=39;    break;
				case 208: keynum=40;    break;
				case 32:  keynum=41;    break;
				case 160: keynum=42;    break;
				case 96:  keynum=43;    break;
				case 224: keynum=44;    break;
		
				default :    ;
			    }

			}
		}

		          
}  
//处理红外键盘
//返回相应的键值
u8 Remote_Process(void)
{               
    u8 t1,t2;   
    t1=Remote_Odr>>24; //得到地址码
    t2=(Remote_Odr>>16)&0xff;//得到地址反码 
    RRdy=0;//清除标记 		      
    if(t1==(u8)~t2&&t1==REMOTE_ID)//检验遥控识别码(ID)及地址 
    { 
        t1=Remote_Odr>>8;
        t2=Remote_Odr; 	
        if(t1==(u8)~t2)return t1; //处理键值  
    }     
    return 0;
}































