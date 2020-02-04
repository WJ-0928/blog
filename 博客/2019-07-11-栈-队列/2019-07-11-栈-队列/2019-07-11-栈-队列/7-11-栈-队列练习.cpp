#include"7-11My.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<cstring>
#include<stack>
#include<queue>

//拷贝复杂链表
CNode * copy(CNode *head)
{
	if (head == NULL)
	{
		return NULL;
	}
	CNode *cur = head;
	while (cur != NULL)
	{
		CNode *node = (CNode *)malloc(sizeof(CNode));
		node->val = cur->val;
		node->next = cur->next;
		cur->next = node;
		cur = node->next;
	}
	cur = head;
	while (cur != NULL)
	{
		if (cur->random != NULL)
		{
			cur->next->random = cur->random->next;
		}
		else
		{
			cur->next->random = NULL;
		}
		cur = cur->next->next;
	}
	cur = head;
	CNode *newHead = head->next;
	while (cur != NULL)
	{
		CNode *node = cur->next;
		cur->next = node->next;
		if (node->next != NULL)
		{
			node->next = node->next->next;
		}
		cur = cur->next;
	}
	return newHead;
}


//创造结点
Node *createNode(int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	return node;
}

//栈初始化
void StackInit(Stack *s)
{
	s->top = 0;
}
//压栈
void StackPush(Stack *s, int val)
{
	s->array[s->top++] = val;
}
//出栈
int StackPop(Stack *s)
{
	assert(s->top > 0);
	return s->array[--s->top];
}
//查看栈顶元素
int StackTop(Stack *s)
{
	return s->array[s->top-1];
}
//查看栈的大小
int StackSize(Stack *s)
{
	return s->top;
}
//判断栈是否为空
int StackEmpty(Stack *s)
{
	return s->top == 0 ? 1 : 0;
}


/*
队列（先进先出 FIFO)

1.普通顺序表  必须有个O(n)
2.出队列后不移动  空间越来越小
   1）循环队列   把指示下表循环起来
   2）插入到最后时，统一搬移，减少搬移频率
*/


//队列初始化
void QueueInit(Queue *q)
{
	q->front = q->rear = NULL;
}
//队列插入
void QueuePush(Queue *q, int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	if (q->front == NULL)
	{
		q->front = node;
	}
	else
	{
		q->rear->next = node;
	}
	q->rear = node;
}
//队列删除
int QueuePop(Queue *q)
{
	assert(q->front != NULL);
	Node *second = q->front->next;
	int val = q->front->val;
	free(q->front);
	q->front = second;

	if (q->front == NULL) {
		q->rear = NULL;
	}

	return val;
}
//队列首元素
int QueueFront(Queue *q)
{
	assert(q->front != NULL);
	return q->front->val;
}

//括号匹配问题
class Solution
{
public:
	bool isValid(string str)
	{
		std::stack<char>  s;
		int size = str.size();//取字符串长度
		for (int i = 0; i < size; i++)
		{
			char ch = str[i];//取i的字符
			switch (ch)
			{
			case '(':case '[':case '{':
				s.push(ch);
				break;
			case ')':case ']':case'}':
			{
				if (s.empty())
				{
					return false;
				}
				char left = s.top();
				s.pop();
				if (!((left == '(' && ch == ')')
					|| (left == '[' && ch == ']')
					|| (left == '{' && ch == '}'))) {
					return false;
				}
				break;
			}
			default:
				break;
			}
		}
		if (!s.empty())
	    {
		     return false;
	    }
	    return true;
	}
	
};

//队列实现栈
class Mystack
{
	std::queue<int> q;//队列结构体
public:
	Mystack(){}//构造方法
	void push(int x)
	{
		q.push(x);
	}
	int pop()
	{
		int n = q.size();
		for (int i = 0; i < n - 1; i++)
		{
			int v = q.front();
			q.pop();
			q.push(v);
		}
		int v = q.front();
		q.pop();
		return v;
	}
	int top()
	{
		int n = q.size();
		for (int i = 0; i < n - 1; i++)
		{
			int v = q.front();
			q.pop();
			q.push(v);
		}
		int v = q.front();
		q.pop();
		q.push(v);
		return v;
	}
	bool empty()
	{
		return q.empty();
	}
};

//用栈实现队列
class MyQueue
{
	std::stack<int> in;
	std::stack<int> out;
public:
	MyQueue() {}
	void push(int x)
	{
		in.push(x);
	}
	int pop()
	{
		if (out.empty())
		{
			int n = in.size();
			for (int i = 0; i < n; i++)
			{
				int v = in.top();
				in.pop();
				out.push(v);
			}
		}
		int v = out.top();
		out.pop();
		return v;
	}
	int peek()
	{
		if (out.empty())
		{
			while (!in.empty())
			{
				int v = in.top();
				in.pop();
				out.push(v);
			}
		}
		int v = out.top();
		return v;
	}
	bool empty()
	{
		return in.empty() && out.empty();
	}

};



//实现一个最小栈

class MinStack
{
public:
	std::stack<int> normal;
	std::stack<int> min;

	MinStack(){}
	void push(int x)//push(x) -- 将元素 x 推入栈中。
	{
		normal.push(x);
		if (min.empty() || x <= min.top())
		{
			min.push(x);
		}
		else
		{
			min.push(min.top());
		}
	}
	void pop()//pop() -- 删除栈顶的元素。
	{
		normal.pop();
		min.pop();
	}
	int top()//top() -- 获取栈顶元素。
	{
		return normal.top();
	}
	int getMin()//getMin() -- 检索栈中的最小元素。
	{
		return min.top();
	}

};



//设计循环队列
class MyCircularQueue {
	int *array;
	int capacity;
	int front;
	int rear;
	int size;

public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) //构造器，设置队列长度为 k 。
	{
		array = (int *)malloc(sizeof(int)*k);
		capacity = k;
		front = 0;
		rear = 0;
		size = 0;
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value)//向循环队列插入一个元素。如果成功插入则返回真。
	{
		if (size >= capacity)
		{
			return false;
		}
		array[rear] = value;
		rear = (rear + 1) % capacity;
		size++;
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue()//从循环队列中删除一个元素。如果成功删除则返回真
	{
		if (size == 0)
		{
			return false;
		}
		front = (front + 1) % capacity;
		size--;
		return true;
	}

	/** Get the front item from the queue. */
	int Front()//从队首获取元素。如果队列为空，返回 - 1 。
	{
		if (size == 0)
		{
			return -1;
		}
		return array[front];
	}

	/** Get the last item from the queue. */
	int Rear() //获取队尾元素。如果队列为空，返回 -1 。
	{
		if (size == 0)
		{
			return -1;
		}
		int index = (rear + capacity - 1) % capacity;
		return array[index];
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() // 检查循环队列是否为空。
	{
		return size == 0;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() //检查循环队列是否已满。
	{
		return size == capacity;
	}
}