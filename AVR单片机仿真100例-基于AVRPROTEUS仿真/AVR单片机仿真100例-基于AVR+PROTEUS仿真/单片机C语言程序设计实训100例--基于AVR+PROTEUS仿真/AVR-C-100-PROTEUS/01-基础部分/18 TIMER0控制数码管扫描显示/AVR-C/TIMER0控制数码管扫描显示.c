//-----------------------------------------------------------------
//  名称: T0定时器控制数码管扫描显示
//-----------------------------------------------------------------
//  说明: 8只数码管分两组动态显示年月日与时分秒,本例的位显示延时
//        用定时器实现,未使用前面案例中常用的延时函数
//     
//-----------------------------------------------------------------
#define F_CPU   4000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#define INT8U   unsigned char
#define INT16U  unsigned int

//0-9的数码管段码,最后一位是"-"的段码,索引为10
const INT8U SEG_CODE[] =
{ 0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0xBF};

//待显示数据09-12-25与21-57-39(分为两组显示)
const INT8U Table_OF_Digits[][8] = 
{





};

INT8U  i = 0,j = 0;
INT16U Keep_Time = 0;         //保持显示时长
//------------------------------------------------------------------
// 主程序
//------------------------------------------------------------------
int main() 
{ 



} 

//-----------------------------------------------------------------
// T0定时器溢出中断程序(控制数码管扫描显示)
//-----------------------------------------------------------------
ISR (....)
{



}
