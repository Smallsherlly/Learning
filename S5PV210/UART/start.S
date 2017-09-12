#define	WTCON	0xE2700000
#define	SVC_STACK	0xD0037D80
#define PS_HOLD   0xE010E81C
.text
.code 32
.global _start

_start:
	mov r0,#0x180
	ldr r1,=PS_HOLD
	ORR r1,r0

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

bl clock_init
bl Main
