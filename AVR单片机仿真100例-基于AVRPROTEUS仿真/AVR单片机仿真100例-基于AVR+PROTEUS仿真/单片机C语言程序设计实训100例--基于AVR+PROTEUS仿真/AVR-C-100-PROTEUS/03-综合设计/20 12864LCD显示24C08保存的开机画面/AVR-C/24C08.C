//-----------------------------------------------------------------
//  名称:AT24C08读写程序
//  (本例未使用TWI接口程序，改用模拟IIC时序读写AT24C08存储器)
//-----------------------------------------------------------------
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#define INT8U   unsigned char
#define INT16U  unsigned int
#define INT32U  unsigned long

//AT24XXXX引脚定义


//AT24XXXX引脚操作定义


//-----------------------------------------------------------------
// 起始位
//-----------------------------------------------------------------
void Start()
{


}

//-----------------------------------------------------------------
// 停止位
//-----------------------------------------------------------------
void Stop()
{


}

//-----------------------------------------------------------------
// 输出ACK(ACK/NACK)
//-----------------------------------------------------------------
void W_ACK(INT8U a)
{


}

//-----------------------------------------------------------------
// 读ACK
//-----------------------------------------------------------------
INT8U R_ACK()
{


}

//-----------------------------------------------------------------
// 写一字节
//-----------------------------------------------------------------
INT8U WriteByte(INT8U dat)
{


}

//-----------------------------------------------------------------
// 读一字节
//-----------------------------------------------------------------
INT8U ReadByte()
{


}

//-----------------------------------------------------------------
// 从AT24C08连续读取数据
//-----------------------------------------------------------------
INT8U AT24CxxRead(INT8U Slave,INT16U addr,INT8U *Buffer,INT8U N)
{


}

//-----------------------------------------------------------------
// 将Flash存储器中的多个字节连续写入AT24C08
//-----------------------------------------------------------------
INT8U AT24CxxWrite(INT8U Slave, INT16U addr,prog_uchar *Buffer,INT8U N)
{


}
