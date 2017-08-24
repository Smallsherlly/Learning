#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd = open("tutu",O_WRONLY|O_CREAT|O_TRUNC,0666);
	int i = 0;
	int arr[1000000];
	for(; i<1000000; i++)
	{
		arr[i] = i;

	}
	write(fd,arr,sizeof(arr));
	close(fd);
	return 0;	
}
