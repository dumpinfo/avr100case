//-----------------------------------------------------------------
//  名称:用TWI接口读写AT24C1024子程序
//-----------------------------------------------------------------
#include <avr/io.h>
#include <util/delay.h>
#include <util/TWI.h>
#define INT8U   unsigned char
#define INT16U  unsigned int
#define INT32U  unsigned long

//TWI通用操作


//-----------------------------------------------------------------
// 从AT24C1024读一字节
//-----------------------------------------------------------------
INT8U Read_A_Byte(INT8U Slave,INT32U ROM_Addr)
{


}

//-----------------------------------------------------------------
// 从AT24C1024接收多字节
//-----------------------------------------------------------------
void Rec_AT24C1024_Bytes(INT8U Slave,INT32U ROM_Addr,INT8U *Buf,INT8U N)
{


}
