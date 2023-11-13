#include "SMG.h"
unsigned char code duanma[19]={
0xc0, //0
0xf9, //1
0xa4, //2
0xb0, //3
0x99, //4
0x92, //5
0x82, //6
0xf8, //7
0x80, //8
0x90, //9
0x88, //A 11
0x83, //b
0xc6, //C
0xa1, //d
0x86, //E
0x8e, //F
0xbf, 
0x7f, 
0xff  
};
/***************************存放将要显示的数据********************************/
unsigned char SMGShow_Buf[9]={0,19,19,19,19,19,19,19,19};

/**************************设置将要显示的数据*********************************/	
void SMG_SetBuf(unsigned char pos,unsigned char number)
{
	SMGShow_Buf[pos]=number;
}

/***************************数码管扫描显示********************************/
void DisplySMG(unsigned char pos,unsigned char date)
{
	P0=0xff;//熄灭所有断码
	HC138_Chose(6);//开启位选通道
	P0 = ~((P0 & 0x00) | (0x01<<(pos-1)));//点亮哪一位数码管
	HC138_Chose(7);//开启断码显示通道
	P0 = duanma[date];//显示数据
}

/***************************定时器定时扫描********************************/
void SMG_Loop(void)
{
	static unsigned char i =1;
	DisplySMG(i,SMGShow_Buf[i]);
	i++;
	if(i<=9){i=1;}
}