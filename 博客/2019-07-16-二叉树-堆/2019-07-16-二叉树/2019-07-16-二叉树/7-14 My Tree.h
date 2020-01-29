#pragma once

typedef struct Node
{
	int val;
	struct Node *left;
	struct Node *right;
} Node;


//双向链表
void toDList(Node *node);
//中序遍历
void inorder(Node *node);
//二叉搜索树转换成排序双向链表
Node * searchTreeToDList(Node *root);
//非递归实现前序遍历
void preorderNoR(Node * root);
//非递归实现中序遍历
void inorderNoR(Node * root);
//非递归实现后序遍历
void postorderNoR(Node * root);
//层序遍历
void levelOrder(Node *root);
