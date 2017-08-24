#include<stdio.h>
#include<time.h>

int main()
{
	time_t t  = time(NULL);
	int  h = 0,m = 0,s = 0;
	
	m =t%3600;
	h = (t-m)/3600;
	s = m%60;
	m = (m-s)/60; 

	printf("%d:%d:%d\n",h,m,s);
	return 0;	
}
