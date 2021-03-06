//-----------------------------------------------------------------
//  名称: 数码管显示两路A/D转换结果
//-----------------------------------------------------------------
//  说明: 调节RV1和RV2时,两路模拟电压将显示在8只集成式数码管上.
//
//-----------------------------------------------------------------
#define F_CPU 4000000UL  //4MHz
#include <avr/io.h>
#include <util/delay.h>
#define INT8U   unsigned char
#define INT16U  unsigned int

//各数字的数码管段码,最后一位为空白
const INT8U SEG_CODE[] =
{0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0xFF};
//两路模拟转换结果显示缓冲,显示格式为:X.XX X.XX ,第4位和第8位不显示
INT8U Display_Buffer[] = {0,0,0,10,0,0,0,10};
//-----------------------------------------------------------------
// 对通道CH进行模数转换
//-----------------------------------------------------------------
void ADC_Convert(INT8U CH)
{



}

//-----------------------------------------------------------------
// 主程序
//-----------------------------------------------------------------
int main()
{





}
