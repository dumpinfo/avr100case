//-----------------------------------------------------------------
//  名称: SHT75传感器程序(参照SENSIRION公司提供的8051版代码改编)
//-----------------------------------------------------------------
#define F_CPU 4000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <math.h>
#define INT8U   unsigned char
#define INT16U  unsigned int

//传感器引脚定义
#define SCL  PC3
#define SDA  PC4

//传感器引脚操作定义
#define SCL_0()        PORTC &= ~_BV(SCL)  //串行时钟
#define SCL_1()        PORTC |=  _BV(SCL)
#define SDA_0()        PORTC &= ~_BV(SDA)  //串行数据
#define SDA_1()        PORTC |=  _BV(SDA)
#define SDA_DDR_0()    DDRC  &= ~_BV(SDA)  //SDA数据方向
#define SDA_DDR_1()    DDRC  |=  _BV(SDA)
#define Get_SDA_Bit()  (PINC & _BV(SDA))   //获取SDA引脚数据(保留括号)

//SHT75传感器命令集         //地址 命令 读/写
#define MEASURE_TEMP 0x03   //000  0001  1
#define MEASURE_HUMI 0x05   //000  0010  1
#define STATUS_REG_W 0x06   //000  0011  0
#define STATUS_REG_R 0x07   //000  0011  1
#define RESET        0x1E   //000  1111  0

//是否应答
#define NACK  0
#define ACK   1

//温湿度信息显示缓冲
char HT_Display_Buffer[20];
//定义温度与湿度符号
enum {TEMP,HUMI};
extern void PutStr(char *s);
//-----------------------------------------------------------------
// 写一节到SHT75并检查应答
//-----------------------------------------------------------------
INT8U s_Write_Byte(INT8U dat)
{ 


}

//-----------------------------------------------------------------
// 从传感器读一字节,在ack=1时发送应答
//-----------------------------------------------------------------
INT8U s_Read_Byte(INT8U ack)
{ 


}

//-----------------------------------------------------------------
// 传输开始
//-----------------------------------------------------------------
void s_TransStart()
{  
    SDA_1(); 
    SCL_0();   _delay_us(1);
    SCL_1();   _delay_us(1);
    SDA_0();   _delay_us(1);
    SCL_0();   _delay_us(3);
    SCL_1();   _delay_us(1);
    SDA_1();   _delay_us(1);
    SCL_0();    
}

//-----------------------------------------------------------------
// 传感器连接复位
//-----------------------------------------------------------------
void s_ConnectionReset()
{  
    INT8U i; 
    SDA_1(); SCL_0();                     //初始状态
    for(i = 0; i < 9; i++)                //模拟9个时钟周期
    { 
       SCL_1(); SCL_0();
    }
    s_TransStart();                       //传输开始
}

//-----------------------------------------------------------------
// 传感器软复位
//-----------------------------------------------------------------
INT8U s_SoftReset()
{ 
    INT8U error = 0;
    s_ConnectionReset();                  //连接通讯复位
    error += s_Write_Byte(RESET);         //向传感器发送复位命令
    return error;                         //传感器无响应时返回1
}

//-----------------------------------------------------------------
// 读状态寄存器
//-----------------------------------------------------------------
INT8U s_Read_StatusReg(INT8U *p_value, INT8U *p_checksum)
{ 
    INT8U error = 0;
    s_TransStart();                       //传输开始
    error = s_Write_Byte(STATUS_REG_R);   //向传感器发送命令STATUS_REG_R
    *p_value = s_Read_Byte(ACK);          //读状态寄存器(8位)
    *p_checksum = s_Read_Byte(NACK);      //读取校验和(8位)
    return error;                         //传感器无响应时返回1
}

//-----------------------------------------------------------------
// 写状态寄存器
//-----------------------------------------------------------------
INT8U s_Write_StatusReg(INT8U *p_value)
{ 
    INT8U error = 0;
    s_TransStart();                       //传输开始
    error += s_Write_Byte(STATUS_REG_W);  //向传感器发送命令STATUS_REG_W
    error += s_Write_Byte(*p_value);      //发送状态寄存器的值
    return error;                         //传感器无响应时返回1
}
     
//-----------------------------------------------------------------
// 带检验码的温度与湿度测量
//-----------------------------------------------------------------
INT8U s_Measure(INT8U *p_value, INT8U *p_checksum, INT8U mode)
{ 


}

//-----------------------------------------------------------------
// 计算温湿度
//-----------------------------------------------------------------
void Calc_STH75(float *p_humidity ,float *p_temperature)
{
    const float C1 = -4.0;              //12位,系数C1
    const float C2 = +0.0405;           //12位,系数C2
    const float C3 = -0.0000028;        //12位,系数C3
    const float T1 = +0.01;             //14位 @ 5V ,系数T1
    const float T2 = +0.00008;          //14位 @ 5V ,系数T2
    float rh = *p_humidity;             // rh:      湿度 12 Bit 
    float t  = *p_temperature;          // t:       温度 14 Bit
    float rh_lin;                       // rh_lin:  线性湿度
    float rh_true;                      // rh_true: 温度补偿湿度
    float t_C;                          // t_C   :  温度(℃)
    t_C = t * 0.01 - 40;                            //计算温度
    rh_lin = C3 * rh * rh + C2 * rh + C1;           //计算湿度
    rh_true=(t_C - 25) * (T1 + T2 * rh) + rh_lin;   //计算:温度补偿湿度
    if(rh_true > 100) rh_true = 100;      //将湿度数据限制在正常范围之内
    if(rh_true < 0.1) rh_true = 0.1;      //即0.1% ~ 100%
    *p_temperature = t_C;                 //返回温度[℃]
    *p_humidity = rh_true;                //返回湿度[%RH]
}

//--------------------------------------------------------------------
// 根据输入的湿度与温度计算露点
//--------------------------------------------------------------------
float Calc_Dew_point(float h,float t)
{ 
    float logEx,dew_point;
    logEx = 0.66077 + 7.5 * t / (237.3 + t) + (log10(h) - 2);
    dew_point = (logEx - 0.66077) * 237.3 / (0.66077 + 7.5 - logEx);
    return dew_point;
}

//--------------------------------------------------------------------
// 传感器测试(读取湿度与温度数据并进行转换计算,送虚拟终端显示)
//--------------------------------------------------------------------
void Temp_and_Humi_Sensors_Test()
{ 








}
