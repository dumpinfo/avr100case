//-----------------------------------------------------------------
//  名称: 数码管显示4×4 键盘矩阵按键序号
//-----------------------------------------------------------------
//  说明: 本例运行时,数码管会显示所按下的任意按键在键盘矩阵上的位置.
//        扫描程序首先判断按键发生在哪一列,然后判断按键发生在哪一行， 
//        由列号和行号即可得到键盘按键序号.
//            
//-----------------------------------------------------------------
#include <avr/io.h>
#include <util/delay.h>
#define INT8U   unsigned char
#define INT16U  unsigned int

#define BEEP() PORTD ^= _BV(PD7)  //蜂鸣器 

//0-9,A-F的数码管段码
const INT8U SEG_CODE[] = 
{ 
  0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,
  0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71
};

//当前按键序号,该矩阵中序号范围为0-15,16表示无按键
INT8U KeyNo = 16 ; 

//-----------------------------------------------------------------
// 判断键盘矩阵是否有键按下
//-----------------------------------------------------------------
INT8U KeyMatrix_Down()
{


}
 
//-----------------------------------------------------------------
// 键盘矩阵扫描子程序
//-----------------------------------------------------------------
void Keys_Scan()
{ 


}

//-----------------------------------------------------------------	
// 蜂鸣器子程序	 
//-----------------------------------------------------------------
void Beep()
{





   
}

//-----------------------------------------------------------------
// 主程序
//-----------------------------------------------------------------
int main()
{










}
