#include<stdio.h>


void exchange(char **p1,char **p2)
{
	char *tem =*p1;
	*p1 = *p2;
	*p2 = tem;
	
}

int main()
{
	char arr[20] ={0};
	char brr[20] = {0};
	char *pa =arr;
	char *pb =brr;
	printf("&pa = %p;\n&pb = %p\n",pa,pb);
	exchange(&pa,&pb);
	printf("&pa = %p;\n&pb = %p\n",pa,pb);
	
	
	return 0;	
}
