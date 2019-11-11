#if 0
#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
	void print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "anmo";
	int _age = 18;
	
};

//�̳к����person�ĳ�Ա����Ա����+��Ա�����������������һ���֡�
//����������Student��Teacher������Person�ĳ�Ա��
class Student :public Person
{
protected:
	int _stuid;
};

class Teacher :public Person
{
protected:
	int _jobid;
};

int main()
{
	Student s;
	Teacher t;
	s.print();
	t.print();
	return 0;
}
#endif

#if 0
class Person
{
protected:
	string _name;
	int _age;

};

class Student :public Person
{
public:
	int _stuid;
};

int main()
{
	Student s;
	
	//1�����������Ը�ֵ���������/ָ��/����
	Person pobj = s;
	Person* pp = &s;
	Person& rp = s;

	//2����������ܸ�ֵ�����������
	//s = pobj;

	//3������ָ�����ͨ��ǿ������ת����ֵ���������ָ��
	pp = &s;
	Student* ps = (Student*)pp;//�����������ת��
	ps->_stuid;

	return 0;
}
#endif

#if 0
//B�е�Fun��A�е�Fun���������أ���Ϊ����ͬһ��������
//B�е�Fun��A�е�Fun�������أ���Ա�������㺯������ͬ�͹�������
class A 
{
public:
	void Fun()
	{
		cout << "Fun()" << endl;
	}
};
class B :public A
{
public:
	void Fun(int i)
	{
		A::Fun();
		cout << "Fun(int i)" << endl;
	}
};

int main()
{
	B b;
	b.Fun(10);
	return 0;
}
#endif
#if 0
class person
{
public:
	person(const char* name = "anmo")
		:_name(name)
	{
		cout << "person()" << endl;
	}
	person(const person& p)
		:_name(p._name)
	{
		cout << "person(const perosn& p)" << endl;
	}
	person& operator=(const person& p)
	{
		cout << "person& operator=(const person& p)" << endl;
		if (this != &p)
		{
			_name = p._name;
		}
		return *this;
	}
	~person()
	{
		cout << "~person()" << endl;
	}
private:
	string _name;
};

class student:public person
{
public:
	student(const char* name,int num)
		:person(name)
		,_num(num)
	{
		cout << "student()" << endl;
	}
	student(const student& s)
		:person(s)
		,_num(s._num)
	{
		cout << "student(const student& s)" << endl;
	}
	student& operator=(const student& s)
	{
		cout << "student& operator=(const student& s)" << endl;
		if (this != &s)
		{
			person::operator=(s);
			_num = s._num;
		}
		return *this;
	}
	~student()
	{
		cout << "~student()" << endl;
	}
private:
	int _num;
};

int main()
{
	student s1("xiaoha", 20);
	student s2(s1);
	student s3("zhangsan", 18);
	s1 = s3;

	return 0;
}
#endif
