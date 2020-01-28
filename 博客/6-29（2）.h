#if 0
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


//结点的定义
typedef struct Node
{
	int val;//数据
	struct Node *next;//下一个结点的线索
	                  //当next==NULL时，表示没有后续结点了
	                  //反过来说，最后一个结点的next一定==NULL
} Node;

//头插
Node * ListPushFront(Node *head,int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	//让node的下一个为原第一个结点
	node->next = head;
	//noed成为新的第一个结点
	return node;
}

//尾插
Node *ListPushBack(Node *head, int val)
{
	//1.装到结点中
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	//2.node的next置位NULL
	node->next = NULL;
	if (head != NULL)
	{
		//链表中有结点的情况
		//3.找到原最后一个结点
		Node *cur = head;
		while (cur != NULL)
		{
			cur = cur->next;
		}
		//cur就是最后一个结点
		//让原最后一个结点的下一个为node
		cur->next = node;
	}
	else
	{
		node = head;
	}
	return head;
}

//头删
Node *ListPopFront(Node *head)
{
	assert(head != NULL);
	/*
	Node *oldHead = head;
	free(oldHead);
	return head->next;
	*/
	Node *next = head->next;
	free(head);
	return next;
	
}

//尾删
Node *ListPopBack(Node *head)
{
	assert(head != NULL);
	if (head->next == NULL)
	{
		free(head);
		head = NULL;
	}
	else
	{
		//先找到倒数第二个节点
		Node *cur = head;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		//
		//释放cur->next的空间
		free(cur->next);
		cur->next = NULL;
	}
		return head;
}

//反转链表
Node *reverseList(Node *head)
{
	Node *rHead = NULL;
	Node *cur = head;
	while (cur != NULL)
	{
		Node *next = cur->next;
		cur->next = rHead;
		rHead = cur;
		cur = cur->next;
	}
	return rHead;
}


//打印
void ListPrint(Node *head)
{
	//如何遍历指针
	for (Node *cur = head; cur != NULL; cur = cur->next)
	{
		printf("%d--> ", cur->val);
	}
	printf("NULL\n");
}


//初始化
void Test()
{
	Node *head = NULL;//链表的初始化

	//对链表做头插
	ListPrint(head);
	head = ListPushFront(head, 1);
	ListPrint(head);
	head = ListPushFront(head, 2);
	ListPrint(head);
	head = ListPushFront(head, 3);
	ListPrint(head);
	head = ListPushFront(head, 4);
	ListPrint(head);
	head = ListPushBack(head, 10);
	head = ListPushBack(head, 20);
	head = ListPushBack(head, 30);

	ListPrint(head);

	head = ListPopBack(head, 10);
	head = ListPopBack(head, 20);
	head = ListPopBack(head, 30);
	ListPrint(head);
	//之前结点内存泄漏，没有释放
	head = NULL;
	head = ListPushBack(10);
	head = ListPushBack(20);
	ListPrint(head);
	//head不应该是NULL了
}
#endif