//-----------------------------------------------------------------
//  ����: LEDģ�⽻ͨ��
//-----------------------------------------------------------------
//  ˵��: �������̵����������,�Ƶ���˸,��˸5�κ������,
//        �������,�ϱ����ɺ�Ʊ�Ϊ�̵�,��������ϱ���Ƶ���˸, 
//        ��˸5�κ������,�������̵���,�������.
//        �������л�ʱ����ý϶̣��Ա���ٹ۲�����Ч��.
// 
//-----------------------------------------------------------------
#include <avr/io.h>
#include <util/delay.h>
#define INT8U   unsigned char
#define INT16U  unsigned int

#define     RED_EW_ON()  PORTC &= ~_BV(PC0)    //������ָʾ�ƿ�
#define  YELLOW_EW_ON()  PORTC &= ~_BV(PC1)
#define   GREEN_EW_ON()  PORTC &= ~_BV(PC2)

#define     RED_EW_OFF() PORTC |=  _BV(PC0)    //������ָʾ�ƹ�
#define  YELLOW_EW_OFF() PORTC |=  _BV(PC1)
#define   GREEN_EW_OFF() PORTC |=  _BV(PC2)
 
#define     RED_SN_ON()  PORTC &= ~_BV(PC3)    //�ϱ���ָʾ�ƿ�
#define  YELLOW_SN_ON()  PORTC &= ~_BV(PC4)
#define   GREEN_SN_ON()  PORTC &= ~_BV(PC5)

#define     RED_SN_OFF() PORTC |=  _BV(PC3)    //�ϱ���ָʾ�ƹ�
#define  YELLOW_SN_OFF() PORTC |=  _BV(PC4)
#define   GREEN_SN_OFF() PORTC |=  _BV(PC5)

#define   YELLOW_EW_BLINK() PORTC ^= _BV(PC1)  //������Ƶ���˸
#define   YELLOW_SN_BLINK() PORTC ^= _BV(PC4)  //�ϱ���Ƶ���˸

//��˸����,�������ͱ���
INT8U Flash_Count = 0, Operation_Type = 1;
//-----------------------------------------------------------------
// ��ͨ���л��ӳ���
//-----------------------------------------------------------------
void Traffic_Light()
{



}

//-----------------------------------------------------------------
// ������
//-----------------------------------------------------------------
int main()
{


}
