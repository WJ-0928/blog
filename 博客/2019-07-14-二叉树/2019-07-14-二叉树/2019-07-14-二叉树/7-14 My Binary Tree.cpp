#include"7-14 My  Binary Tree.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <queue>


// 前序遍历
void preOrderTraversal(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	//根
	printf("%c", root->value);
	//左子树的前序遍历
	preOrderTraversal(root->left);
	//右子树的前序遍历
	preOrderTraversal(root->right);
}


// 中序遍历
void inOrderTraversal(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	//左子树的前序遍历
	inOrderTraversal(root->left);
	//根
	printf("%c", root->value);
	//右子树的前序遍历
	inOrderTraversal(root->right);
}


// 后序遍历
void postOrderTraversal(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	//左子树的前序遍历
	postOrderTraversal(root->left);
	//右子树的前序遍历
	postOrderTraversal(root->right);
	//根
	printf("%c", root->value);
}


//求结点个数
void getNodeCount(Node *root)
{
	int count = 0;
	if (root == NULL)
	{
		return ;
	}
	getNodeCount(root->left);
	count++;
	getNodeCount(root->right);
}


int getNodeCount2(Node *root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = getNodeCount2(root->left);
	int right = getNodeCount2(root->right);
	return left + right + 1;
}


//求二叉树的高度
int getHeight(Node *root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = getHeight(root->left);
	int right = getHeight(root->right);
	return (left > right ? left : right) + 1;
}


//求二叉树叶子结点个数
int getLeafCount(Node *root)
{
	if (root == NULL)
	{
		return 0;
	}
	else if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	else
	{
		return getLeafCount(root->left) + getLeafCount(root->right);
	}
}
//第k层结点个数
int getKLevelCount(Node *root, int k)
{
	assert(k >= 1);
	if (root == NULL)
	{
		return 0;
	}
	else if (k == 1)
	{
		return 1;
	}
	else
	{
		return getKLevelCount(root->left, k - 1) + getKLevelCount(root->right, k - 1);
	}

}
//查找
/*
如果找到，返回结点地址，否则返回NULL
(如果返回NULL，表示没有找到；如果返回非NULL，表示找到）
1）空树：没找到
2）如果根就是v，返回根的地址，否则
3）去左子树中找，如果左子树中找到，返回结点地址
4）否则，去右子树查
*/
Node * find(Node *root, char v)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->value == v)
	{
		return root;
	}
	Node *left = find(root->left, v);
	if (left != NULL)
	{
		return left;
	}
	Node *right = find(root->right, v);
	if (right != NULL)
	{
		return right;
	}
	else
	{
		return NULL;
	}
}
//层序遍历
void levelOrderTraversal(Node *root)
{
	if (root == NULL) {
		return;
	}
	std::queue<Node *>	q;
	q.push(root);

	while (!q.empty()) {
		Node * front = q.front(); q.pop();

		printf("%c ", front->value);

		if (front->left != NULL) {
			q.push(front->left);
		}

		if (front->right != NULL) {
			q.push(front->right);
		}
	}
}

//判断是否是完全二叉树
bool isCompleteTree(Node *root)
{
	if (root == NULL) {
		return true;
	}

	std::queue<Node *> q;
	q.push(root);

	while (true) {
		Node * front = q.front(); q.pop();
		if (front == NULL) {
			break;
		}

		q.push(front->left);
		q.push(front->right);
	}

	while (!q.empty()) {
		Node * front = q.front(); q.pop();
		if (front != NULL) {
			return false;
		}
	}

	return true;
}


//判断两个数是否相等
bool isSameTree(Node *p, Node *q)
{
	if (p == NULL && q == NULL)
	{
		return true;
	}
	if (p == NULL || q == NULL)
	{
		return false;
	}
	return p->value == q->value
		&&isSameTree(p->left, q->left)
		&& isSameTree(p->right, q->right);
}
//判断两个数是否镜像
bool isMirror(Node *p, Node *q)
{
	if (p == NULL && q == NULL)
	{
		return true;
	}
	if (p == NULL || q == NULL)
	{
		return false;
	}
	return p->value == q->value
		&&isMirror(p->left, q->right)
		&& isMirror(p->right, q->left);
}

//创建结点
Node * createNode(char ch)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = ch;
	node->left = node->right = NULL;

	return node;
}
