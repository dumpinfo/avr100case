//-----------------------------------------------------------------
//  名称: 普通电话拨号键盘应用
//-----------------------------------------------------------------
//  说明: 本例将电话拨号键盘上所拨号码显示在1602液晶屏上
//
//-----------------------------------------------------------------
#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define INT8U   unsigned char
#define INT16U  unsigned int

//液晶及键盘相关函数
extern void Initialize_LCD();
extern void Write_LCD_Command(INT8U cmd);
extern void Write_LCD_Data(INT8U dat);
extern void LCD_ShowString(INT8U x, INT8U y,char *str);
extern INT8U GetKey();

//蜂鸣器操作定义
#define SPK() PORTD ^= _BV(PD7) 
//键盘序号与键盘符号映射表
const char Key_Table[] = {'1','2','3','4','5','6','7','8','9','*','0','#'};
//或写成:
//const char Key_Table[] = "123456789*0#";
//键盘拨号数字缓冲(初始时为17个空格)
char Dial_Code_Str[] = {"                "}; 
//计时累加变量
INT16U tCount = 0;
//按键键值
INT8U KeyNo;
//-----------------------------------------------------------------
// T0控制按键声音
//-----------------------------------------------------------------
ISR (TIMER0_OVF_vect)
{


}

//-----------------------------------------------------------------
// 主程序 
//-----------------------------------------------------------------
int main()
{


}
