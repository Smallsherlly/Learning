#include "uart.h"

void delay(int i)
{
	while(i--);
}

void Main(void)
{
	led_init();
	uart_init(115200);
	while(1)
	{
		char str[20] = {};
		puts("sunll#");
		gets(str);
		putc('\n');
		if(myStrcmp(str,"led1_on")==0)
			led1_on();
		if(myStrcmp(str,"led2_on")==0)
			led2_on();
		if(myStrcmp(str,"led3_on")==0)
			led3_on();
		if(myStrcmp(str,"led4_on")==0)
			led4_on();
		if(myStrcmp(str,"led1_off")==0)
			led1_off();
		if(myStrcmp(str,"led2_off")==0)
			led2_off();
		if(myStrcmp(str,"led3_off")==0)
			led3_off();
		if(myStrcmp(str,"led4_off")==0)
			led4_off();
		if(myStrcmp(str,"ring_on")==0)
			ring_on();
		if(myStrcmp(str,"ring_off")==0)
			ring_off();
	}
}
