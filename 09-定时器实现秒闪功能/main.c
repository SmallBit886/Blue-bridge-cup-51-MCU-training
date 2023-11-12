#include "sys.h"

sbit L8 = P0^7;
int main()
{
	LED_Init();//LED初始化
	BUZZ_Init();//蜂鸣器初始化
	Realy_Init();//继电器初始化
	SMG_Init();//数码管初始化
	Exit_Init();//INT0初始化
	Timer0_Init();//定时器0初始化
	while(1)
	{

		LED_Work();

	}
}
