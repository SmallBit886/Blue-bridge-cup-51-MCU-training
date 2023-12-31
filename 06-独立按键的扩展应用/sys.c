#include "sys.h"
/**
  ************************************************************************** 
  ** -------------------------------------------------------------------- **
  ** @name          : ms��ʱ
  ** @brief         : None
  ** @param         : None
  ** @retval        : None
  ** @author        : SmallBit886
  ** -------------------------------------------------------------------- **
  ** @attention     : None
  ** -------------------------------------------------------------------- **
  ************************************************************************** 
**/
void Delay(unsigned int ms)		//@12.000MHz
{
	unsigned char data i, j;
	while(ms)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		ms--;	
	}
}
/**
  ************************************************************************** 
  ** -------------------------------------------------------------------- **
  ** @name          : None
  ** @brief         : P2= (0001 1111) | (1000 0000)  
  ** @param         : 
  ** @retval        : None
  ** @author        : SmallBit886
  ** -------------------------------------------------------------------- **
  ** @attention     :Y0 --- 000  Y1 --- 001  Y2 --- 010  Y3 --- 011 
					 Y4 --- 100  Y5 --- 101  Y6 --- 110  Y7 --- 111
  ** -------------------------------------------------------------------- **
  ************************************************************************** 
**/
void Init_HC138(unsigned char n)
{
	switch (n)
	{
		case 0:
			P2=(P2 & 0x1f) | 0x10;
		break;
		case 1:
			P2=(P2 & 0x1f) | 0x30;
		break;
		case 2:
			P2=(P2 & 0x1f) | 0x50;
		break;
		case 3:
			P2=(P2 & 0x1f) | 0x70;
		break;		
		case 4:
			P2=(P2 & 0x1f) | 0x80;
		break;
		case 5:
			P2=(P2 & 0x1f) | 0xa0;
		break;
		case 6:
			P2=(P2 & 0x1f) | 0xc0;
		break;
		case 7:
			P2=(P2 & 0x1f) | 0xe0;
		break;
	}
}