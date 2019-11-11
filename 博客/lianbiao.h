#if 0
#pragma once
#include<stdio.h>


//����ͷ�ڵ�ĵ����� 

// �ڵ�ṹ 
typedef struct SListNode
{
	int _data;
	struct SListNode* _pNext;
}Node;


// ��һ������ṹ 
typedef struct SList
{
	Node* _pHead;
}SList;


// ����ĳ�ʼ�� 
void SListInit(SList* pl);

// ��������β��ֵΪdata�Ľڵ� 
void SListPushBack(SList* pl, int data);

// ɾ���������һ���ڵ� 
void SListPopBack(SList* pl);

// �������һ��Ԫ��ǰ����ֵΪdata�Ľڵ� 
void SListPushFront(SList* pl, int data);

// ɾ�������е�һ���ڵ� 
void SListPopFront(SList* pl);

// ������posλ�ú������Ϊdata�Ľڵ� 
void SListInsertAfter(Node* pos, int data);

// ɾ��������ֵΪdata�Ľڵ� 
void SListErase(SList* pl, Node* pos);

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻ؿ� 
Node* SListFind(SList* pl, int data);

// �������� 
void SListDestroy(SList* pl);

// ��ȡ��������Ч�ڵ�ĸ��� 
int SListSize(SList* pl);

// ��������Ƿ�Ϊ�� 
int SListEmpty(SList* pl);

// ��ȡ����ĵ�һ���ڵ� 
Node* SListFront(SList* pl);

// ��ȡ����ĵڶ����ڵ� 
Node* SListBack(SList* pl);

// ɾ�������е�һ��ֵΪdata�Ľڵ� 
void SListRemove(SList* pl, int data);

// ɾ������������ֵΪdata�Ľڵ� 
void SListRemoveAll(SList* pl, int data);



typedef struct DListNode
{
	struct DListNode* _pNext;
	struct DListNode* _pPre;
	int _data;
}DNode;

// ��ʼ��˫������ 
void DListInit(DNode** pHead);

// β�� 
void DListPushBack(DNode* pHead, int data);

// βɾ 
void DListPopBack(DNode* pHead);

// ͷ�� 
void DListPushFront(DNode* pHead, int data);

// ͷɾ 
void DListPopFront(DNode* pHead);

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ؽڵ��λ�� 
DNode* DListFind(DNode* pHead, int data);

// ��posλ��(����ɹ����½ڵ�ʵ����posǰ)����ֵΪdata��Ԫ�� 
void DListInsert(DNode* pos, int data);

// ɾ��posλ�õĽڵ� 
void DListErase(DNode* pos);

// �������е����нڵ���� 
void DListClear(DNode* pHead);

// �������� 
void DListDestroy(DNode** pHead);
#endif
