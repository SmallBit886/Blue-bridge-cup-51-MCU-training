#include "LED.h"
void LED_Scan(unsigned char num)
{
	HC138_Chose(4);
	P0= ~ (P0 & 0x00)|(0x01<<(num-1));
}
void L1_ON(void)
{
	LED_Scan(1);
}
void L2_ON(void)
{
	LED_Scan(2);
}
void L3_ON(void)
{
	LED_Scan(3);
}
void L4_ON(void)
{
	LED_Scan(4);
}