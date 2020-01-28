#pragma once

#if 0
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>



//冒泡排序
void  bubbleSort(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		//假设已经有序了
		int ordered = 1;
		//有序：[size-i,size)
		//无序：[0,size-i)
		//冒泡部分，只在无序区间内进行
		for (int j = 0; j < size - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				//发生交换，假设有序不成立
				ordered = 0;
			}
		}
		//如果数组仍然有序，则可以退出了
		if (ordered == 1)
		{
			break;
		}
	}
}


//二分查找
int binarySearch(int a[], int size, int value)
{
	int left = 0;//查找区间的左边界，是个下表，包含
	int right = size - 1;//查找区间的右边界，是个下表，不包含
	int mid = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (a[mid] == value)
		{
			return mid;
		}
		else if (a[mid] > value)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return -1;
}

int main()
{
	int a[] = { 9,5,2,7,3,6,8,4 };
	int size = sizeof(a) / sizeof(int);
	bubbleSort(a, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");

	int index = binarySearch(a, size, 3);
	printf("3在 %d\n", index);
}
#endif