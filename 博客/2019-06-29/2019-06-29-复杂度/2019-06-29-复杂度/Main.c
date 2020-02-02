#include <stdio.h>

void swap(int a[], int i, int j) {
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void bubbleSort(int a[], int size) {
	// 循环了 size 次
	for (int i = 0; i < size; i++) {
		// 假设已经有序了
		int ordered = 1;

		// 有序：[size - i, size)
		// 无序：[0, size - i)
		// 冒泡部分，只在无序区间内进行
		for (int j = 0; j < size - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a, j, j + 1);
				// 发生交换，假设有序不成立
				ordered = 0;
			}
		}

		// 如果数组仍然有序，则可以退出了
		if (ordered == 1) {
			break;
		}
	}
}

int binarySearch(int a[], int size, int value) {
	int left = 0;	// 查找区间的左边界，是个下标，包含
	int right = size;	// 查找区间的右边界，是个下标，不包含

	// [left, right)
	while (left < right) {
		int mid = (left + right) / 2;
		if (value == a[mid]) {
			return mid;
		}
		else if (value < a[mid]) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	return -1;
}

int main() {
	int a[] = { 9, 5, 2, 7, 3, 6, 8, 4 };
	int size = sizeof(a) / sizeof(int);

	bubbleSort(a, size);

	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	int index = binarySearch(a, size, 3);
	printf("3 在 %d\n", index);
}