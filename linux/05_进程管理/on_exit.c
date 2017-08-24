#include <stdio.h>

//stats是程序结束时的状态码(main return 0)
//ptr是on_exit函数的第二个参数，执行时会传给words
void words(int stats,void* ptr)
{
	printf("stats=%d %s\n",stats,(char*)ptr);
}

int main()
{
	//向系统注册一个函数，结束时自动调用
	//int on_exit(void(*func)(int stats,void* ptr),void* ptr);
	char* str = "我和你，心连心";
	int ret  = on_exit(words,str);
	printf("同一个世界，同一个梦想\n");

	return -9;	
}
