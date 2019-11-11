#if 0

#include"lianbiao.h"
#include<stdlib.h>
#include<assert.h>


// ����ĳ�ʼ�� 
void SListInit(SList * pl)
{
	pl->_pHead = NULL;
}

// ��������β��ֵΪdata�Ľڵ� 
void SListPushBack(SList* pl, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->_pNext = NULL;
	if (pl != NULL)
	{
		Node* cur = pl;
		while (cur->_pNext != NULL)
		{
			cur = cur->_pNext;
		}
		cur->_pNext = node;
	}
	else
	{
		node = pl;
	}
}

// ɾ���������һ���ڵ� 
void SListPopBack(SList* pl)
{
	assert(pl != NULL);
	if (pl->_pHead->_pNext == NULL)
	{
		free(pl);
		pl = NULL;
	}
	else
	{
		Node *cur = pl;
		while (cur->_pNext->_pNext != NULL)
		{
			cur = cur->_pNext;
		}
		free(cur->_pNext);
		cur->_pNext = NULL;
	}
	return pl;
}

// �������һ��Ԫ��ǰ����ֵΪdata�Ľڵ� 
void SListPushFront(SList* pl, int data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->_data = data;
	node->_pNext = pl;

	return node;
}

// ɾ�������е�һ���ڵ� 
void SListPopFront(SList* pl)
{
	assert(pl != NULL);
	Node *next = pl->_pHead->_pNext;
	free(pl);
	return next;
}

// ������posλ�ú������Ϊdata�Ľڵ� 
void SListInsertAfter(Node* pos, int data)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->_pNext = pos->_pNext;//ӦΪnode����pos��node����һ������pos����һ��
	pos->_pNext = node;
}

// ɾ��������ֵΪdata�Ľڵ� 
void SListErase(SList* pl,int data)
{
	//����Ϊ��
	if (pl == NULL)
	{
		return;
	}
	//����
	Node *cur = pl->_pHead;
	while (cur->_pNext != NULL)
	{
		if (cur->_data == data)
		{
			Node*next = cur->_pNext;

			free(cur);
			cur = next;
		}
		cur = cur->_pNext;
	}
}

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻ؿ� 
Node* SListFind(SList* pl, int data)
{
	if (pl == NULL)
	{
		return NULL;
	}
	
	Node* cur = pl->_pHead;
	while (cur->_pNext != NULL)
	{
		if (cur->_data == data)
		{
			return cur;
			cur = cur->_pNext;
		}
	}
	return NULL;
}

// �������� 
void SListDestroy(SList* pl)
{
	Node* cur = pl->_pHead;
	while (cur->_pNext != NULL)
	{
		Node* next = cur->_pNext;
		free(cur);
		cur = next;
	}
	pl->_pHead = NULL;
}

// ��ȡ��������Ч�ڵ�ĸ��� 
int SListSize(SList* pl)
{
	int count = 0;
	Node* cur = pl->_pHead;
	while (cur!= NULL)
	{
		cur = cur->_pNext;
		count++;
	}
	return count;
}

// ��������Ƿ�Ϊ�� 
int SListEmpty(SList* pl)
{
	if (pl->_pHead == NULL)
	{
		return 1;
	}
	return 0;
}

// ��ȡ����ĵ�һ���ڵ� 
Node* SListFront(SList* pl)
{
	return pl->_pHead;
}

// ��ȡ����ĵڶ����ڵ� 
Node* SListBack(SList* pl)
{
	return pl->_pHead->_pNext;
}

// ɾ�������е�һ��ֵΪdata�Ľڵ� 
void SListRemove(SList* pl, int data)
{
	assert(pl != NULL);
	Node* cur = pl->_pHead;
	while (cur != NULL)
	{
		if (cur->_data == data)
		{
			Node *next = cur->_pNext;
			free(cur);
			cur = next;
			break;
		}
	}
}

// ɾ������������ֵΪdata�Ľڵ� 
void SListRemoveAll(SList* pl, int data)
{
	assert(pl != NULL);
	Node *cur = pl->_pHead;
	while (cur != NULL)
	{
		if (cur->_data == data)
		{
			Node* next = cur->_pNext;
			free(cur);
			cur = next;
		}
	}
}



//˫������

// ��ʼ��˫������ 
void DListInit(DNode* pHead)
{
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->_data = 0;
	node->_pNext = node;
	node->_pPre = node;

	pHead = node;
}

// β�� 
void DListPushBack(DNode* pHead, int data)
{
	assert(pHead != NULL);
	DNode *node = (DNode*)malloc(sizeof(DNode));
	node->_data = data;

	node->_pPre = pHead->_pPre;
	node->_pNext = pHead;
	pHead->_pPre->_pNext = node;
	pHead->_pPre = node;
}

// βɾ 
void DListPopBack(DNode* pHead)
{
	assert(pHead != NULL);
	if (pHead->_pNext = pHead)
	{
		return;
	}
	else
	{
		pHead->_pPre = pHead->_pPre->_pPre;
		free(pHead->_pPre->_pNext);
		pHead->_pPre->_pNext = pHead;
	}
}

// ͷ�� 
void DListPushFront(DNode* pHead, int data)
{
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->_data = data;
	node->_pPre = pHead->_pPre;
	node->_pNext = pHead;
	pHead->_pPre->_pNext = node;
	pHead->_pPre = node;
}

// ͷɾ 
void DListPopFront(DNode* pHead)
{
	assert(pHead != NULL);
	DNode* cur = pHead;
	pHead->_pNext->_pNext->_pPre = pHead;
	pHead->_pNext = pHead->_pNext->_pNext;
	free(cur);
	cur = NULL;
}

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ؽڵ��λ�� 
DNode* DListFind(DNode* pHead, int data)
{
	assert(pHead != NULL);
	DNode* cur = pHead;
	while (cur != NULL)
	{
		if (cur->_data == data)
		{
			return cur;
		}
		cur = cur->_pNext;
	}
	return NULL;
}

// ��posλ��(����ɹ����½ڵ�ʵ����posǰ)����ֵΪdata��Ԫ�� 
void DListInsert(DNode* pos, int data)
{
	assert(pos);
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->_data = data;

	node->_pNext = pos;
	node->_pPre = pos->_pPre;
	pos->_pPre->_pNext = node;
	pos->_pPre = node;
}

// ɾ��posλ�õĽڵ� 
void DListErase(DNode* pos)
{
	assert(pos);
	pos->_pPre->_pNext = pos->_pNext;
	pos->_pNext->_pPre = pos->_pPre;
	free(pos);
	pos = NULL;
}

// �������е����нڵ���� 
void DListClear(DNode* pHead)
{
	assert(pHead != NULL);
	DNode* cur = pHead->_pNext;
	while (cur != pHead)
	{
		DNode* next = cur->_pNext;
		cur->_pNext->_pPre = cur->_pPre;
		cur->_pPre->_pNext = cur->_pNext;
        free(cur);
		cur = next->_pNext;
	}
}

// �������� 
void DListDestroy(DNode** pHead)
{
	assert(pHead != NULL);
	DNode* cur = *pHead;
	cur = cur->_pNext;
	while (cur != *pHead)
	{
		DNode* next = cur->_pNext;
		free(cur);
		cur = next;
	}
	free(*pHead);
	*pHead = NULL;
}
#endif