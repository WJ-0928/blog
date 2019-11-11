#if 0

#include"lianbiao.h"
#include<stdlib.h>
#include<assert.h>


// 链表的初始化 
void SListInit(SList * pl)
{
	pl->_pHead = NULL;
}

// 在链表中尾插值为data的节点 
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

// 删除链表最后一个节点 
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

// 在链表第一个元素前插入值为data的节点 
void SListPushFront(SList* pl, int data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->_data = data;
	node->_pNext = pl;

	return node;
}

// 删除链表中第一个节点 
void SListPopFront(SList* pl)
{
	assert(pl != NULL);
	Node *next = pl->_pHead->_pNext;
	free(pl);
	return next;
}

// 在链表pos位置后插入置为data的节点 
void SListInsertAfter(Node* pos, int data)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->_pNext = pos->_pNext;//应为node插入pos后，node的下一个就是pos得下一个
	pos->_pNext = node;
}

// 删除链表中值为data的节点 
void SListErase(SList* pl,int data)
{
	//链表为空
	if (pl == NULL)
	{
		return;
	}
	//遍历
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

// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回空 
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

// 销毁链表 
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

// 获取链表中有效节点的个数 
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

// 检测链表是否为空 
int SListEmpty(SList* pl)
{
	if (pl->_pHead == NULL)
	{
		return 1;
	}
	return 0;
}

// 获取链表的第一个节点 
Node* SListFront(SList* pl)
{
	return pl->_pHead;
}

// 获取链表的第二个节点 
Node* SListBack(SList* pl)
{
	return pl->_pHead->_pNext;
}

// 删除链表中第一个值为data的节点 
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

// 删除链表中所有值为data的节点 
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



//双向链表

// 初始化双向链表 
void DListInit(DNode* pHead)
{
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->_data = 0;
	node->_pNext = node;
	node->_pPre = node;

	pHead = node;
}

// 尾插 
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

// 尾删 
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

// 头插 
void DListPushFront(DNode* pHead, int data)
{
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->_data = data;
	node->_pPre = pHead->_pPre;
	node->_pNext = pHead;
	pHead->_pPre->_pNext = node;
	pHead->_pPre = node;
}

// 头删 
void DListPopFront(DNode* pHead)
{
	assert(pHead != NULL);
	DNode* cur = pHead;
	pHead->_pNext->_pNext->_pPre = pHead;
	pHead->_pNext = pHead->_pNext->_pNext;
	free(cur);
	cur = NULL;
}

// 在链表中查找值为data的节点，找到返回节点的位置 
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

// 在pos位置(插入成功后新节点实际在pos前)插入值为data的元素 
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

// 删除pos位置的节点 
void DListErase(DNode* pos)
{
	assert(pos);
	pos->_pPre->_pNext = pos->_pNext;
	pos->_pNext->_pPre = pos->_pPre;
	free(pos);
	pos = NULL;
}

// 将链表中的所有节点清空 
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

// 销毁链表 
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