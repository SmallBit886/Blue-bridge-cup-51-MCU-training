#include "E2PROM.h"

void E2PROM_Write(unsigned char Word_Address,unsigned char date)
{
	I2CStart();
	I2CSendByte(Device_W_Address);
	I2CWaitAck();
	I2CSendByte(Word_Address);
	I2CWaitAck();
	I2CSendByte(date);
	I2CWaitAck();	
	I2CStop();
}
unsigned char E2PROM_Read(unsigned char Word_Address)
{
	unsigned char temp;
	I2CStart();
	I2CSendByte(Device_W_Address);
	I2CWaitAck();
	I2CSendByte(Word_Address);
	I2CWaitAck();
	I2CStart();
	I2CSendByte(Device_R_Address);//∂¡µÿ÷∑
	I2CWaitAck();
	temp = I2CReceiveByte();
	I2CSendAck(1);
	I2CStop();
	return temp;
}
