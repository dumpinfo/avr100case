//-----------------------------------------------------------------
//  名称: PG160128液晶图形滚动演示
//-----------------------------------------------------------------
//  说明: 本例可显示一幅图像,可控制图像滚动,反白,合上"图文"开关时,
//        还可以显示一幅条形统计图.
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

extern void Clear_Screen();                       //清屏
extern INT8U LCD_Initialise();                    //LCD初始化
extern INT8U LCD_Write_Command(INT8U cmd);        //写无参数的命令
                                                  //写双参数命令
extern INT8U LCD_Write_Command_P2(INT8U cmd,INT8U para1,INT8U para2); 
extern INT8U LCD_Write_Data(INT8U dat);           //写数据
extern void Set_LCD_POS(INT8U row, INT8U col);	  //设置当前地址
                                                  //绘制线条   
extern void Line(INT8U x1,INT8U y1, INT8U x2,INT8U y2, INT8U Mode);
                                                  //显示字符串
extern INT8U Display_Str_at_xy(INT8U x,INT8U y,char *fmt); 
extern INT8U LCD_WIDTH;
extern INT8U LCD_HEIGHT;

//开关定义








//当前操作序号
INT8U Current_Operation = 0;
//待显示的统计数据
INT8U Statistics_Data[] = {20,70,80,40,90,65,30};
//-----------------------------------------------------------------
// 绘制条形图
//-----------------------------------------------------------------
void Draw_Bar_Graph(INT8U d[])
{






}

//-----------------------------------------------------------------
// 主程序
//-----------------------------------------------------------------
int main()
{














}
