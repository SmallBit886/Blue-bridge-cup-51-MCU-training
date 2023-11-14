#include "sys.h"


unsigned char Key_Value;
unsigned char Mode;
static unsigned char Temp1,Temp2,Temp3,Temp4;
static unsigned int TempH,TempL,NewValue,LastValue;
/***************************ʱ�����********************************/
void Time_Table(void)
{
	SMG_SetBuf(1,DS1302_Time[3]/10);
	SMG_SetBuf(2,DS1302_Time[3]%10);
	SMG_SetBuf(3,17);//-
	SMG_SetBuf(4,DS1302_Time[4]/10);
	SMG_SetBuf(5,DS1302_Time[4]%10);
	SMG_SetBuf(6,17);
	SMG_SetBuf(7,DS1302_Time[5]/10);
	SMG_SetBuf(8,DS1302_Time[5]%10);
}
/***************************�������********************************/

void Input_Table(void)
{
	static unsigned char count = 0;	//�������´���
	//��ʼ����ʾ����
	SMG_SetBuf(1,12);//C
	SMG_SetBuf(2,19);//��
	SMG_SetBuf(3,19);//��
	SMG_SetBuf(4,19);//��
	SMG_SetBuf(5,19);//��������
	SMG_SetBuf(6,19);//��������
	SMG_SetBuf(7,19);//��������
	SMG_SetBuf(8,19);//��������
	
	Key_Value = Key_GetValue();
	if(Key_Value !=10 && Key_Value !=19 && Key_Value !=11)//�ж��ǲ��������
	{
		count++;
		if(count<4)//�жϴ���
		{
			if(count==1)
			{
				Temp1=Key_Value;//�����һ������
				SMG_SetBuf(8,Temp1);
			}
			else if(count==2)
			{
				Temp2=Key_Value;
				SMG_SetBuf(7,Temp1);
				SMG_SetBuf(8,Key_Value);
			}
			else if(count==3)
			{
				Temp3=Key_Value;
				SMG_SetBuf(6,Temp1);
				SMG_SetBuf(7,Temp2);
				SMG_SetBuf(8,Temp3);
			}
			else if(count==4)
			{
				Temp4=Key_Value;
				SMG_SetBuf(5,Temp1);
				SMG_SetBuf(6,Temp2);
				SMG_SetBuf(7,Temp3);
				SMG_SetBuf(8,Temp4);
				count=0;		
			}
			TempH=Temp4*1000+Temp3*100;
			TempL=Temp2*10+Temp1;
			NewValue = TempH + TempL;
		}
	}
	if(Key_Value ==11)//������㰴�����£�����
	{
		SMG_SetBuf(5,19);
		SMG_SetBuf(6,19);
		SMG_SetBuf(7,19);
		SMG_SetBuf(8,19);
		count=0;	
	}
}
/****************************��¼����*******************************/
void Copy_Table(void)
{
	SMG_SetBuf(1,14);
	SMG_SetBuf(2,19);
	SMG_SetBuf(3,19);
	
	SMG_SetBuf(4,2);
	SMG_SetBuf(5,3);
	SMG_SetBuf(6,17);//-
	SMG_SetBuf(7,0);
	SMG_SetBuf(8,9);
}
unsigned int Old_ValueH,Old_ValueL;
int main()
{
	Delay_ms(500);
	Timer0_Init();	//��ʱ����ʼ��
	DS1302_Init();	//��ʼ��DS1302
	DS1302_SetTime();//����ʱ��
	Time_Table();//ʱ�������ʾ
	L1_ON();	//L1ָʾ����
	while (1)
	{
		Key_Value = Key_GetValue();//ѭ����ȡ����ֵ
		if(Key_Value==10)	//����л�����
		{
			Key_Value=19;	//�ָ���ʼֵ
			Mode++;			//ģʽ��1��ģʽ1---ģʽ2---ģʽ3
			Mode%=4;		//���ModeΪ4������Ϊ0
		}
		switch(Mode)		//ѭ�����ģʽ
		{
			case 1:			//ģʽ1�������������
				L2_ON();	//L2ָʾ����
				Input_Table();//�����������
			break;
			case 2:			//ģʽ2�������¼����
				L3_ON();	//L3ָʾ�Ƶ���
				DS1302_ReadTime();//��ȡ��ǰʱ��
				E2PROM_Write(0,DS1302_Time[3]);//ʱ��д���ַ0
				Delay_ms(5);
				E2PROM_Write(1,DS1302_Time[4]);//����д���ַ1
				Delay_ms(5);
				/**************************���������*********************************/
				Old_ValueH = E2PROM_Read(2);
				Delay_ms(5);
				Old_ValueH = Old_ValueH/16*1000+Old_ValueH%16*100;
				Old_ValueL = E2PROM_Read(3);
				Old_ValueL = Old_ValueL/16*10+Old_ValueL%16;
				Delay_ms(5);
				LastValue = Old_ValueH + Old_ValueL;
				if(LastValue<NewValue)	//�ж��������Ƿ���ھ�����
				{
					L4_ON();
				}
				E2PROM_Write(2,TempH/10*16+TempH%10);//�������ݸ��ֽ�
				Delay_ms(5);
				E2PROM_Write(3,TempL/10*16+TempL%10);//�������ݵ��ֽ�
				Delay_ms(5);
				Copy_Table();
			break;
			case 3:
				L1_ON();
				Time_Table();
			break;
		}
	}
}

void Timer0_interrupt(void) interrupt 1
{
	static unsigned int SMGcount,Keycount;
	TL0 = 0x66;				//���ö�ʱ��ʼֵ
	TH0 = 0xFC;				//���ö�ʱ��ʼֵ
	SMGcount++;
	if(SMGcount>=2)//2ms����һ���������������
	{
		SMGcount=0;
		SMG_Loop();
	}
	Keycount++;
	if(Keycount>=20)//20ms����һ�ΰ�����������
	{
		Keycount=0;
		Key_Loop();
	}
}
