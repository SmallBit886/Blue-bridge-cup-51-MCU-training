#include "relay.h"
sbit relay =  P0^5;

void Realy_Init(void)
{
	Init_HC138(5);//��ͨY5
	relay=0;//�պ�
}
void Realy_ON(void)
{
	Init_HC138(5);//��ͨY5
	relay=1;//��
}
void Realy_OFF(void)
{
	Init_HC138(5);//��ͨY5
	relay=0;//�պ�
}