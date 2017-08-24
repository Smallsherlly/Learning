#include <stdio.h>
#include <dlfcn.h>

int main()
{
	//加载
	void* handl = dlopen("libcalc.so",RTLD_NOW);
	if(NULL==handl)
	{
		printf("dlopen error:%s",dlerror());
	}
	//获取函数指针
	int (*subp)(int,int) = dlsym(handl,"sub");
	if(NULL==subp)
	{
		printf("dlsym error:%s",dlerror());
		return -1;
	}
	
	printf("sub %d\n",subp(10,3));
	//关闭
	dlclose(handl);
	return 0;
}

