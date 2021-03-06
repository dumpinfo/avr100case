//-----------------------------------------------------------------
//  名称:开机显示EPROM27C256中的画面
//-----------------------------------------------------------------
//  说明:开机时系统从EPROM27C256中读取画面并显示到12864LCD
//         
//-----------------------------------------------------------------
#include <avr/io.h>
#include <util/delay.h>
#define INT8U   unsigned char
#define INT16U  unsigned int

//12864LCD相关函数






//外部内存地址地址定义
#define EXTMEM_START_ADDR (INT8U*)0x8000
//开机时首先显示在LCD上的文字 
const INT8U Word_String[] = 
{
/*---------------EP----------------*/
0xFF,0x0F,0x0F,0x4F,0x4F,0x4F,0x4F,0xFF,0xFF,0x0F,0x0F,0xCF,0xCF,0x0F,0x1F,0xFF,
0xFF,0xF0,0xF0,0xF2,0xF2,0xF2,0xF2,0xFF,0xFF,0xF0,0xF0,0xFC,0xFC,0xFC,0xFE,0xFF,
/*---------------RO----------------*/
0xFF,0x0F,0x0F,0x4F,0x4F,0x4F,0x0F,0x1F,0xFF,0xFF,0x3F,0x1F,0xCF,0xCF,0xCF,0x1F,
0xFF,0xF0,0xF0,0xFE,0xFE,0xFC,0xF8,0xF3,0xF7,0xFF,0xFC,0xF8,0xF3,0xF3,0xF3,0xF8,
/*---------------M----------------*/
0x3F,0xFF,0xFF,0x0F,0x0F,0x1F,0xFF,0xFF,0x1F,0x0F,0x0F,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFC,0xFF,0xFF,0xF0,0xF0,0xFE,0xF0,0xF0,0xFE,0xF0,0xF0,0xFF,0xFF,0xFF,0xFF,0xFF,
/*---------------开----------------*/
 0x3F,0x39,0x39,0x39,0x01,0x01,0x39,0x39,0x39,0x01,0x01,0x39,0x39,0x39,0x3F,0xFF,
 0xFF,0xDF,0x9F,0xC7,0xE0,0xF8,0xFF,0xFF,0xFF,0x80,0x80,0xFF,0xFF,0xFF,0xFF,0xFF,
/*---------------机----------------*/
 0xE7,0x67,0x00,0x00,0x67,0xE7,0xFF,0x01,0x01,0xF9,0xF9,0x01,0x01,0xFF,0xFF,0xFF,
 0xF9,0xFC,0x80,0x80,0xFE,0xDC,0x8F,0xC0,0xF0,0xFF,0xFF,0xC0,0x80,0x9F,0x8F,0xFF,











};

//-----------------------------------------------------------------
// 烧写到EPROM27C256的屏幕图像数据,宽度x高度=128x40 (共128*40/8 = 640字节)
// 这些数据已经通过BIN文件绑定到Proteus中的27C256EPROM芯片
//-----------------------------------------------------------------
////const INT8U Start_Screen_Image[] = {






//} ;
 
//-----------------------------------------------------------------
// 主程序
//-----------------------------------------------------------------
int main()
{

}
