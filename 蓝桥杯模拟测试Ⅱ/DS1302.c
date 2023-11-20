/*	# 	DS1302代码片段说明
	1. 	本文件夹中提供的驱动代码供参赛选手完成程序设计参考。
	2. 	参赛选手可以自行编写相关代码或以该代码为基础，根据所选单片机类型、运行速度和试题
		中对单片机时钟频率的要求，进行代码调试和修改。
*/								

//
#include "DS1302.h"
#include "INTRINS.h"
sbit SCK = P1^7;
sbit SDA = P2^3;
sbit RST = P1^3;
#define DS1302_SECOND  0x80
#define DS1302_MINUTES 0x82
#define DS1302_HOUR    0x84
#define DS1302_DATE    0x86
#define DS1302_MONTH   0x88
#define DS1302_DAY     0x8A
#define DS1302_YEAR    0x8C
#define DS1302_WP      0x8E
char DS1302_Time[7]={23,11,13,18,12,30,1};

void DS1302_Init(void)
{
	RST=0;
	SCK=0;
}
void Write_Ds1302(unsigned  char temp) 
{
	unsigned char i;
	for (i=0;i<8;i++)     	
	{ 
		SCK = 0;
		SDA = temp&0x01;
		temp>>=1; 
		SCK=1;
	}
}   

//
void Write_Ds1302_Byte( unsigned char address,unsigned char dat )     
{
 	RST=0;	_nop_();
 	SCK=0;	_nop_();
 	RST=1; 	_nop_();  
 	Write_Ds1302(address);	
 	Write_Ds1302(dat);		
 	RST=0; 
}

//
unsigned char Read_Ds1302_Byte ( unsigned char address )
{
 	unsigned char i,temp=0x00;
 	RST=0;	_nop_();
 	SCK=0;	_nop_();
 	RST=1;	_nop_();
	address |=0x01;//转为读地址
 	Write_Ds1302(address);
 	for (i=0;i<8;i++) 	
 	{		
		SCK=0;
		temp>>=1;	
 		if(SDA)
 		temp|=0x80;	
 		SCK=1;
	} 
 	RST=0;	_nop_();
 	SCK=0;	_nop_();
	SCK=1;	_nop_();
	SDA=0;	_nop_();
	SDA=1;	_nop_();
	return (temp);			
}
void DS1302_SetTime(void)
{
	Write_Ds1302_Byte(DS1302_WP,0x00);//解除写保护
	Write_Ds1302_Byte(DS1302_YEAR,DS1302_Time[0]/10*16+DS1302_Time[0]%10);
	Write_Ds1302_Byte(DS1302_MONTH,DS1302_Time[1]/10*16+DS1302_Time[1]%10);
	Write_Ds1302_Byte(DS1302_DATE,DS1302_Time[2]/10*16+DS1302_Time[2]%10);
	Write_Ds1302_Byte(DS1302_HOUR,DS1302_Time[3]/10*16+DS1302_Time[3]%10);
	Write_Ds1302_Byte(DS1302_MINUTES,DS1302_Time[4]/10*16+DS1302_Time[4]%10);
	Write_Ds1302_Byte(DS1302_SECOND,DS1302_Time[5]/10*16+DS1302_Time[5]%10);
	Write_Ds1302_Byte(DS1302_DAY,DS1302_Time[6]/10*16+DS1302_Time[6]%10);
	Write_Ds1302_Byte(DS1302_WP,0x80);//开启写保护
}
void DS1302_ReadTime(void)
{
	unsigned char Temp;
	Temp = Read_Ds1302_Byte(DS1302_YEAR);
	DS1302_Time[0] = Temp/16*10+Temp%16;
	Temp = Read_Ds1302_Byte(DS1302_MONTH);
	DS1302_Time[1] = Temp/16*10+Temp%16;
	Temp = Read_Ds1302_Byte(DS1302_DATE);
	DS1302_Time[2] = Temp/16*10+Temp%16;
	Temp = Read_Ds1302_Byte(DS1302_HOUR);
	DS1302_Time[3] = Temp/16*10+Temp%16;
	Temp = Read_Ds1302_Byte(DS1302_MINUTES);
	DS1302_Time[4] = Temp/16*10+Temp%16;
	Temp = Read_Ds1302_Byte(DS1302_SECOND);
	DS1302_Time[5] = Temp/16*10+Temp%16;
	Temp = Read_Ds1302_Byte(DS1302_DAY);
	DS1302_Time[6] = Temp/16*10+Temp%16;	
}
