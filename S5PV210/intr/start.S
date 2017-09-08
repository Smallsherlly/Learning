#define	WTCON	0xE2700000
#define	SVC_STACK	0xD0037D80
#define IRQ_STACK   0xD0037F80

.text
.code 32
.global _start
.global irq_handle
.global IRQ_handle

_start:

	@1.p828 WTCON 0xE2700000 b[5]=0
	ldr r0,=WTCON
	ldr r1,=0x0
	str r1,[r0]
	
	@2.初始化缓存
	MRC p15, 0, r1, c1, c0, 0 ;
	ORR r1, r1, #0x1000	@启用 icache
	@BIC r1, r1, #0x1	@禁用 icache
	MCR p15, 0, r1, c1, c0, 0 ;
	
	@3.设置栈指针	C语言默认使用满减栈
	ldr r13,=SVC_STACK

	bl Main

@为什么使用汇编函数，主要是为了现场的保护和恢复
IRQ_handle:
	@设置irq模式下的栈指针
	ldr sp,=IRQ_STACK
	
	@保护现场
	stmfd sp!,{R0-R12,lr}

	@调用中断处理函数
	bl irq_handle

	@恢复现场
	ldmfd sp!,{R0-R12,pc}^
