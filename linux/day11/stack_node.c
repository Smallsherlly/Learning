#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

typedef struct Stack
{
	Node* node;
	size_t top;
}Stack;

Node* node_create(int data)
{
	Node* node = malloc(sizeof(Node));
	node->next = NULL;
	node->data = data;
	return node;
}
Node* list_create(int data)
{
	Node* head;
	Node* node = head;
	for(int i=0; i<data; i++)
	{
		node->next = node_create(i);
		node = node->next;
	}
	return head;
}
//初始化栈
void stack_init(Stack* stack,int data)
{
	stack->node = node_create(data);
	stack->top = 1;
}
//释放栈
//检查栈是否为空
bool stack_empty(Stack* stack)
{
	if(stack->top==0) return true;
	return false;
}
//检查栈是否已满
bool stack_full(Stack* stack)
{
	if(stack->top==stack->top) return true;
	return false;
}
//压栈
bool stack_push(Stack* stack,int data)
{
	Node* node = stack->node;
	for(int i=0; i<stack->top-1; i++)
	{
		node = node->next;
	}
	node->next = node_create(data);
	stack->top++;
}
//查看栈顶元素
int stack_top(Stack* stack)
{
	Node* node = stack->node;
	for(int i=0; i<stack->top-1; i++)
	{
		node = node->next;
	}
	return node->data; 
}
//出栈
bool stack_pop(Stack* stack)
{
	if(stack_empty(stack)) return false;
	stack->top--;
	return true;
}
int main()
{
	Stack stack;
	stack_init(&stack,0);
	printf("%d ",stack_top(&stack));
	for(int i=1; i<10; i++)
	{
		stack_push(&stack,i);
		printf("%d ",stack_top(&stack));
	}
	printf("\n");
	while(!stack_empty(&stack))
	{
		printf("%d ",stack_top(&stack));
		stack_pop(&stack);
	}
}
