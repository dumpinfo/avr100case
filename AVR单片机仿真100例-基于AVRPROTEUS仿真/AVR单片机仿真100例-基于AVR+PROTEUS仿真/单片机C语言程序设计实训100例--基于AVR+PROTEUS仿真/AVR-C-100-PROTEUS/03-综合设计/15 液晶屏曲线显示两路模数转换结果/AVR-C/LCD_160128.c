//-----------------------------------------------------------------
// 名称:160128LCD显示控制程序
//-----------------------------------------------------------------
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "LCD_160128.h" 
#define INT8U   unsigned char
#define INT16U  unsigned int

//ASCII字模8*8



//汉字字模12*12




//ASC字符点阵库
prog_uchar ASC_MSK[96 * 12] = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xff,0xff, // <0x20时
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// ' '
0x00,0x30,0x78,0x78,0x78,0x30,0x30,0x00,0x30,0x30,0x00,0x00,// '!'
0x00,0x66,0x66,0x66,0x24,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// '"'
0x00,0x6c,0x6c,0xfe,0x6c,0x6c,0x6c,0xfe,0x6c,0x6c,0x00,0x00,// '#'
0x30,0x30,0x7c,0xc0,0xc0,0x78,0x0c,0x0c,0xf8,0x30,0x30,0x00,// '$'
0x00,0x00,0x00,0xc4,0xcc,0x18,0x30,0x60,0xcc,0x8c,0x00,0x00,// '%'
0x00,0x70,0xd8,0xd8,0x70,0xfa,0xde,0xcc,0xdc,0x76,0x00,0x00,// '&'
0x00,0x30,0x30,0x30,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// '''
0x00,0x0c,0x18,0x30,0x60,0x60,0x60,0x30,0x18,0x0c,0x00,0x00,// '('
0x00,0x60,0x30,0x18,0x0c,0x0c,0x0c,0x18,0x30,0x60,0x00,0x00,// ')'
0x00,0x00,0x00,0x66,0x3c,0xff,0x3c,0x66,0x00,0x00,0x00,0x00,// '*'
0x00,0x00,0x00,0x18,0x18,0x7e,0x18,0x18,0x00,0x00,0x00,0x00,// '+'
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x38,0x60,0x00,// ','
0x00,0x00,0x00,0x00,0x00,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,// '-'
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x38,0x00,0x00,// '.'
0x00,0x00,0x02,0x06,0x0c,0x18,0x30,0x60,0xc0,0x80,0x00,0x00,// '/'
0x00,0x7c,0xc6,0xce,0xde,0xd6,0xf6,0xe6,0xc6,0x7c,0x00,0x00,// '0'
0x00,0x10,0x30,0xf0,0x30,0x30,0x30,0x30,0x30,0xfc,0x00,0x00,// '1'
0x00,0x78,0xcc,0xcc,0x0c,0x18,0x30,0x60,0xcc,0xfc,0x00,0x00,// '2'
0x00,0x78,0xcc,0x0c,0x0c,0x38,0x0c,0x0c,0xcc,0x78,0x00,0x00,// '3'
0x00,0x0c,0x1c,0x3c,0x6c,0xcc,0xfe,0x0c,0x0c,0x1e,0x00,0x00,// '4'
0x00,0xfc,0xc0,0xc0,0xc0,0xf8,0x0c,0x0c,0xcc,0x78,0x00,0x00,// '5'
0x00,0x38,0x60,0xc0,0xc0,0xf8,0xcc,0xcc,0xcc,0x78,0x00,0x00,// '6'
0x00,0xfe,0xc6,0xc6,0x06,0x0c,0x18,0x30,0x30,0x30,0x00,0x00,// '7'
0x00,0x78,0xcc,0xcc,0xec,0x78,0xdc,0xcc,0xcc,0x78,0x00,0x00,// '8'
0x00,0x78,0xcc,0xcc,0xcc,0x7c,0x18,0x18,0x30,0x70,0x00,0x00,// '9'
0x00,0x00,0x00,0x38,0x38,0x00,0x00,0x38,0x38,0x00,0x00,0x00,// ':'
0x00,0x00,0x00,0x38,0x38,0x00,0x00,0x38,0x38,0x18,0x30,0x00,// ';'
0x00,0x0c,0x18,0x30,0x60,0xc0,0x60,0x30,0x18,0x0c,0x00,0x00,// '<'
0x00,0x00,0x00,0x00,0x7e,0x00,0x7e,0x00,0x00,0x00,0x00,0x00,// '='
0x00,0x60,0x30,0x18,0x0c,0x06,0x0c,0x18,0x30,0x60,0x00,0x00,// '>'
0x00,0x78,0xcc,0x0c,0x18,0x30,0x30,0x00,0x30,0x30,0x00,0x00,// '?'
0x00,0x7c,0xc6,0xc6,0xde,0xde,0xde,0xc0,0xc0,0x7c,0x00,0x00,// '@'
0x00,0x30,0x78,0xcc,0xcc,0xcc,0xfc,0xcc,0xcc,0xcc,0x00,0x00,// 'A'
0x00,0xfc,0x66,0x66,0x66,0x7c,0x66,0x66,0x66,0xfc,0x00,0x00,// 'B'
0x00,0x3c,0x66,0xc6,0xc0,0xc0,0xc0,0xc6,0x66,0x3c,0x00,0x00,// 'C'
0x00,0xf8,0x6c,0x66,0x66,0x66,0x66,0x66,0x6c,0xf8,0x00,0x00,// 'D'
0x00,0xfe,0x62,0x60,0x64,0x7c,0x64,0x60,0x62,0xfe,0x00,0x00,// 'E'
0x00,0xfe,0x66,0x62,0x64,0x7c,0x64,0x60,0x60,0xf0,0x00,0x00,// 'F'
0x00,0x3c,0x66,0xc6,0xc0,0xc0,0xce,0xc6,0x66,0x3e,0x00,0x00,// 'G'
0x00,0xcc,0xcc,0xcc,0xcc,0xfc,0xcc,0xcc,0xcc,0xcc,0x00,0x00,// 'H'
0x00,0x78,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x78,0x00,0x00,// 'I'
0x00,0x1e,0x0c,0x0c,0x0c,0x0c,0xcc,0xcc,0xcc,0x78,0x00,0x00,// 'J'
0x00,0xe6,0x66,0x6c,0x6c,0x78,0x6c,0x6c,0x66,0xe6,0x00,0x00,// 'K'
0x00,0xf0,0x60,0x60,0x60,0x60,0x62,0x66,0x66,0xfe,0x00,0x00,// 'L'
0x00,0xc6,0xee,0xfe,0xfe,0xd6,0xc6,0xc6,0xc6,0xc6,0x00,0x00,// 'M'
0x00,0xc6,0xc6,0xe6,0xf6,0xfe,0xde,0xce,0xc6,0xc6,0x00,0x00,// 'N'
0x00,0x38,0x6c,0xc6,0xc6,0xc6,0xc6,0xc6,0x6c,0x38,0x00,0x00,// 'O'
0x00,0xfc,0x66,0x66,0x66,0x7c,0x60,0x60,0x60,0xf0,0x00,0x00,// 'P'
0x00,0x38,0x6c,0xc6,0xc6,0xc6,0xce,0xde,0x7c,0x0c,0x1e,0x00,// 'Q'
0x00,0xfc,0x66,0x66,0x66,0x7c,0x6c,0x66,0x66,0xe6,0x00,0x00,// 'R'
0x00,0x78,0xcc,0xcc,0xc0,0x70,0x18,0xcc,0xcc,0x78,0x00,0x00,// 'S'
0x00,0xfc,0xb4,0x30,0x30,0x30,0x30,0x30,0x30,0x78,0x00,0x00,// 'T'
0x00,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x78,0x00,0x00,// 'U'
0x00,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0x78,0x30,0x00,0x00,// 'V'
0x00,0xc6,0xc6,0xc6,0xc6,0xd6,0xd6,0x6c,0x6c,0x6c,0x00,0x00,// 'W'
0x00,0xcc,0xcc,0xcc,0x78,0x30,0x78,0xcc,0xcc,0xcc,0x00,0x00,// 'X'
0x00,0xcc,0xcc,0xcc,0xcc,0x78,0x30,0x30,0x30,0x78,0x00,0x00,// 'Y'
0x00,0xfe,0xce,0x98,0x18,0x30,0x60,0x62,0xc6,0xfe,0x00,0x00,// 'Z'
0x00,0x3c,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x3c,0x00,0x00,// '['
0x00,0x00,0x80,0xc0,0x60,0x30,0x18,0x0c,0x06,0x02,0x00,0x00,// '\'
0x00,0x3c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x3c,0x00,0x00,// ']'
0x10,0x38,0x6c,0xc6,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// '^'
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x00,// '_'
0x30,0x30,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// '`'
0x00,0x00,0x00,0x00,0x78,0x0c,0x7c,0xcc,0xcc,0x76,0x00,0x00,// 'a'
0x00,0xe0,0x60,0x60,0x7c,0x66,0x66,0x66,0x66,0xdc,0x00,0x00,// 'b'
0x00,0x00,0x00,0x00,0x78,0xcc,0xc0,0xc0,0xcc,0x78,0x00,0x00,// 'c'
0x00,0x1c,0x0c,0x0c,0x7c,0xcc,0xcc,0xcc,0xcc,0x76,0x00,0x00,// 'd'
0x00,0x00,0x00,0x00,0x78,0xcc,0xfc,0xc0,0xcc,0x78,0x00,0x00,// 'e'
0x00,0x38,0x6c,0x60,0x60,0xf8,0x60,0x60,0x60,0xf0,0x00,0x00,// 'f'
0x00,0x00,0x00,0x00,0x76,0xcc,0xcc,0xcc,0x7c,0x0c,0xcc,0x78,// 'g'
0x00,0xe0,0x60,0x60,0x6c,0x76,0x66,0x66,0x66,0xe6,0x00,0x00,// 'h'
0x00,0x18,0x18,0x00,0x78,0x18,0x18,0x18,0x18,0x7e,0x00,0x00,// 'i'
0x00,0x0c,0x0c,0x00,0x3c,0x0c,0x0c,0x0c,0x0c,0xcc,0xcc,0x78,// 'j'
0x00,0xe0,0x60,0x60,0x66,0x6c,0x78,0x6c,0x66,0xe6,0x00,0x00,// 'k'
0x00,0x78,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x7e,0x00,0x00,// 'l'
0x00,0x00,0x00,0x00,0xfc,0xd6,0xd6,0xd6,0xd6,0xc6,0x00,0x00,// 'm'
0x00,0x00,0x00,0x00,0xf8,0xcc,0xcc,0xcc,0xcc,0xcc,0x00,0x00,// 'n'
0x00,0x00,0x00,0x00,0x78,0xcc,0xcc,0xcc,0xcc,0x78,0x00,0x00,// 'o'
0x00,0x00,0x00,0x00,0xdc,0x66,0x66,0x66,0x66,0x7c,0x60,0xf0,// 'p'
0x00,0x00,0x00,0x00,0x76,0xcc,0xcc,0xcc,0xcc,0x7c,0x0c,0x1e,// 'q'
0x00,0x00,0x00,0x00,0xec,0x6e,0x76,0x60,0x60,0xf0,0x00,0x00,// 'r'
0x00,0x00,0x00,0x00,0x78,0xcc,0x60,0x18,0xcc,0x78,0x00,0x00,// 's'
0x00,0x00,0x20,0x60,0xfc,0x60,0x60,0x60,0x6c,0x38,0x00,0x00,// 't'
0x00,0x00,0x00,0x00,0xcc,0xcc,0xcc,0xcc,0xcc,0x76,0x00,0x00,// 'u'
0x00,0x00,0x00,0x00,0xcc,0xcc,0xcc,0xcc,0x78,0x30,0x00,0x00,// 'v'
0x00,0x00,0x00,0x00,0xc6,0xc6,0xd6,0xd6,0x6c,0x6c,0x00,0x00,// 'w'
0x00,0x00,0x00,0x00,0xc6,0x6c,0x38,0x38,0x6c,0xc6,0x00,0x00,// 'x'
0x00,0x00,0x00,0x00,0x66,0x66,0x66,0x66,0x3c,0x0c,0x18,0xf0,// 'y'
0x00,0x00,0x00,0x00,0xfc,0x8c,0x18,0x60,0xc4,0xfc,0x00,0x00,// 'z'
0x00,0x1c,0x30,0x30,0x60,0xc0,0x60,0x30,0x30,0x1c,0x00,0x00,// '{'
0x00,0x18,0x18,0x18,0x18,0x00,0x18,0x18,0x18,0x18,0x00,0x00,// '|'
0x00,0xe0,0x30,0x30,0x18,0x0c,0x18,0x30,0x30,0xe0,0x00,0x00,// '}'
0x00,0x73,0xda,0xce,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// '~'
};

struct typFNT_GB16 // 汉字字模显示数据结构
{
  char  Index[2];
  INT8U Msk[24];
};

//本例汉字点阵库
const struct typFNT_GB16 GB_16[] = { //12*12点阵,宋体小五号,用Zimo软件取得点阵
{{"液"},{0x81,0x00,0x5F,0xE0,0x25,0x00,0x85,0xC0,0xAA,0x40,0x4E,0xC0,
         0x5A,0x40,0x49,0x80,0xC8,0x80,0x49,0x40,0x4E,0x20,0x00,0x00}},
{{"晶"},{0x1F,0x80,0x10,0x80,0x1F,0x80,0x10,0x80,0x1F,0x80,0x00,0x00,
         0x7B,0xE0,0x4A,0x20,0x7B,0xE0,0x4A,0x20,0x7B,0xE0,0x00,0x00}},
{{"屏"},{0x7F,0xC0,0x40,0x40,0x7F,0xC0,0x50,0x80,0x49,0x00,0x5F,0xC0,
         0x49,0x00,0x7F,0xE0,0x49,0x00,0x91,0x00,0xA1,0x00,0x00,0x00}},
{{"转"},{0x21,0x00,0xF9,0x00,0x47,0xE0,0x61,0x00,0xA7,0xE0,0xFA,0x00,
         0x23,0xC0,0x38,0x40,0xE0,0x80,0x23,0x00,0x20,0x80,0x00,0x00}},
{{"换"},{0x22,0x00,0x27,0x80,0xF8,0x80,0x2F,0xC0,0x29,0x40,0x39,0x40,















};

INT8U   gCurRow,gCurCol; // 图形当前行、列存储，行高16点，列宽8点
INT16U  txthome,grhome;
//-----------------------------------------------------------------
// LCD控制相关函数
//-----------------------------------------------------------------
INT8U Status_BIT_01();   // 状态位STA1,STA0判断（读写指令和读写数据）
INT8U Status_BIT_3();    // 状态位ST3判断（数据自动写状态）

INT8U LCD_Write_Command(INT8U cmd);                             //写无参数的指令
INT8U LCD_Write_Command_P1(INT8U cmd,INT8U para1);              //写单参数的指令
INT8U LCD_Write_Command_P2 (INT8U cmd,INT8U para1,INT8U para2); //写双参数的指令
INT8U LCD_Write_Data(INT8U dat);                                //写数据
INT8U LCD_Read_Data();                                          //读数据
void LCD_Initialise();                                          //LCD初始化
void Set_LCD_POS(INT8U row, INT8U col);                         //设置当前地址
void OutToLCD(INT8U Dat,INT8U x,INT8U y);                       //输出到LCD 

//-----------------------------------------------------------------
// 状态位STA1,STA0判断(读写指令和读写数据)
//-----------------------------------------------------------------
INT8U Status_BIT_01() 
{





}

//-----------------------------------------------------------------
// 状态位ST3判断(数据自动写状态)
//-----------------------------------------------------------------
INT8U Status_BIT_3() 
{




}

//-----------------------------------------------------------------
// 写双参数的指令
//-----------------------------------------------------------------
INT8U LCD_Write_Command_P2(INT8U cmd,INT8U para1,INT8U para2) 
{




}

//-----------------------------------------------------------------
// 写单参数的指令
//-----------------------------------------------------------------
INT8U LCD_Write_Command_P1(INT8U cmd,INT8U para1) 
{


}

//-----------------------------------------------------------------
// 写无参数的指令
//-----------------------------------------------------------------
INT8U LCD_Write_Command(INT8U cmd) 
{




}

//-----------------------------------------------------------------
// 写数据
//-----------------------------------------------------------------
INT8U LCD_Write_Data(INT8U dat) 
{


}

//-----------------------------------------------------------------
// 读数据
//-----------------------------------------------------------------
INT8U LCD_Read_Data() 
{


}

//-----------------------------------------------------------------
// 设置当前地址
//-----------------------------------------------------------------
void Set_LCD_POS(INT8U row, INT8U col)
{


}

//-----------------------------------------------------------------
// LCM 初始化
//-----------------------------------------------------------------
void LCD_Initialise()
{


}

//-----------------------------------------------------------------
// 清屏
//-----------------------------------------------------------------
void Cls()
{


}

//-----------------------------------------------------------------
// ASCII及汉字显示
//-----------------------------------------------------------------
void Display_Str_at_xy(INT8U x,INT8U y,char *Buffer,INT8U wb)
{


}

//-----------------------------------------------------------------
// 输出起点x不是8的倍数时,原字节分成两部分输出到LCD
//-----------------------------------------------------------------
void OutToLCD(INT8U Dat,INT8U x,INT8U y)
{


}

//-----------------------------------------------------------------
// 绘点函数
// 参数:点的坐标,模式1/0分别为显示与清除点
//-----------------------------------------------------------------
void Pixel(INT8U x,INT8U y, INT8U Mode)
{


}

//-----------------------------------------------------------------
// 两数交换
//-----------------------------------------------------------------
void Exchange(INT8U *a, INT8U *b)


}

//-----------------------------------------------------------------
// 绘制直线函数
// 参数:起点与终点坐标,模式为显示(1)或清除(0),点阵不超过255*255)
//-----------------------------------------------------------------
void Line(INT8U x1,INT8U y1,INT8U x2,INT8U y2,INT8U Mode)
{


}

//-----------------------------------------------------------------
// 绘制图像
//-----------------------------------------------------------------
void Draw_Image(INT8U *G_Buffer, INT8U Start_Row, INT8U Start_Col)
{   


}
