#include <STC15F2K60S2.H>
#include "Timer.h"


void Timer0_Init(void)		//1����@12.000MHz
{
	AUXR &= 0x7F;			//��ʱ��ʱ��12Tģʽ
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TL0 = 0x18;				//���ö�ʱ��ʼֵ
	TH0 = 0xFC;				//���ö�ʱ��ʼֵ
	ET0=1;
	TF0 = 0;				//���TF0��־
	EA=1;
	TR0 = 1;				//��ʱ��0��ʼ��ʱ
}
