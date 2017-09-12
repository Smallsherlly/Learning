#define	WTCON		0xE2700000
#define	SVC_STACK	0xD0037D80
#define PS_HOLD		0xE010E81C
.global uart_init
.global _start

_start:
	ldr r1,=PS_HOLD
    ldr r0,[r1]
    ORR r0,r0,#300
    ORR r0,r0,#0x1
	str r0,[r1]

	ldr r0,=WTCON
	ldr r1,=0x0
	str r1,[r0]
	
	MRC p15, 0, r1, c1, c0, 0 ;
	ORR r1, r1, #0x1000	@启用 icache
	MCR p15, 0, r1, c1, c0, 0 ;
	
	ldr r13,=SVC_STACK

	bl uart_init
	bl Main
