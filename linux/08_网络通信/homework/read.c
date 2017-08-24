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
	int ret = fscanf(fp,"%s%s%s%s%s%s%s",buf[0],buf[1],buf[2],buf[3],buf[4],buf[5],buf[6]);
	if(0 > ret)
	{
		perror("fcanf");
		return -1;
	}
	int i = 0;
/*	for(;i<7;i++)
	{
		printf("%s\n",buf[i]);
	}*/
	printf("%s\n",buf[6]);
	return 0;
		
}
