#include "reg52.h"

unsigned char yu = 1;
unsigned char code SMG_duanma[18]=
		{0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,
     0x80,0x90,0x88,0x80,0xc6,0xc0,0x86,0x8e,
     0xbf,0x7f};
/*************  本地常量声明    **************/
/*u8 code t_display[]={                       //标准字库
//   0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
    0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,
//black  -     H    J    K    L    N    o   P    U     t    G    Q    r   M    y
    0x00,0x40,0x76,0x1E,0x70,0x38,0x37,0x5C,0x73,0x3E,0x78,0x3d,0x67,0x50,0x37,0x6e,
    0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF,0x46};    //0. 1. 2. 3. 4. 5. 6. 7. 8. 9. -1

u8 code T_COM[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};      //位码
*/
void SelectHC573(unsigned char channel)
{
	switch(channel)
	{
		case 4:
			P2 = (P2 & 0x1f) | 0x80;
		break;
		case 5:
			P2 = (P2 & 0x1f) | 0xa0;
		break;
		case 6:
			P2 = (P2 & 0x1f) | 0xc0;
		break;
		case 7:
			P2 = (P2 & 0x1f) | 0xe0;
		break;
	}
}

void DisplaySMG_Bit(unsigned char value, unsigned char pos)
{
	P2 = 0xff;
	SelectHC573(6);
	P2 = 0x01 << pos;
	SelectHC573(7);
	P0 = value;
}

void DelaySMG(unsigned int t)
{
	while(t--);
}

void Display_Dynamic()
{
	DisplaySMG_Bit(SMG_duanma[2],0);
	DelaySMG(500);
	DisplaySMG_Bit(SMG_duanma[0],1);
	DelaySMG(500);
	DisplaySMG_Bit(SMG_duanma[1],2);
	DelaySMG(500);
	DisplaySMG_Bit(SMG_duanma[8],3);
	DelaySMG(500);
	
	DisplaySMG_Bit(SMG_duanma[16],4);
	DelaySMG(500);
	DisplaySMG_Bit(SMG_duanma[16],5);
	DelaySMG(500);
	
	DisplaySMG_Bit(SMG_duanma[yu/10],6);
	DelaySMG(500);
	DisplaySMG_Bit(SMG_duanma[yu%10],7);
	DelaySMG(500);
}

void Delay(unsigned char t)
{
		while(t--)
		{
			Display_Dynamic();
		}
}

void main()
{
	while(1)
	{
		Display_Dynamic();
		yu++;
		if(yu > 12)
		{
			yu = 1;
		}
		Delay(200);
	}
}