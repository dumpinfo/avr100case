//-----------------------------------------------------------------
//  名称: 1602LCD液晶显示DS1302实时实钟
//-----------------------------------------------------------------
//  说明: 本例运行时,程序每隔0.5秒读取DS1302实时时钟芯片时间数据,
//        通过格式转换后显示在1602LCD上.
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
//DS1302相关函数与数据
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
