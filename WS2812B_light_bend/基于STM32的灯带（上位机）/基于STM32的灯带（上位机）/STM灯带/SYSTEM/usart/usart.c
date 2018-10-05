#include "sys.h"
#include "usart.h"
 


//�������´���,֧��printf����,������Ҫѡ��use MicroLIB
#if 1
#pragma import(__use_no_semihosting)             
//��׼����Ҫ��֧�ֺ���                 
struct __FILE 
{ 
	int handle; 

}; 

FILE __stdout;       
//����_sys_exit()�Ա���ʹ�ð�����ģʽ    
_sys_exit(int x) 
{ 
	x = x; 
} 
//�ض���fputc���� 
int fputc(int ch, FILE *f)
{      
	while((USART1->SR&0X40)==0);//ѭ������,ֱ���������   
    USART1->DR = (u8) ch;      
	return ch;
}
#endif 

/*ʹ��microLib�ķ���*/
 /* 
int fputc(int ch, FILE *f)
{
	USART_SendData(USART1, (uint8_t) ch);

	while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET) {}	
   
    return ch;
}
int GetKey (void)  { 

    while (!(USART1->SR & USART_FLAG_RXNE));

    return ((int)(USART1->DR & 0x1FF));
}
*/
 
extern u8 keynum,keyback,START;
void Key1_Function(void);
void Key4_Function(void);
void Key33_Function(void); 
void ring(void);


void uart_init(u32 bound){
    //GPIO�˿�����
    GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);
     //USART1_TX   PA.9
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
   
    //USART1_RX	  PA.10
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);  

   //Usart1 NVIC ����

    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3 ;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//

	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���USART1
  
   //USART ��ʼ������
   
	USART_InitStructure.USART_BaudRate = bound;//һ������Ϊ9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx ;

    USART_Init(USART1, &USART_InitStructure);
   

    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//�����ж�
   
    USART_Cmd(USART1, ENABLE);                    //ʹ�ܴ��� 

}

void USART1_IRQHandler(void)                	//����1�жϷ������
{
	u8 Res;
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //�����ж�
		Res =USART_ReceiveData(USART1); 	//��ȡ���յ�������
		USART_SendData(USART1,Res);
	
		
	        if(Res==0x5c)
			{
				Key1_Function();
				keynum=1;
			} 
		    if(Res==0x40)
			{
			 	Key4_Function();
				keynum=4;
			}  
			if(START)
		    {
                ring();								  
				keyback=keynum;		
			switch (Res)
			{
				
				case 0x5d: keynum=2;     break;
				case 0x41: keynum=3;     break;
				case 0x58: keynum=5;     break;
				case 0x59: keynum=6;	 break;
				case 0x45: keynum=7;	 break;
				case 0x44: keynum=8;     break;
				case 0x54: keynum=9;     break;
				case 0x55: keynum=10;	 break;
				case 0x49: keynum=12;    break;
				case 0x48: keynum=13;    break;
				case 0x50: keynum=13;	break;
				case 0x51: keynum=14;	break;
				case 0x4d: keynum=15;    break;
				case 0x4c: keynum=16;    break;
				case 0x1c: keynum=17;    break;
				case 0x1d: keynum=18;    break;
				case 0x1e: keynum=19;	break;
				case 0x1f: keynum=20;    break;
				case 0x18: keynum=21;    break;
				case 0x19: keynum=22;    break;
				case 0x1a: keynum=23;    break;
				case 0x1b: keynum=24;    break;
				case 0x14: keynum=25;    break;
				case 0x15: keynum=26;    break;
				case 0x16: keynum=27;    break;
				case 0x17: keynum=28;    break;
				case 0x10: keynum=29;    break;
				case 0x11: keynum=30;    break;
				case 0x12: keynum=31;    break;
				case 0x13: keynum=32;    break;
				case 0x0c:  keynum=33;
				          Key33_Function();    
						  break;
			    case 0x0d: keynum=34;    break;
				case 0x0e: keynum=35;    break;
				case 0x0f: keynum=36;    break;
				case 0x08: keynum=37;    break;
				case 0x09: keynum=38;    break;
				case 0x0a: keynum=39;    break;
				case 0x0b: keynum=40;    break;
				case 0x04: keynum=41;    break;
				case 0x05: keynum=42;    break;
				case 0x06: keynum=43;    break;
				case 0x07: keynum=44;    break;
		
				default :    ;
			    }

			}
 	
 	  
} 
