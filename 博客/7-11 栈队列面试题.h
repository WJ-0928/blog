#if 0

#pragma once
#include<stdio.h>
#include<cstring>
#include<stack>


//判断字符串是否有效，括号匹配问题
class solution
{
public:
	bool isValid(string s)
	{
		std::stack<char>     s;
		int size = str.size();
		for (int i = 0; i < size; i++)
		{
			char ch = str[i];
			switch (ch)
			{
			case'(': case'[':case'{':
				s.push(ch);//入栈
				break;
			case')':case']':case'}':
			{
				if (s.empty())
				{
					return false;
				}
				char left = s.top();
				s.pop();
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
	if (!s.empty())//栈不为空
	{
		return false;
	}
	return true;
 	}
	
};



//用队列实现栈

/*
压栈
    数据进队列
出栈
     （首先把前（n-1)个数据从队列进队列），把当前队首数据出去
查看栈顶元素
       首先把n-1....，准备返回就是队首元素，队首元素出队列入队列
判断栈是否为空
      队列空
*/

class Mystack
{
	std::queue<int>    q;
public:
	Mystack() {}
	void push(int x) { q.push(x); }//入栈、压栈
	int pop()//出栈
	{
		int n = q.size();
		for (int i = 0; i < n - 1; i++)
		{
			int v = q.ftont();
			q.pop();
			q.push(v);
		}
		int v = q.front;
		q.pop();
		return v;
	}
	int top()//查看栈顶元素
	{
		int n = q.size();
		for (int i = 0; i < n - 1; i++)
		{
			int v = q.ftont();
			q.pop();
			q.push(v);
		}
		int v = q.front;
		q.pop();
		q.push(v);//只看一眼不出栈
		return v;

	}
	bool empty()//判断栈是否为空
	{
		return q.empty();//队列为空，栈就为空
	}
};



//用栈实现队列

class MyQueue
{
	std::stack<int>  in;
	std::stack<int>  out;
public:
	MyQueue(){}
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
#endif