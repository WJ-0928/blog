typedef struct ListNode {
	int val;
	struct ListNode *next;
}	ListNode;


ListNode * deleteDuplication(ListNode *head) {
	if (head == NULL) {
		return NULL;
	}

	ListNode *prev = NULL;
	ListNode *p1 = head;
	ListNode *p2 = head->next;	// head 一定不能是 NULL

	while (p2 != NULL) {
		if (p1->val != p2->val) {
			prev = p1;
			p1 = p2;
			p2 = p2->next;
		}
		else {
			while (p2 != NULL && p2->val == p1->val) {
				p2 = p2->next;
			}
			if (prev != NULL) {
				prev->next = p2;
			}
			else {
				head = p2;
			}
			p1 = p2;
			if (p2 != NULL) {
				p2 = p2->next;	// 保证 p2 不能为 空
			}
		}
	}

	return head;
}

ListNode * reverseList(ListNode * head) {
	ListNode * r = NULL;
	ListNode * c = head;

	while (c != NULL) {
		ListNode *n = c->next;

		c->next = r;
		r = c;

		c = n;
	}

	return r;
}

ListNode * removeAll(ListNode *head, int val) {
	ListNode * p = head;	// 永远保持 p 是 c 的前驱
	ListNode * c = head->next;
	while (c != NULL) {
		if (c->val == val) {
			p->next = c->next;
		}
		else {
			p = c;
		}

		c = c->next;
	}

	if (head->val == val) {
		head = head->next;
	}

	return head;
}

bool hasCycle(struct ListNode *head) {
	if (head == NULL) {
		return NULL;
	}

	// 如何判断带环/快慢指针找相遇点
	struct ListNode *fast = head;
	struct ListNode *slow = head;

	do {
		fast = fast->next;
		if (fast == NULL) {
			return NULL;
		}
		fast = fast->next;
		if (fast == NULL) {
			return NULL;
		}
		slow = slow->next;
	} while (fast != slow);
	// fast 和 slow 都是相遇点
	// 如何找到环的入口点
	// 一个从起点出发 head
	// 一个从相遇点出发 slow
	// 如果两个指针相等了，环的入口点
	struct ListNode *p1 = head;
	struct ListNode *p2 = slow;

	while (p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;
	}

	return p1;
}


ListNode * copy(ListNode * head) {
	ListNode * result = NULL;
	ListNode * last = NULL;

	ListNode * cur = head;
	while (cur != NULL) {
		// 1. 复制的是值
		ListNode *node = (ListNode *)malloc(sizeof(ListNode));
		node->val = cur->val;

		if (result == NULL) {
			result = node;
		}
		else {
			last->next = node;
		}
		last = node;

		cur = cur->next;
	}

	last->next = NULL;

	return result;
}