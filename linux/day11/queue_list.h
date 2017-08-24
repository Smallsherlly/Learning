#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H
#include <stdbool.h>
#include <stdio.h>
typedef struct Node
{
	void* data;
	struct Node* next;
}Node;

typedef struct queue
{
	Node* head;
	Node* tail;
	size_t cap;
}Queue;
//创建节点
Node* node_create(void* data);
//初始化队列
void queue_init(Queue* queue,size_t cap);
//释放队列
void queue_deinit(Queue* queue);
//判断队列是否为空
bool queue_empty(Queue* queue);
//判断是否已满
bool queue_full(Queue* queue);
//查看队头
Node* queue_head(Queue* queue);
//查看队尾
Node* queue_tail(Queue* queue);
//入队
bool queue_push(Queue* queue,void* data);
//出队
bool queue_pop(Queue* queue);
//计算队列的容量
size_t queue_cap(Queue* queue);
//计算队列的长度
size_t queue_size(Queue* queue);

#endif
