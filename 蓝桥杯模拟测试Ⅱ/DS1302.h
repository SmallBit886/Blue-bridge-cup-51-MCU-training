#ifndef __DS1302_H__
#define __DS1302_H__
#include "sys.h"
extern char DS1302_Time[];
void DS1302_Init(void);
void Write_Ds1302(unsigned  char temp);
void Write_Ds1302_Byte( unsigned char address,unsigned char dat );
unsigned char Read_Ds1302_Byte ( unsigned char address );

void DS1302_SetTime(void);
void DS1302_ReadTime(void);
#endif