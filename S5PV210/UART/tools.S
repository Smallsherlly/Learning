.global ring_on
.global ring_off
.global led1_on
.global led2_on
.global led3_on
.global led4_on
.global led1_off
.global led2_off
.global led3_off
.global led4_off
.global led_init



@蜂鸣器打开
ring_on:
@配置基础参数
ldr r0,=0xE02000A0
ldr r1,=0x00000100
ldr r2,=0xfffff0ff
ldr r3,[r0]
and r3,r3,r2
orr r3,r3,r1
str r3,[r0]

ldr r0,=0xE02000A8
ldr r1,=0x00000000
ldr r2,=0xffffffcf
ldr r3,[r0]
and r3,r3,r2
orr r3,r3,r1
str r3,[r0]

ldr r0,=0xE02000A4    
ldr r1,=0x00000004
ldr r2,=0xfffffffb
ldr r3,[r0]
and r3,r3,r2
orr r3,r3,r1
str r3,[r0]

mov pc,lr

@蜂鸣器打开
ring_off:
@配置基础参数
ldr r0,=0xE02000A0
ldr r1,=0x00000100
ldr r2,=0xfffff0ff
ldr r3,[r0]
and r3,r3,r2
orr r3,r3,r1
str r3,[r0]

ldr r0,=0xE02000A8
ldr r1,=0x00000000
ldr r2,=0xffffffcf
ldr r3,[r0]
and r3,r3,r2
orr r3,r3,r1
str r3,[r0]

ldr r0,=0xE02000A4    
ldr r1,=0x00000000
ldr r2,=0xfffffffb
ldr r3,[r0]
and r3,r3,r2
orr r3,r3,r1
str r3,[r0]

mov pc,lr



loop_time:
ldr r0,=0x8000ffff
time:
subs r0,r0,#1
bpl time_end
b time

loop_time2:
ldr r0,=0x80300000
time2:
subs r0,r0,#1
bpl time_end
b time2

time_end:
mov pc,lr

ring_end:
mov pc,r5

led_init:
@配置基础参数
ldr r0,=0xE0200240     
ldr r1,=0x00111000	
ldr r2,=0xff000fff
ldr r3,[r0]
and r3,r3,r2
orr r3,r3,r1
str r3,[r0]

ldr r0,=0xE02000A0
ldr r1,=0x00000010
ldr r2,=0xffffff0f
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
ldr r2,=0xfffffff3
ldr r3,[r0]
and r3,r3,r2
orr r3,r3,r1
str r3,[r0]

@将所有灯熄灭
ldr r0,=0xE02000A4    
ldr r1,=0x00000002
ldr r2,=0xfffffffd
ldr r3,[r0]
and r3,r3,r2
orr r3,r3,r1
str r3,[r0]

ldr r0,=0xE0200244    
ldr r1,=0x00000038
ldr r2,=0xffffffc7
ldr r3,[r0]
and r3,r3,r2
orr r3,r3,r1
str r3,[r0]

mov pc,lr


led1_on:
ldr r0,=0xE0200244    
ldr r1,=0x00000000
ldr r2,=0xfffffff7
ldr r3,[r0]
and r3,r3,r2
orr r3,r3,r1
str r3,[r0]

mov pc,lr

led1_off:
ldr r0,=0xE0200244    
ldr r1,=0x00000008
ldr r2,=0xfffffff7
ldr r3,[r0]
and r3,r3,r2
orr r3,r3,r1
str r3,[r0]

mov pc,lr

led2_on:
ldr r0,=0xE0200244    
ldr r1,=0x00000000
ldr r2,=0xffffffef
ldr r3,[r0]
and r3,r3,r2
orr r3,r3,r1
str r3,[r0]

mov pc,lr

led2_off:
ldr r0,=0xE0200244    
ldr r1,=0x00000010
ldr r2,=0xffffffef
ldr r3,[r0]
and r3,r3,r2
orr r3,r3,r1
str r3,[r0]

mov pc,lr

led3_on:
ldr r0,=0xE0200244    
ldr r1,=0x00000000
ldr r2,=0xffffffdf
ldr r3,[r0]
and r3,r3,r2
orr r3,r3,r1
str r3,[r0]

mov pc,lr

led3_off:
ldr r0,=0xE0200244    
ldr r1,=0x00000020
ldr r2,=0xffffffdf
ldr r3,[r0]
and r3,r3,r2
orr r3,r3,r1
str r3,[r0]

mov pc,lr

led4_on:
ldr r0,=0xE02000A4    
ldr r1,=0x00000000
ldr r2,=0xfffffffd
ldr r3,[r0]
and r3,r3,r2
orr r3,r3,r1
str r3,[r0]

mov pc,lr

led4_off:
ldr r0,=0xE02000A4    
ldr r1,=0x00000002
ldr r2,=0xfffffffd
ldr r3,[r0]
and r3,r3,r2
orr r3,r3,r1
str r3,[r0]

mov pc,lr
