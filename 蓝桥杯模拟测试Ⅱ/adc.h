#ifndef __ADC_H__
#define __ADC_H__
#include "sys.h"
#define PCF8591T_ADDRESS_W 0x90
#define PCF8591T_ADDRESS_R 0x91

uchar adc_read(uchar addr);
void dac_out(uchar date);
#endif

