//-----------------------------------------------------------------
//  名称: 模拟比较器测试
//-----------------------------------------------------------------
//  说明: 当AN0上的电压高于AN1时,模拟比较器置位,LED1点亮,反之LED2点亮.
//
//-----------------------------------------------------------------
#define F_CPU   1000000UL            //1M晶振
#include <avr/io.h>
#include <avr/interrupt.h>
#define INT8U   unsigned char
#define INT16U  unsigned int

#define LED0_ON()  (PORTC &= 0xFE)  //开LED0
#define LED0_OFF() (PORTC |= 0x01)  //关LED0
#define LED1_ON()  (PORTC &= 0xEF)  //开LED1
#define LED1_OFF() (PORTC |= 0x10)  //关LED1
//------------------------------------------------------------------
// 主程序
//------------------------------------------------------------------
int main()
{ 



} 

//-----------------------------------------------------------------
// 模拟比较器中断服务程序
//-----------------------------------------------------------------
ISR (ANA_COMP_vect)
{






}
