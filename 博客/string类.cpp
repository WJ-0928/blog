

//============================================================================
//#include<iostream>
//using namespace std;
//#include<string>
#if 0
//string ������ֹ���
int main()
{
	string s1;//����յ�string�����s1
	string s2("hello");//��C��ʽ�ַ�������string�����s2
	string s3(10, '$');//���10��$�ķ���
	string s4(s2);//��������s4
	cin >> s1;
	cout << s1 << endl;//anmo
	cout << s2 << endl;//hello
	cout << s3 << endl;	//$$$$$$$$$$
	cout << s4 << endl;//hello
	system("pause");
	return 0;
}
#endif

//============================================================================
//string��������������

#if 0
//size�������ַ�����Ч�ַ��ĳ���
//length:�����ַ�����Ч�ַ��ĳ���
//capacity:���ؿռ��ܴ�С
//empty:����ַ����ͷ�Ϊ�մ����Ƿ���true�����򷵻�false
//clear:�����Ч�ַ�
//resize:����Ч�ַ��ĸ����ĳ�n��������Ŀռ����ַ�c���
int main()
{
	//ע�⣺string�����֧��ֱ����cin��cout������������
	string s("hello anmo!");
	cout << s.size() << endl;//11
	cout << s.length() << endl;//11
	cout << s.capacity() << endl;//15
	cout << s << endl;//hello anmo!

	//��s���ַ�����գ�ע�����ʱֻ�ǽ�size��0�����ı�Ͳ�ռ��С
    s.clear();
	cout << s.size() << endl;//0
	cout << s.length() << endl;//0
	cout << s.capacity() << endl;//15

	//��s����Ч�ַ��������ӵ�10����������λ����'!'�������
	//resize���ܣ��ı�string����Ч�ַ��ĸ���
	//1������Ч�ַ��������ӵ�n���������λ����Ҫ��c�����䣨������Ҫ���ݣ�
	//2������Ч�ַ��������ٵ�n����ֻ�޸���Ч�ַ��ĸ���������С�ռ�
	string s1("anmo");
	cout << s1.size() << endl;//4
	cout << s1.length() << endl;//4
	cout << s1.capacity() << endl;//15
	cout << s1 << endl;//anmo
	s1.resize(10, '!');
	cout << s1.size() << endl;//10
	cout << s1.length() << endl;//10
	cout << s1.capacity() << endl;//15
	cout << s1 << endl;//anmo!!!!!!
	s1.resize(15);
	cout << s1.size() << endl;//15
	cout << s1.length() << endl;//15
	cout << s1.capacity() << endl;//15
	cout << s1 << endl;//anmo!!!!!!
	s1.resize(2);//����Ч�ַ��������ٵ�5��
	cout << s1.size() << endl;//2
	cout << s1.length() << endl;//2
	cout << s1.capacity() << endl;//15
	cout << s1 << endl;//an


	system("pause");
	return 0;
}
#endif

//============================================================================

#if 0
//void reserve(size_t n);�ı�Ͳ������Ĵ�С�������޸���Ч�ַ��ĸ���
//1������������n<=��������С           ��������
//             n>�ɿռ��С            ����
//2����С������n>���Ĭ�Ͽռ��С      ������С
//             n<=���Ĭ�Ͽռ��С     ��С����
//����reserve��߲������ݵ�Ч�ʣ��������ݴ����Ŀ���
int main()
{
	string s("anmo");
	s.reserve(10);
	cout << s.size() << endl;//4
	cout << s.capacity() << endl;//15
	s.reserve(15);
	cout << s.size() << endl;//4
	cout << s.capacity() << endl;//15
	s.reserve(40);
	cout << s.size() << endl;//4
	cout << s.capacity() << endl;//47
	s.reserve(80);
	cout << s.size() << endl;//4
	cout << s.capacity() << endl;//95
	s.reserve(30);
	cout << s.size() << endl;//4
	cout << s.capacity() << endl;//95
	s.reserve(16);
	cout << s.size() << endl;//4
	cout << s.capacity() << endl;//95
	s.reserve(8);
	cout << s.size() << endl;//4
	cout << s.capacity() << endl;//15

	system("pause");
	return 0;
}
#endif


//===========================================================================
#if 0
//reverse��ת
int main()
{
	string s("anmo");
	cout << s << endl;//anmo
	reverse(s.begin(), s.end());
	cout << s << endl;//omna

	system("pause");
	return 0;
}
#endif
//===========================================================================

#if 0
//append���
int main()
{
	string s("I");
	string s2(" anmo ");
	s+= " love ";
	cout << s << endl;//I love
	s += " you ";
	cout << s << endl;//I love you
	s.append(s2);
	cout << s << endl;//I love you anmo
	s.append("!!!");
	cout << s << endl;//I love you anmo!!!


	system("pause");
	return 0;
}
#endif

//===========================================================================
#if 0
//insert����
int main()
{
	string s("IYOU");
	s.insert(1, " LOVE ");
	cout << s << endl;//I LOVE YOU

	system("pause");
	return 0;
}
#endif

//===========================================================================
#if 0
//erase��� find����
int main()
{
	string s("hello anmo");
	cout << s << endl;//hello anmo
	s.erase(s.begin() + s.find(" "), s.end());
	cout << s << endl;//hello

	string s1("hauhduadh.txt");
	cout << s1 << endl;//hauhduadh.txt
	s1.erase(s1.begin() + s1.find("."), s1.end());
	cout << s1 << endl;//hauhduadh

	system("pause");
	return 0;
}
#endif

//===========================================================================
#if 0
//substr��ȡ rfind�������
int main()
{
	string s("anmo.txt");
	cout << s << endl;//anmo.txt
	cout << s.substr(s.rfind(".") + 1) << endl;//txt

	string s1("https://www.duba.com/?f=qlswdhq&tjiedb=1&ft=gjlock&--type=0");
	int ret = s1.find(":") + 3;
	cout << s1.substr(ret, s1.find("/", ret)-ret) << endl;//www.duba.com

	system("pause");
	return 0;
}
#endif
//===========================================================================
#if 0
int main()
{
	string s;
	s.push_back('I');//��s�����I
	cout << s << endl;//I
	s.append(" Love ");//��s��׷��һ���ַ���"Love"
	cout << s << endl;//I Love
	s += " you "; // ��s��׷��һ���ַ���'you'
	cout << s << endl;//I Love  you
    s += " anmo ";// ��s��׷��һ���ַ���"anmo" 
	cout << s << endl;//I Love  you  anmo
	s += '!';//��s��׷��һ���ַ�'!'
	cout << s << endl;//I Love  you  anmo !


	//��ȡfile��׺
	string file("anmo.txt");
	size_t pos = file.rfind('.');
	cout << file.substr(pos+1, file.size() - pos) << endl;//txt


	system("pause");
	return 0;
}
#endif
#if 0
void Teststring()
{
	string s1("hello anmo");
	const string s2("hello anmo");
	cout << s1 << " " << s2 << endl;//hello anmo  hello anmo
	cout << s1[0] << " " << s2[0] << endl;//h h

	s1[0] = 'H';
	cout << s1 << endl;//Hello anmo

	//s2[0]='H';//�������ʧ�ܣ���Ϊconst���Ͷ������޸�
}

void TestString()
{
	string s("hello Bit");
	// 3�ֱ�����ʽ��    
	// ��Ҫע����������ַ�ʽ���˱���string���󣬻����Ա������޸�string�е��ַ���    
	// �����������ַ�ʽ����string���ԣ���һ��ʹ�����   
	// 1. for+operator[]    
	for (size_t i = 0; i < s.size(); ++i)
	{
		cout << s[i] << endl;
	}

	// 2.������    
	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << endl;
		++it;
	}

	string::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit << endl;
	}
	// 3.��Χfor
	for (auto ch : s)
	{
		cout << ch << endl;
	}


}
#endif