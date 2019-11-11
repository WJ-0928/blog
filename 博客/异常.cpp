#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;

#if 0

#include<stdio.h>
#include<setjmp.h>
#include<stdlib.h>
jmp_buf buff;

void Func1()
{
	FILE* pf = fopen("333.txt", "rb");
	if (nullptr == pf)
	{
		longjmp(buff, 1);
	}
	//...
	fclose(pf);
}
void Func2()
{
	char* p = (char*)malloc(0x7fffffff);
	if (p == nullptr)
	{
		//让程序跳转到指定位置，buff所标记的位置（setjmp函数调用位置）
		//longjmp：参数1---跳转位置
		//         参数2---用来区分错误类型，state
		longjmp(buff, 2);
	}
	//...
	free(p);
}

int main()
{
	//setjmp函数在首次调用：设置longjmp的跳转点buff
	//buff：中记录当前位置程序中寄存器状态信息
	//第一次调用时，该函数一定返回0
	int state = setjmp(buff);
	if (state == 0)
	{
		//正常流程
		Func1();
		Func2();
	}
	else
	{
		//非法情况
		switch (state)
		{
		case 1:
			printf("文件打开失败 \n");
			break;
		case 2:
			printf("malloc申请空间失败\n");
			break;
		default:
			printf("未知错误\n");
		}
	}
	return 0;
}
#endif

#if 0
void Func1()
{
	FILE* pf = fopen("333.txt", "rb");
	if (nullptr == pf)
	{
		//throw将该种异常抛出，
		//注意：必须对代码抛出的异常进行捕获，否则：代码会奔溃
		throw 1;
	}
	//...
	fclose(pf);
}
void Func2()
{
	char* p = (char*)malloc(0x7fffffff);
	if (p == nullptr)
	{
		throw '2';
	}
	//...
	free(p);
}

int main()
{
	try
	{
		//对有可能会抛出异常的代码，必须放在try块中
		Func1();
		Func2();
	}
	catch (int err)//捕获列表
	{
		//异常处理位置
		cout << err << endl;
	}
	catch(char err)
	{
		cout << err << endl;
	}
	return 0;
}
#endif

#if 0
void Func1()
{
	throw 1;
}
void Func2()
{
	Func1();
}
void Func3()
{
	Func2();
}
void Func4()
{
	Func3();
}
int main()
{
	try
	{
		Func4();
	}
	catch (int err)
	{
		cout << err << endl;
	}
	return 0;
}
#endif

#if 0
void Func1()
{
	FILE* pf = fopen("333.txt", "rb");
	if (nullptr == pf)
	{
		throw 1;
	}
	//...
	fclose(pf);
}

//异常重新抛出
void Func2()
{
	int* p = new int[10];
	try
	{
		Func1();
	}
	catch (...)
	{
		//1、可能不知道Func1()函数抛出什么类型的异常
		//2、不关心Func2()到底抛出什么类型的异常
		delete[] p;

		//将Func1中的异常继续抛出
		throw;
	}

	//...
	delete[] p;
}
int main()
{
	try { 
		Func2();
	}
	catch (int err)
	{
		cout << err << endl;
	}
	return 0;
}
#endif
#if 0
// 这里表示这个函数会抛出A/B/C/D中的某种类型的异常
void fun() throw(A，B，C，D);
// 这里表示这个函数只会抛出bad_alloc的异常
void fun(std::size_t size) throw (std::bad_alloc);
// 这里表示这个函数不会抛出异常
void fun(int size, void* ptr) throw();
#endif