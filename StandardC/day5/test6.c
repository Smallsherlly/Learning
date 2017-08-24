#include<stdio.h>

char *mystrcpy(char *dest,const char *src)
{
	assert(dest!=NULL&&src!=NULL);
	for(int i = 0; *(src+i)!='\0';i++)
	{
		
		*(dest+i) = *(src+i);
	}

}
int main()
{
	char arr[2] = {0};
	char brr[20] = {0};
	scanf("%s",arr);
	scanf("%s",brr);
	mystrcpy(arr,brr);
	printf("%s\n",arr);
	return 0 ;	
}
