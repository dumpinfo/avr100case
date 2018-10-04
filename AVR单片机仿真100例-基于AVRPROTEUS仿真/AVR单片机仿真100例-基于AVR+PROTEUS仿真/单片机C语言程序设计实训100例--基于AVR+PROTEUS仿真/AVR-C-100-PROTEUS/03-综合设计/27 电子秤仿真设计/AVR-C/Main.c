//-----------------------------------------------------------------
//  名称: 电子秤仿真设计
//-----------------------------------------------------------------
//  说明: 本例运行时,LCD显示当前压力(未转换为重量),所输入的价格将
//        直接与该值相乘,LCD显示计算后的应付金额.       
//
//-----------------------------------------------------------------
#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define INT8U  unsigned char
#define INT16U unsigned int

//蜂鸣器输出
extern void Sounder();
//液晶相关函数
extern void Initialize_LCD();
extern void LCD_ShowString(INT8U x, INT8U y,char *str);
//键盘处理及金额计算与显示函数
extern void KeyBoard_Handle();
extern void Compute_and_show_sum();
//液晶显示缓冲(重量)
extern char disp_buffer_W[];
//模数转换结果及压力换算结果
volatile INT16U AD_Result,Pre_Result = 0,Pressure_Value;
//-----------------------------------------------------------------
// 主程序
//-----------------------------------------------------------------
int main()
{


}
