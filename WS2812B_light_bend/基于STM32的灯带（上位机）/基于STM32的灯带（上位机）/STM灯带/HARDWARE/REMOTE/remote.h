#ifndef __RED_H
#define __RED_H 
#include "sys.h"   	  
  
#define RDATA PAin(1)	 //�������������
//����ң��ʶ����(ID),ÿ��ң�����ĸ�ֵ��������һ��,��Ҳ��һ����.
//����ѡ�õ�ң����ʶ����Ϊ0
#define REMOTE_ID 0      

   
extern u8 RRdy;			 //������յ����� 
extern u32 Remote_Odr;   //�����ݴ洦
void Remote_Init(void);    //���⴫��������ͷ���ų�ʼ��
u8 Remote_Process(void);   //������յ����ݴ���
u8 Pulse_Width_Check(void);//�������	  	
#endif















