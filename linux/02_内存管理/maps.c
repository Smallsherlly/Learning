#include <stdio.h>
#include <malloc.h>
const int const_init_num_g = 1;
int init_num_g = 2;
int uninit_num_g;
extern char** environ;
int main(int argc,char** argv)
{
	const static int const_init_static = 0;
	static int init_static = 0;
	static int uninit_static;
	char* heap = malloc(1);
	const int const_num = 0;
	int num = 0;
	printf("----------代码区----------\n");
	printf("初始化过的全局常量：%p\n",&const_init_num_g);
	printf("            字面值：%p\n","hehe");
	printf("初始化过的局部常量：%p\n",&const_init_static);
	printf("             函数：%p\n",main);
	printf("----------数据区----------\n");
	printf("初始化过的全局常量：%p\n",&init_num_g);
	printf("初始化过的局部常量：%p\n",&init_static);
	printf("----------bss区----------\n");
	printf("未初始化过的全局常量：%p\n",&uninit_num_g);
	printf("未初始化过的局部常量：%p\n",&uninit_static);
	printf("----------堆区----------\n");
	printf("              malloc:%p\n",heap);
	printf("----------栈区----------\n");
	printf("            局部常量：%p\n",&const_num);
	printf("            局部变量：%p\n",&num);
	printf("-------命令行 环境变量-------\n");
	printf("              命令行：%p\n",argv);
	printf("            环境变量：%p\n",environ);
	
	printf("进程号%d,回车键退出\n",getpid());
	scanf("%*c");
}
	
