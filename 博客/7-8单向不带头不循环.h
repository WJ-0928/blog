#if 0
#pragma once


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//1.结点
typedef struct Node
{
	int val;
	struct Node *next;
} Node;

//2.链表
typedef struct List
{
	Node *head;//链表的第一个结点
} List;


//初始化
void ListInit(List *list)
{
	list->head = NULL;
}

//销毁
void ListDestroy(List *list)
{
	//把每个结点都需要释放
	Node *cur = list->head;
	while (cur != NULL)
	{
		Node *next = cur->next;
		free(cur);
		cur = next;
	}
	list->head = NULL;
}

//头插
void ListPushFront(List *list, int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	node->next = list->head;
	list->head = node;
}

//尾插
void ListPushBack(List *list, int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	node->next = NULL;
	if (list->head == NULL)
	{
		list->head = node;
	}
	else
	{
		Node *cur = list->head;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = node;
	}
}


//头删
void ListPopFront(List *list)
{
	assert(list->head != NULL);
	Node *second = list->head->next;
	free(list->head);
	list->head=second;
}

//尾删
void ListPopBack(List *list)
{
	assert(list->head != NULL);
	//找倒数第二个结点（至少有两个结点)
	if (list->head->next == NULL)
	{
		free(list->head);
		list->head = NULL;
	}
	else
	{
		Node *cur = list->head;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}


//中间删除(index肯定合法）
void ListInsert(List *list,int index, int val)
{
	Node *prev = list->head;
	for (int i = 0; i < index - 1; i++)
	{
		prev = prev->next;
	}
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	node->next = prev->next;
	prev->next = node;
}
#endif
