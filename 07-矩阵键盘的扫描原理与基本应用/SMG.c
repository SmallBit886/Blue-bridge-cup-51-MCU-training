#include "SMG.h"
/**************************0---9 a---h*********************************/
unsigned char code daunma[18]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,
							 0x88,0x80,0xc6,0xc0,0x86,0x8e,0xbf,0x7f};
void SMG_Init(void)
{
	Init_HC138(7);//Y7��ͨ
	Init_HC138(6);//Y6��ͨ
	
}
void SMG_Show(unsigned char pos ,unsigned char date)
{
	//Init_HC138(6);//Y6��ͨ
	P2=~(0x00 | (0x01<<pos));
	//Init_HC138(7);//Y7��ͨ
	P0=daunma[date];
//	Delay(1);
//	P0=0xff;
}
/***************************8 ������ܴ������ң� ��������������ʾ��0�� ����9�� �� 10 ������********************************/
void show1(void)
{
	unsigned char i,j;
	for(i=0;i<8;i++)
	{
		for(j=0;j<10;j++)
		{
			SMG_Show(i,daunma[j]);
			Delay(500);
		}
	}
}
/****************************8 �������ͬʱ��ʾ��0�� ����9�� �� 10 �����ֺ͡�A�� ����F�� �� 6 ����ĸ*******************************/
void show2(void)
{
	unsigned char j;
	
	for(j=0;j<16;j++)
	{
		P0=0xff;
		Delay(2);
		P0=daunma[j];
		Delay(500);
	}

}

/****************************����ܵĶ�̬��ʾ*******************************/
unsigned char yu;
void display_show()
{
	SMG_Show(0,daunma[2]);
	Delay(2);
	SMG_Show(1,daunma[0]);
	Delay(2);
	SMG_Show(2,daunma[2]);
	Delay(2); 
	SMG_Show(3,daunma[3]);
	Delay(2); 
	SMG_Show(4,daunma[16]);
	Delay(2); 
	SMG_Show(5,daunma[16]);
	Delay(2);	
	SMG_Show(6,yu/10);
	Delay(2);
	SMG_Show(7,yu%10);
	Delay(2);
}

void YueAdd(void)
{
	yu++;
	if(yu>12) 
	{
		yu=1;
	}
	Delay(500);
}





