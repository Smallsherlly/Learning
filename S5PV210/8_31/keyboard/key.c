#define GPH0CON (*(volatile unsigned long*)0xE0200C00)
#define GPH0DAT (*(volatile unsigned long*)0xE0200C04)
#define GPH0PUD (*(volatile unsigned long*)0xE0200C08)
#define GPH2CON (*(volatile unsigned long*)0xE0200C40)
#define GPH2DAT (*(volatile unsigned long*)0xE0200C44)
#define GPH2PUD (*(volatile unsigned long*)0xE0200C48)



void key_init(void)
{
	//把GPH0CON(0xE020_0C00) 2~3 配置为 input(b8~15 0x00)
	GPH0CON &= ~(0xff << 8);
	//把GPH0PUD(0xE020_0C08) 4~7 配置为 down(b4~7 0x5)
	GPH0PUD &= ~(0xf << 4);
	GPH0PUD |= (0x5 << 4);
	//把GPH2CON(0xE020_0C40) 0~3 配置为 input(b0~15 0x0000)
	GPH2CON &= ~0xffff;
	//把GPH2PUD(0xE020_0C48) 0~3 配置为 down(b0~7 0x55)
	GPH2PUD &= ~0xff;
	GPH2PUD |= 0x55;
}

void key_polling(void)
{
	key_init();
	led_init();

	while(1)
	{
		//读取GPH0(0xE020_0C04) b2~3 0按下  1弹起
		if(0 == (GPH0DAT & (1 << 2)))
		{
			led1_on();
		}
		if(0 == (GPH0DAT & (1 << 3)))
		{
			led2_on();
		}
		//读取GPH2(0xE020_0C44) b0~3 0按下  1弹起
		if(0 == (GPH2DAT & (1 << 0)))
		{
			led3_on();
		}
		if(0 == (GPH2DAT & (1 << 1)))
		{
			led4_on();
		}
		if(0 == (GPH2DAT & (1 << 2)))//back
		{
			ring_on();
		}
		if(0 == (GPH2DAT & (1 << 3)))//men
		{
			ring_off();
		}
	}
}


