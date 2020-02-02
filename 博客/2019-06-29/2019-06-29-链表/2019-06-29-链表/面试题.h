struct ListNode* reverseList(struct ListNode* head){
	struct ListNode *resultHead = NULL;
	struct ListNode *cur = head;
	while (cur != NULL) {
		struct ListNode *next = cur->next;

		// 头插
		cur->next = resultHead; // 更改 cur->next
		resultHead = cur;

		// 让循环走起来
		cur = next;
	}

	return resultHead;
}