#include<stdio.h>

#include<iostream>
using namespace std;
//
//int a = 10;
//
//
//
////1、普通的命名空间
////{}表示一个范围（作用域）----命名空间实际就是一个有名字的只作用域
//namespace N1//N1为命名空间的名称
//{
//    //命名空间中的内容，既可以定义变量，也可以定义函数
//    int a=20;
//    int b = 20;
//    int Add(int left, int right)
//    {
//        return left + right;
//    }
//}
//
////2、命名空间可以嵌套----命名空间中可以定义命名空间
//namespace N2//N2为命名空间的名称
//{
//    int a=30;
//    int b=30;
//    int Add(int left, int right)
//    {
//        return left + right;
//    }
//    namespace N3
//    {
//        int a=40;
//        int b=40;
//        int Sub(int left, int right)
//        {
//            return left - right;
//        }
//    }
//}
//
//int main()
//{
//    int a = 50;
//    printf("%d\n", a);//main局部变量a
//    printf("%d\n", ::a);//全局作用域中的a
//    printf("%d\n", N1::a);//N1命名空间中的a
//    printf("%d\n", N2::a);//N2命名空间中的a
//    printf("%d\n", N2::N3::a);//N3命名空间中的a
//    return 0;
//}
//
//
//namespace N1//N1为命名空间的名称
//{
//    //命名空间中的内容，既可以定义变量，也可以定义函数
//    int a = 20;
//    int b = 20;
//    int Add(int left, int right)
//    {
//        return left + right;
//    }
//}
//
////在命名空间成员前增加N1：：（命名空间名字以及作用域限定符)
////using N1::成员名字；
//using N1::b;//b相当于该文件的全局变量（实际上b是N1命名空间的成员）
//
//
////3、using namespace N1;
//using namespace N1;
////优点：命名空间中的成员可以直接在当前文件中直接使用
////缺点：产生冲突的概率比较大
//int main()
//{
//    printf("%d\n", N1::a);
//    printf("%d\n", b);
//    Add(a, b);
//    return 0;
//
//}
//
//
//namespace N1//N1为命名空间的名称
//{
//    //命名空间中的内容，既可以定义变量，也可以定义函数
//    int a = 20;
//    int b = 20;
//    int Add(int left, int right)
//    {
//        return left + right;
//    }
//}
//namespace N1//N1为命名空间的名称
//{
//    //命名空间中的内容，既可以定义变量，也可以定义函数
//    int c;
//    int d;
//    int Sub(int left, int right)
//    {
//        return left - right;
//    }
//}
//
//int main()
//{
//    int a;
//    int b;
//    int c;
//    cin >> a >> b >> c;
//    cout << 1 << " " << 1.23 << endl;
//    cout << "hello world" << endl;
//    return 0;
//}
//
//
////函数原型：返回值类型  函数名字（参数列表）{}
////c语言编译器对函数原型检测要求不是非常严格
//void Test1()
//{
//    printf("Test1()\n");
//}
//int main()
//{
//    Test1();
//    return 0;
//}
//
//
////能否给参数带上默认值
//void Test1(int a=0)
//{
//    printf("%d\n",a);
//}
//int main()
//{
//    Test1();
//    Test1(10);
//    return 0;
//}
//
//
//
////缺省参数分类：
////1、全缺省参数----所有参数都带有默认值
//
//void Func(int a = 1, int b = 2, int c = 3)
//{
//    cout << a << " " << b << " " << c << endl;
//}
//
////函数传参规则：从右往左一次来传递参数
////缺省参数匹配规则：从左到右来进行匹配
//int main()
//{
//    Func();//打印1,2,3
//    Func(10);//打印10,2,3
//    Func(10, 20);//打印10,20,3
//    Func(10, 20, 30);//打印10,20,30
//}
//
//
//void Func(int a , int b = 2, int c = 3)
//{
//    cout << a << " " << b << " " << c << endl;
//}
//
////函数传参规则：从右往左一次来传递参数
////缺省参数匹配规则：从左到右来进行匹配
//int main()
//{
//    //Func();//打印1,2,3
//    //Func(10);//打印10,2,3
//    //Func(10, 20);//打印10,20,3
//    //Func(10, 20, 30);//打印10,20,30
//    return 0;
//}
//
//
////一不小心，声明和定义位置给出的默认值可能不一致，在调用的时候应该用哪个就会存在问题，在** 声明** 的位置给出比较好
//
//
//
////C语言中，函数名字必须唯一
//int Add(int left, int right)
//{
//    return left + right;
//}
//double Add(double left, double right)
//{
//    return left + right;
//}
//int main()
//{
//    Add(1, 2);//int,int--->Add(int,int)
//    Add(1.0, 2.0);//double,double--->ADD(double,double)
//    Add('1', '2');//没有提供字符串类型的加法函数，char和int可以发生隐式类型的转化---->char,char-->隐式类型转化
//    Add(1,(int) 2.0);//int double 转化：int int或者double  double，编译器不知道该如何让转化---直接显示类型转化
//}
//
//
////C语言中，函数名字必须唯一
//int Add(int left, int right)
//{
//    return left + right;
//}
//double Add(double left, double right)
//{
//    return left + right;
//}
//int main()
//{
//    Add(1, 2);//int,int--->Add(int,int)
//    Add(1.0, 2.0);//double,double--->ADD(double,double)
//    Add('1', '2');//没有提供字符串类型的加法函数，char和int可以发生隐式类型的转化---->char,char-->隐式类型转化
//    Add(1, (int)2.0);//int double 转化：int int或者double  double，编译器不知道该如何让转化---直接显示类型转化
//}
//
//
//
//int main()
//{
//    int a = 10;
//    int& ra = a;
//    ra = 100;
//    a = 200;
//    return 0;
//}
//
//
//
//void Swap(int& left, int& right)
//{
//
//    cout << &left << endl;
//    cout << &right << endl;
//    int temp = left;
//    left = right;
//    right = temp;
//}
//
//int main()
//{
//    int a = 10;
//    int b = 20;
//    cout << &a << endl;
//    cout << &b << endl;
//    Swap(a, b);
//    return 0;
//}
//
//
//int& Add(int left, int right)
//{
//    int temp = left + right;
//    return temp;
//}
//
//int main()
//{
//    int& ret = Add(1, 2);
//    Add(3, 4);
////    return 0;
////}
//#if 0
//
//#include<stdio.h>
//#include<string.h>
//
////C语言中定义的学生结构体
//struct Student
//{
//    char name[20];
//    char gender[3];
//    int age;
//};
//
////定义操作学生结构体的方法
//void InitStudent(Student* ps, char* name, char* gender, int age)
//{
//    strcpy(ps->name, name);
//    strcpy(ps->gender, gender);
//    ps->age = age; 
//}
//void PrintStudent(Student* ps)
//{
//    printf("%s-%s-%d\n", ps->name, ps->gender, ps->age);
//}
//int main()
//{
//    Student s1, s2, s3;
//    InitStudent(&s1, "peter", "男", 31);
//    InitStudent(&s2, "仅仅", "女", 26);
//    InitStudent(&s3, "summer", "男", 2);
//    PrintStudent(&s1);
//    PrintStudent(&s2);
//    PrintStudent(&s3);
//    return 0;
//}
//#endif
//#include<iostream>
//using namespace std;

//class Date
//{
//public:
//	Date(int year, int month ,int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void SetDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void printDate()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//#if 0
//class Date
//{
//public:
//    //1、无参构造函数
//    Date()
//    {}
//
//    //2、带参构造函数
//    Date(int year, int month, int day)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//
//void TestDate()
//{
//    Date d1;//调用无参构造函数
//    Date d2(2019, 7, 27);//调用带参构造函数
//
//    //注意：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则就成了函数声明
//    //以下代码的函数：声明了d3函数，该函数无参，返回一个日期类型的对象
//    Date d3();
//}
//
//int main()
//{
//	int a1;
//	int a2 = 0;
//	int a3(0);
//
//	Date d(2021, 9, 14);
//	//d.SetDate(2021, 9, 14);
//	d.printDate();
//	return 0;
//}
//
//
//class Date
//{
//public:
//    /*
//    //如果用户显示定义了构造函数，编译器将不再生成
//    Date(int year, int month, int day)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    */
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//
//void TestDate()
//{
//    //没有定义构造函数，对象也可以创建成功，因此此处调用的是编译器生成的默认构造函数
//    Date d1;
//}
//
//
//
//
//#include<assert.h>
//#include<malloc.h>
//class Seqlist
//{
//public:
//    Seqlist(int capacity = 10)
//    {
//        _pData = (int*)malloc(sizeof(int) * capacity);
//        assert(_pData);
//
//        _size = 0;
//        _capacity = capacity;
//    }
//
//    ~Seqlist()
//    {
//        if (_pData)
//        {
//            free(_pData);//释放堆上的空间
//            _pData = NULL;//将指针置为空
//            _capacity = 0;
//            _size = 0;
//        }
//    }
//private:
//    int* _pData;
//    int _size;
//    int _capacity;
//};
//
//int main()
//{
//    return 0;
//}
//#endif

//
//class Date
//{
//public:
//	Date(int year=1970, int month=1 ,int day=1)
//        :_year(year)
//        ,_month(month)
//        ,_day(day)
//        ,count(0)
//	{
//        count++;
//        cout << "Date(int,int,int):" << this << endl;
//	}
//	Date(Date& d)
//        :_year(d._year)
//        ,_month(d._month)
//        ,_day(d._day)
//        ,count(++d.count)
//    {}
//
//    Date& operator=(const Date& d)
//    {
//        cout << this << "=" << &d << endl;
//        if (this != &d)
//        {
//            _year = d._year;
//            _month = d._month;
//            _day = d._day;
//        }
//        return *this;
//    }
//
//    ~Date()
//    {
//        count--;
//        cout << "~Date():" << this << endl;
//    }
//	void printDate()const
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//    int count;
//};
//
//void TestDate()
//{
//    Date d1;
//    Date d2(d1);
//}
//int main()
//{
//    TestDate();
//    return 0;
//}


//int g_count = 0;
//class Date
//{
//public:
//    Date(int year = 1970, int month = 1, int day = 1)
//        :_year(year)
//        , _month(month)
//        , _day(day)
//    {
//        g_count++;
//        cout << "Date(int,int,int):" << this << endl;
//    }
//    Date(Date& d)
//        :_year(d._year)
//        , _month(d._month)
//        , _day(d._day)
//    {
//        g_count++;
//        cout << "Date(Date& ):" << this << endl;
//    }
//
//    Date& operator=(const Date& d)
//    {
//        cout << this << "=" << &d << endl;
//        if (this != &d)
//        {
//            _year = d._year;
//            _month = d._month;
//            _day = d._day;
//        }
//        return *this;
//    }
//
//    ~Date()
//    {
//        g_count--;
//        cout << "~Date():" << this << endl;
//    }
//    void printDate()const
//    {
//        cout << _year << "/" << _month << "/" << _day << endl;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
////采用全局变量是可以的
////有缺陷：全局变量是所有函数都可以访问的，万一被修改计数就不准确了
//void TestDate()
//{
//    Date d1;
//    Date d2(d1);
//}
//int main()
//{
//    TestDate();
//    return 0;
//}


//在类中：有没有共享的变量
//class Date
//{
//public:
//    Date(int year = 1970, int month = 1, int day = 1)
//        :_year(year)
//        , _month(month)
//        , _day(day)
//    {
//        count++;
//        cout << "Date(int,int,int):" << this << endl;
//    }
//    Date(Date& d)
//        :_year(d._year)
//        , _month(d._month)
//        , _day(d._day)
//    {
//        count++;
//        cout << "Date(Date& ):" << this << endl;
//    }
//
//    Date& operator=(const Date& d)
//    {
//        cout << this << "=" << &d << endl;
//        if (this != &d)
//        {
//            _year = d._year;
//            _month = d._month;
//            _day = d._day;
//        }
//        return *this;
//    }
//
//    ~Date()
//    {
//        count--;
//        cout << "~Date():" << this << endl;
//    }
//    void printDate()const
//    {
//        cout << _year << "/" << _month << "/" << _day << endl;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//public:
//
//    //static修饰的成员变量---称为静态成员变量
//    static int count;//注意：静态成员变量在类中只是声明，必须在类外进行初始化
//};
////静态成员变量的初始化：
////注意：静态成员变量在类外进行初始化是不需要添加static关键字
//int Date::count = 0;
//void TestDate()
//{
//    Date d1;
//    Date d2(d1);
//}
//int main()
//{
//    Date d1;
//    Date d2(d1);
//    cout << &d1.count << " " << &d2.count << endl;
//    TestDate();
//    return 0;
//}

//class Date
//{
//public:
//    Date(int year = 1970, int month = 1, int day = 1)
//        :_year(year)
//        , _month(month)
//        , _day(day)
//    {
//        count++;
//        cout << "Date(int,int,int):" << this << endl;
//    }
//    Date(Date& d)
//        :_year(d._year)
//        , _month(d._month)
//        , _day(d._day)
//    {
//        count++;
//        cout << "Date(Date& ):" << this << endl;
//    }
//
//    Date& operator=(const Date& d)
//    {
//        cout << this << "=" << &d << endl;
//        if (this != &d)
//        {
//            _year = d._year;
//            _month = d._month;
//            _day = d._day;
//        }
//        return *this;
//    }
//
//    ~Date()
//    {
//        count--;
//        cout << "~Date():" << this << endl;
//    }
//    void printDate()const
//    {
//        cout << _year << "/" << _month << "/" << _day << endl;
//    }
//    static int GetCount()
//    {
//        return count;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//    static int count;};
//int Date::count = 0;
//void TestDate()
//{
//    cout << Date::GetCount() << endl;
//    Date d1;
//    Date d2(d1);
//}
//int main()
//{
//    Date d1;
//    Date d2(d1);
//
//    cout << d1.GetCount() << endl;
//
//    TestDate();
//    return 0;
//}

#if 0
class Date;//前置声明
class Time
{
    friend class Date;//声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
public:
    Time(int hour, int minute, int second)
        :_hour(hour)
        , _minute(minute)
        , _second(second)
    {}
private:
    int _hour;
    int _minute;
    int _second;
};
class Date
{
public:
    Date(int year = 1900, int month = 1, int day = 1)
        :_year(year)
        , _month(month)
        , _day(day)
    {}
    void SetTimeOfDate(int hour, int minute, int second)
    {
        //直接访问时间类私有成员变量
        _t._hour = hour;
        _t._minute = minute;
        _t._second = second;
    }
private:
    int _year;
    int _month;
    int _day;
    Time _t;
};
#endif
