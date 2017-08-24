#include<stdio.h>

char *mystrcat(char *dest,const char *src)
{
	if(dest!=NULL&&src!=NULL)
	{
		
		char *pdest = dest;
			while(*pdest++);
		pdest--;	
				while(*src!='\0')
				{
					*pdest++ =*src++;
				}
			//	*dest = '\0';
				return dest;
		
	}
    
	

}
int main()
{
	char arr[9] = "auadfasdb";
	char brr[9] = "qwer4567";
//	printf("%s\n",arr);
//	printf("%s\n",mystrcat(arr,brr));
	printf("%s\n",arr);

	for(int i = 0;i<8;i++)
	{
		printf("&arr[%d] = %p\n",i,&arr[i]);
	}
	for(int i = 0;i<8;i++)
	{
		printf("&brr[%d] = %p\n",i,&brr[i]);
	}
	return 0;	
}
