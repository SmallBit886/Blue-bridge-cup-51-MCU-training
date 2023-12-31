#include "LED.h"
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
void LED_Work(void)
{
	Init_HC138(4);//Y4
	L1=0;
	Delay(500);
	Init_HC138(4);//Y4
	L1=1;
	Delay(500);
}
/**
  ************************************************************************** 
  ** -------------------------------------------------------------------- **
  ** @name          : None
  ** @brief         : num为0,L1点亮
  ** @param         : P0=~(0000 0000 | 0000 0001)=1111 1110
  ** @retval        : None
  ** @author        : SmallBit886
  ** -------------------------------------------------------------------- **
  ** @attention     : 非法操作全部熄灭
  ** -------------------------------------------------------------------- **
  ************************************************************************** 
**/

void LED_SHOW(unsigned char num)
{
	if(8 > num && 0 <= num)
	{
		Init_HC138(4);//Y4
		P0 = ~((P0 & 0x00) | (0x01 << num));
	}
	else
	{
		Init_HC138(4);//Y4
		P0 = 0xff;//全部熄灭
	}
}
/***********************************************************/
void LED_Init(void)
{
	Init_HC138(4);//Y4
	LED_ALL_OFF();//熄灭全部
}
/***********************************************************/
void LED_ALL_ON(void)
{
	Init_HC138(4);//Y4
	P0 = 0x00;//全部亮
}
/***********************************************************/
void LED_ALL_OFF(void)
{
	Init_HC138(4);//Y4
	P0 = 0xff;//全部熄灭
}
