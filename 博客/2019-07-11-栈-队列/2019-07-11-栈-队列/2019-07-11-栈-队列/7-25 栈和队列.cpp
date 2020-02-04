#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<queue>
#include<stack>

#if 0
typedef struct Stack
{
	int* _array;
	int _capacity;
	int _top; // 标记栈顶位置 
}Stack;

// 初始化栈 
void StackInit(Stack* ps)
{
	ps->_top = 0;
}

// 入栈 
void StackPush(Stack* ps, int data)
{
	ps->_array[ps->_top++] = data;
}

// 出栈 
void StackPop(Stack* ps)
{
	assert(ps->_top > 0);
	ps->_array[--ps->_top];
}

// 获取栈顶元素 
int StackTop(Stack* ps)
{
	assert(ps->_top > 0);
	return ps->_array[ps->_top-1];
}

// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	return ps->_array[ps->_top];
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	return ps->_top == 0 ? 1 : 0;
}

// 销毁栈 
void StackDestroy(Stack* ps)
{
	assert(ps);

	if (ps->_array == NULL)
	{
		return;
	}
	ps->_capacity = 0;
	ps->_top = 0;
	free(ps->_array);
	ps->_array = NULL;
	ps = NULL;

}


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
void QueueInit(Queue* q)
{
	q->_rear=q->_front = NULL;
}

// 队尾入队列 
void QueuePush(Queue* q, int data)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = data;
	if (q->_front == NULL)
	{
		q->_front =node;
	}
	else
	{
		q->_rear->_pNext = node;
	}
	q->_rear = node;
}

// 队头出队列 
void QueuePop(Queue* q)
{

	assert(q);
	if (NULL == q->_front)
	{
		return;
	}
	//一个元素
	if (NULL == q->_front->_pNext)
	{
		q->_front = NULL;
		free(q->_front);
		return;
	}
	//多个元素
	else
	{
		q->_front = q->_front->_pNext;
	}
	free(q->_front->_pNext);
	q->_front->_pNext = NULL;
}

// 获取队列头部元素 
int QueueFront(Queue* q)
{
	assert(q->_front != NULL);
	return q->_front->_data;
}

// 获取队列队尾元素 
int QueueBack(Queue* q)
{
	assert(q->_front != NULL);
	return q->_rear->_data;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q->_front != NULL);
	int count = 0;
	while (q->_front!=NULL)
	{
		count++;
		q->_front = q->_front->_pNext;
	}
	return count;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	return q->_front == NULL ? 1 : 0;
}

// 销毁队列 
void QueueDestroy(Queue* q)
{
	while (q->_front != NULL)
	{
		q->_rear = q->_front->_pNext;
		free(q->_front);
		q->_front = q->_rear;
	}
}




//用队列实现栈
class MyStack {
	std::queue<int> q;
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		q.push(x);

	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int n = q.size();
		for (int i = 0; i < n-1; i++)
		{
			int v = q.front();
			q.pop();
			q.push(v);
		}
		int v = q.front();
		q.pop();
		return v;
	}

	/** Get the top element. */
	int top() {
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

	/** Returns whether the stack is empty. */
	bool empty() {
		return q.empty();
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

//有效括号
class Solution {
public:
	bool isValid(string s) {
		std::stack<char> str;
		int size = s.size();
		for (int i = 0; i < size; i++)
		{
			char ch = s[i];
			switch (ch)
			{
			case '(':case '[':case '{':

				str.push(ch);
				break;
			case ')':case ']':case'}':
			{
				if (str.empty())
				{
					return false;
				}
				char left = str.top();
				str.pop();
				if (!((left == '('&&ch == ')')
					|| (left == '['&&ch == ']')
					|| (left == '{'&&ch == '}')))
				{
					return false;
				}
				break;
			}
			default:
				break;
			}
		}
		if (!str.empty())
	    {
			return false;
	     }
		return true;
	}
	
};
#endif




//栈实现队列
class MyQueue {
	std::stack<int> in;
	std::stack<int> out;
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		in.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
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

	/** Get the front element. */
	int peek() {
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

	/** Returns whether the queue is empty. */
	bool empty() {
		return in.empty() && out.empty();
	}
};


//最小栈
class MinStack {
	
public:
	std::stack<int> normal;
	std::stack<int> min;
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		normal.push(x);
		if (min.empty() || x < min.top())
		{
			min.push(x);
		}
		else
		{
			min.push(min.top());
		}
	}

	void pop() {
		normal.pop();
		min.pop();
	}

	int top() {
		return normal.top();
	}

	int getMin() {
		return min.top();
	}
};
