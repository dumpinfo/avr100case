//-----------------------------------------------------------------
//  ����: ���ӳӷ������
//-----------------------------------------------------------------
//  ˵��: ��������ʱ,LCD��ʾ��ǰѹ��(δת��Ϊ����),������ļ۸�
//        ֱ�����ֵ���,LCD��ʾ������Ӧ�����.       
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

//���������
extern void Sounder();
//Һ����غ���
extern void Initialize_LCD();
extern void LCD_ShowString(INT8U x, INT8U y,char *str);
//���̴�������������ʾ����
extern void KeyBoard_Handle();
extern void Compute_and_show_sum();
//Һ����ʾ����(����)
extern char disp_buffer_W[];
//ģ��ת�������ѹ��������
volatile INT16U AD_Result,Pre_Result = 0,Pressure_Value;
//-----------------------------------------------------------------
// ������
//-----------------------------------------------------------------
int main()
{


}
