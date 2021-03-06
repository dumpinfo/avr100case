//-----------------------------------------------------------------
//  名称: 高度仿真的可调式数码管电子钟
//-----------------------------------------------------------------
//  说明: 本例在Proteus中选用了高度仿真的电子钟元器件,并添加了
//        时分调整功能,冒号闪烁显示,AM/PM切换,12/24小时制选择等.
//                
//-----------------------------------------------------------------
#define F_CPU 4000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define INT8U   unsigned char
#define INT16U  unsigned int

//时钟设置开关及按键  





//时钟指示组件控制引脚定义(不要误定义为1,2,3,4)



//3-8译码器使能控制引脚定义



//当前时间(时:分:秒)(本例设为12:59:40,这样可便于快速观察到切换效果.)
INT8U current_Time[] = {12,59,40};
//时分秒显示缓冲(各占两位,共6字节),
//第7个字节0x00控制(AM/PM),(12/24),(SET)及":"显示.
//该字节低四位的对应关系是XXXX-0(:)0(AM/PM)0(12/24)0(SET)
//这与上述的四个#define对应.0x00默认设置AM,12,非SET
INT8U disp_Buffer[] = {0,0,0,0,0,0,0x00};

//本例函数申明



//-----------------------------------------------------------------
// 根据当前时间刷新时分秒显示缓冲
//-----------------------------------------------------------------
void Refresh_Disp_Buffer()
{


}

//-----------------------------------------------------------------
// 加时
//-----------------------------------------------------------------
void Add_Hour()
{


}

//-----------------------------------------------------------------
// 加分
//-----------------------------------------------------------------
void Add_Miniute()
{


}

//-----------------------------------------------------------------
// 显示时间
//-----------------------------------------------------------------
void Display_Time()
{


}

//-----------------------------------------------------------------
// 处理12/24小时制按键切换后的数据变更及AM/PM显示开关
//-----------------------------------------------------------------
void Handle_12_24_and_AM_PM_Switch()
{


}

//-----------------------------------------------------------------
// 时钟调整与设置
//-----------------------------------------------------------------
void Adjust_and_Set_Clock()
{


}

//------------------------------------------------------------------
// 主程序
//------------------------------------------------------------------
int main() 
{  


} 

//-----------------------------------------------------------------
// T/C2溢出中断控制时钟运行
//-----------------------------------------------------------------
ISR (TIMER2_OVF_vect )
{


}
