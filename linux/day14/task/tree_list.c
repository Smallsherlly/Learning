#include "tree_list.h"
#include <malloc.h>
//创建树节点
Node* create_node(int data)
{
	Node* node = malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
//树初始化
void tree_init(Tree* tree)
{
	tree->root = NULL;
	tree->size = 0;
}
void deinit(Node* root)
{
	if(root ==NULL) return;
	deinit(root->left);
	deinit(root->right);
	free(root);
}
//树释放
void tree_deinit(Tree* tree)
{
	deinit(tree->root);
	tree->root = NULL;
}
void Newinsert(Node** root,int data)
{
	Node* node = create_node(data);
	Node** root1 = root;
	while(1)
	{
		if(*root1 == NULL)
		{
			*root1 = node;

			return;
		}
		else
		{
			if((*root1)->data > node->data)
			{
				
				root1 = &(*root1)->left;
			}
			else
			{
				
				root1 = &(*root1)->right;
				
			}
		}
	}
}
int iCount = 0;
int iNum = 1;
//向树中插入一个节点
static void insert(Node** root,Node* node)
{
	
	if(*root == NULL)
	{
		*root = node;
	}
	else
	{
		if((*root)->data > node->data)
		{
			insert(&(*root)->left,node);
			iNum++;
		}
		else
		{
			insert(&(*root)->right,node);
			iNum++;
		}
	}
	if(iNum>iCount) iCount = iNum;
}
//向树中插入一个节点
void tree_insert(Tree* tree,int data)
{
	iNum = 1;
	insert(&tree->root,create_node(data));
}
Node* find(Node* root,int data);

bool delete(Node** root,int data)
{
	if(*root == NULL) return false;
	if((*root)->data == data)
	{
		Node* temp = *root;
		Node* right = (*root)->right;

		*root = (*root)->left;
		insert(root,right);
		free(temp);
		return true;

	}
	if((*root)->data > data)
	{
		delete(&(*root)->left,data);
	}
	else
	{
		delete(&(*root)->right,data);
	}

}
//从树中删除一个节点
bool tree_delete(Tree* tree,int data)
{
	return delete(&tree->root,data);
}
//修改指定的值
bool tree_modify(Tree* tree,int old,int new)
{
	if(delete(&tree->root,old));
	{
		insert(&tree->root,create_node(new));
		return true;
	}
	return false;

}

Node* find(Node* root,int data)
{
	if(root == NULL) return NULL;
	if(root->data == data) return root;
	if(root->data > data)
	{
		find(root->left,data);
	}
	else
	{
		find(root->right,data);
	}
}
//查找指定值一个节点
Node* tree_find(Tree* tree,int data)
{
	return find(tree->root,data);
}
void ergodic(Node* root)
{
	if(root == NULL) return;
	ergodic(root->left);
	printf("%d ",root->data);
	ergodic(root->right);
}
//中序遍历树
void tree_show(Tree* tree)
{
	ergodic(tree->root);
	printf("\n");
}

//找出最左边的结点
Node* findmostleft(Node* root)
{
	if(root==NULL)return NULL;
	while(1)
	{
		if(root->left==NULL) 
			return root;
		else
			root = root->left;
	}
}

//转换
void change(Node* root,Node** last_node)
{
	if(root==NULL) return;
	if(root->left!=NULL)
	{
		change(root->left,last_node);
	}
	
	root->left = *last_node;
	if(*last_node!=NULL)
	{
		(*last_node)->right = root; 
	}
	*last_node = root;
		
	if(root->right!=NULL)
		change(root->right,last_node);
}
Node* tree_list(Tree* tree)
{
	Node* head = findmostleft(tree->root);
	Node* last_node = NULL;
	change(tree->root,&last_node);
	return head;
}
//打印链表
void show_tree_list(Node* node)
{
	while(node!=NULL)
	{
		printf("%d ", node->data);
		node = node->right;
	}
}

void again(Node** root,int* tree1,int* tree2,int* index,int start,int end)
{
	*root = create_node(tree1[*index]);
	(*index)++;
	int mid = find_index(tree2,tree1[*index-1]);
	if(mid>find_index(tree2,tree1[*index])&&find_index(tree2,tree1[*index])>=start)
	{
		again(&(*root)->left,tree1,tree2,index,start,mid-1);
	}
	if(mid<find_index(tree2,tree1[*index])&&find_index(tree2,tree1[*index])<=end)
	{
		again(&(*root)->right,tree1,tree2,index,mid+1,end);
	}
}
//通过前序遍历和中序遍历得到原二叉树
Tree recover(int* tree1,int* tree2,int iLen)
{
	Tree tree;
	tree_init(&tree);
	int index = 0;
	Node* root = NULL;
	again(&root,tree1,tree2,&index,0,iLen-1);
	tree.root = root;
	return tree;
}
//找到某一个值的下标
int find_index(int* tree,int data)
{
	int i = 0;
	while(tree[i]!=data)
	{
		i++;
	}
	return i;
}

//判断两个值的下标相对位置
int judge(int* tree,int data1,int data2)
{
	int i = 0,j = 0;
	while(tree[i]!=data1) i++;
	while(tree[j]!=data2) j++;
	if(i>j)
		return 1;
	if(i<j)
		return -1;
	return 0;
}

bool check(int* tree,int start,int end)
{
	if(start>=end) 
	{
		return true;
	}
	int i = start;
	for(; i<end; i++)
	{
		if(tree[i]>tree[end])
			break;
	}
	for(int j=start; j<i; j++)
	{
		if(tree[j]>tree[end])
		{
			return false;
		}
	}
	for(int j=i; j<end; j++)
	{
		if(tree[j]<tree[end])
		{	
			return false;
		}
	}
	if(!check(tree,start,i-1))
	{
		return false;
	}
	if(!check(tree,i+1,end)) 
	{
		return false;
	}
	return true;

}
bool houxu(int* tree,int iLen)
{
	if(check(tree,0,iLen-1))
		return true;
	return false;

}
//求出树的深度
int tree_deep(Node* root)
{
	if(root==NULL) return 0;
	int left_length = tree_deep(root->left);
	int right_length = tree_deep(root->right);

	return (left_length>right_length?left_length+1:right_length+1);
}
bool balance(Node* root)
{
	if(root==NULL) return true;
	int left_length = tree_deep(root->left);
	int right_length = tree_deep(root->right);
	int result = left_length - right_length;
	if(result>1||result<-1)
		return false;
	return balance(root->left)&&balance(root->right);
}

Node* findk(Node* root,int* iNum,int target)
{
	if(*iNum>target) return NULL;
	if(root==NULL) return NULL;
	Node* node=NULL;
	if(node=findk(root->left,iNum,target))
		return node;
	(*iNum)++;
	if(*iNum==target) return root;
	if(node=findk(root->right,iNum,target))
		return node;

}
Node* findK(Tree* tree,int target)
{
	int iNum = 0;
	return findk(tree->root,&iNum,target);

}


