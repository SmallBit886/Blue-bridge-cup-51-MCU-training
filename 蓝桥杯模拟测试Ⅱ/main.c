#include "sys.h"


unsigned char Key_Value;
uint T;
uchar Lux;
static uchar Table_Mode = 0x11;
static uchar T_Flag ,L_Flag,ADC_Flag = 0;


/******************************模式界面0x10*****************************/
/***************************模式1温度界面0x11********************************/
void Temperture_Table(void)
{
	T_Flag = 1;
	L_Flag = 0;
	//初始化显示界面
	SMG_SetBuf(1,1);//C
	SMG_SetBuf(2,17);//灭
	SMG_SetBuf(3,17);//灭
	SMG_SetBuf(4,17);//灭
	SMG_SetBuf(5,17);//灭
	SMG_SetBuf(6,T/10);//输入数据
	SMG_SetBuf(7,T%10+32);//输入数据
	SMG_SetBuf(8,T*10%10);//输入数据
}
/***************************模式2光照度界面0x12********************************/

void Light_Table(void)
{
	uchar tmp;
	T_Flag = 0;
	L_Flag = 1;
	
	if(Lux/100 == 0) tmp = 17;
	else tmp = Lux/100;
	//初始化显示界面
	SMG_SetBuf(1,2);//C
	SMG_SetBuf(2,17);//灭
	SMG_SetBuf(3,17);//灭
	SMG_SetBuf(4,17);//灭
	SMG_SetBuf(5,17);//灭
	SMG_SetBuf(6,tmp);//输入数据
	SMG_SetBuf(7,Lux/10);//输入数据
	SMG_SetBuf(8,Lux%10);//输入数据
	
}
/****************************输出界面0x20*******************************/
void OutPut_Table(void)
{
	if(T_Flag)
	{
		uchar T_Tmp = (uchar)(T);
		uchar T_DAC = (uchar)(0.013*T_Tmp+0.826);
		if(ADC_Flag == 0) 
		{
			ADC_Flag = 1;
			dac_out(T_DAC);
			ADC_Flag = 0;
		}
		
		SMG_SetBuf(1,26);
		SMG_SetBuf(2,17);
		SMG_SetBuf(3,17);
		
		SMG_SetBuf(4,17);
		SMG_SetBuf(5,17);
		SMG_SetBuf(6,17);//-
		SMG_SetBuf(7,T_DAC/10+32);
		SMG_SetBuf(8,T_DAC%10);		
	}
	else if(L_Flag)
	{
		uchar L_Tmp = (uchar)(Lux/16.0);
		uchar L_DAC = (uchar)(0.13*L_Tmp-0.30);
		if(ADC_Flag == 0) 
		{
			ADC_Flag = 1;
			dac_out(L_DAC);
			ADC_Flag = 0;
		}

		
		SMG_SetBuf(1,26);
		SMG_SetBuf(2,17);
		SMG_SetBuf(3,17);
		
		SMG_SetBuf(4,17);
		SMG_SetBuf(5,17);
		SMG_SetBuf(6,17);//-
		SMG_SetBuf(7,L_DAC/10+32);
		SMG_SetBuf(8,L_DAC%10);		
	}
}
int main()
{
	
	Delay_ms(500);
	DS18B20_ConvertT();	//转换温度
	T=DS18B20_ReadT();	//读取温度
	Lux = adc_read(1);
	Led1_ON();
	T_Flag = 1;
	L_Flag = 0;
	Timer0_Init();	//定时器初始化
	while (1)
	{
		Key_Value = Key_GetValue();
		if(Key_Value == 5)	//界面切换
		{
			if(Table_Mode == 0x11 || Table_Mode == 0x12) Table_Mode = 0x20;
			else if(Table_Mode == 0x20) Table_Mode = 0x11;
		}
		if(Key_Value == 4)	//模式切换
		{
			if(Table_Mode == 0x11) Table_Mode = 0x12;
			else if(Table_Mode == 0x12) Table_Mode = 0x11;
		}
		if(Table_Mode == 0x11)
		{
			Led1_ON();
			Temperture_Table();
		}
		else if(Table_Mode == 0x12)
		{
			Led2_ON();
			Light_Table();
		}
		else if(Table_Mode == 0x20)
		{
			Led_OFF();
			OutPut_Table();
		}
	}
}

void Timer0_interrupt(void) interrupt 1
{

	static unsigned int Keycount ,Temperature,LuxCount;
	Keycount++;
	if(Keycount>=20)//20ms调用一次按键驱动函数
	{
		Keycount=0;
		Key_Loop();
	}
	Temperature++;
	if(Temperature >= 1500)//1.5s采集温度
	{
		Temperature=0;
		DS18B20_ConvertT();	//转换温度
		T=DS18B20_ReadT();	//读取温度
	}
	
	LuxCount++;
	if(LuxCount >= 2000)//2S采集光照
	{ 
		if(ADC_Flag == 0)
		{
			ADC_Flag = 1;	//关闭DAC
			Lux = adc_read(1);		
		}
		ADC_Flag = 0;	//打开ADC
	}
	//1ms调用一次数码管驱动函数
	SMG_Loop();
}
