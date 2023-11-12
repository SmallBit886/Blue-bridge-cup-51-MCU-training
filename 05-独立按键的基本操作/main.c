#include "sys.h"

int main()
{
	LED_Init();//LED初始化
	BUZZ_Init();//蜂鸣器初始化
	Realy_Init();//继电器初始化
	SMG_Init();//数码管初始化
	while(1)
	{
		/*************************当 S7 按键按下时， 点亮L1 指示灯， 松开后熄灭**********************************/
		ScanKey_Alone();
	}
}
