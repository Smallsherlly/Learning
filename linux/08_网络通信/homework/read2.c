#include <stdio.h>


int main()
{
	FILE* fp = fopen("ip.dat","r");
	if(0 > fp)
	{
		perror("fopen");
		return -1;
	}
	printf("读取成功！\n");
	char buf[7][255] = {};
	int i = 0;
	int ret = 0;
	for(; i<7; i++)
	{	
		ret = fscanf(fp,"%s",buf[i]);
		if(0 > ret)
		{
			perror("fcanf");
			return -1;
		}
	}
/*	for(;i<7;i++)
	{
		printf("%s\n",buf[i]);
	}*/
	printf("%s\n",buf[6]);
	return 0;
		
}
