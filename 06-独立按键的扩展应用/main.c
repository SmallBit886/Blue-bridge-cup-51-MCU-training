#include "sys.h"

int main()
{
	LED_Init();//LED��ʼ��
	BUZZ_Init();//��������ʼ��
	Realy_Init();//�̵�����ʼ��
	SMG_Init();//����ܳ�ʼ��
	while(1)
	{
		Key_contron();
	}
}
