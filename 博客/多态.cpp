

#if 0
class person
{
public:
	virtual void BuyTicket()
	{
		cout << "��Ʊ-ȫ��" << endl;
	}
};

class student :public person
{
public:
	virtual void BuyTicket()
	{
		cout << "��Ʊ-���" << endl;
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
		cout << "��ǰһС��������һ��" << endl;
	}

	void GoToLadyRoom()
	{
		cout << "����һС��������һ��" << endl;
	}

};


// ������
class Person
{
public:
	// ���麯��
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