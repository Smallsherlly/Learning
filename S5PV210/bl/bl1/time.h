#ifndef _TIME_H__
#define _TIME_H__

typedef struct Time
{
	unsigned char year;
	unsigned char month;
	unsigned char date;
	unsigned char hour;
	unsigned char min;
	unsigned char sec;
	unsigned char day;
}Timer;

void showTime();
void changeTime();
Timer get_time();
unsigned char num_to_bcd(unsigned char num);
unsigned char bcd_to_num(unsigned char bcd);

#endif // _TIME_H__
