/* �ڶ��ڣ������
 * �öŰ���һ�˽ӵأ�һ����IO�ڣ�
 * ���IO�ڵ������ƽ��ʹLED ��/��
 * ֪ʶ�㣺Bool���塢|&���㡢16���ơ�PX_IDR��Ӧ��
 */

#include <stm8s105c_s.h>
_Bool IN0 @PB_IDR:0;
_Bool IN1 @PB_IDR:1;
_Bool LED @PG_ODR:1;
void GPIO_Init(void)
{
  PG_DDR |=0x02;//0B0000 0010 ��PG1Ϊ���ģʽ
	PG_CR1 |=0x02;//��PG_CR1 = PG_CR1 | 0x02  �������
	PG_CR2 &=0xfd;//0B1111 1101 
	
	PB_DDR &=0xfc;//0B1111 1001
	PB_CR1 |=0x03;//0B0000 0110
}
void delay(unsigned int x)
{
   unsigned int i,j;
	 for(i=x;i>0;i--)
	    for(j=300;j>0;j--);
}
main()
{ 
  GPIO_Init();
  while(1)
	{
    if((IN0==0)&(IN1==0))
    {
		  LED=0;
	  }
	  else if(IN0==0)
    {
			LED=1;
			delay(100);
			LED=0;
			delay(100);
	  }
		 else if(IN1==0)
    {
			LED=1;
			delay(25);
			LED=0;
			delay(25);
	  }
		
		
	  else 
    {
	    LED=1;
	  }
  }
}
