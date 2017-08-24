#include <stdio.h>
#include <stdint.h>

int main()
{
	FILE* fwp = fopen("hehe","w");
	int arr[1000000];
	for(int32_t i=0; i<1000000; i++)
	{
		arr[i] = i;
	}
	
	fwrite(arr,sizeof(arr),1,fwp);
	fclose(fwp);
	
}
