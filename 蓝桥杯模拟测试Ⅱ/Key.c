#include "Key.h"
unsigned char Key_KeyNumber;

unsigned char Key_GetValue(void)
{
	unsigned char Temp;
	Temp = Key_KeyNumber;
	Key_KeyNumber = 0;
	return Temp;
}

uchar Key_Scan(void)
{
	unsigned char Key_Number = 0;
	P44=0;
	P30=1;P31=1;P32=1;P33=1;
	if(P30==0){Key_Number=0;}
	else if(P31==0){Key_Number=0;}
	else if(P32==0){Key_Number=5;}//界面切换S5
	else if(P33==0){Key_Number=4;}//模式切换S4
	return Key_Number;
}

void Key_Loop(void)
{
	static unsigned char New_Number,Old_Number;
	Old_Number = New_Number;
	New_Number = Key_Scan();
	if(Old_Number == 0 && New_Number==0){Key_KeyNumber = 0;}
	if(Old_Number == 4 && New_Number==0){Key_KeyNumber = 4;}
	if(Old_Number == 5 && New_Number==0){Key_KeyNumber = 5;}

}
