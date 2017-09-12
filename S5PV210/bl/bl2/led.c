#define GPJ0CON  (*(volatile unsigned long *)0xE0200240)
#define GPJ0DAT  (*(volatile unsigned long *)0xE0200244)
#define GPJ0PUD  (*(volatile unsigned long *)0xE0200248)
#define GPD0CON  (*(volatile unsigned long *)0xE02000A0)
#define GPD0DAT  (*(volatile unsigned long *)0xE02000A4)
#define GPD0PUD  (*(volatile unsigned long *)0xE02000A8)
void loop_time()
{
	volatile int r0=0x00200000;
	while(r0!=0)
		r0--;
}

int Main()
{

	//@配置基础参数
	int r1=0x00111000;	
	int r2=0xff000fff;
	GPJ0CON = GPJ0CON&r2;
	GPJ0CON = GPJ0CON|r1;
	

	r1=0x00000010;
	r2=0xffffff0f;
	GPD0CON = GPD0CON&r2;
	GPD0CON = GPD0CON|r1;
  
	r1=0x00000000;
	r2=0xffff81ff;
	GPJ0PUD = GPJ0PUD&r2;
	GPJ0PUD = GPJ0PUD|r1;

	r1=0x00000000;
	r2=0xfffffff3;
	GPD0PUD = GPD0PUD&r2;
	GPD0PUD = GPD0PUD|r1;

	//@将所有灯熄灭
  
	r1=0x00000002;
	r2=0xfffffffd;
	GPD0DAT = GPD0DAT&r2;
	GPD0DAT = GPD0DAT|r1;
  
	r1=0x00000038;
	r2=0xffffffc7;
	GPJ0DAT = GPJ0DAT&r2;
	GPJ0DAT = GPJ0DAT|r1;

	loop_time();

	//@流水灯循环
	while(1){
   
		r1=0x00000030;
		r2=0xffffffc7;
		GPJ0DAT = GPJ0DAT&r2;
		GPJ0DAT = GPJ0DAT|r1;

		loop_time();

		r1=0x00000028;
		r2=0xffffffc7;
		GPJ0DAT = GPJ0DAT&r2;
		GPJ0DAT = GPJ0DAT|r1;

		loop_time();

		r1=0x00000018;
		r2=0xffffffc7;
		GPJ0DAT = GPJ0DAT&r2;
		GPJ0DAT = GPJ0DAT|r1;

		loop_time();
 
		r1=0x00000038;
		r2=0xffffffc7;
		GPJ0DAT = GPJ0DAT&r2;
		GPJ0DAT = GPJ0DAT|r1;

		r1=0x00000000;
		r2=0xfffffffd;
		GPD0DAT = GPD0DAT&r2;
		GPD0DAT = GPD0DAT|r1;

		loop_time();
  
		r1=0x00000002;
		r2=0xfffffffd;
		GPD0DAT = GPD0DAT&r2;
		GPD0DAT = GPD0DAT|r1;
	}
}
