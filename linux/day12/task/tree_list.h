#ifndef TREE_LIST_H
#define TREE_LIST_H

#include <stdio.h>
#include <stdbool.h>

typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

typedef struct Tree
{
	Node* root;
	size_t size;
}Tree;

//创建树节点
Node* create_node(int data);
//树初始化
void tree_init(Tree* tree);
//树释放
void tree_deinit(Tree* tree);
//向树中插入一个节点
void tree_insert(Tree* tree,int data);
//从树中删除一个节点
bool tree_delete(Tree* tree,int data);
//修改指定的值
bool tree_modify(Tree* tree,int old,int new);
//查找指定值一个节点
Node* tree_fine(Tree* tree,int data);
//中序遍历树
size_t tree_show(Tree* tree);
void tree_wide(Tree* tree);
void tree_mirror(Tree* tree);
bool tree_belong(Node* parent,Node* kid);
#endif//TREE_LIST_H
