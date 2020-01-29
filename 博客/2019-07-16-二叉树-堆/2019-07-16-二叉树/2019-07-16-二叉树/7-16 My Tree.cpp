#include"7-14 My Tree.h"
#include<stdio.h>
#include<stdlib.h>
#include <stack>
#include<queue>

//二叉搜索树
//对于树的任意一个结点
//保证该节点左子树中所有的值都小于该节点的值
//保证该节点右子树中所有的值都大于该节点的值
Node *head = NULL;
Node *prev = NULL;
//双向链表
void toDList(Node *node)
{
	node->left = prev;
	if (prev == NULL) {
		head = node;
	}
	else {
		prev->right = node;
	}

	prev = node;
}
//中序遍历
void inorder(Node *node)
{
	if (node == NULL) {
		return;
	}

	inorder(node->left);
	toDList(node);
	inorder(node->right);
}
//二叉搜索树转换成排序双向链表
Node * searchTreeToDList(Node *root)
{
	head = NULL; prev = NULL;
	inorder(root);

	return head;
}
//非递归实现前序遍历
void preorderNoR(Node * root)
{
	Node *cur = root;
	std::stack<Node *> st;

	while (cur != NULL || !st.empty())
	{
		while (cur != NULL)
		{
			printf("%d", cur->val);
			st.push(cur);
			cur = cur->left;
		}

		Node *top = st.top();
		st.pop();

		cur = top->right;
	}
}
//非递归实现中序遍历
void inorderNoR(Node * root)
{
	Node *cur = root;
	std::stack<Node *> st;

	while (cur != NULL || !st.empty())
	{
		while (cur != NULL)
		{
			
			st.push(cur);
			cur = cur->left;
		}

		Node *top = st.top();
		printf("%d", top->val);
		st.pop();

		cur = top->right;
	}
}
//非递归实现后序遍历
void postorderNoR(Node * root)
{
	Node *cur = root;
	Node *last = NULL;

	std::stack<Node *> st;

	while (cur != NULL || !st.empty())
	{
		while (cur != NULL)
		{
			st.push(cur);
			cur = cur->left;
		}

		Node *top = st.top();
		if (top->right == NULL || top->right == last)
		{
			st.pop();
			printf("%d", top->val);
			last = top;
		}
		else
		{
             cur = top->right;
		}
		
	}
}
//层序遍历
void levelOrder(Node *root)
{
	if (root == NULL) {
		return;
	}

	std::queue<Node *> q;
	q.push(root);

	while (!q.empty()) {
		// Node * front = QueueFront(&q); QueuePop(&q);
		Node * front = q.front();	q.pop();

		printf("%d ", front->val);
		if (front->left != NULL) {
			q.push(front->left);
		}
		if (front->right != NULL) {
			q.push(front->right);
		}
	}
}
