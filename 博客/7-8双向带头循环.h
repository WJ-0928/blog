#if 0


#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>



//1.结点

typedef struct Node
{
	int val;
	struct Node *prev;
	struct Node *next;
} Node;


//2.链表
typedef struct List
{
	Node *head;//头结点（没有有效值）
} List;

//初始化
void ListInit(List *list)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val =0;
	node->next = node;
	node->prev = node;
	list->head = node;
}

//头插
void ListPushFront(List *list,int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	
	node->prev = list->head;
	node->next = list->head->next;
	list->head->next->prev = node;
	list->head->next = node;
}

//尾插
void ListPushBack(List *list, int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;

	node->prev = list->head->prev;
	node->next = list->head;
	list->head->prev->next = node;
	list->head->prev = node;
}

//把结点查到pos之后
void ListInsertAfterPos(Node *pos, int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;

	node->prev = pos;
	node->next = pos->next;
	pos->next->prev = node;
	pos->next = node;
}

// 把结点查到pos之后
void ListInsertBeforePos(Node *pos, int val)
{
	ListInsertAfterPos(pos->prev, val);
}
#endif