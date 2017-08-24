#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
	int data;
	struct Node* next;

}Node;
typedef struct List
{
	Node* head;
	Node* tail;
	size_t len;

}List;

Node* create_node(int data)
{
	Node* node = malloc(sizeof(Node));
	node->next = NULL;
	node->data = data;
	return node;
}

//构建一个指定长度的链表
void list_init(List* list,size_t len)
{
	if(len == 0) return;
	Node* node = creat_node(0);
	list->head = node;
	
	for(int i = 1;i < len;i++)
	{
		node->next = create_node(0);
		node = node->next;
	}
	
	list->tail = node;
	list->len = len;

}

//遍历链表
void list_show(List* list)
{
	for(Node* node = list->head;
		node!=list->tail->next;
		node=node->next)
	{
		
	}


int main()
{
	
	
}
