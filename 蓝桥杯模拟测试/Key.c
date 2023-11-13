#include "Key.h"
unsigned char Key_KeyNumber = 19;

unsigned char Key_GetValue(void)
{
	unsigned char Temp = 19;
	Temp = Key_KeyNumber;
	Key_KeyNumber = 19;
	return Temp;
}

unsigned char Key_Scan(void)
{
	unsigned char Key_Number = 19;
	P44=0;P42=1;P35=1;P34=1;
	P30=1;P31=1;P32=1;P33=1;
	if(P30==0){Key_Number=17;}
	else if(P31==0){Key_Number=0;}
	else if(P32==0){Key_Number=11;}//Çå³ı¼ü
	else if(P33==0){Key_Number=10;}//ÇĞ»»¼ü
	
	P44=1;P42=0;P35=1;P34=1;
	P30=1;P31=1;P32=1;P33=1;
	if(P30==0){Key_Number=17;}
	else if(P31==0){Key_Number=1;}
	else if(P32==0){Key_Number=4;}
	else if(P33==0){Key_Number=7;}
	
	P44=1;P42=1;P35=0;P34=1;
	P30=1;P31=1;P32=1;P33=1;
	if(P30==0){Key_Number=17;}
	else if(P31==0){Key_Number=2;}
	else if(P32==0){Key_Number=5;}
	else if(P33==0){Key_Number=8;}
	
	P44=1;P42=1;P35=1;P34=0;
	P30=1;P31=1;P32=1;P33=1;
	if(P30==0){Key_Number=17;}
	else if(P31==0){Key_Number=3;}
	else if(P32==0){Key_Number=6;}
	else if(P33==0){Key_Number=9;}
	return Key_Number;
}

void Key_Loop(void)
{
	static unsigned char New_Number,Old_Number;
	Old_Number = New_Number;
	New_Number = Key_Scan();
	if(Old_Number == 0 && New_Number==19){Key_KeyNumber = 0;}
	if(Old_Number == 1 && New_Number==19){Key_KeyNumber = 1;}
	if(Old_Number == 2 && New_Number==19){Key_KeyNumber = 2;}
	if(Old_Number == 3 && New_Number==19){Key_KeyNumber = 3;}
	if(Old_Number == 4 && New_Number==19){Key_KeyNumber = 4;}
	if(Old_Number == 5 && New_Number==19){Key_KeyNumber = 5;}
	if(Old_Number == 6 && New_Number==19){Key_KeyNumber = 6;}
	if(Old_Number == 7 && New_Number==19){Key_KeyNumber = 7;}
	if(Old_Number == 8 && New_Number==19){Key_KeyNumber = 8;}
	if(Old_Number == 9 && New_Number==19){Key_KeyNumber = 9;}
}