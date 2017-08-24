#include "stack_list.h"

// 初始化栈
void stack_init(Stack* stack,int cap)
{
	stack->cap = cap;
	stack->top = NULL;
}
//判断栈空
bool stack_empty(Stack* stack)
{
	return !stack->top;
}
//出栈
bool stack_pop(Stack* stack)
{
	if(stack_empty(stack)) return false;
	Node* temp = stack->top;
	stack->top = stack->top->next;
	free(temp);//释放该块内存
	return true;
}
//释放栈
void stack_deinit(Stack* stack)
{
	while(stack_pop(stack));
		//出栈
}
//查看栈顶
Node* stack_top(Stack* stack)
{
	return stack->top;
}
//计算栈的大小
size_t stack_size(Stack* stack)
{
	Node* node = stack->top;
	size_t size = 0;
	while(node)
	{
		size++;
		node = node->next;
	}
	return size;
}
//判断栈满
bool stack_full(Stack* stack)
{
	return stack_size(stack) == stack->cap;	
}
//入栈
bool stack_push(Stack* stack,int data)
{
	if(stack_full(stack)) return false;
	Node* node = node_create(data);
	node->next = stack->top;
	stack->top = node;
}

