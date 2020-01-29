#include"7-22 bite.h"

#include<stdio.h>
#include<stdlib.h>
int main()
{
	Node *n1 = (Node *)malloc(sizeof(Node));
	n1->val = 1;
	Node *n2 = (Node *)malloc(sizeof(Node));
	n2->val = 2;
	Node *n3 = (Node *)malloc(sizeof(Node));
	n3->val = 3;
	Node *n4 = (Node *)malloc(sizeof(Node));
	n4->val = 4;
	Node *n5 = (Node *)malloc(sizeof(Node));
	n5->val = 5;
	Node *n6 = (Node *)malloc(sizeof(Node));
	n6->val = 6;
	Node *n7 = (Node *)malloc(sizeof(Node));
	n7->val = 7;
	Node *n8 = (Node *)malloc(sizeof(Node));
	n8->val = 8;
	Node *n9 = (Node *)malloc(sizeof(Node));
	n9->val = 9;

	n1->left = NULL; n1->right = NULL;
	n2->left = n1; n2->right = NULL;
	n3->left = n2; n3->right = n4;
	n4->left = NULL; n4->right = NULL;
	n5->left = n3; n5->right = n8;
	n6->left = NULL; n6->right = n7;
	n7->left = NULL; n7->right = NULL;
	n8->left = n6; n8->right = n9;
	n9->left = NULL; n9->right = NULL;


	// 二叉树的三种遍历方式 
	PreOrder(n5);     printf("\n");
	PreOrderNor(n5);  printf("\n");
	InOrder(n5);      printf("\n");
	InOrderNor(n5);   printf("\n");
	PostOrder(n5);    printf("\n");
	PostOrderNor(n5); printf("\n");
	LevelOrder(n5);   printf("\n");

	// 拷贝二叉树 
	CopyBinTree(n5); printf("\n");

	// 获取二叉树中节点的个数 
	printf("%d\n", GetNodeCount(n5));

	// 求二叉树的高度 
	printf("%d\n", Height(n5));

	// 检测二叉树是否平衡O(N^2) 
	printf("%d\n", IsBalanceTree(n5));
	// 检测二叉树是否平衡O(N) 
	//int* height=0;
	//printf("%d\n",IsBalanceTree_P(n5, height));

	// 获取二叉数中叶子节点的个数 
	printf("%d\n", GetLeafNodeCount(n5));

	// 获取二叉树第K层节点的个数 
	printf("%d\n", GetKLevelNodeCount(n5,3));

	// 获取二叉树中某个节点的双亲节点 
	GetNodeParent(n5, n9); printf("\n");

	// 求二叉树的镜像 
	Mirror(n5); printf("\n");
	// 销毁二叉树 
	DestroyBinTree(n5); printf("\n");
	
	printf("你好世界\n");

}