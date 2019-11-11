

//============================================================================
//#include<iostream>
//using namespace std;
//#include<string>
#if 0
//string 类的四种构造
int main()
{
	string s1;//构造空的string类对象s1
	string s2("hello");//用C格式字符串构造string类对象s2
	string s3(10, '$');//输出10个$的符号
	string s4(s2);//拷贝构造s4
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
//string类对象的容量操作

#if 0
//size：返回字符串有效字符的长度
//length:返回字符串有效字符的长度
//capacity:返回空间总大小
//empty:检测字符串释放为空串，是返回true，否则返回false
//clear:清空有效字符
//resize:将有效字符的个数改成n个，多出的空间用字符c填充
int main()
{
	//注意：string类对象支持直接用cin和cout进行输入和输出
	string s("hello anmo!");
	cout << s.size() << endl;//11
	cout << s.length() << endl;//11
	cout << s.capacity() << endl;//15
	cout << s << endl;//hello anmo!

	//将s中字符串清空，注意清空时只是将size清0，不改变低层空间大小
    s.clear();
	cout << s.size() << endl;//0
	cout << s.length() << endl;//0
	cout << s.capacity() << endl;//15

	//将s中有效字符个数增加到10个，都出的位置用'!'进行填充
	//resize功能：改变string中有效字符的个数
	//1、将有效字符个数增加到n个：多出的位置需要用c来补充（可能需要扩容）
	//2、将有效字符个数减少到n个：只修改有效字符的个数不会缩小空间
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
	s1.resize(2);//将有效字符个数减少到5个
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
//void reserve(size_t n);改变低层容量的大小，不会修改有效字符的个数
//1、扩大容量：n<=旧容量大小           不会扩容
//             n>旧空间大小            扩容
//2、缩小容量：n>最初默认空间大小      不会缩小
//             n<=最初默认空间大小     缩小容量
//利用reserve提高插入数据的效率，避免增容带来的开销
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
//reverse逆转
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
//append添加
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
//insert插入
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
//erase清除 find查找
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
//substr截取 rfind反向查找
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
	s.push_back('I');//在s后插入I
	cout << s << endl;//I
	s.append(" Love ");//在s后追加一个字符串"Love"
	cout << s << endl;//I Love
	s += " you "; // 在s后追加一个字符串'you'
	cout << s << endl;//I Love  you
    s += " anmo ";// 在s后追加一个字符串"anmo" 
	cout << s << endl;//I Love  you  anmo
	s += '!';//在s后追加一个字符'!'
	cout << s << endl;//I Love  you  anmo !


	//获取file后缀
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

	//s2[0]='H';//代码编译失败，因为const类型对象不能修改
}

void TestString()
{
	string s("hello Bit");
	// 3种遍历方式：    
	// 需要注意的以下三种方式除了遍历string对象，还可以遍历是修改string中的字符，    
	// 另外以下三种方式对于string而言，第一种使用最多   
	// 1. for+operator[]    
	for (size_t i = 0; i < s.size(); ++i)
	{
		cout << s[i] << endl;
	}

	// 2.迭代器    
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
	// 3.范围for
	for (auto ch : s)
	{
		cout << ch << endl;
	}


}
#endif