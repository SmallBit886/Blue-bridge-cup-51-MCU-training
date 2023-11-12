#include "sys.h"
sbit buzz =  P0^7;

void BUZZ_Init(void)
{
	Init_HC138(5);//导通Y5
	buzz=0;
}
void BUZZ_ON(void)
{
	Init_HC138(5);//导通Y5
	buzz=1;//蜂鸣器响
}
void BUZZ_OFF(void)
{
	Init_HC138(5);//导通Y5
	buzz=0;
}