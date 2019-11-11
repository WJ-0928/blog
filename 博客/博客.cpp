#if 0
#include<iostream>
#include<cstring>
#include<assert.h>
using namespace std;

struct Student
{
	void SetStudent(const char* name,const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PrintStudent()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}


	char _name[20];
	char _gender[3];
	int _age;
};

int main()
{
	Student S;
	S.SetStudent("anmo", "女", 3);
	return 0;
}
#endif


#if 0
class Student
{
	//类体：由成员函数和成员变量组成

};//一定要注意后面的分号
#endif

#if 0
class person
{
public:
	void printperson();
private:
	char name[20];
	char gender[3];
	int age;
};


//在类外定义类的函数，需要指定该函数(printperson)是属于这个类域的（person)
void person::printperson()
{
	cout << name << " " << gender << " " << age << endl;
}
#endif


#if 0
//类中既有成员函数又有成员变量
class A1
{
public:
	void f1(){}
private:
	int a;
};

//类中仅有成员函数
class A2
{
public:
	void f2(){}
};

//类中什么都没有----空类
class A3
{

};
#endif


#if 0
class Date
{
public:
	//1、无参构造函数
	Date()
	{}

	//2、带参构造函数
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};


void TestDate()
{
	Date d1;//调用无参构造函数
	Date d2(2019, 7, 27);//调用带参构造函数

	//注意：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则就成了函数声明
	//以下代码的函数：声明了d3函数，该函数无参，返回一个日期类型的对象
	Date d3();
}
#endif

#if 0
class Date
{
public:
	/*
	//如果用户显示定义了构造函数，编译器将不再生成
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	*/
private:
	int _year;
	int _month;
	int _day;
};


void TestDate()
{
	//没有定义构造函数，对象也可以创建成功，因此此处调用的是编译器生成的默认构造函数
	Date d1;
}
#endif


#if 0
class Seqlist
{
public:
	Seqlist(int capacity = 10)
	{
		_pData = (int *)malloc(sizeof(int)*capacity);
		assert(_pData);

		_size = 0;
		_capacity = capacity;
	}

	~Seqlist()
	{
		if (_pData)
		{
			free(_pData);//释放堆上的空间
			_pData = NULL;//将指针置为空
			_capacity = 0;
			_size = 0;
		}
	}
private:
	int* _pData;
	int _size;
	int _capacity;
};
#endif
#if 0
class Date
{
public:
	Date(int year=2019, int month=7, int day=27)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1;
	Date d2(d1);

	return 0;
}
#endif

#if 0
//全局的operator==
class Date
{
public:
	Date(int year = 2019, int month = 7, int day = 27)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	bool operator==(const Date& d2)
	{
		return _year == d2._year
		&&_month = d2._month
		&&_day = d2._day;
	}
private:
	int _year;
	int _month;
	int _day;
};

void Test()
{
	Date d1(2019, 7, 27);
	Date d2(2019, 7, 28);
	cout << (d1 == d2) << endl;
}

#endif
#if 0
class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
#endif
#if 0
class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};
#endif
#if 0
class Date
{
public:
	Date(int year, int month)
		:_year(year)
		, _month(month)
		, _day(_month)
	{
		cout << _year << endl;
		cout << _month << endl;
		cout << _day << endl;
	}
private:
	int _year;
	int _day;
	int _month;
	
};
int main()
{
	Date a(2019, 1);
	system("pause");
	return 0;
}
#endif
#if 0
class Date
{
public:
	explicit Date(int year)
		:_year(year)
		, _month(1)
		, _day(1)
	{}
	Date(const Date& d)
		:_year(d._year)
		,_month(d._month)
		,_day(d._day)
	{}

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d(2018);
	//用一个整型变量给日期类型对象赋值
	//实际编译器背后会用2019构造一个无名对象，最后用无名对象给d1对象进行赋值

	//调用单参构造函数将2019转换为临时对象
	//最后使用临时对象给d赋值
	d = 2019;
	system("pause");
	return 0;
}
#endif

#if 0
class Date
{
friend ostream& operator<<(ostream& _cout, const Date& d);
friend istream& operator>>(istream& _cin, const Date& d);
public:
	Date(int year,int month,int day)
		:_year(year)
		,_month(month)
		,_day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day <<endl;
	return _cout;
}

istream& operator >>(istream& _cin, const Date& d)
{
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;
	return _cin;
}
int main()
{
	Date d;
	cin >> d;
	cout << d << endl;;
	return 0;
}
#endif
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
		_t._minute= minute;
		_t._second = second;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};
#endif
#if 0
//求1 + 2 + 3 + ... + n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A ? B : C）。
class Solution {
public:
	class Sum
	{
	public:
		Sum()
		{
			_count++;
			_sum += _count;
		}
		static int GetSum()
		{
			return _sum;
		}
		static void ReSetSum()
		{
			_sum = 0;
			_count = 0;
		}
	private:
		static int _count;
		static int _sum;
	};
	int Sum_Solution(int n) {
		Sum::ReSetSum();
		Sum a[n];
		return Sum::GetSum();
	}
};

int Solution::Sum::_count = 0;
int Solution::Sum::_sum = 0;
#endif


