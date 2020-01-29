#if 0
typedef struct Node {
	int val;
	struct Node *left;
	struct Node *right;
}	Node;

#include <stdlib.h>
#include <stdio.h>

Node *head = NULL;
Node *prev = NULL;
void toDList(Node *node) {
	node->left = prev;
	if (prev == NULL) {
		head = node;
	}
	else {
		prev->right = node;
	}

	prev = node;
}

void inorder(Node *node) {
	if (node == NULL) {
		return;
	}

	inorder(node->left);
	toDList(node);
	inorder(node->right);
}

Node * searchTreeToDList(Node *root) {
	head = NULL; prev = NULL;
	inorder(root);

	return head;
}

#include <stack>
void preorderNoR(Node * root) {
	Node *cur = root;
	std::stack<Node *> st;

	while (cur != NULL || !st.empty()) {
		while (cur != NULL) {
			printf("%d ", cur->val);
			st.push(cur);
			cur = cur->left;
		}

		Node *top = st.top();
		st.pop();

		cur = top->right;
	}
}

void inorderNoR(Node * root) {
	Node *cur = root;
	std::stack<Node *> st;

	while (cur != NULL || !st.empty()) {
		while (cur != NULL) {
			st.push(cur);
			cur = cur->left;
		}

		Node *top = st.top();
		printf("%d ", top->val);
		st.pop();

		cur = top->right;
	}
}

void postorderNoR(Node * root) {
	Node *cur = root;
	Node *last = NULL;	// 上一次被完整遍历过的结点
	std::stack<Node *> st;
	while (cur != NULL || !st.empty()) {
		while (cur != NULL) {
			st.push(cur);
			cur = cur->left;
		}
		Node *top = st.top();
		if (top->right == NULL || top->right == last) {
			st.pop();
			printf("%d ", top->val);
			last = top;
		}
		else {
			cur = top->right;
		}
	}
}

#include <queue>

void levelOrder(Node *root) {
	if (root == NULL) {
		return;
	}

	std::queue<Node *> q;
	Queue	q;
	q.push(root);

	while (!q.empty()) {
		// Node * front = QueueFront(&q); QueuePop(&q);
		Node * front = q.front();	q.pop();

		printf("%d ", front->val);
		if (front->left != NULL) {
			q.push(front->left);
		}
		if (front->right != NULL) {
			q.push(front->right);
		}
	}
}

int main() {
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
	Node *n6 = (Node *)malloc(sizeof(Node));
	n6->val = 6;
	Node *n7 = (Node *)malloc(sizeof(Node));
	n7->val = 7;
	Node *n8 = (Node *)malloc(sizeof(Node));
	n8->val = 8;
	Node *n9 = (Node *)malloc(sizeof(Node));
	n9->val = 9;

	n1->left = NULL; n1->right = NULL;
	n2->left = n1; n2->right = NULL;
	n3->left = n2; n3->right = n4;
	n4->left = NULL; n4->right = NULL;
	n5->left = n3; n5->right = n8;
	n6->left = NULL; n6->right = n7;
	n7->left = NULL; n7->right = NULL;
	n8->left = n6; n8->right = n9;
	n9->left = NULL; n9->right = NULL;

	preorderNoR(n5); printf("\n");
	inorderNoR(n5); printf("\n");
	postorderNoR(n5); printf("\n");
	levelOrder(n5); printf("\n");

	Node *r = searchTreeToDList(n5);

	printf("你好世界\n");
}

#endif