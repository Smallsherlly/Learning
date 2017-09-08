#include "key.h"
#include "int.h"

#define rGPH0CON		 (*(volatile unsigned long*) 0xE0200C00)
#define rGPH2CON		 (*(volatile unsigned long*) 0xE0200C40)
#define rEXT_INT_0_CON   (*(volatile unsigned long*) 0xE0200E00)
#define rEXT_INT_2_CON   (*(volatile unsigned long*) 0xE0200E08)
#define rEXT_INT_0_MASK  (*(volatile unsigned long*) 0xE0200F00)
#define rEXT_INT_2_MASK  (*(volatile unsigned long*) 0xE0200F08)
#define rEXT_INT_0_PEND  (*(volatile unsigned long*) 0xE0200F40)
#define rEXT_INT_2_PEND  (*(volatile unsigned long*) 0xE0200F48)

// 按键中断的初始化函数
void key_init(void)
{
	// 设置eint2~3为中断工作模式
	rGPH0CON |= 0xff<<8;
	// 设置eint16~19为中断工作模式
	rGPH2CON |= 0xffff;

	// eint2~3中断信号产生的条件设置为下降沿
	rEXT_INT_0_CON &= ~(0xff<<8);
	rEXT_INT_0_CON |= 0x22<<8;

	// eint16~19中断信号产生的条件设置为下降沿
	rEXT_INT_2_CON &= ~(0xffff<<0); 
	rEXT_INT_2_CON |= 0x2222;

	// 设置eint2~3 mask 为 pass
	rEXT_INT_0_MASK &= ~(0x3<<2);

	// 设置eint16~19 mask 为 pass
	rEXT_INT_2_MASK &= ~(0xf<<0);
	
	// 清除eint2~3的挂起
	rEXT_INT_0_PEND |= (0x3<<2);
	
	// 清除eint16~19的挂起
	rEXT_INT_2_PEND |= (0xf<<0);

}

void WTDOG(void)
{
	puts("watch dog!");
	WTCLRINT = 1;
	//rEXT_INT_0_PEND |= 0x1<<27;
}

// 按键的中断响应函数
void isr_eint2(void)
{
	// 执行中断响应
	puts("isr_eint2\r");
	// 清除中断挂起
	rEXT_INT_0_PEND |= 0x1<<2;
}

void isr_eint3(void)
{
	// 执行中断响应
	puts("isr_eint3\r");
	// 清除中断挂起
	rEXT_INT_0_PEND |= 0x1<<3;

}

void isr_eint16(void)
{
	// 执行中断响应
	puts("isr_eint16\r");
	// 清除中断挂起
	rEXT_INT_2_PEND |= 0x1<<0;
}

void isr_eint17(void)
{
	// 执行中断响应
	puts("isr_eint17\r");
	// 清除中断挂起
	rEXT_INT_2_PEND |= 0x1<<1;
}

void isr_eint18(void)
{
	// 执行中断响应
	puts("isr_eint18\r");
	// 清除中断挂起
	rEXT_INT_2_PEND |= 0x1<<2;

}

void isr_eint19(void)
{
	// 执行中断响应
	puts("isr_eint19\r");
	// 清除中断挂起
	rEXT_INT_2_PEND |= 0x1<<3;

}

void isr_eint16171819(void)
{
	if(rEXT_INT_2_PEND & 1<<0)
	{
		isr_eint16();
	}
	if(rEXT_INT_2_PEND & 1<<1)
	{
		isr_eint17();
	}
	if(rEXT_INT_2_PEND & 1<<2)
	{
		isr_eint18();
	}
	if(rEXT_INT_2_PEND & 1<<3)
	{
		isr_eint19();
	}

//	rEXT_INT_2_PEND |= 0xf;
}
