#include"7-15 My BinaryTree.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//二叉树的构建及遍历

// A B D F # # # # C # E # G # #
// CreateTree 函数需要返回两个值
// 1. Node *	根结点
// 2. int		使用了多少值
ReturnType createTree(char preordered[], int size)
{
	char rootvalue = preordered[0];
	if (rootvalue == '#')
	{
		ReturnType returnvalue;
		returnvalue.root = NULL;
		returnvalue.use = 1;
		return returnvalue;
	}
	//前序遍历的第一个值就是根的值，
	//所以，取第一个值，创建当前树的根节点
	Node *root = (Node *)malloc(sizeof(Node));
	root->value = rootvalue;
	//用递归的思路创建当前树的
	//1)左子树
	//需要传入左子树的前序遍历值
	ReturnType left = createTree(preordered + 1, size - 1);
    //右子树
	//需要传入右子树的前序遍历值
	//右子树的前序遍历值，需要先计算创建左子树过程中用掉的值个树
	ReturnType right = createTree(preordered + 1 + left.use, size - 1 - left.use);
	root->left = left.root;
	root->right = right.root;
	//创建好后，返回
	//1）创建好树的根节点
	//2)创建树过程中用掉的节点个数
	ReturnType returnvalue;
	returnvalue.root = root;
	returnvalue.use = 1 + left.use + right.use;
	return returnvalue;
}


//根据一棵树的前中序遍历构造二叉树
Node *bulidTree1(int *preorder, int preorderSize, int *inorder, int inorderSize)
{
	if (preorderSize == 0)
	{
		return NULL;
	}
	int size = preorderSize;
	int rootValue = preorder[0];
	Node *root = (Node *)malloc(sizeof(Node));
	root->value = rootValue;
	//在中序中查找rootValue出现的下标，记录在leftSize中
	int leftSize = -1;
	for (int i = 0; i < leftSize; i++)
	{
		if (inorder[i] == rootValue)
		{
			leftSize = i;
			break;
		}
	}
	root->left = bulidTree1(preorder + 1, leftSize, inorder, leftSize);
	root->right = bulidTree1(preorder + 1 + leftSize, size - leftSize - 1, inorder - 1 - leftSize, size - 1 - leftSize);
	return root;
}


//根据一棵树的中后序遍历构造二叉树
Node *bulidTree2(int *inorder, int *postorder, int size1)
{
	if (size1 == 0)
	{
		return NULL;
	}
	int rootValue = postorder[size1 - 1];
	Node *root = (Node *)malloc(sizeof(Node));
	root->value = rootValue;
	int leftSize = -1;
	for (int i = 0; i < size1; i++)
	{
		if (inorder[i] == rootValue)
		{
			leftSize = i;
			break;
		}
	}
	root->left = bulidTree2(inorder, postorder, leftSize);
	root->right = bulidTree2(inorder + 1 + leftSize, postorder + leftSize, size1 - 1 - leftSize);
	return root;
}


