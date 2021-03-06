//-----------------------------------------------------------------
//  名称: DS18B20温度传感器程序
//-----------------------------------------------------------------
#include <avr/io.h>
#include <util/delay.h>
#define INT8    signed char
#define INT8U   unsigned char
#define INT16U  unsigned int
//DS18B20引脚定义


//设置数据方向


//温度管引脚操作定义



//温度小数对照表(四位的温度值0000~1111对应16个小数位)



//从DS18B20读取的温度值
INT8U Temp_Value[] = {0x00,0x00};
//传感器状态标志
INT8U DS18B20_ERROR = 0;
//-----------------------------------------------------------------
//读取报警温度上下限,为进行正负数比较,此处注意设为INT8类型(不是INT8U).
//取值范围为-128 - +127,DS18B20支持范围为-50 - +125.
INT8 Alarm_Temp_HL[2];
//-----------------------------------------------------------------
// 初始化DS18B20 
//-----------------------------------------------------------------
INT8U Init_DS18B20()
{


}

//-----------------------------------------------------------------
// 读一字节 
//-----------------------------------------------------------------
INT8U ReadOneByte()
{


}

//-----------------------------------------------------------------
// 写一字节 
//-----------------------------------------------------------------
void WriteOneByte(INT8U dat)
{


}

//-----------------------------------------------------------------
// 读取温度值 
//-----------------------------------------------------------------
void Read_Temperature()
{


}

//-----------------------------------------------------------------
// 设置DS18B20温度报警值(参数为有符号字节整数)
//-----------------------------------------------------------------
void Set_Alarm_Temp_Value(INT8 ha, INT8 la)
{


}

//-----------------------------------------------------------------
// 转换温度数据,返回温度符号(INT8),整数部分和小数部分(INT8U)
//-----------------------------------------------------------------
void Convert_Temperature(INT8 *sign,INT8U *iTemp,INT8U *fTemp)
{


}
