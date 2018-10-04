//-----------------------------------------------------------------
//  名称: 用IE访问AVR以太网应用系统
//-----------------------------------------------------------------
//  功能: 本例运行时,客户端通过IE浏览器可以查询LED状态,启停电机,
//        设置管理员密码等.
//
//-----------------------------------------------------------------
//MAC地址,如果EEPROM包含了有效配置则忽略此行
#define MY_MAC  "\x00\x06\x98\x30\x00\x35"
//IP地址(如果启用了DHCP则忽略)
#define MY_IPADDR "192.168.1.100"
//IP网络掩码(如果启用了DHCP则忽略)
#define MY_IPMASK "255.255.255.0"
//网关IP(如果启用了DHCP则忽略)
#define MY_IPGATE "192.168.1.1"
//是否使用DHCP
#define USE_DHCP
//定义文件系统设备
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

//服务器线程堆栈大小
#ifndef HTTPD_SERVICE_STACK
#define HTTPD_SERVICE_STACK ((580 * NUT_THREAD_STACK_MULT) + NUT_THREAD_STACK_ADD)
#endif

static char *html_mt = "text/html";
static char admin_password[16] = "root:";  //管理员帐号密码
//-----------------------------------------------------------------
// 根据LED与MOTOR状态构造创建WEB页
//-----------------------------------------------------------------
void create_status_webpage(FILE *stream, int led, int motor)
{
	u_char i;
	//待输出状态WEB页的HTML标记
	static char *html_x[] = 
	{
		"<html><head><style type='text/css'>",  //此行开始的0~9行为固定部分
		".title_style {font-family: '黑体';font-size: 24px; }",
		".red_style {font-family: '黑体';font-size: 60px;color: #FF0000;}",
		".blk_style {font-family: '黑体';font-size: 60px;color: #000000;}",
		"</style></head><body><br />",
		"<table width='630' height='160' border='1' align='center'>",
		"<tr><td width='290' height='49'><div align='center'>",
		"<span class='title_style'>LED状态</span></div></td><td width='326'>",
		"<div align='center'><span class='title_style'>电机状态</span>",
		"</div></td></tr><tr><td height='98'>",
		"<div align='center' class='%s'>%s</div></td><td>", //10.LED状态格式串
		"<div align='center' class='%s'>%s</div></td></tr>",//11.MOTOR状态格式串
		"</table></body></html>"                            //12.结尾部分
	};

	//将固定的HTML标记写入stream(0~9行).


	//向流中写入红色"ON"字符串标记


	//否则向流中写入黑色"OFF"字符串标记


	//向流中写入红色"Running..."字符串标记


	//否则向流中写入黑色"*STOP*"字符串标记的


	//输出结尾部分


}

//-----------------------------------------------------------------
// LED状态查询与电机控制函数
// 该函数必须由NutRegisterCgi()注册,当客户端请求cgi-bin/mcu_control.cgi时
// 自动被NutHttpProcessRequest()调用.
//-----------------------------------------------------------------
static int mcu_control(FILE * stream, REQUEST * req)
{
	//led及motor状态
	int led, motor;
	//参数名及参数值变量,根据参数决定返回LED状态或启停电机
    char *para_name, *para_value;

	//三个用户请求超链接格式
	//admin/mcu_control.cgi?para=GETLEDSTATUS
	//admin/mcu_control.cgi?para=STARTMOTOR
	//admin/mcu_control.cgi?para=STOPMOTOR
	//读取所接收到的参数名及参数值

	
	//根据不同参数值完成不同操作
	if (!strcmp(para_name,"para"))
	{








	}

	//LED状态由PF6位判断(注意led与motor的状态判断返回值是相反的.)

	//MOTOR状态由PF0判断

	//以下两行发送HTTP头部,创建HTTP响应
	//发送HTTP及版本行

	//发送Content-Type, Content-Lenght等

	//根据LED与MOTOR状态构造返回WEB页

	//刷新返回的流

}

//-----------------------------------------------------------------
// 设置管理员密码
// 该函数必须由NutRegisterCgi()注册,当客户端请求
// admin/cgi-bin/setpassword.cgi时,该函数将自动
// 被NutHttpProcessRequest()调用.
//-----------------------------------------------------------------
static int setpassword(FILE * stream, REQUEST * req)
{
	u_char save_OK = 0;       //是否保存成功
	char *pwd1, *pwd2;        //两次输入的密码字符串指针
	
	//调用获取参数API,根据文本框的名称pass1与pass2分别获取两个密码


	//检查两次输入的密码是否相同,且长度是否在10以内
	if ( !strcmp(pwd1,pwd2) && strlen(pwd1) > 0 && strlen(pwd1) < 11)
	{






	}

	//以下两行发送HTTP头部,创建HTTP响应



	
	//待输出密码保存成功与否信息WEB页的HTML标记
	static char* html_x[] = 
	{
		"<html><head><title>设置管理员密码</title></head>",
		"<body><br><H1>返回信息:</H1><br>",
		"<font color='%s'>%s</font><br></body></html>"
	};






	//根据save_OK输出蓝色的保存成功信息或红色的保存失败信息.




}

//-----------------------------------------------------------------
// HTTP服务线程(循环等待客户连接,处理HTTP请求并断开连接)
//-----------------------------------------------------------------
THREAD(Service, arg)
{


}

//-----------------------------------------------------------------
// 外部中断INT7控制LED开关
//-----------------------------------------------------------------
static void External_Interrupt7_IRQ(void *arg) 
{


}

//-----------------------------------------------------------------
// 主程序(Nut/OS在初始化后自动调用该入口函数)
//-----------------------------------------------------------------
int main(void)
{



}
