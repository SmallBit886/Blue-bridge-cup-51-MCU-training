#include "DS18B20.h"
#include "onewire.h"
//DS18B20指令
#define DS18B20_SKIP_ROM			0xCC
#define DS18B20_CONVERT_T			0x44
#define DS18B20_READ_SCRATCHPAD 	0xBE
/**
  * @brief  DS18B20开始温度变换
  * @param  无
  * @retval 无
  */
void DS18B20_ConvertT(void)
{
	init_ds18b20();		//先初始化
	Write_DS18B20(DS18B20_SKIP_ROM);//跳过指令
	Write_DS18B20(DS18B20_CONVERT_T);//温度转换指令
}

/**
  * @brief  DS18B20读取温度
  * @param  无
  * @retval 温度数值
  */
uint DS18B20_ReadT(void)
{
	unsigned char TLSB,TMSB;//定义接收变量
	unsigned int Temp;//定义计算后的真实温度
	
	init_ds18b20();	//初始化
	Write_DS18B20(DS18B20_SKIP_ROM);//跳过指令
	Write_DS18B20(DS18B20_READ_SCRATCHPAD);//读取指令
	TLSB=Read_DS18B20();	//先读取低字节
	TMSB=Read_DS18B20();//再读取高字节
	Temp=(TMSB<<8)|TLSB;	//高字节与低字节合并为整体
	Temp=Temp/16;	//将16进制转换为10进制
	return Temp;//返回温度
}
