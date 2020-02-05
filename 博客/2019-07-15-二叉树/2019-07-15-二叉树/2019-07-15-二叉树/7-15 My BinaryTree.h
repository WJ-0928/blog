#pragma once

typedef struct Node
{
	char value;
	struct Node *left;
	struct Node *right;
}Node;


typedef struct ReturnType
{
	int use;// 创建树过程中用掉的值个数
	Node *root;// 创建好树的根节点
} ReturnType;




//二叉树的构建及遍历
ReturnType createTree(char preorder[], int size);
//根据一棵树的前中序遍历构造二叉树
Node *bulidTree1(int *preorder, int preorderSize, int *inorder, int inorderSize);
//根据一棵树的中后序遍历构造二叉树
Node *bulidTree2( int *inorder, int *postorder,int size1);
