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
		//�ó�����ת��ָ��λ�ã�buff����ǵ�λ�ã�setjmp��������λ�ã�
		//longjmp������1---��תλ��
		//         ����2---�������ִ������ͣ�state
		longjmp(buff, 2);
	}
	//...
	free(p);
}

int main()
{
	//setjmp�������״ε��ã�����longjmp����ת��buff
	//buff���м�¼��ǰλ�ó����мĴ���״̬��Ϣ
	//��һ�ε���ʱ���ú���һ������0
	int state = setjmp(buff);
	if (state == 0)
	{
		//��������
		Func1();
		Func2();
	}
	else
	{
		//�Ƿ����
		switch (state)
		{
		case 1:
			printf("�ļ���ʧ�� \n");
			break;
		case 2:
			printf("malloc����ռ�ʧ��\n");
			break;
		default:
			printf("δ֪����\n");
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
		//throw�������쳣�׳���
		//ע�⣺����Դ����׳����쳣���в��񣬷��򣺴���ᱼ��
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
		//���п��ܻ��׳��쳣�Ĵ��룬�������try����
		Func1();
		Func2();
	}
	catch (int err)//�����б�
	{
		//�쳣����λ��
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

//�쳣�����׳�
void Func2()
{
	int* p = new int[10];
	try
	{
		Func1();
	}
	catch (...)
	{
		//1�����ܲ�֪��Func1()�����׳�ʲô���͵��쳣
		//2��������Func2()�����׳�ʲô���͵��쳣
		delete[] p;

		//��Func1�е��쳣�����׳�
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
// �����ʾ����������׳�A/B/C/D�е�ĳ�����͵��쳣
void fun() throw(A��B��C��D);
// �����ʾ�������ֻ���׳�bad_alloc���쳣
void fun(std::size_t size) throw (std::bad_alloc);
// �����ʾ������������׳��쳣
void fun(int size, void* ptr) throw();
#endif