#include <stdio.h>
#include <errno.h>
#include <string.h>
int main()
{
	FILE* frp = fopen("fubiao","r");
	if(NULL == frp)
	{
		printf("errno = %d\n",errno);
		printf("errno:%s\n",strerror(errno));
		return -1;
	}
	return 0;
}
