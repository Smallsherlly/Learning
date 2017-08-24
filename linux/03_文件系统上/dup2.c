#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd = open("haha",O_RDONLY);

	dup2(fd,0);
	char str[20] = {};
	scanf("%s",str);
	printf("%s\n",str);
	
	close(fd);
	
	return 0;
}
