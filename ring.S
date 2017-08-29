.text
.code 32
.global Main

Main:

@配置基础参数
ldr r0,=0xE02000A0
ldr r1,=0x00000100
ldr r2,=0xfffff00f
ldr r3,[r0]
and r3,r3,r2
orr r3,r3,r1
str r3,[r0]


ldr r0,=0xE0200248    
ldr r1,=0x00000000
ldr r2,=0xffff81ff
ldr r3,[r0]
and r3,r3,r2
orr r3,r3,r1
str r3,[r0]

ldr r0,=0xE02000A8
ldr r1,=0x00000000
ldr r2,=0xffffffc3
ldr r3,[r0]
and r3,r3,r2
orr r3,r3,r1
str r3,[r0]


@蜂鸣器打开
loop_ring:
ldr r0,=0xE02000A4    
ldr r1,=0x00000004
ldr r2,=0xfffffffb
ldr r3,[r0]
and r3,r3,r2
orr r3,r3,r1
str r3,[r0]

bl loop_time

ldr r0,=0xE02000A4    
ldr r1,=0x00000000
ldr r2,=0xfffffffb
ldr r3,[r0]
and r3,r3,r2
orr r3,r3,r1
str r3,[r0]

bl loop_time
b loop_ring


loop_time:
ldr r0,=0x80030000
time:
subs r0,r0,#1
bpl time_end
b time

time_end:
mov pc,lr

