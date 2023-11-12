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
			L2=0;
			while(S6==0);
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
/***************************矩阵键盘********************************/
/*发现有按键按下， 等待其松开后， 在数码管的最左边 1 位显示相应的数字*/
unsigned char Key_Num;
void Key_Read(void)
{
	
	P44 = 0; P42 = 1; P35 = 1; P34 = 1; // 第 1 列
	P30 = 1; P31 = 1; P32 = 1; P33 = 1; 
	if(P30==0)
	{
		Delay(20);
		if(P30==0)Key_Num = 1;
		while(P30==0);
	}
	else if(P31==0)
	{
		Delay(20);
		if(P31==0)Key_Num =  2;
		while(P31==0);
	}
		else if(P32==0)
	{
		Delay(20);
		if(P32==0)Key_Num =  3;
		while(P32==0);
	}
		else if(P33==0)
	{
		Delay(20);
		if(P33==0) Key_Num =  4;
		while(P33==0);
	}
	P44 = 1; P42 = 0; P35 = 1; P34 = 1; // 第 2 列
	P30 = 1; P31 = 1; P32 = 1; P33 = 1; 
	if(P30==0)
	{
		Delay(20);
		if(P30==0)Key_Num = 5;
		while(P30==0);
	}
	else if(P31==0)
	{
		Delay(20);
		if(P31==0)Key_Num =  6;
		while(P31==0);
	}
		else if(P32==0)
	{
		Delay(20);
		if(P32==0)Key_Num =  7;
		while(P32==0);
	}
		else if(P33==0)
	{
		Delay(20);
		if(P33==0) Key_Num =  8;
		while(P33==0);
	}
	P44 = 1; P42 = 1; P35 = 0; P34 = 1; // 第 3 列
	P30 = 1; P31 = 1; P32 = 1; P33 = 1; 
	if(P30==0)
	{
		Delay(20);
		if(P30==0)Key_Num = 9;
		while(P30==0);
	}
	else if(P31==0)
	{
		Delay(20);
		if(P31==0)Key_Num =  10;
		while(P31==0);
	}
		else if(P32==0)
	{
		Delay(20);
		if(P32==0)Key_Num =  11;
		while(P32==0);
	}
		else if(P33==0)
	{
		Delay(20);
		if(P33==0) Key_Num =  12;
		while(P33==0);
	}
	P44 = 1; P42 = 1; P35 = 1; P34 = 0; // 第 4 列
	P30 = 1; P31 = 1; P32 = 1; P33 = 1; 
	if(P30==0)
	{
		Delay(20);
		if(P30==0)Key_Num = 13;
		while(P30==0);
	}
	else if(P31==0)
	{
		Delay(20);
		if(P31==0)Key_Num =  14;
		while(P31==0);
	}
		else if(P32==0)
	{
		Delay(20);
		if(P32==0)Key_Num =  15;
		while(P32==0);
	}
		else if(P33==0)
	{
		Delay(20);
		if(P33==0) Key_Num =  16;
		while(P33==0);
	}
}