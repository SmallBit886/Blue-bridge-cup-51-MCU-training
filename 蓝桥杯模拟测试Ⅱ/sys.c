#include "sys.h"

void Delay1ms()		//@12.000MHz
{
	unsigned char data i, j;

	i = 12;
	j = 169;
	do
	{
		while (--j);
	} while (--i);
}

void HC138_Chose(unsigned char channel)
{
	switch(channel)
	{
		case 0:
			P2 = (P2 & 0x1f);//0000
		break;
		case 4:
			P2 = (P2 & 0x1f) | 0x80;//1000
		break;
		case 5:
			P2 = (P2 & 0x1f) | 0xa0;//1010
		break;
		case 6:
			P2 = (P2 & 0x1f) | 0xc0;//1100
		break;
		case 7:
			P2 = (P2 & 0x1f) | 0xe0;//1110
		break;
	}
}
