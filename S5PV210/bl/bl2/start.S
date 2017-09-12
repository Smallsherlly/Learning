#define	WTCON	0xE2700000
#define	SVC_STACK	0xD0037D80

.global _start
.global end

_start:
bl Main
b .
