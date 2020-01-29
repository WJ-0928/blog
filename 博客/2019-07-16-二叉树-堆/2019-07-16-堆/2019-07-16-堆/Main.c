#if 0

#include <stdio.h>

// Ð¡¶Ñ
void heapify(int a[], int size, int index) {
	while (1) {
		int left = 2 * index + 1;
		int right = 2 * index + 2;

		if (left >= size) {
			return;
		}

		int min = left;
		if (right < size && a[right] < a[left]) {
			min = right;
		}

		if (a[index] <= a[min]) {
			return;
		}

		int t = a[min];
		a[min] = a[index];
		a[index] = t;

		index = min;
	}
}

void createHeap(int a[], int size) {
	for (int i = (size - 2) / 2; i >= 0; i--) {
		heapify(a, size, i);
	}
}

int main() {
	int a[] = { 9, 5, 2, 7, 3, 6, 4, 8, 3 };
	int size = sizeof(a) / sizeof(int);

	createHeap(a, size);

	printf("³É¹¦\n");
}

#endif
