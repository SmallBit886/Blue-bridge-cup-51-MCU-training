#include "SMG.h"
//unsigned char code duanma[19]={
//0xc0, //0
//0xf9, //1
//0xa4, //2
//0xb0, //3
//0x99, //4
//0x92, //5
//0x82, //6
//0xf8, //7
//0x80, //8
//0x90, //9
//0x88, //A 11
//0x83, //b
//0xc6, //C
//0xa1, //d
//0x86, //E
//0x8e, //F
//0xbf, 
//0x7f, 
//0xff  
//};
/*************  ���س�������    **************/
unsigned char code duanma[]={                       //��׼�ֿ�
//   0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
    0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,
//black  -     H    J    K    L    N    o   P    U     t    G    Q    r   M    y
    0x00,0x40,0x76,0x1E,0x70,0x38,0x37,0x5C,0x73,0x3E,0x78,0x3d,0x67,0x50,0x37,0x6e,
    0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF,0x46};    //0. 1. 2. 3. 4. 5. 6. 7. 8. 9. -1

unsigned char code weima[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};      //λ��

/***************************��Ž�Ҫ��ʾ������********************************/
uchar SMGShow_Buf[9]={0,19,19,19,19,19,19,19,19};

/**************************���ý�Ҫ��ʾ������*********************************/	
void SMG_SetBuf(unsigned char pos,unsigned char number)
{
	SMGShow_Buf[pos]=number;
}

/***************************�����ɨ����ʾ********************************/
void DisplySMG(unsigned char pos,unsigned char date)
{
	
	HC138_Chose(6);//����λѡͨ��
	//P0 = ~((P0 & 0x00) | (0x01<<(pos-1)));//������һλ�����
	P0=weima[pos-1];
	HC138_Chose(7);//����������ʾͨ��
	P0 = ~duanma[date];//��ʾ����
	Delay1ms();
	P0=0xff;//����
}

/***************************��ʱ����ʱɨ��********************************/
void SMG_Loop(void)
{
	static unsigned char i =1;
	DisplySMG(i,SMGShow_Buf[i]);
	i++;
	if(i<=9){i=1;}
}