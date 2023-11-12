#include "Timer0.h"
sbit S7 = P3^0;
sbit S6 = P3^1;
sbit S5 = P3^2;
sbit S4 = P3^3;

sbit L1 = P0^0;
sbit L2 = P0^1;
sbit L3 = P0^2;
sbit L4 = P0^3;
sbit L5 = P0^4;
sbit L6 = P0^5;
sbit L7 = P0^6;
sbit L8 = P0^7;
void Timer0_Init(void)	    //50����@11.0592MHz
{							
	AUXR &= 0x3F;			//��ʱ��ʱ��12Tģʽ
	TMOD &= 0xf0;			//16 λ�Ķ�ʱ/������
	TMOD |= 0x01;			//16 λ�Ķ�ʱ/������
	TH0=(65535-50000)/256;	//����ֵ60---0xD1
	TL0=(65535-50000)%256;	//68----0x20
	ET0=1;					//����ʱ��0�ж�
	IT0=1;					//�ⲿ�ж� 0 Ϊ�½��ش�����ʽ
	PT0=1;					//�� 1 Ϊ�����ȼ�
	TF0 = 0;				//���TF0��־
	EA=1;//CPU �����ж�
	TR0=1;//������ʱ��0
}
void Timer1_Init(void)		//50����@11.0592MHz
{
	
	//AUXR &= 0xBF;			//��ʱ��ʱ��12Tģʽ
	TMOD &= 0x0F;			//���ö�ʱ��ģʽ
	TMOD |= 0x10;			//���ö�ʱ��ģʽ
	TL1 = 0x00;				//���ö�ʱ��ʼֵ
	TH1 = 0x4C;				//���ö�ʱ��ʼֵ
	ET1=1;
	IT1=1;
	PT1=0;
	TF1 = 0;				//���TF1��־
	EA=1;
	TR1 = 1;				//��ʱ��1��ʼ��ʱ
}

unsigned char count;
void Timer0_Intrrupt(void) interrupt 1 //50ms�ж�
{
	TH0=(65535-50000)/256;//����ֵ
	TL0=(65535-50000)%256;
	count++;
	if(count%10)//500ms
	{
		L1 = ~L1;
	}
	if(count == 100)//5s
	{
		L8 =~L8;
		count=0;
	}
}
unsigned char count1;
void Timer1_Intrrupt(void) interrupt 3 //50ms�ж�
{
	TH1=0x0C;//����ֵ
	TL1=0x4C;
	count1++;
	if(count1%10)//500ms
	{
		L2 = ~L2;
	}
	if(count1 == 20)//1s
	{
		L7 =~L7;//ÿ�����һ��
		count1=0;
	}
}