#include "SeqList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DEFAULT_CAPACITY (16)

// 链接属性
// 从外部链接属性更改为内部链接属性
// 1. static 修饰局部变量，影响它的声明周期（从函数的执行变成整个进程期间）
// 2. static 修饰全局变量，影响它的链接属性（从外部变成内部）
// 3. static 修饰函数，影响它的链接属性（从外部变成内部）
// 时间复杂度 O(n)
static void ensureCapacity(SeqList *seq) {
	if (seq->size < seq->capacity) {
		// 容量够用
		return;
	}

	// 1. 找新房子
	// 通常来说，新申请的房子是原来的 1.5 或者 2 倍
	int newCapacity = 2 * seq->capacity;
	int *newArray = (int *)malloc(sizeof(int)* newCapacity);
	// 2. 全家老小搬家
	for (int i = 0; i < seq->size; i++) {
		newArray[i] = seq->array[i];
	}
	// 3. 退掉老房子
	free(seq->array);
	// 4. 发朋友圈
	seq->array = newArray;
}

// 初始化
// O(1)
void SeqListInit(SeqList *seq) {
	// 申请个教室并记录
	// 记录教室的容量
	// size = 0

	seq->array = (int *)malloc(sizeof(int)* DEFAULT_CAPACITY);
	seq->capacity = DEFAULT_CAPACITY;
	seq->size = 0;
}

// 销毁
// O(1)
void SeqListDestroy(SeqList *seq) {
	free(seq->array);
	// 下面的属于可加可不加
	seq->capacity = 0;
	seq->size = 0;
}

// 头插
// O(n)
void SeqListPushFront(SeqList *seq, int val) {
	/*
	for (int i = seq->size - 1; i >= 0; i--) {
		seq->array[i + 1] = seq->array[i];
	}

	seq->array[0] = val;
	seq->size++;
	*/
	SeqListInsert(seq, 0, val);
}
// 尾插
// O(1)	平均
// 如果发生扩容就是 O(n)
// 如果没有扩容就是 O(1)
void SeqListPushBack(SeqList *seq, int val) {
	// 先不考虑放不下的问题
#if 0
	seq->array[seq->size] = val;
	seq->size++;
#endif
	SeqListInsert(seq, seq->size, val);
}

// O(n)	头插
void SeqListInsert(SeqList *seq, int index, int val) {
	if (index < 0 || index > seq->size) {
		printf("下标不合法");
		return;
	}

	ensureCapacity(seq);

	for (int i = seq->size; i > index; i--) {
		seq->array[i] = seq->array[i - 1];
	}

	seq->array[index] = val;
	seq->size++;
}

// 头删
void SeqListPopFront(SeqList *seq) {
	assert(seq->size > 0);
	for (int i = 0; i <= seq->size - 2; i++) {
		seq->array[i] = seq->array[i + 1];
	}
	seq->size--;
}

// 尾删
void SeqListPopBack(SeqList *seq) {
	// 函数调用合法性的校验
	assert(seq->size > 0);
	seq->size--;
}

// 根据下标做删除
void SeqListErase(SeqList *seq, int index) {
	assert(seq->size > 0);

	for (int i = index; i <= seq->size - 2; i++) {
		seq->array[i] = seq->array[i + 1];
	}

	seq->size--;
}

// 打印
void SeqListPrint(SeqList *seq) {
	for (int i = 0; i < seq->size; i++) {
		printf("%d, ", seq->array[i]);
	}
	printf("\n");
}

int SeqListFind(SeqList *seq, int val) {
	for (int i = 0; i < seq->size; i++) {
		if (seq->array[i] == val) {
			return i;
		}
	}

	return -1;
}

// 删除顺序表中第一个遇到的 val
void SeqListRemove(SeqList *seq, int val) {
	int index = SeqListFind(seq, val);
	if (index != -1) {
		SeqListErase(seq, index);
	}
}

// 删除顺序表中的所有 val
void SeqListRemoveAll(SeqList *seq, int val) {
#if 0
	int index;

	// O(n^2)
	// O(n)
	while ((index = SeqListFind(seq, val)) != -1) {
		// O(n)
		SeqListErase(seq, index);
	}
#endif

#if 0
	// 你可以用到额外的空间，时间上快点
	// 空间：O(n)
	int *extra = (int *)malloc(sizeof(int)* seq->size);
	int j = 0;
	// 时间：O(n)
	for (int i = 0; i < seq->size; i++) {
		if (seq->array[i] != val) {
			extra[j++] = seq->array[i];
		}
	}

	// 删完之后，顺序表中还剩多少个数？j 个数
	free(seq->array);
	seq->array = extra;
	seq->size = j;
#endif
	// 时间复杂度 O(n)	空间复杂度 O(1)
	int j = 0;
	for (int i = 0; i < seq->size; i++) {
		if (seq->array[i] != val) {
			seq->array[j++] = seq->array[i];
		}
	}

	seq->size = j;
}