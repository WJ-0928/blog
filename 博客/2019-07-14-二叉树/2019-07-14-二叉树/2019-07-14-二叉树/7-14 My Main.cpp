#include"7-14 My  Binary Tree.h"
#include<stdio.h>

void test()
{
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

	int count = 0; getNodeCount(a);
	printf("结点个数：%d\n",count);

	printf("结点个数2: %d\n", getNodeCount2(a));
	printf("树的高度：%d\n", getHeight(a));
	printf("叶子结点个数：%d\n", getLeafCount(a));

	printf("第一层的结点个数：%d\n", getKLevelCount(a, 1));
	printf("第二层的结点个数：%d\n", getKLevelCount(a, 2));
	printf("第三层的结点个数：%d\n", getKLevelCount(a, 3));
	printf("第四层的结点个数：%d\n", getKLevelCount(a, 4));
	printf("第五层的结点个数：%d\n", getKLevelCount(a, 5));

	printf("层序遍历："); levelOrderTraversal(a); printf("\n");

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


int main() {
	test();
}