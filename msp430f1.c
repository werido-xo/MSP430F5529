#include"msp430f5529.h"

#define uint 	unsigned int		//为了方便数据的定义，自定义数据类型
#define uchar 	unsigned char

#define set_Rs P1OUT |=BIT3			//设置与清零RS端口
#define clr_Rs P1OUT &=~BIT3

#define lcd_en 	P1OUT |=BIT5		//使能与否的设置
#define lcd_clr P1OUT &=~BIT5

#define dataout 	P2DIR=oxff			//输出端口的设置
#define dataport	P2OUT


void init_clk(void)
{
	unsigned char i;
	BCSTL1 &=~XT2OFF;
	BCSTL2 |=SELM1+SELS;
	
	do
	{
		IFG1 &=~OFIFG;
		for(i=0;i<100;i++)
			_NOP();
	}while((IFG1&OFIFG)!=0);
	IFG1 &=~OFIFG;
}

void write_com(void)
{
	


