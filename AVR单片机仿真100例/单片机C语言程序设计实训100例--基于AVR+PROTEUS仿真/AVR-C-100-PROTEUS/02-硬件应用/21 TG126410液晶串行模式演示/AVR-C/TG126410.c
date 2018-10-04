//-----------------------------------------------------------------
//  名称: TG126410LCD显示驱动程序(SEG1565) (不带字库)
//-----------------------------------------------------------------
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#define INT8U   unsigned char
#define INT16U  unsigned int

//液晶引脚操作定义








//SEG1565显示地址控制命令





//大写字母R的8*8点阵(纵向取模,字节倒序)
const INT8U R[8] = { 0x00,0xFE,0x12,0x32,0x52,0x8C,0x00,0x00 };

//案例文件夹下的一幅图像点阵(存放于程序Flash空间)------------------------------
prog_uchar ICONs_Picture[1024] = { //纵向取模,字节倒序










};

//-----------------------------------------------------------------
// 写指令
//-----------------------------------------------------------------
void Write_Command(INT8U cmd)
{   






}

//-----------------------------------------------------------------
// 写数据
//-----------------------------------------------------------------
void Write_Data(INT8U dat)
{   





}

//-----------------------------------------------------------------
// LCD初始化
//-----------------------------------------------------------------
void LCD_Initialize()
{





}

//-----------------------------------------------------------------
// 全屏显示或全屏不显示(形成全黑色屏幕/或底色屏幕)
//-----------------------------------------------------------------
void Full_Disp_ON_OFF(INT8U k)
{




}

//-----------------------------------------------------------------
// 显示边框
//-----------------------------------------------------------------
void Disp_Frame()
{





}

//-----------------------------------------------------------------
// 正显与反显棋板
//-----------------------------------------------------------------
void Disp_Checker(INT8U k)
{



  
}

//-----------------------------------------------------------------
// R字符平铺画面
//-----------------------------------------------------------------
void Disp_R()
{


  
}

//-----------------------------------------------------------------
// 显示案例文件夹下的一幅图片(代码与上一函数相同,区别仅在于使用了不同的点阵数组)
//-----------------------------------------------------------------
void Disp_Picture()
{


   
}
