#include "sys.h"

sbit L8 = P0^7;
int main()
{
//	LED_Init();//LED��ʼ��
//	BUZZ_Init();//��������ʼ��
//	Realy_Init();//�̵�����ʼ��
//	SMG_Init();//����ܳ�ʼ��
	Exit_Init();//INT0��ʼ��
	while(1)
	{

		LED_Work();
		ScanKey_Alone();
		if(Flag_EX0==1)
		{
			//Init_HC138(4);//Y4
			L8=~L8;
			Flag_EX0=0;
		}
		
	}
}
