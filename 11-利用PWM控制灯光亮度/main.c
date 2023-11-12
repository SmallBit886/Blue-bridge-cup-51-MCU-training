#include "sys.h"
sbit S7 = P3^0;
sbit L1 = P0^0;
unsigned char Key_Flag;
int main()
{
	//LED_Init();//LED初始化
	//BUZZ_Init();//蜂鸣器初始化
	//Realy_Init();//继电器初始化
	//SMG_Init();//数码管初始化
	//Exit_Init();//INT0初始化
	Timer0_Init();//定时器0初始化
	L1 = 1;
	//Timer1_Init();//定时器0初始化
	while(1)
	{
		if(S7==0)
		{
			Delay(20);
			if(S7==0 && Key_Flag==0)
			{
				TR0=1;
				L1=0;
				pwm=10;
				Key_Flag==1;
			}
			else if(S7==0 && Key_Flag==1)
			{
				pwm=50;
				Key_Flag==2;	
			}
			else if(S7==0 && Key_Flag==2)
			{
				pwm=90;
				Key_Flag==3;	
			}
			else if(S7==0 && Key_Flag==3)
			{
				TR0=0;
				L1=1;
				Key_Flag==0;	
			}
			while(S7==0);
		}

	}
}
