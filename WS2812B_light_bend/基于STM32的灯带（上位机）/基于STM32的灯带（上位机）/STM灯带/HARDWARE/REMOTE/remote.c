#include "remote.h"
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 
//����ң�ؽ��� ��������		   
////////////////////////////////////////////////////////////////////////////////// 	  
 	  		  
u32 Remote_Odr=0;  	 //�����ݴ洦
u8 RRdy=0;
u8 keynum=0;
u8 keyback=0;	   //��һ�μ�ֵ
void Key1_Function(void);
void Key4_Function(void); 
void Key33_Function(void);
u8 key;
u8 START; 
void ring(void);
//��ʼ������������ŵ�����												
//�����ж�,��ӳ�� 
void Remote_Init(void)
{							 
	GPIO_InitTypeDef GPIO_InitStructure;	//GPIO
	NVIC_InitTypeDef NVIC_InitStructure;	//�ж�
	EXTI_InitTypeDef EXTI_InitStructure;	//�ⲿ�ж���
 		 
	RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE );	  
 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU ;  //��������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);  
 
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource1);  	//ѡ��PA1���ڵ�GPIO�ܽ������ⲿ�ж���·EXIT1		
 
	EXTI_InitStructure.EXTI_Line = EXTI_Line1;	//�ⲿ��·EXIT1
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;			//�����ⲿ�ж�ģʽ:EXTI��·Ϊ�ж�����  EXTI_Mode_Event ;//���� EXTI��·Ϊ�¼����� 
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  //�ⲿ�жϴ�����ѡ��:����������·�½���Ϊ�ж�����
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;		//ʹ���ⲿ�ж���״̬
	EXTI_Init(&EXTI_InitStructure);		//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���	
 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn; //ʹ�ܰ������ڵ��ⲿ�ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; //��ռ���ȼ�2��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; //�����ȼ�1��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //ʹ���ⲿ�ж�ͨ��
	NVIC_Init(&NVIC_InitStructure); //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���
}   
//���������
//�����Ϊ5ms
//����ֵ:x,��������Ϊx*20us(x=1~250);
u8 Pulse_Width_Check(void)
{
    u8 t=0;	 
    while(RDATA)
    {	 
		t++;delay_us(20);					 
        if(t==250)return t; //��ʱ���
    }
    return t;
}			   
//����������  
/*-------------------------Э��--------------------------
��ʼ����9ms,������һ��4.5ms�ĸ�����,֪ͨ������ʼ����������
�����Ƿ���4��8λ��������,��һ������ң��ʶ����(REMOTE_ID),��һ��Ϊ
����(0),�ڶ���Ϊ����(255),�������������Ǽ�ֵ,��һ��Ϊ����
�ڶ���Ϊ����.�������40ms,ң���ٷ���һ��9ms��,2ms�ߵ�����,
��ʾ�����Ĵ���,����һ����֤��ֻ������һ��,������ֶ��,���
����Ϊ�ǳ������¸ü���ͬʱ���ָ�����֤�������Ѿ��������.
---------------------------------------------------------*/		 
//�ⲿ�жϷ������	   
void EXTI1_IRQHandler(void)
{       
	u8 res=0;
    u8 OK=0; 
    u8 RODATA=0;
	   		 
	while(1)
    {        
        if(RDATA)//�и��������
        {
            res=Pulse_Width_Check();//��ô˴θ�������       
            if(res==250)break;//�������ź�
            if(res>=200&&res<250)OK=1; //���ǰ��λ(4.5ms)
            else if(res>=85&&res<200)  //����������һ(2ms)
            {  							    		 

				RRdy=1;	        //���ܵ�����
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
	EXTI_ClearITPendingBit(EXTI_Line1);  //���EXTI1��·����λ
//�������ң����44��	
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
				keyback=keynum;						  //�����ϴμ�ֵ,ִ�����⹦��ʱ������
				switch (key)                          //���ݽ��պ���ֵ��ִ����Ӧ����
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
//����������
//������Ӧ�ļ�ֵ
u8 Remote_Process(void)
{               
    u8 t1,t2;   
    t1=Remote_Odr>>24; //�õ���ַ��
    t2=(Remote_Odr>>16)&0xff;//�õ���ַ���� 
    RRdy=0;//������ 		      
    if(t1==(u8)~t2&&t1==REMOTE_ID)//����ң��ʶ����(ID)����ַ 
    { 
        t1=Remote_Odr>>8;
        t2=Remote_Odr; 	
        if(t1==(u8)~t2)return t1; //�����ֵ  
    }     
    return 0;
}































