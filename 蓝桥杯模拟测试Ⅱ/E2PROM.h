#ifndef __E2PROM_H__
#define __E2PROM_H__
#include "sys.h"
#define Device_W_Address 0xA0
#define Device_R_Address 0xA1
void E2PROM_Write(unsigned char stress,unsigned char date);
unsigned char E2PROM_Read(unsigned char Word_Address);

#endif