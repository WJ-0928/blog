#if 0
#pragma once
#include<stdio.h>


//不带头节点的单链表 

// 节点结构 
typedef struct SListNode
{
	int _data;
	struct SListNode* _pNext;
}Node;


// 给一个链表结构 
typedef struct SList
{
	Node* _pHead;
}SList;


// 链表的初始化 
void SListInit(SList* pl);

// 在链表中尾插值为data的节点 
void SListPushBack(SList* pl, int data);

// 删除链表最后一个节点 
void SListPopBack(SList* pl);

// 在链表第一个元素前插入值为data的节点 
void SListPushFront(SList* pl, int data);

// 删除链表中第一个节点 
void SListPopFront(SList* pl);

// 在链表pos位置后插入置为data的节点 
void SListInsertAfter(Node* pos, int data);

// 删除链表中值为data的节点 
void SListErase(SList* pl, Node* pos);

// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回空 
Node* SListFind(SList* pl, int data);

// 销毁链表 
void SListDestroy(SList* pl);

// 获取链表中有效节点的个数 
int SListSize(SList* pl);

// 检测链表是否为空 
int SListEmpty(SList* pl);

// 获取链表的第一个节点 
Node* SListFront(SList* pl);

// 获取链表的第二个节点 
Node* SListBack(SList* pl);

// 删除链表中第一个值为data的节点 
void SListRemove(SList* pl, int data);

// 删除链表中所有值为data的节点 
void SListRemoveAll(SList* pl, int data);



typedef struct DListNode
{
	struct DListNode* _pNext;
	struct DListNode* _pPre;
	int _data;
}DNode;

// 初始化双向链表 
void DListInit(DNode** pHead);

// 尾插 
void DListPushBack(DNode* pHead, int data);

// 尾删 
void DListPopBack(DNode* pHead);

// 头插 
void DListPushFront(DNode* pHead, int data);

// 头删 
void DListPopFront(DNode* pHead);

// 在链表中查找值为data的节点，找到返回节点的位置 
DNode* DListFind(DNode* pHead, int data);

// 在pos位置(插入成功后新节点实际在pos前)插入值为data的元素 
void DListInsert(DNode* pos, int data);

// 删除pos位置的节点 
void DListErase(DNode* pos);

// 将链表中的所有节点清空 
void DListClear(DNode* pHead);

// 销毁链表 
void DListDestroy(DNode** pHead);
#endif
