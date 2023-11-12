#include "relay.h"
sbit relay =  P0^5;

void Realy_Init(void)
{
	Init_HC138(5);//导通Y5
	relay=0;//闭合
}
void Realy_ON(void)
{
	Init_HC138(5);//导通Y5
	relay=1;//打开
}
void Realy_OFF(void)
{
	Init_HC138(5);//导通Y5
	relay=0;//闭合
}