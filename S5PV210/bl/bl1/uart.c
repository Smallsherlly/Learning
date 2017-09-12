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

typedef enum{FALSE,TRUE} bool;
#define CopySDMMCtoMem(z,a,b,c,e) (\
((bool(*)(int, unsigned int,unsigned short, unsigned int*, bool))\
(*((unsigned int *)0xD0037F98)))(z,a,b,c,e))

typedef bool(*pCopySDMMC2Mem)(int, unsigned int, unsigned short, unsigned int*, bool);  

typedef void(*bl2)(void);

void copy()
{
//	CopySDMMCtoMem(2,33,1,(unsigned int*)0x23E00000,0);
	pCopySDMMC2Mem p1 = *(pCopySDMMC2Mem*)0xD0037F98;
	p1(2,33,2,(unsigned int*)0x23E00000,0);
//	CopySDMMCtoMem(2,33,2,(unsigned int*)0x23E00000,0);
	bl2 p2 = (bl2)0x23E00000;
	p2();
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

	putc('P');
	putc('s');
}

//输出一个字符
void putc(const char ch)
{
	while(0 == (rTRSTA2 & (1 << 1)));
	rTbuff2 = ch;
}


//输入一个字符
char getc(void)
{
	while(0 == (rTRSTA2 & 1));
	return rRbuff2 & 0xff;
}

