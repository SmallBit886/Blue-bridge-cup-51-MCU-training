#include "adc.h"
#include "IIC.h"

uchar adc_read(uchar addr)
{
	uchar date;
	I2CStart();
	I2CSendByte(PCF8591T_ADDRESS_W);
	I2CWaitAck();
	I2CSendByte(addr);
	I2CWaitAck();
	I2CStop();
	
	I2CStart();
	I2CSendByte(PCF8591T_ADDRESS_R);
	I2CWaitAck();	
	date = I2CReceiveByte();
	I2CSendAck(1);
	I2CStop();
	return date;
}

void dac_out(uchar date)
{
	I2CStart();
	I2CSendByte(PCF8591T_ADDRESS_W);
	I2CWaitAck();
	I2CSendByte(0x40);
	I2CWaitAck();
	I2CSendByte(date);
	I2CWaitAck();	
	I2CStop();
}






