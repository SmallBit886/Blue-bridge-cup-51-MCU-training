#include "INTRINS.h"
#include "Delay.h"
void Delay_ms(unsigned char ms)		//@11.0592MHz
{
	unsigned char data i, j;
	while(ms)
	{
		_nop_();
		_nop_();
		_nop_();
		i = 11;
		j = 190;
		do
		{
			while (--j);
		} while (--i);
		ms--;
	}
}
