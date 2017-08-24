#ifndef STACK_LIST_H
#define STACK_LIST_H
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
	Node* top;
	size_t cap;
}Stack;

Node* node_create(int data);
// 初始化栈
void stack_init(Stack* stack,int cap);
//判断栈空
bool stack_empty(Stack* stack);
//出栈
bool stack_pop(Stack* stack);
//释放栈
void stack_deinit(Stack* stack);
//查看栈顶
Node* stack_top(Stack* stack);
//计算栈的大小
size_t stack_size(Stack* stack);
//判断栈满
bool stack_full(Stack* stack);
//入栈
bool stack_push(Stack* stack,int data);

#endif
