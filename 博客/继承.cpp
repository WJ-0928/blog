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

//继承后父类的person的成员（成员函数+成员变量）都会变成子类的一部分。
//这里体现了Student和Teacher复用了Person的成员。
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
	
	//1、子类对象可以赋值给父类对象/指针/引用
	Person pobj = s;
	Person* pp = &s;
	Person& rp = s;

	//2、基类对象不能赋值给派生类对象
	//s = pobj;

	//3、基类指针可以通过强制类型转换赋值给派生类的指针
	pp = &s;
	Student* ps = (Student*)pp;//这种情况可以转换
	ps->_stuid;

	return 0;
}
#endif

#if 0
//B中的Fun和A中的Fun不构成重载，因为不在同一个作用域
//B中的Fun和A中的Fun构成隐藏，成员函数满足函数名相同就构成隐藏
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
