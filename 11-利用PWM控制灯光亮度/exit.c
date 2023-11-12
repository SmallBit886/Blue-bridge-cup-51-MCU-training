#include "exit.h"
void Exit_Init(void)
{
	EX0=1;//允许外部中断 0 中断
	IT0=1;//下降沿后可产生外部中断
	PX0=1;//外部中断 0 为最高优先级中断（优先级 1）
	EA=1;//CPU 开放中断
}
unsigned char Flag_EX0 = 0;

void interrupt0(void) interrupt 0
{
	Flag_EX0=1;
}
