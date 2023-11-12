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
void Timer0_Init(void)	    //12MHZ
{							
	AUXR |= 0x80;			//定时器时钟1T模式
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

unsigned char count;
void Timer0_Intrrupt(void) interrupt 1 //50ms中断
{
	TH0=(65535-10000)/256;//赋初值
	TL0=(65535-10000)%256;
	count++;
	if(count%10)//500ms
	{
		L1 = ~L1;
	}
	if(count == 100)//5s
	{
		L8 =~L8;
	}
}