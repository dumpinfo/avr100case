//-----------------------------------------------------------------
//  名称: 红外遥控器受控端程序
//-----------------------------------------------------------------
//  说明: 程序运行时,根据SONY红外协议接收数据并解码,然后将12位编码
//        以16进制数形式显示在三只数码管上.
//  
//-----------------------------------------------------------------
#define F_CPU 2000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define INT8U   unsigned char
#define INT16U  unsigned int

//蜂鸣器定义
#define BEEP() PORTD ^= _BV(PD7)
//读取红外输入信号
#define Read_IR() (PIND & _BV(PD2))

//0-9,A-F的数码管段码
const INT8U SEG_CODE[] = 
{ 0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,
  0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71
};	
 
//接收到的12位红外数据及上次接收的数据
INT16U IR_D12 = 0x0000, Old_IR_D12 = 0x0000; 
//12位二进制编码分解为3个16进制数位
INT8U Digit_Buffer[] = {0,0,0};
//-----------------------------------------------------------------
// 输出提示音
//-----------------------------------------------------------------
void Sounder()				
{


}

//-----------------------------------------------------------------
// 主程序
//-----------------------------------------------------------------
int main()				
{


}

//-----------------------------------------------------------------
// INT0中断函数 (通过实测,以122,242为两个时长的上限)
//-----------------------------------------------------------------
ISR (INT0_vect)
{     


}
