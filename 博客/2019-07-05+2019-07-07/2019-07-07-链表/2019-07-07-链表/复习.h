typedef struct Node {
	int val;
	struct Node *next;
}	Node;


// 反转单链表
// 1 -> 2 -> 3 -> 4 -> 5
// 5 -> 4 -> 3 -> 2 -> 1
/*
思路：
	新建一个新的链表(空链表)
	Node * result = NULL;

	不断的遍历原来的链表，把结点头插到新链表上
	Node * cur = head;
	while (cur != NULL) {

		Node * next = cur->next;
		// 头插
		// 在头插的过程，会改变 cur->next 的值
		cur = next;
	}

	把 cur 头插到 result 上
	cur 已经是个结点了，还需要 malloc 申请结点么？	不需要
	1) 要头插的必须是个结点（已经是了）
	2) 新结点(cur)的下一个是原来的第一个结点(result)
		cur->next = result;
	3) 更新链表的第一个结点，变为 cur 指向的结点
	   让 result 和 cur 指向同一个结点
	   result = cur;
*/

Node * reverseList(Node * head) {
	Node * result = NULL;

	Node * cur = head;
	while (cur != NULL) {
		Node *next = cur->next;

		cur->next = result;
		result = cur;

		cur = next;
	}

	return result;
}


/*
合并两个有序链表

申请一个新链表（空链）
Node *result = NULL;

同时遍历两个链表（要求两个链表中都还有结点）
	选择小的一个，尾插到新链表(result)上
	
Node *c1 = head1;
Node *c2 = head2;

while (c1 != NULL && c2 != NULL) {
	if (c1->val <= c2->val) {
		// 把 c1 尾插到 result 上
		
		c1 = c1->next;
	} else {
		// 把 c2 尾插到 result 上
		
		c2 = c2->next;
	}
}

把 c1 尾插到 result 上
1) 链表为空	(result == NULL)
	原来链表一个结点都没有，把 c1 尾插到 result 上
	意味着 result 链表中只有 c1 一个结点
	result 指向 c1 所在的结点，[c1 的下一个是 NULL 这步是可选的]
	result = c1;	c1->next = NULL;
2) 链表不为空 (result != NULL)
	1) 手上 result 链表的最后一个结点 last
		第一个方法：	从 第一个结点（result）开始遍历找
		第二个方法：	记录
		last = c1;
	2) 让 last 的下一个结点变为 c1
		last->next = c1;
	3) 会影响 result 链表的第一个结点是谁么？不会
	4) [c1 的下一个是 NULL 这步是可选的]
		c1->next = NULL;

如果循环结束，意味着有个链表中的结点被取完了
把剩余链表整个接到新链表后边
*/
Node * merge(Node *head1, Node *head2) {
	if (head1 == NULL) ...
	if (head2 == NULL) ...
	
	Node * result = NULL;
	Node * last = NULL;
	
	Node *c1 = head1;
	Node *c2 = head2;
	
	while (c1 != NULL && c2 != NULL) {
		if (c1->val <= c2->val) {
			Node * next = c1->next;
			
			c1->next = NULL;
			if (result == NULL) {
				result = c1;
			} else {
				last->next = c1;
			}
			last = c1;
			
			c1 = next;
		} else {
			// 同样处理 c2
		}
	}
	
	if (c1 != NULL) {
		last->next = c1;
	} else {
		last->next = c2;
	}
	
	return result;
}

// 找链表的中间位置
Node * findMiddle(Node *head) {
	Node * fast = head;
	Node * slow = head;
	
	while (fast != NULL) {
		fast = fast->next;
		if (fast == NULL) {
			break;
		}
		slow = slow->next;
		fast = fast->next;
	}
	
	return slow;
}
// 逆置链表
Node * reverseList(Node *head) {
	...
}

bool chkPalindrome(Node* A) {
    Node *middle = findMiddle(A);
	Node *result = reverseList(middle);
	
	Node *c1 = A;
	Node *c2 = result;
	
	while (c1 != NULL && c2 != NULL) {
		if (c1->val != c2->val) {
			return false;
		}
		
		c1 = c1->next;
		c2 = c2->next;
	}
	
	return true;
}


/*
思路：
1）先求两个链表的长度
2）让长度先走几步（长度差）
3）同时往后走，什么时候两个指针指向同一个结点了，表示找到交叉点了
*/
int getLength(struct ListNode *head) {
	int length = 0;
	for (struct ListNode *cur = head; cur != NULL; cur = cur->next) {
		length++;
	}
	
	return length;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lengthA = getLength(headA);
	int lengthB = getLength(headB);
	
	struct ListNode *longer = headA;
	struct ListNOde *shorter = headB;
	int diff = lengthA - lengthB;
	if (lengthB > lengthA) {
		longer = headB;
		shorter = headA;
		diff = lengthB - lengthA;
	}
	
	for (int i = 0; i < diff; i++) {
		longer = longer->next;
	}
	
	// 即使没有交叉点，最后 longer 和 shorter 也会同时走到 NULL
	// 导致循环条件不满足
	while (longer != shorter) {
		longer = longer->next;
		shorter = shorter->next;
	}
	
	return longer;
}











