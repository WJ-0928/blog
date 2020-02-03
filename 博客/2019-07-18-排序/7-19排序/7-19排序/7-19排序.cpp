#include<stdio.h>
#include<stack>
#include<stdlib.h>

//打印
void printArray(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
}
//交换
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}


//直接插入排序

void insertSort(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int k = a[i];//要插入的数
		int j;
		//在有序区间[0,1)中向前遍历，如果要插入的数小于有序数组中最后一个数，交换两个数，继续比较
		for (j = i - 1; j >= 0 && k < a[j]; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = k;//新的要插入的值，有序数组最后一个数得下一个数
	}
}



//希尔排序
void shellSort(int a[], int size)
{
	int gap = size;
	while (1)
	{
		gap = gap / 3 + 1;//gap=gap/2;
		for (int i = 0; i < size; i++)
		{
			int k = a[i];
			int j;
			for (j = i - gap; j >= 0 && k < a[j]; j -= gap)
			{
				a[j + gap] = a[j];
			}
			a[j + gap] = k;
		}
		if (gap == 1)
		{
			break;
		}
	}
}




//选择排序
void selectsort(int a[], int size)
{
	int left = 0;
	int right = size - 1;

	//无序区间是[left,right]
	//无序区间内只剩1个数或者没有数
	while (left < right)
	{
		//无序区间内最大最小
		int min = left;
		int max = left;
		for (int i = left + 1; i <= right; i++)
		{
			if (a[i] < a[min])
			{
				min = i;
			}
			if (a[i] > a[max])
			{
				max = i;
			}
		}
		swap(&a[min], &a[left]);//等于（a+min，a+left）最小的数和无序区间的第一个数交换
		if (max == left)
		{
			max = min;
		}
		swap(a + max, a + right);//最大的数和最后一个数交换
		left++;
		right--;
	}
}



//堆排序
//向下调整  建大堆
void heapify(int a[], int size, int index)//index是堆顶元素
{
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	if (left >= size)
	{
		return;
	}
	int max = left;//假设最大的数是左子树
	if (right<size&&a[right]>a[left])//如果右子树的值大于左子树的值，则最大的数为右子树
	{
		max = right;
	}
	if (a[index] >= a[max])//如果堆顶元素大于左右子节点，返回
	{
		return;
	}
	swap(a + index, a + max);//交换最大子节点的位置
	heapify(a, size, max);
}


//建堆
void createHeap(int a[], int size)
{
	//从最后一个非子节点开始遍历
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		heapify(a, size, i);
	}
}


void heapSort(int a[], int size)
{
	createHeap(a, size);
	for (int i = 0; i < size; i++)
	{
		swap(a, a + size - 1 - i);//堆顶元素和无序区间的最后一个数交换
		heapify(a, size - 1 - i, 0);
	}
}

//冒泡排序

void bubbleSort(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int sort = 1;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a + j, a + j + 1);

				sort = 0;
			}
		}
		if (sort == 1)
		{
			break;
		}
	}
}
//快速排序


//找基准值
int partition1(int a[], int left, int right)
{
	int begin = left;
	int end = right;
	int pivot = a[right];
	while (begin < end)
	{
		while (begin < end&&a[begin] <= pivot)
		{
			begin++;
		}
		while (begin < end&&a[end] >= pivot)
		{
			end--;
		}
		swap(a + begin, a + end);
	}
	swap(a + begin, a + right);
	return begin;
}

int partition2(int a[], int left, int right)
{
	int begin = left;
	int end = right;
	int pivot = a[right];
	while (begin < end)
	{
		while (begin < end&&a[begin] <= pivot)
		{
			begin++;
		}
		a[end] = a[begin];
		while (begin < end&&a[end] >= pivot)
		{
			end--;
		}
		a[begin] = a[end];
	}
	a[begin] = pivot;
	return begin;
}

int partition3(int a[], int left, int right)
{
	int div = left;
	int i = left;
	for (i = left; i < right; i++)
	{
		if (a[i] < a[right])
		{
			swap(a + i, a + div);
			div++;
		}
	}
	swap(a + div, a + right);
	return div;
}
//待排序区间
void quickSortTnternal(int a[], int left, int right)
{
	if (left >= right)
	{
		//[left,right]区间内只剩1个或者0个数
		return;
	}
	//1.确定基准值，最右边 a[right]
	//2.做partition，小的左，大的右，返回基准值最终得下标
	int pivotIndex = partition3(a, left, right);
	//3.分治处理左右两个小区间
	quickSortTnternal(a, left, pivotIndex - 1);
	quickSortTnternal(a, pivotIndex + 1, right);
}

//非递归
void quickSortNoR(int a[], int left, int right)
{
	std::stack<int> s;
	s.push(left);
	s.push(right);
	while (!s.empty())
	{
		int high = s.top();
		s.pop();
		int low = s.top();
		s.pop();
		if (low >= high)
		{
			continue;
		}
		int pivotIndex = partition3(a, low, high);
		s.push(pivotIndex + 1);
		s.push(high);
		s.push(low);
		s.push(pivotIndex - 1);
	}
}
void quickSort(int a[], int size)
{
	quickSortNoR(a, 0, size - 1);
}

//归并
void MergeData(int  a[], int left, int mid, int right, int *temp)
{
	int begin1 = left, end1 = mid;
	int begin2 = mid, end2 = right;
	int index = left;//临时空间的最左边
	while (begin1 < end1&&begin1 < end2)//说明两个区间内都有元素
	{
		if (a[begin1] <= a[begin2])//升序
		{
			temp[index++] = a[begin1++];//搬移左边区间元素
		}
		else
		{
			temp[index++] = a[begin2++];//搬移右边区间元素
		}
	}
	while (begin1 < end1)
	{
		temp[index++] = a[begin1++];
	}
	while (begin2 < end2)
	{
		temp[index++] = a[begin2++];
	}
}





//归并排序
void _MergeSort(int a[], int left, int right, int* temp)
{
	//只有一个元素
	if (right - left <= 1)
	{
		return;
	}
	//先找中间位置
	int mid = (left+((right - left) >> 1));
	//[0,mid)[mid,size)
	_MergeSort(a, left, mid,temp);
	_MergeSort(a, mid, right, temp);
	MergeData(a, left, mid, right, temp);//归并
	memcpy(a + left, temp + left, (right - left) * sizeof(a[0]));
}

void MergeSort(int a[], int size)
{
	int *temp = (int *)malloc(sizeof(a[0])*size);
	if (temp == NULL)
	{
		return;
	}
	_MergeSort(a, 0, size, temp);
	free(temp);
}

//非递归归并排序
void MergeSortNor(int a[], int size)
{
	int *temp = (int *)malloc(sizeof(a[0])*size);
	if (temp == NULL)
	{
		return;
	}
	int gap = 1;
	while (gap < size)
	{
		for (int i = 0; i < size; i+=2*gap)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;
			if (mid >= size)
			{
				mid = size;
			}
			if (right >= size)
			{
				right = size;
			}
			MergeData(a, left, mid, right, temp);
		}
		memcpy(a, temp, size * sizeof(a[0]));
		gap *= 2;
	}
	
	free(temp);
}
//非比较排序
//计数排序
/*
适合场景：数据密集的出现在某一个范围里

1、统计每个数据出现的次数
    count[a[i]]++;
2、对数据进行回收（排序）
   将计数的数组遍历一遍--->取到一个计数
*/
void CountSort(int a[], int size)
{
	//1、计算数据范围
	int minValue = a[0];
	int maxValue = a[0];
	for (int i = 0; i < size; ++i)
	{
		if (a[i] < minValue)
		{
			minValue = a[i];
		}
		if (a[i] > maxValue)
		{
			maxValue = a[i];
		}
	}
	//2、获取计数的空间
	int range = maxValue - minValue + 1;
	int *temp = (int *)malloc(range * sizeof(int));
	if (NULL == temp)
	{
		return;
	}
	//3、统计每个元素出现的次数
	memset(temp, 0, sizeof(int)*range);//初始化为0，否则为随机值
	for (int i = 0; i < size; ++i)
	{
		temp[a[i] - minValue]++;
	}
	//4、回收
	int index = 0;
	for (int i = 0; i < range; ++i)
	{
		while (temp[i])
		{
			a[index++] = i + minValue;
			temp[i]--;
		}
	}
	free(temp);
}
int main() {
	int a[] = { 1,9,2,8,3,7,4,6,5 };
	int size = sizeof(a) / sizeof(int);
	//直接插入排序
	insertSort(a, size);
	printArray(a, size);
	//希尔排序
	shellSort(a, size);
	printArray(a, size);
	//选择排序
	selectsort(a, size);
	printArray(a, size);
	//堆排序
	heapSort(a, size);
	printArray(a, size);
	//冒泡排序
	bubbleSort(a, size);
	printArray(a, size);
	//快速排序
	quickSort(a, size);
	printArray(a, size);
	//归并排序
	MergeSort(a, size);
	printArray(a, size);
	//计数排序
	CountSort(a, size);
	printArray(a, size);
	//非递归归并排序
	//MergeSortNor(a, size);
	//printArray(a, size);
	system("pause");
	return 0;
}