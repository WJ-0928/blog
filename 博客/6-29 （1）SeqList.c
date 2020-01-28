#if 0

#include"6-29(1)SeqList.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define DEFAULT_CAPACITY (16)

//扩容

//static连接属性
//从外部链接属性更改为内部连接属性
//1.static修饰局部变量，影响它的申明周期（从函数的执行变成整个进程期间）
//2.static修饰全局变量，影响它的链接属性（从外部变成内部）
//3.static修饰函数，影响它的链接属性（从外部变成内部）
//时间复杂度O（n）
static void ensureCapacity(SeqList *seq)
{
	if (seq->capacity > seq->size)
	{
		//容量够用
		return;
	}
	//1.找新房子
	//通常来说，新申请的房子是原来的1.5或2倍
	int *newArray = (int *)malloc(sizeof(int)*seq->capacity * 2);
	//2.全家老小搬家
	for (int i = 0; i < seq->size; i++)
	{
		newArray[i]=seq->array[i];
	}
	//3.退掉老房子
	free(seq->array);
	//4.发朋友圈
	seq->array = newArray;
}
//初始化

void SeqListInit(SeqList *seq)
{
	//申请个教室并记录
	//记录教室的容量
	//size=0;
	seq->array = (int *)malloc(sizeof(int)*DEFAULT_CAPACITY);
	seq->capacity = DEFAULT_CAPACITY;
	seq->size = 0;
}
//销毁

void SeqListDestroy(SeqList *seq)
{
	free(seq->array);
	//下面属于可加可不加
	seq->capacity = 0;
	seq->size = 0;
}
//头插 O(n) 
void SeqListPushFront(SeqList *seq, int val)
{
	for (int i = seq->size - 1; i >= 0; i--)
	{
		seq->array[i + 1] = seq->array[i];
	}
	seq->array[0] = val;
	seq->size++;
}
//尾插 
//O(1) 平均
//如果发生扩容就是O(n)
//如果没有扩容就是O(1)
void SeqListPushBack(SeqList *seq, int val)
{
	//先不考虑放不下的问题
	seq->array[seq->size] = val;
	seq->size++;
}

//根据下标做插

void SeqListInsert(SeqList *seq, int index, int val)
{
	if (index < 0 || index >= seq->size)
	{
		printf("下标不合法");
		return;
	}
	ensureCapacity(seq);
	for (int i = seq->size - 1; i >= index; i--)
	{
		seq->array[i + 1] = seq->array[i];
	}
	seq->array[index] = val;
	seq->size++;
}

//头删
void SeqListPopFront(SeqList *seq)
{
	assert(seq->size > 0);
	for (int i =0; i <= seq->size-2; i++)
	{
		seq->array[i] = seq->array[i + 1];
	}
	seq->size--;
}
//尾删
void SeqListPopBack(SeqList *seq)
{
	//函数调用合法性的校验
	/*
	if (seq->size <= 0)
	{
		printf("空的\n");
		return;
	}
	*/
	assert(seq->size > 0);
	seq->size--;
}
//根据下标做删除
void SeqListErase(SeqList *seq, int index)
{
	assert(seq->size > 0);
	for (int i = index; i <=seq->size-2; i++) 
	{
		seq->array[i] = seq->array[i + 1];
	}
	seq->size--;
}

//查找
int SeqListFind(SeqList *seq, int val)
{
	for (int i = 0; i < seq->size; i++)
	{
		if (seq->array[i] == val)
		{
			return i;
		}
	}
	return -1;
}
//打印
void SeqListPrint(SeqList *seq)
{
	for (int i = 0; i < seq->size; i++)
	{
		printf("%d ", seq->array[i]);
	 }
	printf("\n");
}

//删除顺序表中第一个遇到的val
void SeqListRemove(SeqList *seq, int val)
{
	int index = SeqListFind(seq, val);
	if (index != -1)
	{
		SeqListErase(seq, index);
	}
}


//删除顺序表中所有的val
void SeqListRemoveAll(SeqList *seq, int val)
{
#if 0
	int index;

	//O(n^2)
	//O(n)
	while ((index = SeqListFind(seq, val)) != -1)
	{
		//O(n)
		SeqListErase(seq, index);
	}
#endif
#if 0
	//你可以用到额外的空间，时间上快一点
	//空间复杂度O(n）
	int *extra = (int *)malloc(sizeof(int)*seq->size);
	int j = 0;
	//时间复杂度O(n) 
	for (int i = 0; i < seq->size; i++)
	{
		if (seq->array[i] != val)
		{
			extra[j++] = seq->array[i];
		}
	}
	//删完之后，顺序表中还有多少个数？   j个数
	free(seq->array);
	seq->array = extra;
	seq->size = j;
#endif
	//时间复杂度O(n)  空间复杂度O(1)
	int j = 0;
	for (int i = 0; i < seq->size; i++)
	{
		if (seq->array[i] != val)
		{
			seq->array[j++] = seq->array[i];
		}
	}
	seq->size = j;
}
#endif