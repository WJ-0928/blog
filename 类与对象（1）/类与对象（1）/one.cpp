#include<iostream>
using namespace std;


#if 0
int a1 = 10;
int a2 = 20;//ȫ�ֱ���

int main()
{
	int a = 10;//�ֲ�����
	return 0;
}

#endif



#if 0
//�����ռ��е����ݣ��ȿ��Զ��������Ҳ���Զ��庯��
int a = 1;
namespace N1
{
	int a = 10;
	int b = 20;
	int Add(int left, int right)
	{
		return left + right;
	}
}

//�����ռ����Ƕ��
namespace N2
{
	int a = 30;
	int b = 40;

	int Sub(int left, int right)
	{
		return left - right;
	}
	namespace N3
	{
		int a = 40;
		int b = 50;
		int Mul(int left, int right)
		{
			return left*right;
		}
	}
}


int main()
{
	int a = 60;
	printf("%d\n", a);//�����������е�a
	printf("%d\n", ::a);//����ȫ�ֱ����е�a
	printf("%d\n", N1::a);//����N1�����ռ��е�a
	printf("%d\n", N2::N3::a);//����Ƕ�������ռ��е�a
	return 0;
}
#endif

#if 0
//�����ռ������ʹ�÷�����
//1��ֱ���ڳ�Աǰ�������ռ�����::
namespace N1
{
	int a = 10;
	int b = 20;

	int Add(int left, int right)
	{
		return left + right;
	}
}

//using N1::a;
int a = 10;

int main()
{
	printf("%d\n", N1::a);
	return 0;
}

#endif

#if 0
//2��ʹ��using�������ռ��г�Ա����
namespace N1
{
	int a = 10;
	int b = 20;
	int Add(int left, int right)
	{
		return left + right;
	}
}

using namespace N1;

int main()
{
	printf("%d\n", Add(a, b));
	return 0;
}
#endif

#if 0
// ���һ�������д��ڶ����ͬ���������ռ�ʱ���������Ὣ��ϳɲ�һ��
namespace N1
{
	int a = 10;
	int b = 20;

	int Add(int left, int right)
	{
		return left + right;
	}
}

namespace N1
{
	int c = 10;
	int d = 20;

	int Sub(int left, int right)
	{
		return left - right;
	}
}
#endif


#if 0
#include<iostream>
using namespace std;

int main()
{
	int a;
	double d;
	cin >> a;
	cin >> d;
	cout << a << " " << d << endl;

	cin >> a >> d;
	cout << a << " " << d << endl;

	cout << 10;
	cout << 12.34 << " " << 'A' << "\n";
	cout << "hello world" << endl;

	return 0;
}
#endif

/*
void TestFunc(int a = 10)
{
	cout << a << endl;
}

int main()
{
	TestFunc();
	TestFunc(100);
	return 0;
}
*/

#if 0
//ȫȱʡ���������в���������Ĭ��ֵ
void TestFunc(int a = 1, int b = 2, int c = 3)
{
	cout << a << " " << b << " " << c << endl;
}

int main()
{
	TestFunc();
	TestFunc(10);
	TestFunc(10, 20);
	TestFunc(10, 20, 30);
	return 0;
}
#endif

#if 0
//��ȱʡ���������ֲ�������Ĭ��ֵ  Ҫ��ֻ�ܴ����������
void TestFunc(int a, int b = 2, int c = 3)
{
	cout << a << " " << b << " " << c << endl;
}

int main()
{
	TestFunc(10);//10,2,3
	TestFunc(10, 20);//10,20,3
	TestFunc(10, 20, 30);//10,20,30
	return 0;
}
#endif

#if 0
//ȱʡ���������ٺ��������Ͷ�����ͬʱ����
//��������Ͷ���λ��ͬʱ���֣�ǡ������λ���ṩֵ��ͬ���Ǳ��������޷�ȷ�����׸�ʹ���Ǹ�ȱʡֵ
void TestFunc(int a = 10);
void TestFunc(int a = 20)
{
	cout << a << endl;
}

int main()
{
	TestFunc();
	return 0;
}
#endif

#if 0
//ȱʡֵ�����ǳ�������ȫ�ֱ���
int g_a = 30;
void TestFunc(int a);
void TestFunc(int a)
{
	cout << a << endl;
}
int main()
{
	TestFunc(10);//10
	return 0;
}

#endif

#if 0
//�������أ���������ͬ����������ͬ���ֵĺ�������������б�ͬ�����������͡����ʹ���
//�뷵��ֵ�����Ƿ���ͬ�޹�
int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

namespace N
{
	char Add(char left, char right)
	{
		return left + right;
	}
}

int main()
{
	//�������ڱ���׶Σ������ʵ�ε����ͽ������ݣ��������ݵ�ʵ�����͵Ľ��ѡ����ú��ʵĺ���

	Add(1, 2);
	Add(1.0, 2.0);
	return 0;
}

#endif

#if 0
//1
void TestFunc()
{}

//2��1�ǲ���������ͬ
//2
void TestFunc(int a)
{}

//3
void TestFunc(int a,double b)
{}

//3��4�ǲ�������ͬ
//4
void TestFunc(double a,int b)
{}

//2��5�ǲ������Ͳ�ͬ
//5
//int TestFunc(char a)
//{
//	return 0;
//}

//6
char TestFunc(char a)
{
	return a;
}

int main()
{
	int ret1 = TestFunc('a');
	char ret2 = TestFunc('b');
	TestFunc('c');
	return 0;
}
#endif


#if 0
//C���Ժ����������ι��򣺱�����ֻ���ں�������ǰ��_
//_Add
int Add(int left, int right);
{
	return left + right;
}

double Add(double left, double right);
{
	return left + right;
}
int main()
{
	Add(1, 2);
	return 0;
}
#endif


#if 0
int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;
}
double Add(int left, double right);
int main()
{
	Add(1, 2);
	Add(1.0, 2.0);
	Add(1, 2.0);
	return 0;
}
#endif

#if 0
//��C++������

//extern "C"���ã�����������C�ķ����б���

extern "C" int Add(int left, int right);//_Add

int main()
{
	Add(1, 2);//?Add@@YAHHH@Z
	return 0;
}
#endif

#if 0
//���벻��ͨ��
void TestFunc(int a=10)
{}

void TestFunc()
{}

int main()
{
	TestFunc();
	return 0;
}
#endif
#if 0

//��ֵ
//�ŵ㣺�Ժ����βεĸı䲻��Ӱ���ⲿ��ʵ��
//ȱ�㣺����ͨ���βθı��ⲿ��ʵ�Σ��˷ѿռ䣬���ʹ��������Ч��
struct SeqList
{
	int array[100000];
	int _size;
};

void Swap(int left, int right)
{
	int temp = left;
	left = right;
	right = temp;
}

//����ַ
//�ŵ㣺����ͨ���βθı��ⲿ��ʵ�Σ����ε�Ч��
//ȱ�㣺�����ĸ����û�Ӱ���ⲿ��ʵ�Σ�ָ�벻��ȫ�����ʹ���Ŀɶ���
void Swap(int *left, int *right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

int main()
{
	int a = 10;
	int b = 20;
	Swap(a, b);
	Swap(&a, &b);
	Swap(NULL, NULL);
	return 0;
}
#endif

#if 0
//���õĸ���
int main()
{
	int a = 10;

	//һ��ʵ������ж������
	int& ra1 = a;
	int& ra2 = a;
	int& ra3 = ra2;

	ra1 = 100;
	ra2 = 200;
	ra3 = 200;

	cout << &a << " " << &ra1 << endl;

	//һ���������͵ı���һ����һ��ʵ���Ϻ󣬾Ͳ����ں�����ʵ����
	int b = 10;
	//&ra1=b;

	if (true)
	{
		int& rb = b;
	}

	//rb=200;
	return 0;
}
#endif

#if 0
int main()
{
	const int a = 10;
	const int &ra = a;
	const int &rb = 10;

	//����ͨ��rc�޸�c
	int c = 10;
	const int& rc = c;

	double d = 12.34;
	const int& rd = d;
	cout << &rd << " " << &d << endl;
}
#endif

#if 0
//������Ϊ�������βΣ������Ҫͨ���βθı��ⲿʵ��---������ͨ��������
//                   �������ͨ���βθı��ⲿʵ��---����const��������
void Swap(int &left, int &right)
{
	int temp = left;
	left = right;
	right = temp;
}

void Testfunc(const int& ra)
{
	//ra=100;
}

int main()
{
	int a = 10;
	int b = 20;
	Swap(a, b);

	cout << a << " " << b << endl;

	Testfunc(a);

}

#endif

#if 0
//������Ϊ�����ķ���ֵ����
//ע�⣺����������÷�ʽ���з��أ�һ�����ܷ���ջ�ϵĿռ�
//�������ͣ����ر������������ڲ��ܺ���������Ӱ��

int g_a = 0;
int& Add(int left, int right)
{
	/*
	int ret=left+right;//ջ�ϵĿռ�
	return ret;
	*/

	g_a = left + right;
	return g_a;
}
int main()
{
	int &r = Add(1, 2);
	Add(3, 4);
	return 0;
}
#endif

#if 0
#include<time.h>
struct A
{
	int a[10000];
};

void TestFunc1(A* a)
{}

void TestFunc2(A& a)
{}

void TestRefAndValue()
{
	A a;

	//��ֵ��Ϊ��������
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc1(&a);
	size_t end1 = clock();

	//��������Ϊ��������
	size_t begin2 = clock();
	for (int i = 0;i < 10000; ++i)
	{
		TestFunc2(a);
	}
	size_t end2 = clock();

	//�ֱ���������������н������ʱ��
	cout << "TestFunc1(int*)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(int&)-time:" << end2 - begin2 << endl;


}
//���ж�Σ����ֵ�������ڴ��η����Ч������
int main()
{
	for (int i = 0; i < 10; ++i)
	{
		TestRefAndValue();
	}
	return 0;
}
#endif

#if 0
//ָ������õ�����****
int main()
{
	int a = 10;

	int *pa = &a;
	*pa = 100;

	int &ra = a;
	ra = 100;
	return 0;
}
#endif

#if 0
int main()
{
	int a = 10;
	int b = 20;
	int* pa;
	int &ra = a;

	pa = &a;
	pa = &b;

	++ra;
	++pa;

	char c = 'a';
	char& rc = c;
	char* pc = &c;

	cout << sizeof(rc) << " " << sizeof(pc) << endl;

	int **pb;
	int &&r = 10;
	return  0;
}
#endif

//�����ȱ�㣺
//�꣺���峣��

#if 0
#define PI "3.14"

int main()
{
	cout << PI * 2 * 2 << endl;
	return 0;
}
#endif

#if 0
int main()
{
	const int a = 10;

	int *pa = (int*)&a;
	*pa = 100;

	cout << 10 << " " << *pa << endl;
}
#endif

#if 0
#define MAX(a,b) ((a)>(b))?(a):(b)

int main()
{
	int a = 10;
	int b = 20;
	int c = MAX(a, b);
	c = MAX(++b, a);

}
#endif

#if 0
//��������
//����׶Σ������������ĵ���λ��ʹ������������չ��
inline int Add(int left, int right)
{
	Add(left, right);
	return left + right;
}

int main()
{
	int a = 10;
	int b = 20;
	int c = 0;
	c = Add(a, b);

	Sub(a, b);
	return 0;
}
#endif

#if 0
//auto
int TestAuto()
{
	return 0;
}

#include<map>
#include<string>
int main()
{
	int a = 10;
	auto b = a;
	auto c = 'c';
	auto d = TestAuto();

	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;

	std::map<std::string,std::string>m{ { "apple", "ƻ��" }, {"banana", "�㽶"} };

	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << " " << it->second << endl;
		++it;
	}
	return 0;
}
#endif

#if 0
int main()
{
	int a = 10;
	auto pa1 = &a;
	auto* pa2 = &a;

	cout << typeid(pa1).name() << endl;
	cout << typeid(pa2).name() << endl;

	auto ra1 = a;
	auto& ra2 = a;

	cout << &a << " " << &ra1 << endl;
	cout << &a << " " << &ra2 << endl;

	auto c1 = 1, c2 = 2, c3 = 3;
	//auto c1=1,c2=1.0;

	int arr1[10] = { 1, 2, 3 };
	//auto arr2[10]={1,2,3};
}
#endif

#if 0
//void testfor(int array[10])
//{
//	for (auto e : array)
//		cout << endl;
//}

int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
	{
		array[i] *= 2;
	}
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		cout << array[i] << " ";
	cout << endl;


	for (auto& e : array)
		e = e * 2;
	for (auto e : array)
		cout << e << " ";
	cout << endl;

	int *p = array;
	//for (auto e : p)
	//	cout << e << endl;
}
#endif

#if 0
void Testfunc(int a)
{
	cout << "Testfunc(int)" << endl;
}
void Testfunc(int* pa)
{
	cout << "Testfunc(int*)" << endl;
}

int main()
{
	Testfunc(0);
	Testfunc(NULL);
	Testfunc(nullptr);

	int *p = nullptr;
	return 0;
}
#endif
