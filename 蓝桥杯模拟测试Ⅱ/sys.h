#ifndef __SYS_H_
#define __SYS_H_

#define DELAY_TIME	5
#define uchar 	unsigned char
#define uint 	unsigned int
/***********************************************************/

#include <STC15F2K60S2.H>
#include "LED.h"
#include "Key.h"
#include "SMG.h"
#include "DS18B20.h"
#include "IIC.h"
#include "onewire.h"
#include "Timer.h"
#include "Delay.h"
#include "adc.h"
/*****************************************************/
extern unsigned char code duanma[];

void HC138_Chose(unsigned char channel);
void Delay1ms();


#endif