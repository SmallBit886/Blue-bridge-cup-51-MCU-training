#include "SMG.h"
/**************************0---9 a---h*********************************/
unsigned char code daunma[18]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,
							 0x88,0x80,0xc6,0xc0,0x86,0x8e,0xbf,0x7f};
void SMG_Init(void)
{
	Init_HC138(7);//Y7导通
	Init_HC138(6);//Y6导通
	
}
void SMG_Show(unsigned char pos ,unsigned char date)
{
	//Init_HC138(6);//Y6导通
	P2=~(0x00 | (0x01<<pos));
	//Init_HC138(7);//Y7导通
	P0=daunma[date];
//	Delay(1);
//	P0=0xff;
}
/***************************8 个数码管从左至右， 逐个数码管依次显示“0” 到“9” 的 10 个数字********************************/
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
/****************************8 个数码管同时显示“0” 到“9” 的 10 个数字和“A” 到“F” 的 6 个字母*******************************/
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

/****************************数码管的动态显示*******************************/
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





