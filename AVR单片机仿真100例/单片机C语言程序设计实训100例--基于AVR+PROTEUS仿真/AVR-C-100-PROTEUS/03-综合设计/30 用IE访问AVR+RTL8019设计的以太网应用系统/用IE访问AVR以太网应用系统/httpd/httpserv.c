//-----------------------------------------------------------------
//  ����: ��IE����AVR��̫��Ӧ��ϵͳ
//-----------------------------------------------------------------
//  ����: ��������ʱ,�ͻ���ͨ��IE��������Բ�ѯLED״̬,��ͣ���,
//        ���ù���Ա�����.
//
//-----------------------------------------------------------------
//MAC��ַ,���EEPROM��������Ч��������Դ���
#define MY_MAC  "\x00\x06\x98\x30\x00\x35"
//IP��ַ(���������DHCP�����)
#define MY_IPADDR "192.168.1.100"
//IP��������(���������DHCP�����)
#define MY_IPMASK "255.255.255.0"
//����IP(���������DHCP�����)
#define MY_IPGATE "192.168.1.1"
//�Ƿ�ʹ��DHCP
#define USE_DHCP
//�����ļ�ϵͳ�豸
#ifndef MY_FSDEV
#define MY_FSDEV   devUrom
#endif

#include <cfg/os.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>
#include <dev/board.h>
#include <dev/urom.h>
#include <dev/irqreg.h>
#include <arch/avr32/ihndlr.h>
#include <avr/eeprom.h>
#include <sys/version.h>
#include <sys/thread.h>
#include <sys/timer.h>
#include <sys/heap.h>
#include <sys/confnet.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/route.h>
#include <pro/httpd.h>
#include <pro/dhcp.h>

//�������̶߳�ջ��С
#ifndef HTTPD_SERVICE_STACK
#define HTTPD_SERVICE_STACK ((580 * NUT_THREAD_STACK_MULT) + NUT_THREAD_STACK_ADD)
#endif

static char *html_mt = "text/html";
static char admin_password[16] = "root:";  //����Ա�ʺ�����
//-----------------------------------------------------------------
// ����LED��MOTOR״̬���촴��WEBҳ
//-----------------------------------------------------------------
void create_status_webpage(FILE *stream, int led, int motor)
{
	u_char i;
	//�����״̬WEBҳ��HTML���
	static char *html_x[] = 
	{
		"<html><head><style type='text/css'>",  //���п�ʼ��0~9��Ϊ�̶�����
		".title_style {font-family: '����';font-size: 24px; }",
		".red_style {font-family: '����';font-size: 60px;color: #FF0000;}",
		".blk_style {font-family: '����';font-size: 60px;color: #000000;}",
		"</style></head><body><br />",
		"<table width='630' height='160' border='1' align='center'>",
		"<tr><td width='290' height='49'><div align='center'>",
		"<span class='title_style'>LED״̬</span></div></td><td width='326'>",
		"<div align='center'><span class='title_style'>���״̬</span>",
		"</div></td></tr><tr><td height='98'>",
		"<div align='center' class='%s'>%s</div></td><td>", //10.LED״̬��ʽ��
		"<div align='center' class='%s'>%s</div></td></tr>",//11.MOTOR״̬��ʽ��
		"</table></body></html>"                            //12.��β����
	};

	//���̶���HTML���д��stream(0~9��).


	//������д���ɫ"ON"�ַ������


	//����������д���ɫ"OFF"�ַ������


	//������д���ɫ"Running..."�ַ������


	//����������д���ɫ"*STOP*"�ַ�����ǵ�


	//�����β����


}

//-----------------------------------------------------------------
// LED״̬��ѯ�������ƺ���
// �ú���������NutRegisterCgi()ע��,���ͻ�������cgi-bin/mcu_control.cgiʱ
// �Զ���NutHttpProcessRequest()����.
//-----------------------------------------------------------------
static int mcu_control(FILE * stream, REQUEST * req)
{
	//led��motor״̬
	int led, motor;
	//������������ֵ����,���ݲ�����������LED״̬����ͣ���
    char *para_name, *para_value;

	//�����û��������Ӹ�ʽ
	//admin/mcu_control.cgi?para=GETLEDSTATUS
	//admin/mcu_control.cgi?para=STARTMOTOR
	//admin/mcu_control.cgi?para=STOPMOTOR
	//��ȡ�����յ��Ĳ�����������ֵ

	
	//���ݲ�ͬ����ֵ��ɲ�ͬ����
	if (!strcmp(para_name,"para"))
	{








	}

	//LED״̬��PF6λ�ж�(ע��led��motor��״̬�жϷ���ֵ���෴��.)

	//MOTOR״̬��PF0�ж�

	//�������з���HTTPͷ��,����HTTP��Ӧ
	//����HTTP���汾��

	//����Content-Type, Content-Lenght��

	//����LED��MOTOR״̬���췵��WEBҳ

	//ˢ�·��ص���

}

//-----------------------------------------------------------------
// ���ù���Ա����
// �ú���������NutRegisterCgi()ע��,���ͻ�������
// admin/cgi-bin/setpassword.cgiʱ,�ú������Զ�
// ��NutHttpProcessRequest()����.
//-----------------------------------------------------------------
static int setpassword(FILE * stream, REQUEST * req)
{
	u_char save_OK = 0;       //�Ƿ񱣴�ɹ�
	char *pwd1, *pwd2;        //��������������ַ���ָ��
	
	//���û�ȡ����API,�����ı��������pass1��pass2�ֱ��ȡ��������


	//�����������������Ƿ���ͬ,�ҳ����Ƿ���10����
	if ( !strcmp(pwd1,pwd2) && strlen(pwd1) > 0 && strlen(pwd1) < 11)
	{






	}

	//�������з���HTTPͷ��,����HTTP��Ӧ



	
	//��������뱣��ɹ������ϢWEBҳ��HTML���
	static char* html_x[] = 
	{
		"<html><head><title>���ù���Ա����</title></head>",
		"<body><br><H1>������Ϣ:</H1><br>",
		"<font color='%s'>%s</font><br></body></html>"
	};






	//����save_OK�����ɫ�ı���ɹ���Ϣ���ɫ�ı���ʧ����Ϣ.




}

//-----------------------------------------------------------------
// HTTP�����߳�(ѭ���ȴ��ͻ�����,����HTTP���󲢶Ͽ�����)
//-----------------------------------------------------------------
THREAD(Service, arg)
{


}

//-----------------------------------------------------------------
// �ⲿ�ж�INT7����LED����
//-----------------------------------------------------------------
static void External_Interrupt7_IRQ(void *arg) 
{


}

//-----------------------------------------------------------------
// ������(Nut/OS�ڳ�ʼ�����Զ����ø���ں���)
//-----------------------------------------------------------------
int main(void)
{



}
