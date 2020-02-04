#include"7-11My.h"

#include<stdio.h>

void test()
{
	CNode *n1 = createNode(1);
	CNode *n2 = createNode(2);
	CNode *n3 = createNode(3);
	CNode *n4 = createNode(4);
	CNode *n5 = createNode(5);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;

	n1->random = n3;
	n2->random = n1;
	n3->random = n4;
	n4->random = n4;
	n5->random = NULL;

	CNode *result = copy(n1);

	for (CNode *cur = n1; cur != NULL; cur = cur->next)
	{
		printf("%p(%d,%p) ", cur, cur->val, cur->random);
	}
	printf("\n");
	for (CNode *cur = result; cur != NULL; cur = cur->next)
	{
		printf("%p(%d,%p) ", cur, cur->val, cur->random);
	}
	printf("\n");
}

int main()
{
	test();
	system("pause");
}