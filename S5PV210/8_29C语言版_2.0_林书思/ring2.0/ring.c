#define GPD0CON *((volatile unsigned long *)0xE02000A0)
#define GPD0PUD *((volatile unsigned long *)0xE02000A8)
#define GPD0DAT *((volatile unsigned long *)0xE02000A4)

void delay_t()
{
	int r0=0x00100000;
	while(r0!=0)
		r0--;                      
}

void init(void)
{
	GPD0CON=0x00000100;
	GPD0PUD=0x00000000;
}

int Main()
{
	//@配置基础参数
	int r1=0x00000100;
	int r2=0xfffff0ff;
	GPD0CON = GPD0CON&r2;
	GPD0CON = GPD0CON|r1;

	r1=0x00000000;
	r2=0xffffffcf;
	GPD0PUD = GPD0PUD&r2;
	GPD0PUD = GPD0PUD|r1;
	
	while(1)
	{
		GPD0DAT=0x00000000;
		delay_t();
		GPD0DAT=0x00000004;
		delay_t();
	}
}

