#include "sys.h"

int main()
{
	LED_Init();//LED初始化
	BUZZ_Init();//蜂鸣器初始化
	Realy_Init();//继电器初始化
	SMG_Init();//数码管初始化
	while(1)
	{

		/***************************数码管的动态显示********************************/
		display_show();
		YueAdd();

	}
}
