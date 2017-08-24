#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

//链表结点结构体
typedef struct Node
{
	//前一个结点的指针
	struct Node* prev;
	//数据
	int data;
	//下一个结点的指针
	struct Node* next;
}Node;

//链表结构体
typedef struct List
{
	//链表头结点指针
	struct Node* head;
	//链表尾结点指针
	struct Node* tail;
	//链表结点的数量
	size_t size;
}List;

//初始化链表
void init(List* list);
//释放链表
void deinit(List* list);
//插入一个头结点
void push_head(List* list,int data);
//插入一个尾结点
void push_tail(List* list,int data);
//在任意位置插入结点
bool insert(List* list,int index,int data);
//删除头结点
bool pop_head(List* list);
//删除尾结点
bool pop_tail(List* list);
//删除任意位置结点
bool delete(List* list,int index);
//获取头结点
Node* get_head(List* list);
//获取尾结点
Node* get_tail(List* list);
//获取任意位置结点
Node* get_node(List* list,int index);
//更新结点的值
bool updata(List* list,int old,int new);
//修改任意结点的值
bool modify(List* list,int index,int new);
//判断链表是否为空
bool empty(List* list);
//计算链表结点的数量
size_t size(List* list);
//查找结点
Node* find(List* list,int data);
//遍历链表
void travel(List* list);

#endif//LIST_H
