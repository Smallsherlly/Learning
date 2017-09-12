#include "uart.h"

#define NULL 0
#define rGPA1CON   (*(volatile unsigned long*) 0xE0200020)
#define rULCON2    (*(volatile unsigned long*) 0xE2900800)
#define rUCON2     (*(volatile unsigned long*) 0xE2900804)
#define rUFCON2    (*(volatile unsigned long*) 0xE2900808)
#define rUMCON2    (*(volatile unsigned long*) 0xE290080C)
#define rTRSTA2    (*(volatile unsigned long*) 0xE2900810)
#define rTbuff2    (*(volatile unsigned long*) 0xE2900820)
#define rRbuff2    (*(volatile unsigned long*) 0xE2900824)
#define rUBRDIV2   (*(volatile unsigned long*) 0xE2900828)
#define rUDIVSLOT2 (*(volatile unsigned long*) 0xE290082C)

#define TSADCCON0  (*(volatile unsigned long*) 0xE1700000)
#define TSDATX0    (*(volatile unsigned long*) 0xE170000C)
#define TSDATY0    (*(volatile unsigned long*) 0xE1700010)
#define ADCMUX     (*(volatile unsigned long*) 0xE170001C)

// AD初始化
void ConfigAD(void)
{
	TSADCCON0 |= (0x1 << 16);
	TSADCCON0 &= ~(0x1ff << 6);
	TSADCCON0 |= (0x10E << 6);
	TSADCCON0 &= ~(0x1 <<2);

	ADCMUX &= ~(0xf); 

	// 开启转换
	TSADCCON0 |= 0x1;
	while(TSADCCON0 & (0x1 << 15) == 0);

	
	int tx = TSDATX0 & 0xfff;
	int ty = TSDATY0 & 0xfff;
	printf("tx:%d   ty:%d\n",tx,ty);
}

// uart初始化
void uart_init(unsigned int baud)
{
	// 设置GPA1CON 0～1 设置为 UART 工作模式
	rGPA1CON &= ~(0xff);
	rGPA1CON |= 0x22;
	// 设置ULCON2 设置为 正常 无校验 1停止位 8数据位 0x3
	rULCON2 &= ~(0x3f);
	rULCON2 |= 0x3;
	// 设置UCON2 把T和R设置为中断或轮询模式 0x5
	rUCON2 &= ~(0xf);
	rUCON2 |= 0x5;
	// 禁用FIFO 和Modem  全部设置为0
	rUFCON2 &= 0;
	rUMCON2 &= 0;
	// 设置rUBRDIV2 = (PLCK/(baud*16))-1 整数部分
	//(66500000/baud/16)-1;
	rUBRDIV2 &= ~(0xffff);
	rUBRDIV2 |= 0x23;
	// 设置rUDIVSLOT2 小数部分*16(查表)
	rUDIVSLOT2 &= ~(0xffff);
	rUDIVSLOT2 |= 0x0008;
}


//输出一个字符
void putc(const char ch)
{
	// 如果要显示的字符是/n。那么首先显示一个/r
	if(ch == '\n')
		putc('\r');
	while(0 == (rTRSTA2 & (1 << 1)));
	rTbuff2 = ch;
}


//输入一个字符
char getc(void)
{
	while(0 == (rTRSTA2 & 1));
	return rRbuff2 & 0xff;
}
