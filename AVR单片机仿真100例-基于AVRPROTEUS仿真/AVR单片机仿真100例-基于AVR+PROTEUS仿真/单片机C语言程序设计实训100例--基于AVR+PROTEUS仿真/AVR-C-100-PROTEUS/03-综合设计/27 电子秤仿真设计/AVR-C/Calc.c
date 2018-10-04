//-----------------------------------------------------------------
// 名称: 电子秤价格输入与金额计算程序
//-----------------------------------------------------------------
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define INT8U  unsigned char
#define INT16U unsigned int

//蜂鸣器定义


//按键判断及按键键值


//键盘字符表(其中注意2,5,8后各保留一个空格)
const char KEY_CHAR_TABLE[] = "012 345 678 9.C";
//液晶显示字符串函数
extern void LCD_ShowString(INT8U x, INT8U y,char *str);

//LCD显示输出缓冲(价格/重量/金额)的最大长度
//因为要预留结束标志,实际串长比定义少1位
#define PLEN   7
#define WLEN   4
#define SUMLEN 10
//LCD显示输出缓冲(价格/重量/金额)
char disp_buffer_P[PLEN];
char disp_buffer_W[WLEN];
char disp_buffer_SUM[SUMLEN];
//价格输入缓冲的指针
INT8U NumberPtr = 0;

//-----------------------------------------------------------------
// 蜂鸣器输出
//-----------------------------------------------------------------
void Sounder()
{ 


}

//-----------------------------------------------------------------
// 处理运算并显示金额
//-----------------------------------------------------------------
void Compute_and_show_sum()
{ 


}

//-----------------------------------------------------------------
// 处理键盘操作
//-----------------------------------------------------------------
void KeyBoard_Handle()
{

}
