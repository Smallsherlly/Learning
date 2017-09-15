#define	WTCON		0xE2700000
#define	SVC_STACK	0xD0037D80
#define IRQ_STACK   0xD0037F80

.global uart_init
.global _start

_start:
	bl Main
	b .
