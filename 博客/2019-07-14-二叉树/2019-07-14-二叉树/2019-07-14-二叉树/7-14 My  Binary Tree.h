#pragma once

typedef struct Node
{
	char value;
	struct Node *left;//指向我的左孩子
	struct Node *right;//指向我的右孩子
} Node;

// 前序遍历
void preOrderTraversal(Node *root);
// 中序遍历
void inOrderTraversal(Node *root);
// 后序遍历
void postOrderTraversal(Node *root);
//求结点个数
void getNodeCount(Node *root);
int getNodeCount2(Node *root);
//求二叉树的高度
int getHeight(Node *root);
//求二叉树叶子结点个数
int getLeafCount(Node *root);
//第k层结点个数
int getKLevelCount(Node *root, int k);
//查找
Node * find(Node *root, char v);
//层序遍历
void levelOrderTraversal(Node *root);
//判断是否是完全二叉树
bool isCompleteTree(Node *root);
//判断两个数是否相等
bool isSameTree(Node *p, Node *q);
//判断两个数是否镜像
bool isMirror(Node *p, Node *q);
//创建结点
Node * createNode(char ch);

