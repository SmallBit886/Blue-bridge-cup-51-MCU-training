#include "Timer0.h"
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
sbit L7 = P0^6;
sbit L8 = P0^7;
void Timer0_Init(void)	    //50毫秒@11.0592MHz
{							
	AUXR &= 0x3F;			//定时器时钟12T模式
	TMOD &= 0xf0;			//16 位的定时/计数器
	TMOD |= 0x01;			//16 位的定时/计数器
	TH0=(65535-50000)/256;	//赋初值60---0xD1
	TL0=(65535-50000)%256;	//68----0x20
	ET0=1;					//允许定时器0中断
	IT0=1;					//外部中断 0 为下降沿触发方式
	PT0=1;					//置 1 为高优先级
	TF0 = 0;				//清除TF0标志
	EA=1;//CPU 开放中断
	TR0=1;//开启定时器0
}
void Timer1_Init(void)		//50毫秒@11.0592MHz
{
	
	//AUXR &= 0xBF;			//定时器时钟12T模式
	TMOD &= 0x0F;			//设置定时器模式
	TMOD |= 0x10;			//设置定时器模式
	TL1 = 0x00;				//设置定时初始值
	TH1 = 0x4C;				//设置定时初始值
	ET1=1;
	IT1=1;
	PT1=0;
	TF1 = 0;				//清除TF1标志
	EA=1;
	TR1 = 1;				//定时器1开始计时
}

unsigned char count;
void Timer0_Intrrupt(void) interrupt 1 //50ms中断
{
	TH0=(65535-50000)/256;//赋初值
	TL0=(65535-50000)%256;
	count++;
	if(count%10)//500ms
	{
		L1 = ~L1;
	}
	if(count == 100)//5s
	{
		L8 =~L8;
		count=0;
	}
}
unsigned char count1;
void Timer1_Intrrupt(void) interrupt 3 //50ms中断
{
	TH1=0x0C;//赋初值
	TL1=0x4C;
	count1++;
	if(count1%10)//500ms
	{
		L2 = ~L2;
	}
	if(count1 == 20)//1s
	{
		L7 =~L7;//每秒点亮一次
		count1=0;
	}
}