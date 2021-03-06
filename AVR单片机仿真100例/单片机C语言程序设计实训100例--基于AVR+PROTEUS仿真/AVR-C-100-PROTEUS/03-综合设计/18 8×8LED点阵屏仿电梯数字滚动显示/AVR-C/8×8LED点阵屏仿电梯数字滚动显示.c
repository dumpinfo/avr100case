//-----------------------------------------------------------------
//  名称: 8×8LED点阵屏仿电梯数字滚动显示
//-----------------------------------------------------------------
//  说明: 本例模拟了电梯显示屏上下滚动显示楼层的效果,当目标楼层大于
//   	  当前楼层时将向上滚动显示,反之则向下滚动显示,到达目标楼层时
//        将发出蜂鸣声.
//
//-----------------------------------------------------------------
#define F_CPU   4000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define INT8U   unsigned char
#define INT16U  unsigned int

#define BEEP() PORTA ^= _BV(PA0)            //蜂鸣器定义
const INT8U Table_OF_Digits[]=              //0~9的数字点阵
{  
	0x00,0x3C,0x66,0x42,0x42,0x66,0x3C,0x00,//0	 
	0x00,0x08,0x38,0x08,0x08,0x08,0x3E,0x00,//1	
	0x00,0x3C,0x42,0x04,0x08,0x32,0x7E,0x00,//2	
	0x00,0x3C,0x42,0x1C,0x02,0x42,0x3C,0x00,//3	
	0x00,0x0C,0x14,0x24,0x44,0x3C,0x0C,0x00,//4	
	0x00,0x7E,0x40,0x7C,0x02,0x42,0x3C,0x00,//5	
	0x00,0x3C,0x40,0x7C,0x42,0x42,0x3C,0x00,//6	
	0x00,0x7E,0x44,0x08,0x10,0x10,0x10,0x00,//7	
	0x00,0x3C,0x42,0x24,0x5C,0x42,0x3C,0x00,//8	
	0x00,0x38,0x46,0x42,0x3E,0x06,0x3C,0x00 //9	
};

INT8U  Current_Floor = 1,Dest_Floor = 1;    //当前楼层,目标楼层
//------------------------------------------------------------------
// 主程序
//------------------------------------------------------------------
int main() 
{ 


} 

//-----------------------------------------------------------------
// T1定时器控制声音输出
//-----------------------------------------------------------------
ISR (TIMER1_OVF_vect )
{


}

//-----------------------------------------------------------------
// T0定时器控制楼层数字滚动及刷新显示
//-----------------------------------------------------------------
ISR (TIMER0_OVF_vect )
{



}
