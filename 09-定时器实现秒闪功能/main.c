#include "sys.h"

sbit L8 = P0^7;
int main()
{
	LED_Init();//LED��ʼ��
	BUZZ_Init();//��������ʼ��
	Realy_Init();//�̵�����ʼ��
	SMG_Init();//����ܳ�ʼ��
	Exit_Init();//INT0��ʼ��
	Timer0_Init();//��ʱ��0��ʼ��
	while(1)
	{

		LED_Work();

	}
}
