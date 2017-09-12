#include "stdio.h"
#include "time.h"

#define RTCCON 			*((volatile unsigned long*) 0xE2800040)

#define BCD_TIME_BASE 	*((volatile unsigned long*) 0xE2800070)


#define BCDSEC			*((volatile unsigned long*) 0xE2800070)
#define BCDMIN			*((volatile unsigned long*) 0xE2800074)
#define BCDHOUR			*((volatile unsigned long*) 0xE2800078)
#define BCDDAY			*((volatile unsigned long*) 0xE280007c)
#define BCDDAYWEEK		*((volatile unsigned long*) 0xE2800080)
#define BCDMON			*((volatile unsigned long*) 0xE2800084)
#define BCDYEAR			*((volatile unsigned long*) 0xE2800088)



void time_init(void)
{
	RTCCON |= 0x1;
	showTime();
	changeTime();
	showTime();
}

void changeTime()
{
	BCDYEAR = num_to_bcd(17);
	BCDMON = num_to_bcd(9);
	BCDDAY = num_to_bcd(8);
	BCDHOUR = num_to_bcd(20);
	BCDMIN = num_to_bcd(33);
	BCDSEC = num_to_bcd(10);
	BCDDAYWEEK = num_to_bcd(5);
}

unsigned char num_to_bcd(unsigned char num)
{
	unsigned char ten = num/10;;
	unsigned char one = num%10;
	return (ten<<4)+one;
}

unsigned char bcd_to_num(unsigned char bcd)
{
	unsigned char ten = (bcd&0xf0)>>4;
	unsigned char one = bcd&0xf;
	return ten*10+one;
}

Timer get_time()
{
	Timer time;
	time.year = bcd_to_num(BCDYEAR);
	time.month = bcd_to_num(BCDMON);
	time.hour = bcd_to_num(BCDHOUR);
	time.date = bcd_to_num(BCDDAY);
	time.min = bcd_to_num(BCDMIN);
	time.sec = bcd_to_num(BCDSEC);
	time.day = bcd_to_num(BCDDAYWEEK);
	return time;
}
void showTime()
{
	Timer time = get_time();

	// year
	printf("%d ",time.year);	

	// month
	printf("%d ",time.month);	

	// date
	printf("%d ",time.date);	

	// hour
	printf("%d ",time.hour);	

	// min
	printf("%d ",time.min);	

	// sec
	printf("%d ",time.sec);	

	//day
	printf("%d \n",time.day);	

}



