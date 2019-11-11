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
	S.SetStudent("anmo", "Ů", 3);
	return 0;
}
#endif


#if 0
class Student
{
	//���壺�ɳ�Ա�����ͳ�Ա�������

};//һ��Ҫע�����ķֺ�
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


//�����ⶨ����ĺ�������Ҫָ���ú���(printperson)�������������ģ�person)
void person::printperson()
{
	cout << name << " " << gender << " " << age << endl;
}
#endif


#if 0
//���м��г�Ա�������г�Ա����
class A1
{
public:
	void f1(){}
private:
	int a;
};

//���н��г�Ա����
class A2
{
public:
	void f2(){}
};

//����ʲô��û��----����
class A3
{

};
#endif


#if 0
class Date
{
public:
	//1���޲ι��캯��
	Date()
	{}

	//2�����ι��캯��
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
	Date d1;//�����޲ι��캯��
	Date d2(2019, 7, 27);//���ô��ι��캯��

	//ע�⣺���ͨ���޲ι��캯����������ʱ��������治�ø����ţ�����ͳ��˺�������
	//���´���ĺ�����������d3�������ú����޲Σ�����һ���������͵Ķ���
	Date d3();
}
#endif

#if 0
class Date
{
public:
	/*
	//����û���ʾ�����˹��캯��������������������
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
	//û�ж��幹�캯��������Ҳ���Դ����ɹ�����˴˴����õ��Ǳ��������ɵ�Ĭ�Ϲ��캯��
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
			free(_pData);//�ͷŶ��ϵĿռ�
			_pData = NULL;//��ָ����Ϊ��
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
//ȫ�ֵ�operator==
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
	//��һ�����ͱ������������Ͷ���ֵ
	//ʵ�ʱ������������2019����һ������������������������d1������и�ֵ

	//���õ��ι��캯����2019ת��Ϊ��ʱ����
	//���ʹ����ʱ�����d��ֵ
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
class Date;//ǰ������
class Time
{
	friend class Date;//����������Ϊʱ�������Ԫ�࣬�����������о�ֱ�ӷ���Time���е�˽�г�Ա����
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
		//ֱ�ӷ���ʱ����˽�г�Ա����
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
//��1 + 2 + 3 + ... + n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A ? B : C����
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


