#include "sys.h"


unsigned char Key_Value;
unsigned char Mode;
static unsigned char Temp1,Temp2,Temp3,Temp4;
static unsigned int TempH,TempL,NewValue,LastValue;
/***************************时间界面********************************/
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
/***************************输入界面********************************/

void Input_Table(void)
{
	static unsigned char count = 0;	//按键按下次数
	//初始化显示界面
	SMG_SetBuf(1,12);//C
	SMG_SetBuf(2,19);//灭
	SMG_SetBuf(3,19);//灭
	SMG_SetBuf(4,19);//灭
	SMG_SetBuf(5,19);//输入数据
	SMG_SetBuf(6,19);//输入数据
	SMG_SetBuf(7,19);//输入数据
	SMG_SetBuf(8,19);//输入数据
	
	Key_Value = Key_GetValue();
	if(Key_Value !=10 && Key_Value !=19 && Key_Value !=11)//判断是不是输入键
	{
		count++;
		if(count<4)//判断次数
		{
			if(count==1)
			{
				Temp1=Key_Value;//储存第一次数据
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
	if(Key_Value ==11)//如果清零按键按下：清零
	{
		SMG_SetBuf(5,19);
		SMG_SetBuf(6,19);
		SMG_SetBuf(7,19);
		SMG_SetBuf(8,19);
		count=0;	
	}
}
/****************************记录界面*******************************/
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
	Timer0_Init();	//定时器初始化
	DS1302_Init();	//初始化DS1302
	DS1302_SetTime();//设置时间
	Time_Table();//时间界面显示
	L1_ON();	//L1指示灯亮
	while (1)
	{
		Key_Value = Key_GetValue();//循环获取按键值
		if(Key_Value==10)	//检测切换按键
		{
			Key_Value=19;	//恢复初始值
			Mode++;			//模式加1：模式1---模式2---模式3
			Mode%=4;		//如果Mode为4，则置为0
		}
		switch(Mode)		//循环检测模式
		{
			case 1:			//模式1：切入输入界面
				L2_ON();	//L2指示灯亮
				Input_Table();//进入输入界面
			break;
			case 2:			//模式2：切入记录界面
				L3_ON();	//L3指示灯点亮
				DS1302_ReadTime();//读取当前时间
				E2PROM_Write(0,DS1302_Time[3]);//时钟写入地址0
				Delay_ms(5);
				E2PROM_Write(1,DS1302_Time[4]);//分钟写入地址1
				Delay_ms(5);
				/**************************读入旧数据*********************************/
				Old_ValueH = E2PROM_Read(2);
				Delay_ms(5);
				Old_ValueH = Old_ValueH/16*1000+Old_ValueH%16*100;
				Old_ValueL = E2PROM_Read(3);
				Old_ValueL = Old_ValueL/16*10+Old_ValueL%16;
				Delay_ms(5);
				LastValue = Old_ValueH + Old_ValueL;
				if(LastValue<NewValue)	//判断新数据是否大于旧数据
				{
					L4_ON();
				}
				E2PROM_Write(2,TempH/10*16+TempH%10);//输入数据高字节
				Delay_ms(5);
				E2PROM_Write(3,TempL/10*16+TempL%10);//输入数据低字节
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
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	SMGcount++;
	if(SMGcount>=2)//2ms调用一次数码管驱动函数
	{
		SMGcount=0;
		SMG_Loop();
	}
	Keycount++;
	if(Keycount>=20)//20ms调用一次按键驱动函数
	{
		Keycount=0;
		Key_Loop();
	}
}
