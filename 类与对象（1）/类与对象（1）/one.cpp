#include<iostream>
using namespace std;


#if 0
int a1 = 10;
int a2 = 20;//全局变量

int main()
{
	int a = 10;//局部变量
	return 0;
}

#endif



#if 0
//命名空间中的内容，既可以定义变量，也可以定义函数
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

//命名空间可以嵌套
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
	printf("%d\n", a);//访问主函数中的a
	printf("%d\n", ::a);//访问全局变量中的a
	printf("%d\n", N1::a);//访问N1命名空间中的a
	printf("%d\n", N2::N3::a);//访问嵌套命名空间中的a
	return 0;
}
#endif

#if 0
//命名空间的三种使用方法；
//1、直接在成员前加命名空间名字::
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
//2、使用using将命名空间中成员引用
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
// 如果一个工程中存在多个相同名称命名空间时，编译器会将其合成并一个
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
//全缺省参数：所有参数都带有默认值
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
//半缺省参数：部分参数带有默认值  要求：只能从右往左给出
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
//缺省参数不能再函数声明和定义中同时出现
//如果声明和定义位置同时出现，恰巧两个位置提供值不同，那编译器就无法确定到底该使用那个缺省值
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
//缺省值必须是常量或者全局变量
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
//函数重载：必须在相同的作用域，相同名字的函数，如果参数列表不同（个数、类型、类型次序）
//与返回值类型是否相同无关
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
	//编译器在编译阶段，必须对实参的类型进行推演，根据推演的实参类型的结果选择调用合适的函数

	Add(1, 2);
	Add(1.0, 2.0);
	return 0;
}

#endif

#if 0
//1
void TestFunc()
{}

//2与1是参数个数不同
//2
void TestFunc(int a)
{}

//3
void TestFunc(int a,double b)
{}

//3与4是参数次序不同
//4
void TestFunc(double a,int b)
{}

//2和5是参数类型不同
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
//C语言函数名字修饰规则：编译器只是在函数名字前加_
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
//在C++工程中

//extern "C"作用：将函数按照C的风格进行编译

extern "C" int Add(int left, int right);//_Add

int main()
{
	Add(1, 2);//?Add@@YAHHH@Z
	return 0;
}
#endif

#if 0
//编译不能通过
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

//传值
//优点：对函数形参的改变不会影响外部的实参
//缺点：不能通过形参改变外部的实参，浪费空间，减低代码的运行效率
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

//传地址
//优点：可以通过形参改变外部的实参，传参的效率
//缺点：函数的副作用会影响外部的实参，指针不安全，降低代码的可读性
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
//引用的概念
int main()
{
	int a = 10;

	//一个实体可以有多个别名
	int& ra1 = a;
	int& ra2 = a;
	int& ra3 = ra2;

	ra1 = 100;
	ra2 = 200;
	ra3 = 200;

	cout << &a << " " << &ra1 << endl;

	//一个引用类型的变量一旦与一个实体结合后，就不能在和其他实体结合
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

	//不想通过rc修改c
	int c = 10;
	const int& rc = c;

	double d = 12.34;
	const int& rd = d;
	cout << &rd << " " << &d << endl;
}
#endif

#if 0
//引用作为函数的形参：如果想要通过形参改变外部实参---传递普通类型引用
//                   如果不想通过形参改变外部实参---传递const类型引用
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
//引用作为函数的返回值类型
//注意：如果按照引用方式进行返回，一定不能返回栈上的空间
//返回类型：返回变量的生命周期不受函数结束的影响

int g_a = 0;
int& Add(int left, int right)
{
	/*
	int ret=left+right;//栈上的空间
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

	//以值作为函数参数
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc1(&a);
	size_t end1 = clock();

	//以引用作为函数参数
	size_t begin2 = clock();
	for (int i = 0;i < 10000; ++i)
	{
		TestFunc2(a);
	}
	size_t end2 = clock();

	//分别计算两个函数运行结束后的时间
	cout << "TestFunc1(int*)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(int&)-time:" << end2 - begin2 << endl;


}
//运行多次，检测值和引用在传参方面的效率区别
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
//指针和引用的区别：****
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

//宏的优缺点：
//宏：定义常量

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
//内联函数
//编译阶段，对内联函数的调用位置使用内联函数体展开
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

	std::map<std::string,std::string>m{ { "apple", "苹果" }, {"banana", "香蕉"} };

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
