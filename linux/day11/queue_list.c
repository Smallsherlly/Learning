#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"queue_list.h"
//创建节点
Node* node_create(void* data)
{
	Node* node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

//初始化队列
void queue_init(Queue* queue,size_t cap)
{
	queue->head = NULL;
	queue->tail = NULL;
	queue->cap = cap;
}
//释放队列
void queue_deinit(Queue* queue)
{
	while(!queue_empty(queue))
	{
		queue_pop(queue);
	}
}
//判断队列是否为空
bool queue_empty(Queue* queue)
{
	return !queue->head;
}
//判断是否已满
bool queue_full(Queue* queue)
{
	return !queue_cap(queue);
}
//查看队头
Node* queue_head(Queue* queue)
{
	return queue->head;
}
//查看队尾
Node* queue_tail(Queue* queue)
{
	return queue->tail;
}
//入队
bool queue_push(Queue* queue,void* data)
{
	if(queue_full(queue)) return false;
	Node* node = node_create(data);
	if(queue_empty(queue))
	{
		queue->head = node;
		queue->tail = queue->head;
	}else
	{
		queue->tail->next = node;
		queue->tail = node;
	}
	return true;
}
//出队
bool queue_pop(Queue* queue)
{
	if(queue_empty(queue)) return false;
	Node* temp = queue->head;
	queue->head = queue->head->next;
	free(temp);
	return true;
}
//计算队列的容量
size_t queue_cap(Queue* queue)
{
	return queue->cap - queue_size(queue);
}
//计算队列的长度
size_t queue_size(Queue* queue)
{
	size_t size = 0;
	Node* node = queue->head;
	while(node)
	{
		size++;
		node = node->next;
	}
	return size;
}

