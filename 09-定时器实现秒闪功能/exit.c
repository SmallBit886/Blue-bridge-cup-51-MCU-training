#include "exit.h"
void Exit_Init(void)
{
	EX0=1;//�����ⲿ�ж� 0 �ж�
	IT0=1;//�½��غ�ɲ����ⲿ�ж�
	PX0=1;//�ⲿ�ж� 0 Ϊ������ȼ��жϣ����ȼ� 1��
	EA=1;//CPU �����ж�
}
unsigned char Flag_EX0 = 0;

void interrupt0(void) interrupt 0
{
	Flag_EX0=1;
}
