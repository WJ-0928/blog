#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct SeqList
{
	int *array;
	int capacity;
	int size;
};

struct ListNode
{
	int val;
	struct ListNode *next;
};

typedef struct ListNode Node;



//冒泡排序
void bubbleSort(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
}
//在顺序表seq的index位置插入val
//确保插入前，顺序表容量够用
//如果不够，扩容到原来的2倍

void insert(SeqList *seq, int index, int val)
{
	if (index<0 || index>seq->size)
	{
		printf("不合法的下标\n");
		return;
	}
	if (seq->size >= seq->capacity)
	{
		int *newArray = (int *)malloc(sizeof(int)* seq->capacity * 2);
		for (int i = 0; i < seq->size; i++)
		{
			newArray[i] = seq->array[i];
		}
		free(seq->array);
		seq->array = newArray;
	}
	for (int i = seq->size ; i > index; i--)
	{
		seq->array[i] = seq->array[i - 1];
	}
	seq->array[index] = val;
	seq->size++;
}


//头插
Node * pushFront(Node *head, int val)
{
	Node * node = (Node *)malloc(sizeof(Node));
	node->val = val;
	node->next = head;
	return node;
}


//尾插
Node * pushBack(Node *head, int val)
{
	Node * node = (Node *)malloc(sizeof(Node));
	node->val = val;
	node->next = NULL;
	if (head == NULL)
	{
		return node;
	}
	else
	{
		Node *cur = head;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = node;
		return head;
	}
}
//头删
Node * popFront(Node *head)
{
	assert(head != NULL);
	Node * second = head->next;
	free(head);
	return second;
}


//尾删
Node * popBack(Node *head)
{
	assert(head != NULL);
	if (head->next == NULL)
	{
		free(head);
		return NULL;
	}
	else
	{
		Node *cur = head;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
		return head;
	}
}
// 反转链表
Node * reverseList(Node *head)
{
	Node * rHead = NULL;
	Node * cur = head;
	while (cur != NULL)
	{
		Node *next = cur->next;
		cur->next = rHead;
		rHead = cur;
		cur = next;
	}
	return rHead;
}

// 删除链表中所有的 val
// 遇到等于 val 的就删除

struct ListNode* removeElements_1(struct ListNode* head, int val)
{
	if (head == NULL)
	{
		return NULL;
	}
	Node *prev = head;
	Node *cur = head->next;
	while (cur != NULL)
	{
		if (cur->val == val)
		{
			prev->next = cur->next;
		}
		else
		{
			prev = cur;
		}
		cur = cur->next;
	}
	if (head->val == val)
	{
		return head->next;
	}
	else
	{
		return head;
	}
}


// 删除链表中所有的 val
// 遇到不等于 val 的，就尾插到另一个链表中
struct ListNode* removeElements_2(struct ListNode* head, int val)
{
	Node *rHead = NULL;
	Node *cur = head;
	Node *last = NULL;//记录rHead代表链表的最后一个结点
	while (cur != NULL)
	{
		Node *next = cur->next;
		if (cur->val != val)
		{
			if (rHead == NULL)
			{
				cur->next == rHead;
				rHead = cur;
			}
			else
			{
				cur->next = NULL;
				last->next = cur;
			}
			last = cur;
		}
		cur = next;
	}
	return rHead;
}


// 合并有序链表

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	Node *rHead = NULL; // 结果链表
	Node *last = NULL;  // 记录 rHead 的最后一个结点
	Node *c1 = l1;  // 遍历 l1 链表
	Node *c2 = l2;  // 遍历 l2 链表

	while (c1 != NULL && c2 != NULL) {
		if (c1->val <= c2->val) {
			Node *next = c1->next;
			// 把 c1 尾插到 rHead
			c1->next = NULL;
			if (rHead == NULL) {
				rHead = c1;
			}
			else {
				last->next = c1;
			}
			last = c1;

			c1 = next;
		}
		else {
			Node *next = c2->next;
			// 把 c2 尾插到 rHead
			c2->next = NULL;
			if (rHead == NULL) {
				rHead = c2;
			}
			else {
				last->next = c2;
			}
			last = c2;

			c2 = next;
		}
	}

	// 只是一个链表的结点被处理完了
	// 剩余的结点一定至少比 last 结点中值要大
	// last 是现在 rHead 中的最后一个结点
	if (c1 != NULL) {
		last->next = c1;
	}
	else {
		last->next = c2;
	}

	return rHead;

}

//创建链表1
Node * createTestList1() {
	Node *n1 = (Node *)malloc(sizeof(Node));
	n1->val = 1;

	Node *n2 = (Node *)malloc(sizeof(Node));
	n2->val = 2;

	Node *n3 = (Node *)malloc(sizeof(Node));
	n3->val = 3;

	Node *n4 = (Node *)malloc(sizeof(Node));
	n4->val = 4;

	Node *n5 = (Node *)malloc(sizeof(Node));
	n5->val = 5;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;

	return n1;
}
//反转列表
void testReverseList() {
	Node *head = createTestList1();
	for (Node *cur = head; cur != NULL; cur = cur->next) {
		printf("%d ", cur->val);
	}
	printf("\n");

	Node *result = reverseList(head);

	for (Node *cur = result; cur != NULL; cur = cur->next) {
		printf("%d ", cur->val);
	}
	printf("\n");
}
//创建列表2
Node * createTestList2() {
	Node *n1 = (Node *)malloc(sizeof(Node));
	n1->val = 6;

	Node *n2 = (Node *)malloc(sizeof(Node));
	n2->val = 2;

	Node *n3 = (Node *)malloc(sizeof(Node));
	n3->val = 3;

	Node *n4 = (Node *)malloc(sizeof(Node));
	n4->val = 6;

	Node *n5 = (Node *)malloc(sizeof(Node));
	n5->val = 5;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;

	return n1;
}

// 删除链表中所有的 val
// 遇到等于 val 的就删除
void testRemoveAll() {
	Node *head = createTestList2();
	// 6 2 3 6 5

	Node *result = removeElements_2(head, 6);
	// 2 3 5
	for (Node *cur = result; cur != NULL; cur = cur->next) {
		printf("%d ", cur->val);
	}
	printf("\n");
}

int main() {
	testReverseList();
	testRemoveAll();
}
