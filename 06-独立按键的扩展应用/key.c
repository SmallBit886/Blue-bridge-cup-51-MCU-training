#include "key.h"
sbit S7 = P3^0;
sbit S6 = P3^1;
sbit S5 = P3^2;
sbit S4 = P3^3;

sbit L1 = P0^0;
sbit L2 = P0^1;
sbit L3 = P0^2;
sbit L4 = P0^3;
sbit L5 = P0^4;
sbit L6 = P0^5;
unsigned char S7Flag;
unsigned char S6Flag;
void ScanKey_Alone(void)
{
	if(S7==0)
	{
		Delay(20);
		if(S7==0)
		{
			L1=0;
			while(S7==0);
			L1=1;
		}
	}
	if(S6==0)
	{
		Delay(20);
		if(S6==0)
		{
			L2=0;
			while(S6==0);
			L2=1;
		}
	}
	if(S5==0)
	{
		Delay(20);
		if(S5==0)
		{
			L3=0;
			while(S5==0);
			L3=1;
		}
	}
	if(S4==0)
	{
		Delay(20);
		if(S4==0)
		{
			L4=0;
			while(S4==0);
			L4=1;
		}
	}
}
void Key_contron(void)
{
	/*S7 和 S6 为选择键， 确定控制键控制那组 LED 指示灯； 
	S5 和 S4 为控制键， 按键按下时点亮指定的 LED 指示灯， 按键松开， LED 指示灯熄灭*/
	if(S7==0)	//检测按键7是否按下
	{
		Delay(20);//消抖
		if(S7==0 && S6Flag==0 && S7Flag==0)//如果按键7按下，并且按键6没有工作
		{
			S7Flag=1;//标志位置1：按键7工作
			L1=0;//点亮L1
			while(S7==0);//等待按键松手				
		}
		if(S7==0 && S7Flag==1)////如果按键7按下，并且按键7工作
		{
			S7Flag=0;//标志位置0：按键7解除
			L1=1;//熄灭L1
			while(S7==0);//等待按键松手				
		}
	}
	if(S6==0)//如果按键6按下
	{
		Delay(20);//消抖
		if(S6==0 && S7Flag==0 && S6Flag==0)//如果按键6按下，并且按键7位工作
		{
			S6Flag=1;//标志位置1：按键6工作
			L2=0;//L2点亮
			while(S6==0);//等待按键6放手				
		}
		if(S6==0 && S6Flag==1)//如果按键6按下，并且按键6工作
		{
			S6Flag=0;//标志位置0：按键2解除
			L2=1;//熄灭L2
			while(S6==0);//等待按键松手				
		}
	}
	
	if(S5==0)//如果按键5按下
	{
		Delay(20);//消抖
		if(S5==0 && S7Flag==1)//如果按键5按下，并且按键7工作
		{
			L3=~L3;//点亮L3
			while(S5==0);//等待按键松手				
		}
		else if(S5==0 && S6Flag==1)//如果按键5按下，并且按键6工作
		{
			L5=~L5;//点亮L5
			while(S5==0);//等待按键松手				
		}
	}
	if(S4==0)//如果按键4按下
	{
		Delay(20);//消抖
		if(S4==0 && S7Flag==1)//如果按键4按下，并且按键7工作
		{
			L4=~L4;//点亮L4
			while(S4==0);//等待按键松手				
		}
		else if(S4==0 && S6Flag==1)//如果按键4按下，并且按键6工作
		{
			L6=~L6;//点亮L6
			while(S4==0);//等待按键4松手				
		}
	}
}