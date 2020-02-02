#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// 结点的定义
typedef struct Node {
	int val;			// 数据
	struct Node *next;	// 下一个结点的线索
						// 当 next == NULL 时，表示没有后续结点了
						// 反过来说，最后一个结点的 next 一定 == NULL
}	Node;

// O(1)
Node * ListPushFront(Node *head, int val) {
	// val 不在结点中，先装入结点中
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	// 让 node 的下一个为原第一个结点
	node->next = head;
	// node 成为新的第一个结点
	// head = node;
	return node;
}

// O(n)
Node * ListPushBack(Node *head, int val) {
	// 1. 装到结点中
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	// 2. node 的 next 置为 NULL
	node->next = NULL;

	if (head != NULL) {
		// 链表中有结点的情况
		// 3. 找到原最后一个结点
		Node *cur = head;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		// cur 就是最后一个结点
		// 让原最后一个结点的下一个为 node
		cur->next = node;
	}
	else {
		head = node;
	}

	return head;
}

void ListPrint(Node *head) {
	// 如何遍历链表
	for (Node *cur = head; cur != NULL; cur = cur->next) {
		printf("%d --> ", cur->val);
	}
	printf("NULL\n");
}

Node * ListPopFront(Node *head) {
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

Node * ListPopBack(Node *head) {
	assert(head != NULL);
	if (head->next == NULL) {
		free(head);
		head = NULL;
	}
	else {
		// 先找到倒数第二个结点
		Node *cur = head;
		while (cur->next->next != NULL) {
			cur = cur->next;
		}
		// 释放 cur->next 的空间
		// 让 cur->next = NULL
		free(cur->next);
		cur->next = NULL;
	}

	return head;
}

void Test() {
	Node *head = NULL;	// 链表的初始化

	// 对链表做头插
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


	head = ListPopFront(head);
	head = ListPopFront(head);
	head = ListPopFront(head);
	ListPrint(head);
	head = ListPopBack(head);
	head = ListPopBack(head);
	head = ListPopBack(head);
	head = ListPopBack(head);
	ListPrint(head);

	// 之前的结点内存泄漏了，没有释放
	head = NULL;
	head = ListPushBack(head, 10);
	head = ListPushBack(head, 20);
	ListPrint(head);
	// head 不应该是 NULL 了
	printf("你好世界\n");
}

#if 0

// 把 val 头插到 head 为第一个结点所代表的链表中
// 返回新的第一个结点的地址
Node * ListPushFront(Node *head, int val) {
	// 先把 val 装结点中
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	// 让 node 的下一个应该是原来的第一个结点，也就是 head
	node->next = head;
	// 更新新的第一个结点，我们这里通过返回的方式更新
	return node;
}

// 把 val 尾插到 head 为第一个结点所代表的链表中
// 返回新的第一个结点的地址
Node * ListPushBack(Node *head, int val) {
	//  把 val 装结点里
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	node->next = NULL;	// 因为 node 一定是最后一个结点，所以 node->next == NULL
	// 分情况讨论
	if (head == NULL) {
		// 链表中原来没有结点，按头插方式处理
		return node;
	}
	else {
		// 链表中原来有结点
		// 先找到原来的最后一个结点
		Node *last = head;
		// 走到 last->next == NULL 的时候停下来，last->next == NULL 就代表是最后一个结点
		while (last->next != NULL) {
			last = last->next;
		}
		// 让最后一个结点的下一个为 node
		last->next = node;
		return head;
	}
}

#endif