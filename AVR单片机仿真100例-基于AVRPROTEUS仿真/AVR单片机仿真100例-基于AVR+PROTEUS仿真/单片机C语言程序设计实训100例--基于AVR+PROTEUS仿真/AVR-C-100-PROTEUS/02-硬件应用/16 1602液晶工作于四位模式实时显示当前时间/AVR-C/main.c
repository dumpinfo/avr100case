//-----------------------------------------------------------------
//  ����: 1602LCD��������λģʽʵʱ��ʾ��ǰʱ��
//-----------------------------------------------------------------
//  ˵��: ����һ������ͬ���Ǳ���Һ�����ݶ˿ڽ�ʹ������ֻ����,ʵ��
//        ����ʱ���ʵʱ��ʾ.
//                          
//-----------------------------------------------------------------
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#define INT8U   unsigned char
#define INT16U  unsigned int

//Һ����غ���
extern void Initialize_LCD();
extern void LCD_ShowString(INT8U x, INT8U y,char *str);
// DS1302��غ���������
extern void GetDateTime();
extern INT8U DateTime[];
extern char *WEEK[];
//LCD��ʾ����
char LCD_DSY_BUFFER[17];
//-----------------------------------------------------------------
// ������     
//-----------------------------------------------------------------
int main()
{

















}
