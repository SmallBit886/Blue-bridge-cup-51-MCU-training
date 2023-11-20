#include "DS18B20.h"
#include "onewire.h"
//DS18B20ָ��
#define DS18B20_SKIP_ROM			0xCC
#define DS18B20_CONVERT_T			0x44
#define DS18B20_READ_SCRATCHPAD 	0xBE
/**
  * @brief  DS18B20��ʼ�¶ȱ任
  * @param  ��
  * @retval ��
  */
void DS18B20_ConvertT(void)
{
	init_ds18b20();		//�ȳ�ʼ��
	Write_DS18B20(DS18B20_SKIP_ROM);//����ָ��
	Write_DS18B20(DS18B20_CONVERT_T);//�¶�ת��ָ��
}

/**
  * @brief  DS18B20��ȡ�¶�
  * @param  ��
  * @retval �¶���ֵ
  */
uint DS18B20_ReadT(void)
{
	unsigned char TLSB,TMSB;//������ձ���
	unsigned int Temp;//�����������ʵ�¶�
	
	init_ds18b20();	//��ʼ��
	Write_DS18B20(DS18B20_SKIP_ROM);//����ָ��
	Write_DS18B20(DS18B20_READ_SCRATCHPAD);//��ȡָ��
	TLSB=Read_DS18B20();	//�ȶ�ȡ���ֽ�
	TMSB=Read_DS18B20();//�ٶ�ȡ���ֽ�
	Temp=(TMSB<<8)|TLSB;	//���ֽ�����ֽںϲ�Ϊ����
	Temp=Temp/16;	//��16����ת��Ϊ10����
	return Temp;//�����¶�
}
