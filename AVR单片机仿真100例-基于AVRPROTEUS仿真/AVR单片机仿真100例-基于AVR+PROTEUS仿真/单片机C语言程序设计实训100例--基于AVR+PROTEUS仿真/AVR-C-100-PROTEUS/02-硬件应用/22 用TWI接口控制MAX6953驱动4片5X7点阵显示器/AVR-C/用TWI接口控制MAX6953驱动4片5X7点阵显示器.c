//-----------------------------------------------------------------
//  名称: 用TWI接口控制MAX6953驱动4片5*7点阵显示器
//-----------------------------------------------------------------
//  说明: 本例运行时,四块点阵屏将滚动显示一组信息串,信息串中的字符
//        点阵信息由MAX6953提供,本例不需要为各字符单独提供字模点阵.
//        运行过程中通过按键命令可随时关断或开启6953.
//
//-----------------------------------------------------------------
#define F_CPU 4000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/twi.h>
#include <util/delay.h>
#include <string.h>
#define INT8U   unsigned char
#define INT16U  unsigned int
#define INT32U  unsigned long

//子器件地址



//TWI通用操作




//四块点阵屏滚动显示的信息串
char LED_String[] = "LEDSHOW: <----0123456789";
//-----------------------------------------------------------------
// 写MAX6953子程序
//-----------------------------------------------------------------
INT8U MAX6953_Write(INT8U addr, INT8U dat)
{


}

//-----------------------------------------------------------------
// MAX6953初始化
//-----------------------------------------------------------------
void MAX6953_INIT()
{



}

//-----------------------------------------------------------------
// 主程序
//-----------------------------------------------------------------
int main()
{



}

//-----------------------------------------------------------------
// INT0中断函数控制点阵屏关断或开启
//-----------------------------------------------------------------
ISR (INT0_vect) 
{


}
