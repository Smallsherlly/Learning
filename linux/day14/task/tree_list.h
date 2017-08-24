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
void Newinsert(Node** root,int data);
//从树中删除一个节点
bool tree_delete(Tree* tree,int data);
//修改指定的值
bool tree_modify(Tree* tree,int old,int new);
//查找指定值一个节点
Node* tree_fine(Tree* tree,int data);
//中序遍历树
void tree_show(Tree* tree);
void show_tree_list(Node* node);
Node* tree_list(Tree* tree);
Tree recover(int* tree1,int* tree2,int iLen);
int find_index(int* tree,int data);
int judge(int* tree,int data1,int data2);
bool houxu(int* tree,int iLen);
int tree_deepshow(Tree* tree);
bool balance(Node* node);
Node* findK(Tree* tree,int target);
#endif//TREE_LIST_H