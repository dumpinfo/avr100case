//-----------------------------------------------------------------
// 名称: 1601LCD液晶程序头文件
//-----------------------------------------------------------------
//允许显示的最大字符个数
#define MAX_DISPLAY_CHAR 9
//液晶相关函数
void Initialize_LCD();
void ClearScreen();
void ShowString(char *str);

