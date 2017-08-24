#include<stdio.h>
#include<time.h>

int main()
{
	time_t t  = time(NULL);//0 ==NULL
	int  y = 0,d = 0,h = 0,m = 0,s = 0;
	
	m =t%3600;
	h = (t-m)/3600;
	d = h/24;
	h = h-d*24;
	s = m%60;
	m = (m-s)/60; 
	y= d/365;
	d = d%365;
	printf("%d:%d:%d:%d:%d\n",y+1970,d,h+8,m,s);
	return 0;	
}
