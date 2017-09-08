#include "int.h"

// 异常响应函数
void exception_reset_func(void)
{
	puts("exception_reset\n");
}

void exception_undef_func(void)
{
	puts("exception_undef\n");
}

void exception_sotf_int_func(void)
{
	puts("exception_sotf\n");
}

void exception_prefetch_func(void)
{
	puts("exception_prefetch\n");
}

void exception_data_func(void)
{
	puts("exception_data\n");
}

void exception_fiq_func(void)
{
	puts("exception_fiq\n");
}

void set_exception_vector_table(void)
{
	r_exception_reset = (unsigned long)exception_reset_func;
	r_exception_undef = (unsigned long)exception_undef_func;
	r_exception_sotf_int = (unsigned long)exception_sotf_int_func;
	r_exception_prefetch = (unsigned long)exception_prefetch_func;
	r_exception_data = (unsigned long)exception_data_func;
	r_exception_fiq = (unsigned long)exception_fiq_func;
	r_exception_irq = (unsigned long) IRQ_handle;
}

void intr_init(void)
{
	// 先禁用所有中断
	VIC0INTENCLEAR = ~0x0;
	VIC1INTENCLEAR = ~0x0;
	VIC2INTENCLEAR = ~0x0;
	VIC3INTENCLEAR = ~0x0;
	
	// 选择中断类型
	VIC0IRQSTATUS = 0x0;
	VIC1IRQSTATUS = 0x0;
	VIC2IRQSTATUS = 0x0;
	VIC3IRQSTATUS = 0x0;

	// 初始化看门狗
	WTCON &= ~(0xffff);
	WTCON |= 0xff1c;
	
	WTDAT &= ~(0xffff);
	WTDAT |= 0x1000;

	WTCNT = 0x2000;


	WTCON |= 1 << 5;

	// 初始化定时蜂鸣器
	GPD0CON &= ~(0xf<<8);
	GPD0CON |= (0x2 <<8);

	TCFG0 &= ~(0xff<<8);
	TCFG0 |= (0x41<<8);

	TCFG1 &= ~(0xf<<8);
	TCFG1 |= 0;

	TCON |= 1<<14;

	TCNTB2 = 0x0050;
	TCMPB2 = 0x00A0;

	TCON |= (1<<15);

	TCON |= (1<<12);

}

// 中断使能
void intr_enable(unsigned long intrnum)
{
	// 根据中断编号确定是哪一组 0～31 32～63 64～95 96～127
	if(intrnum < 32)
	{
		VIC0INTENABLE |= 0x1 << intrnum;
	}
	else if(intrnum < 64)
	{
		VIC1INTENABLE |= 0x1 << intrnum - 32;
	}
	else if(intrnum < 96)
	{
		VIC2INTENABLE |= 0x1 << intrnum - 64;

	}else if(intrnum < 128)
	{
		VIC3INTENABLE |= 0x1 << intrnum - 96;
	}
	else
	{
		VIC0INTENABLE = ~0x0;
		VIC1INTENABLE = ~0x0;
		VIC2INTENABLE = ~0x0;
		VIC3INTENABLE = ~0x0;
	}

}

void disable(unsigned long intrnum)
{
	// 作业
}

void set_vicvectaddr(unsigned long intrnum,void(*handle)(void))
{
	// 根据中断源编号确定是哪一组
	if(intrnum < 32)
	{
		*((volatile unsigned long*)VIC0VECTADDR + intrnum) = 
			(unsigned long)handle;
	}
	else if(intrnum < 64)
	{
		*((volatile unsigned long*)VIC1VECTADDR + intrnum-32) = 
			(unsigned long)handle;

	}
	else if(intrnum < 96)
	{
		*((volatile unsigned long*)VIC2VECTADDR + intrnum-64) = 
			(unsigned long)handle;
	}
	else if(intrnum < 128)
	{
		*((volatile unsigned long*)VIC3VECTADDR + intrnum-96) = 
			(unsigned long)handle;

	}
}

void irq_handle()
{
	void (*isr)(void) = NULL;

	// 根据状态寄存器来确定哪一组发生了中断
	// 从VICADDR寄存器中找到绑定的函数，然后执行
	if(VIC0IRQSTATUS)
	{
		isr = (void(*)(void))VIC0ADDR;
		//(void(*)(void))VIC0ADDR;
		isr();
		VIC0ADDR = 0x0;
	}
	
	if(VIC1IRQSTATUS)
	{
		isr = (void(*)(void))VIC1ADDR;
		//(void(*)(void))VIC0ADDR;
		isr();
		VIC1ADDR = 0x0;

	}

	if(VIC2IRQSTATUS)
	{
		isr = (void(*)(void))VIC2ADDR;
		//(void(*)(void))VIC0ADDR;
		isr();
		VIC2ADDR = 0x0;

	}

	if(VIC3IRQSTATUS)
	{
		isr = (void(*)(void))VIC3ADDR;
		//(void(*)(void))VIC0ADDR;
		isr();
		VIC3ADDR = 0x0;

	}
}
