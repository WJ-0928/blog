#if 0
#pragma once

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int val;
	struct Node *random;
	struct Node *next;
} Node;



//进行带random指针的链表复制
Node *copy(Node *head)
{
	/*
	把每个结点（老结点）复制出一个结点（新结点）
	让新结点跟在老结点后面
	*/
	Node *cur = head;
	while (cur != NULL)
	{
		//先复制新结点
		Node *node = (Node *)malloc(sizeof(Node));
		node->val = cur->val;
		//让新结点（node）跟在老结点（cur）后面
		node->next = cur->next;
		cur->next = node;
		//遍历，让cur指向下一个老结点
		cur = node->next;
	}
	/*
	进行random的复制
	cur指向每一个老结点
	*/
	cur = head;
	while (cur != NULL)
	{
		//cur->next就是cur对应得新结点
		if (cur->random != NULL)
		{
			cur->next->random = cur->random->next;
		}
		else
		{
			cur->next->random = NULL;
		}
		cur = cur->next->next;
	}
	/*
	把链表拆成新的和老的
	*/
	cur = head;
	Node *newHead = head->next;
	while (cur != NULL)
	{
		Node *node = cur->next;
		cur->next = node->next;
		if (node->next != NULL)
		{
			node->next = node->next->next;
		}
		cur = cur->next;
	}
	return newHead;
}

Node *createNode(int val)
{
     Node *node = (Node *)malloc(sizeof(Node));
	 node->val = val;
	 return node;
}

void test()
{
	Node *n1 = createNode(1);
	Node *n2 = createNode(2);
	Node *n3 = createNode(3);
	Node *n4 = createNode(4);
	Node *n5 = createNode(5);

	n1->next = n2;
	n2->next = n3;
	n3->next = n3;
	n4->next = n4;
	n5->next = NULL;

	n1->random = n3;
	n2->random= n1;
	n3->random= n4;
	n4->random= n4;
	n5->random = NULL;

	Node *result = copy(n1);

	for (Node *cur = n1; cur != NULL; cur = cur->next)
	{
		printf("%p(%d,%p) ", cur, cur->val, cur->random);
	}
	printf("\n");
	for (Node *cur = result; cur != NULL; cur = cur->next)
	{
		printf("%p(%d,%p) ", cur, cur->val, cur->random);
	}
	printf("\n");
}
#endif