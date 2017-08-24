#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define DATA_TYPE int
typedef struct Stack
{
	DATA_TYPE* arr;//栈空间的首地址
	size_t cap;//栈空间的容量
	size_t top;//栈顶
}Stack;

//初始化栈
void stack_init(Stack* stack,DATA_TYPE cap)
{
	//开辟栈空间
	stack->arr = malloc(sizeof(DATA_TYPE)*cap);
	//设置栈容量
	stack->cap = cap;
	//设置栈顶的位置
	stack->top = 0;
}

//释放栈
void stack_deinit(Stack* stack)
{
	//释放栈空间
	free(stack->arr);
	//杜绝出现野指针
	stack->arr = NULL;
	//修改栈的容量
	stack->cap = 0;
	//修改栈顶位置
	stack->top = 0;
}

//判断栈是否为空
bool stack_empty(Stack* stack)
{
	return 0 == stack->top;
}
//判断栈是否已满
bool stack_full(Stack* stack)
{
	return stack->top >= stack->cap;
}
//压栈 向栈存放数据
bool stack_push(Stack* stack,DATA_TYPE data)
{
	if(stack_full(stack)) return false;
	stack->arr[stack->top] = data;
	stack->top++;
	return true;
}
//出栈 把栈顶元素从栈中删除
bool stack_pop(Stack* stack)
{
	if(stack_empty(stack)) return false;
	stack->top--;
	return true;
}

//查看栈顶元素
DATA_TYPE stack_top(Stack* stack)
{
	return stack->arr[stack->top-1];//使用前判断栈是否为空
}
//计算栈的容量
size_t stack_size(Stack* stack)
{
	return stack->cap - stack->top;
}


int main()
{
	Stack stack;
	stack_init(&stack,10);
	printf("%s",stack_empty(&stack)?"空":"不空");
	printf("%d\n",stack_size(&stack));

	printf("数据压栈的顺序：");
	for(int i = 0; i<10; i++)
	{
		stack_push(&stack,i);
		printf("%d ",i);

	}
	printf("\n");
	printf("数据出栈的顺序：");
	while(!stack_empty(&stack))
	{
		printf("%d ",stack_top(&stack));
		stack_pop(&stack);
	}
	printf("\n");
}
