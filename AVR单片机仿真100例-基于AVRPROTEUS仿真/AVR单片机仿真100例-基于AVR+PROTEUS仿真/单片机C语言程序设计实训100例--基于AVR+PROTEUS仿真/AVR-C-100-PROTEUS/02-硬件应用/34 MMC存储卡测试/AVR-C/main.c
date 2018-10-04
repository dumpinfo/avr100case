//-----------------------------------------------------------------
//  名称: MMC存储卡测试
//-----------------------------------------------------------------
//  说明: 本例运行时,按下K1将向MMC卡第0块写入512个有序字节,按下K2时
//        将向第1块写入512个随机字节,按下K3与K4时将分别读取并通过
//        虚拟终端显示这些字节数据.
//
//-----------------------------------------------------------------
#define F_CPU 4000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#define INT8U  unsigned char
#define INT16U unsigned int
#define INT32U unsigned long

//定义按键操作



//MMC相关函数


//串口相关函数



//当前按键操作代号
INT8U OP = 0;
//MMC块字节读写缓冲
INT8U Block_bytes[512];
//MMC卡操作错误标识(为1表示正常,为0表示出错)
INT8U ERROR_Flag = 1;
//-----------------------------------------------------------------
// 以十六进制形式显示所读取的字节
//-----------------------------------------------------------------
void Show_Byte_by_HEX(INT8U *Buffer, INT32U Len)
{




}

//-----------------------------------------------------------------
// 主程序
//-----------------------------------------------------------------
int main()
{



}
