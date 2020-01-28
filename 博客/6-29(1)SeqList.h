#pragma once//保证头文件只包含一次
#if 0
struct SeqList
{
	int *array;       //记录数据存放位置（教室的地址）
	int capacity;     //记录总容量      （教室的大小）
	int size;         //记录已有数据个数 （有同学在里面）
};
//为类型起一个别名
typedef struct SeqList SeqList;

//初始化

void SeqListInit(SeqList *seq);
//销毁

void SeqListDestroy(SeqList *seq);
//头插
void SeqListPushFront(SeqList *seq, int val);
//尾插
void SeqListPushBack(SeqList *seq, int val);
//根据下标做插入
void SeqListInsert(SeqList *seq, int index, int val);
//头删
void SeqListPopFront(SeqList *seq);
//尾删
void SeqListPopBack(SeqList *seq);
//根据下标做删除
void SeqListErase(SeqList *seq, int index);
//查找
int SeqListFind(SeqList *seq, int val);
//打印
void SeqListPrint(SeqList *seq);
//删除顺序表中第一个遇到的val
void SeqListRemove(SeqList *seq, int val);
//删除顺序表中所有的val
void SeqListRemoveAll(SeqList *seq, int val);
#endif