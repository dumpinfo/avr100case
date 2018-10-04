//-----------------------------------------------------------------
//  名称: LED模拟交通灯
//-----------------------------------------------------------------
//  说明: 东西向绿灯亮若干秒后,黄灯闪烁,闪烁5次后亮红灯,
//        红灯亮后,南北向由红灯变为绿灯,若干秒后南北向黄灯闪烁, 
//        闪烁5次后亮红灯,东西向绿灯亮,如此往复.
//        本例将切换时间设得较短，以便快速观察运行效果.
// 
//-----------------------------------------------------------------
#include <avr/io.h>
#include <util/delay.h>
#define INT8U   unsigned char
#define INT16U  unsigned int

#define     RED_EW_ON()  PORTC &= ~_BV(PC0)    //东西向指示灯开
#define  YELLOW_EW_ON()  PORTC &= ~_BV(PC1)
#define   GREEN_EW_ON()  PORTC &= ~_BV(PC2)

#define     RED_EW_OFF() PORTC |=  _BV(PC0)    //东西向指示灯关
#define  YELLOW_EW_OFF() PORTC |=  _BV(PC1)
#define   GREEN_EW_OFF() PORTC |=  _BV(PC2)
 
#define     RED_SN_ON()  PORTC &= ~_BV(PC3)    //南北向指示灯开
#define  YELLOW_SN_ON()  PORTC &= ~_BV(PC4)
#define   GREEN_SN_ON()  PORTC &= ~_BV(PC5)

#define     RED_SN_OFF() PORTC |=  _BV(PC3)    //南北向指示灯关
#define  YELLOW_SN_OFF() PORTC |=  _BV(PC4)
#define   GREEN_SN_OFF() PORTC |=  _BV(PC5)

#define   YELLOW_EW_BLINK() PORTC ^= _BV(PC1)  //东西向黄灯闪烁
#define   YELLOW_SN_BLINK() PORTC ^= _BV(PC4)  //南北向黄灯闪烁

//闪烁次数,操作类型变量
INT8U Flash_Count = 0, Operation_Type = 1;
//-----------------------------------------------------------------
// 交通灯切换子程序
//-----------------------------------------------------------------
void Traffic_Light()
{



}

//-----------------------------------------------------------------
// 主程序
//-----------------------------------------------------------------
int main()
{


}
