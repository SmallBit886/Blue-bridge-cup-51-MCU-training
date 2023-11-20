#include "LED.h"

//uchar led[]={0xfe,0xfd,0xfb,0xf7, 0xef,0xdf,0xbf,0x7f, 0x00};
//uchar led_date=0xff;
//void LED_Init(void)
//{
//	HC138_Chose(4);
//	P0=0xff;
//	HC138_Chose(0);
//}
//void LED_Scan(unsigned char led_date)
//{
//	HC138_Chose(4);
//	P0 = led_date;
//	HC138_Chose(0);
//}
//void Led_ON(uchar num)
//{
//	led_date &= led[num-1];
//}
//void Led_OFF(uchar num)
//{
//	led_date |= ~led[num-1];
//}
void Led1_ON(void)
{
	HC138_Chose(4);
	P0=0xfe;
	HC138_Chose(0);
}

void Led2_ON(void)
{
	HC138_Chose(4);
	P0=0xfd;
	HC138_Chose(0);
}
void Led_OFF(void)
{
	HC138_Chose(4);
	P0=0xff;
	HC138_Chose(0);
}
