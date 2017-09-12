#define	WTCON	0xE2700000
#define	SVC_STACK	0xD0037D80

.global _start
.global end

loop_before:
ldr r3,=end
adr r0,_start
ldr r1,=_start
loop: 
cmp r1,r3
beq loop_end
ldr r2,[r0]
str r2,[r1]
add r0,r0,#4    @此处关键，每个寄存器容量为32位，即四个字节，所以每次拷贝完的步进也为4
add r1,r1,#4
b loop

loop_end:
ldr pc,=_start

_start:
@p828 WTCON 0xE2700000 b[5]=0
ldr r0,=WTCON
ldr r1,=0x0
str r1,[r0]
	
@2.初始化缓存
MRC p15, 0, r1, c1, c0, 0 ;
ORR r1, r1, #0x1	@启用 icache
@BIC r1, r1, #0x1	@禁用 icache
MCR p15, 0, r1, c1, c0, 0 ;
	
@3.设置栈指针	C语言默认使用满减栈
ldr r13,=SVC_STACK

bl Main
b .
