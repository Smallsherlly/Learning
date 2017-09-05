#define GPD0CON  (*(volatile unsigned long *)0xE02000A0)
#define GPD0DAT  (*(volatile unsigned long *)0xE02000A4)
#define GPD0PUD  (*(volatile unsigned long *)0xE02000A8)
void loop_time()
{
	int r0=0x0000ffff;
	while(r0!=0)
		r0--;
}
void loop_time2()
{
	int r0=0x00100000;
	while(r0!=0)
		r0--;
}

void loop_ring()
{
	int r4=16;
	for(;r4>0;r4--)
	{  
		int r1=0x00000004;
		int r2=0xfffffffb;
		GPD0DAT = GPD0DAT&r2;
		GPD0DAT = GPD0DAT|r1;


		loop_time();
   
		r1=0x00000000;
		r2=0xfffffffb;
		GPD0DAT = GPD0DAT&r2;
		GPD0DAT = GPD0DAT|r1;

	}
}


void ring_code()
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


	//@蜂鸣器打开
	while(1)
	{
		loop_ring();
		loop_time2();
	}

}
