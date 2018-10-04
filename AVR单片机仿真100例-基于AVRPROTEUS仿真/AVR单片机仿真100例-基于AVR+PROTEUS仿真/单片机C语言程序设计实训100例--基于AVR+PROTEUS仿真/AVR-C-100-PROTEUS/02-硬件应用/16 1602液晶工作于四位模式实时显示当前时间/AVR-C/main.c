//-----------------------------------------------------------------
//  名称: 1602LCD工作于四位模式实时显示当前时间
//-----------------------------------------------------------------
//  说明: 与上一案例不同的是本例液晶数据端口仅使用了四只引脚,实现
//        日期时间的实时显示.
//                          
//-----------------------------------------------------------------
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#define INT8U   unsigned char
#define INT16U  unsigned int

//液晶相关函数
extern void Initialize_LCD();
extern void LCD_ShowString(INT8U x, INT8U y,char *str);
// DS1302相关函数与数据
extern void GetDateTime();
extern INT8U DateTime[];
extern char *WEEK[];
//LCD显示缓冲
char LCD_DSY_BUFFER[17];
//-----------------------------------------------------------------
// 主程序     
//-----------------------------------------------------------------
int main()
{

















}
