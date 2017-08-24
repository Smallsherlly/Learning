#include <stdio>
#include "diamond.h"

int main()
{
	int width = 0;
	int num = 0;
	char c = '*';
	puts("请输入菱形宽度：");
	scanf("%d",&width);
	puts("请输入1.实心 0.空心：");
	scanf("%d",&num);
	getchar();
	puts("请输入菱形符号：");
	scanf("%c",&c);
	diamond(width,num,c);
}
