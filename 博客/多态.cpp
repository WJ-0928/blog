

#if 0
class person
{
public:
	virtual void BuyTicket()
	{
		cout << "买票-全价" << endl;
	}
};

class student :public person
{
public:
	virtual void BuyTicket()
	{
		cout << "买票-半价" << endl;
	}
};

void Func(person& p)
{
	p.BuyTicket();
}

int main()
{
	person ps;
	student st;
	Func(ps);
	Func(st);
	return 0;
}
#endif

#if 0
class WashRoom
{
public:
	void GoToManRoom()
	{
		cout << "往前一小步，文明一大步" << endl;
	}

	void GoToLadyRoom()
	{
		cout << "往后一小步，文明一大步" << endl;
	}

};


// 抽象类
class Person
{
public:
	// 纯虚函数
	virtual void GoToWC(WashRoom& wc) = 0;

protected:
	string _name;
	int _age;
};

class Man : public Person
{
public:
	virtual void GoToWC(WashRoom& wc)
	{
		wc.GoToManRoom();
	}
};

class Woman : public Person
{
public:
	virtual void GoToWC(WashRoom& wc)
	{
		wc.GoToLadyRoom();
	}
};


void Test()
{
	WashRoom wc;

	Person* man = new Man;
	man->GoToWC(wc);

	Person* woman = new Woman;
	woman->GoToWC(wc);

}

int main()
{
	Test();

	system("pause");
	return 0;
}
#endif