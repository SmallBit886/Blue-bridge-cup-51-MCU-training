#ifndef __SYS_H_
#define __SYS_H_

#define DELAY_TIME	5
/***********************************************************/

#include <STC15F2K60S2.H>
#include "LED.h"
#include "Key.h"
#include "SMG.h"
#include "E2PROM.h"
#include "DS1302.h"
#include "IIC.h"
#include "Timer.h"
#include "Delay.h"

/*****************************************************/
extern unsigned char code duanma[];

void HC138_Chose(unsigned char channel);



#endif