//-----------------------------------------------------------------
//  ����: PG160128Һ��ͼ�ι�����ʾ
//-----------------------------------------------------------------
//  ˵��: ��������ʾһ��ͼ��,�ɿ���ͼ�����,����,����"ͼ��"����ʱ,
//        ��������ʾһ������ͳ��ͼ.
//
//-----------------------------------------------------------------
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdio.h>
#include "PG160128.h"
#include "PictureDots.h"
#define INT8U  unsigned char
#define INT16U unsigned int 

extern void Clear_Screen();                       //����
extern INT8U LCD_Initialise();                    //LCD��ʼ��
extern INT8U LCD_Write_Command(INT8U cmd);        //д�޲���������
                                                  //д˫��������
extern INT8U LCD_Write_Command_P2(INT8U cmd,INT8U para1,INT8U para2); 
extern INT8U LCD_Write_Data(INT8U dat);           //д����
extern void Set_LCD_POS(INT8U row, INT8U col);	  //���õ�ǰ��ַ
                                                  //��������   
extern void Line(INT8U x1,INT8U y1, INT8U x2,INT8U y2, INT8U Mode);
                                                  //��ʾ�ַ���
extern INT8U Display_Str_at_xy(INT8U x,INT8U y,char *fmt); 
extern INT8U LCD_WIDTH;
extern INT8U LCD_HEIGHT;

//���ض���








//��ǰ�������
INT8U Current_Operation = 0;
//����ʾ��ͳ������
INT8U Statistics_Data[] = {20,70,80,40,90,65,30};
//-----------------------------------------------------------------
// ��������ͼ
//-----------------------------------------------------------------
void Draw_Bar_Graph(INT8U d[])
{






}

//-----------------------------------------------------------------
// ������
//-----------------------------------------------------------------
int main()
{














}
