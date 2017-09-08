#include "uart.h"
#include "key.h"
#include "int.h"

void delay(void)
{
	int i = 100000;
	while(i--);
}

void Main(void)
{
	// 初始化
	uart_init(115200);
	key_init();
	set_exception_vector_table();
	intr_init();

	intr_enable(NUM_EINT2);
	set_vicvectaddr(NUM_EINT2,isr_eint2);
	intr_enable(NUM_EINT3);
	set_vicvectaddr(NUM_EINT3,isr_eint3);

	intr_enable(NUM_EINT16_31);
	set_vicvectaddr(NUM_EINT16_31,isr_eint16171819);

	intr_enable(NUM_WDT);
	set_vicvectaddr(NUM_WDT,WTDOG);
	while(1)
	{
		putc('.');
		delay();
	}
}
