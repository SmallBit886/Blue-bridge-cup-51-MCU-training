#include "key.h"
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
void ScanKey_Alone()
{
	if(S7==0)
	{
		Delay(20);
		if(S7==0)
		{
			L1=0;
			while(S7==0);
			L1=1;
		}
	}
	if(S6==0)
	{
		Delay(20);
		if(S6==0)
		{
			Init_HC138(4);//Y4
			L2=0;
			while(S6==0);
			Init_HC138(4);//Y4
			L2=1;
		}
	}
	if(S5==0)
	{
		Delay(20);
		if(S5==0)
		{
			L3=0;
			while(S5==0);
			L3=1;
		}
	}
	if(S4==0)
	{
		Delay(20);
		if(S4==0)
		{
			L4=0;
			while(S4==0);
			L4=1;
		}
	}
}
/***************************¾ØÕó¼üÅÌ********************************/
unsigned char Key_Num;
void Key_Read(void)
{
	
	P44 = 0; P42 = 1; P35 = 1; P34 = 1; // µÚ 1 ÁÐ
	P30 = 1; P31 = 1; P32 = 1; P33 = 1; 
	if(P30==0)
	{
		Delay(20);
		if(P30==0)Key_Num = 1;
	}
	else if(P31==0)
	{
		Delay(20);
		if(P31==0)Key_Num =  2;
	}
		else if(P32==0)
	{
		Delay(20);
		if(P32==0)Key_Num =  3;
	}
		else if(P33==0)
	{
		Delay(20);
		if(P33==0) Key_Num =  4;
	}
	
}