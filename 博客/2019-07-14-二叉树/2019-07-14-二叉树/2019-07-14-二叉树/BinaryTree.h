#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct Node {
	char value;
	struct Node *left;	// 指向我的左孩子
	struct Node *right;	// 指向我的右孩子
}	Node;


// 前序遍历
void preOrderTraversal(Node *root) {
	if (root == NULL) {
		return;
	}

	// 根
	printf("%c ", root->value);

	// 左子树的前序遍历
	preOrderTraversal(root->left);

	// 右子树的前序遍历
	preOrderTraversal(root->right);
}

// 中序遍历
void inOrderTraversal(Node *root) {
	if (root == NULL) {
		return;
	}

	// 左子树的中序遍历
	inOrderTraversal(root->left);

	// 根
	printf("%c ", root->value);

	// 右子树的中序遍历
	inOrderTraversal(root->right);
}


// 后序遍历
void postOrderTraversal(Node *root) {
	if (root == NULL) {
		return;
	}

	// 左子树的后序遍历
	postOrderTraversal(root->left);

	// 右子树的后序遍历
	postOrderTraversal(root->right);

	// 根
	printf("%c ", root->value);
}



int count = 0; 
void getNodeCount(Node *root) {
	if (root == NULL) {
		return;
	}

	getNodeCount(root->left);
	count++;
	getNodeCount(root->right);
}

int getNodeCount2(Node *root) {
	if (root == NULL) {
		return 0;
	}

	int left = getNodeCount2(root->left);
	int right = getNodeCount2(root->right);

	return left + 1 + right;
}

int myMax(int a, int b) {
	return a >= b ? a : b;
}

int getHeight(Node *root) {
	if (root == NULL) {
		return 0;
	}

	int left = getHeight(root->left);
	int right = getHeight(root->right);

	return myMax(left, right) + 1;
}

int getLeafCount(Node *root) {
	if (root == NULL) {
		return 0;
	}
	else if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	else {
		return getLeafCount(root->left) + getLeafCount(root->right);
	}
}

int getKLevelCount(Node *root, int k) {
	assert(k >= 1);

	if (root == NULL) {
		return 0;
	} else if (k == 1) {
		return 1;
	}
	else {
		return getKLevelCount(root->left, k - 1)
			+ getKLevelCount(root->right, k - 1);
	}
}

Node * find(Node *root, char v) {
	if (root == NULL) {
		return NULL;	// 没有找到
	}

	if (root->value == v) {
		return root;
	}

	Node * left = find(root->left, v);
	if (left != NULL) {
		return left;
	}

	Node * right = find(root->right, v);
	//return right;
	if (right != NULL) {
		return right;
	}
	else {
		return NULL;
	}
}

#include <queue>

void levelOrderTraversal(Node *root) {
	if (root == NULL) {
		return;
	}
	std::queue<Node *>	q;
	q.push(root);

	while (!q.empty()) {
		Node * front = q.front(); q.pop();

		printf("%c ", front->value);

		if (front->left != NULL) {
			q.push(front->left);
		}

		if (front->right != NULL) {
			q.push(front->right);
		}
	}
}

bool isCompleteTree(Node *root) {
	if (root == NULL) {
		return true;
	}

	std::queue<Node *> q;
	q.push(root);

	while (true) {
		Node * front = q.front(); q.pop();
		if (front == NULL) {
			break;
		}

		q.push(front->left);
		q.push(front->right);
	}

	while (!q.empty()) {
		Node * front = q.front(); q.pop();
		if (front != NULL) {
			return false;
		}
	}

	return true;
}

Node * createNode(char ch) {
	Node * node = (Node *)malloc(sizeof(Node));
	node->value = ch;
	node->left = node->right = NULL;

	return node;
}

void test() {
	Node *a = createNode('A');
	Node *b = createNode('B');
	Node *c = createNode('C');
	Node *d = createNode('D');
	Node *e = createNode('E');
	Node *f = createNode('F');
	Node *g = createNode('G');
	Node *h = createNode('H');

	a->left = b; a->right = c;
	b->left = d; b->right = e;
	c->left = f; c->right = g;
	d->left = NULL; d->right = NULL;
	e->left = NULL; e->right = h;
	f->left = NULL; f->right = NULL;

	preOrderTraversal(a); printf("\n");
	inOrderTraversal(a); printf("\n");
	postOrderTraversal(a); printf("\n");

	count = 0; getNodeCount(a);
	printf("结点个数: %d\n", count);

	printf("结点个数 2: %d\n", getNodeCount2(a));
	printf("高度: %d\n", getHeight(a));

	printf("叶子结点个数: %d\n", getLeafCount(a));
	printf("第 1 层结点个数: %d\n", getKLevelCount(a, 1));
	printf("第 2 层结点个数: %d\n", getKLevelCount(a, 2));
	printf("第 3 层结点个数: %d\n", getKLevelCount(a, 3));
	printf("第 4 层结点个数: %d\n", getKLevelCount(a, 4));
	printf("第 5 层结点个数: %d\n", getKLevelCount(a, 5));

	printf("层序遍历: "); levelOrderTraversal(a); printf("\n");
	if (isCompleteTree(a)) {
		printf("A 是完全二叉树\n");
	}
	else {
		printf("A 不是完全二叉树\n");
	}

	if (isCompleteTree(c)) {
		printf("C 是完全二叉树\n");
	}
	else {
		printf("C 不是完全二叉树\n");
	}
}