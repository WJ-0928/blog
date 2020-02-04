#pragma once

#if 0
//复杂链表
typedef struct CNode
{
	int val;
	struct CNode *next;
	struct CNode *random;
} CNode;
//普通链表
typedef struct Node
{
	int val;
	struct Node *next;
}Node;
//队列
typedef struct Queue 
{
    Node *front;	// head;
    Node *rear;	    // last;
}Queue;

//栈
typedef struct Stack
{
	int array[100];//capacity
	int top;//size
}Stack;


//拷贝复杂链表
CNode * copy(CNode *head);
//创造结点
Node *createNode(int val);
//栈初始化
void StackInit(Stack *s);
//压栈
void StackPush(Stack *s,int val);
//出栈
int StackPop(Stack *s);
//查看栈顶元素
int StackTop(Stack *s);
//查看栈的大小
int StackSize(Stack *s);
//判断栈是否为空
int StackEmpty(Stack *s);
//队列初始化
void QueueInit(Queue *q);
//队列插入
void QueuePush(Queue *q, int val);
//队列删除
int QueuePop(Queue *q);
//队列首元素
int QueueFront(Queue *q);

//括号匹配问题
#endif
typedef struct Stack
{
	int a[100];
	int top;//栈顶
}Stack;
typedef struct Stack
{
	int* _array;
	int _capacity;
	int _top; // 标记栈顶位置 
}Stack;

// 初始化栈 
void StackInit(Stack* ps);

// 入栈 
void StackPush(Stack* ps, int data);

// 出栈 
void StackPop(Stack* ps);

// 获取栈顶元素 
int StackTop(Stack* ps);

// 获取栈中有效元素个数 
int StackSize(Stack* ps);

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps);

// 销毁栈 
void StackDestroy(Stack* ps);


// 链式结构：表示队列 
typedef struct QListNode
{
	struct QListNode* _pNext;
	int _data;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

// 初始化队列 
void QueueInit(Queue* q);

// 队尾入队列 
void QueuePush(Queue* q, int data);

// 队头出队列 
void QueuePop(Queue* q);
// 获取队列头部元素 
int QueueFront(Queue* q);

// 获取队列队尾元素 
int QueueBack(Queue* q);

// 获取队列中有效元素个数 
int QueueSize(Queue* q);

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q);

// 销毁队列 
void QueueDestroy(Queue* q);


