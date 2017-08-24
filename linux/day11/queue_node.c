#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

typedef struct Queue
{
	Node* node;
	size_t cap;
	size_t num;
}Queue;

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
//初始化队列
void queue_init(Queue* queue,int cap)
{
	queue->cap = cap;
	queue->num = 0;
}
//释放队
//检查队是否为空
bool queue_empty(Queue* queue)
{
	if(queue->num==0) return true;
	return false;
}
//检查队是否已满
bool queue_full(Queue* queue)
{
	if(queue->num==queue->cap) return true;
	return false;
}
//入队
bool queue_push(Queue* queue,int data)
{
	Node* node = queue->node;
	if(queue->num==0)
	{
		queue->node = node_create(data);
		queue->num++;
		return true;
	}
	for(int i=0; i<queue->num-1; i++)
	{
		node = node->next;
	}
	node->next = node_create(data);
	queue->num++;
	return true;
}
//查看队头元素
int queue_head(Queue* queue)
{
	return queue->node->data;	
}
//查看队尾元素
int queue_tail(Queue* queue)
{
	Node* node = queue->node;
	for(int i=0; i<queue->num-1; i++)
	{
		node = node->next;
	}
	return node->data; 
}
//出队
bool queue_pop(Queue* queue)
{
	if(queue_empty(queue)) return false;
	queue->node = queue->node->next;
	queue->num--;
	return true;
}
int main()
{
	Queue queue;
	queue_init(&queue,10);
	printf("入队顺序：");
	for(int i=0; i<10; i++)
	{
		queue_push(&queue,i);
		printf("%d ",queue_tail(&queue));
	}
	printf("\n");
	printf("出队顺序：");
	while(!queue_empty(&queue))
	{
		printf("%d ",queue_head(&queue));
		queue_pop(&queue);
	}
}
