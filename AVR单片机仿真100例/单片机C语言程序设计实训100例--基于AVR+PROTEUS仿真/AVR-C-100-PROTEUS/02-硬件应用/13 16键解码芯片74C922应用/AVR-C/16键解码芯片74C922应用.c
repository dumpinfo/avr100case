//-----------------------------------------------------------------
//  名称: 16键解码芯片74C922应用
//-----------------------------------------------------------------
//  说明: 本例因为使用了74C922解码芯片,使得程序代码非常简单
//        在按下不同按键时,数码管将显示对应键值.
//
//-----------------------------------------------------------------
#include <avr/io.h>
#include <util/delay.h>
#define INT8U   unsigned char
#define INT16U  unsigned int

//蜂鸣器 
#define BEEP() PORTD ^= _BV(PD7) 
//按键判断(有键按下时,74C922的DA引脚向PA7输出高电平)




//获取键值




//0-9,A-F的数码管段码
const INT8U SEG_CODE[] = 
{ 
  0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,
  0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71
};
//-----------------------------------------------------------------
// 发声子程序	 
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
