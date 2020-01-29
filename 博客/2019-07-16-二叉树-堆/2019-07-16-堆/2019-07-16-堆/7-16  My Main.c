#include<stdio.h>

//小堆
void heapify(int a[], int size, int indext)
{
	while (1)
	{
		int left = indext * 2 + 1;
		int right = indext * 2 + 2;

		if (left >= size)
		{
			return;
		}
		int min = left;
		if (right < size&&a[right] < a[left])
		{
			min = right;
		}
		if (a[indext] <= a[min])
		{
			return;
		}
		int t = a[min];
		a[min] = a[indext];
		a[indext] = t;

		indext = min;
	}
}

//建堆

void crearHeap(int a[], int size)
{
	//最后一个非子叶结点就是最后一个结点的双亲
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		heapify(a, size, i);
	}
}

int main() {
	int a[] = { 9, 5, 2, 7, 3, 6, 4, 8, 3 };
	int size = sizeof(a) / sizeof(int);

	crearHeap(a, size);

	printf("成功\n");
}