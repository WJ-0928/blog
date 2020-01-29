#include"7-14 My Tree.h"

#include<stdio.h>
#include<stdlib.h>
int main()
{
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

	printf("ƒ„∫√ ¿ΩÁ\n");

}


