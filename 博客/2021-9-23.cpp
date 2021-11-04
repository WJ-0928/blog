#include<iostream>
using namespace std;

//void Swap(int& left, int& right) {
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right) {
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right) {
//	char temp = left;
//	left = right;
//	right = temp;
//}



//template<typename T>
//T Add(T& left, T& right) {
//	return left + right;
//}

//template<class T> 
//
//T Add(const T& left, const T& right) {
//	return left + right;
//}
//int main()
//{
//	int a1 = 1, a2 = 2;
//	double d1 = 1.0, d2 = 2.0;
//	Add(a1, a2);
//	Add(d1, d2);
//
//	/*
//	该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型
//	通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有一个T，
//	编译器无法确定此处到底该将T确定为int 或者 double类型而报错
//	注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要背黑锅
//	Add(a1, d1);
//	*/
//
//	// 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化
//	Add(a, (int)d);
//	return 0;
//}
//template<class T>
//
//T Add(const T& left, const T& right) {
//	return left + right;
//}
//int main(void) {
//
//	// 显式实例化
//	Add<int>(1, 12.0);
//	return 0;
//}


//// 普通函数
//int Add(int left, int right)
//{
//    return left + right;
//}
//// 函数模板
//template<class T>
//T Add(T left, T right) {
//    return left + right;
//}
//void Test()
//{
//    Add(1, 2); // 与非模板函数匹配，编译器不需要特化
//    Add<int>(1, 2); // 调用编译器特化的Add版本
//}

//
//// 普通函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 函数模板
//template<class T，class U>
//T Add(T left, U right) {
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
//	Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
//}
//
//
//int main()
//{
//	Test();
//	return 0;
//}

//
//template<class T>
//
//class SeqList
//{
//public:
//	SeqList(int capacity = 10)
//	{
//		capacity = capacity < 10 ? 10 : capacity;
//		_array = new T[capacity];
//		_capacity = capacity;
//		_size = 0;
//	}
//	//在类中声明，类外定义
//	~SeqList() {}
//private:
//	T* _array;
//	int _size;
//	int _capacity;
//};
//template<class T>
//SeqList<T>::~SeqList()
//{
//	if (_array)
//	{
//		delete[] _array;
//		_array = nullptr;
//		_capacity = 0;
//		_size = 0;
//	}
//}
//
//int main()
//{
//	// SeqList类名，SeqList<int>才是类型
//	SeqList<int> s1;
//
//	SeqList<double> s2;
//}

//
//void Teststring1()
//{
//	// 注意：string类对象支持直接用cin和cout进行输入和输出
//	string s("hello, bit!!!");
//	cout << s.size() << endl;
//	cout << s.length() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//
//	// 将s中的字符串清空，注意清空时只是将size清0，不改变底层空间的大小
//	s.clear();
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	// 将s中有效字符个数增加到10个，多出位置用'a'进行填充
//	// “aaaaaaaaaa”
//	s.resize(10, 'a');
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	// 将s中有效字符个数增加到15个，多出位置用缺省值'\0'进行填充
//	// "aaaaaaaaaa\0\0\0\0\0"
//	// 注意此时s中有效字符个数已经增加到15个
//	s.resize(15);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//	// 将s中有效字符个数缩小到5个
//	s.resize(5);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//}
////================================================================================
//void Teststring2()
//{
//	string s;
//	// 测试reserve是否会改变string中有效元素个数
//	s.reserve(100);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	// 测试reserve参数小于string的底层空间大小时，是否会将空间缩小
//	s.reserve(50);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//}
//// 利用reserve提高插入数据的效率，避免增容带来的开销
////================================================================================
//void TestPushBack()
//{
//	string s;
//	size_t sz = s.capacity();
//	cout << "making s grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		s.push_back('c');
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}
//void TestPushBackReserve()
//{
//	string s;
//	s.reserve(100);
//	size_t sz = s.capacity();
//
//	cout << "making s grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		s.push_back('c');
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}


//void Teststring()
//{
//	string s1("hello Bit");
//	const string s2("Hello Bit");
//	cout << s1 << " " << s2 << endl;
//	cout << s1[0] << " " << s2[0] << endl;
//
//	s1[0] = 'H';
//	cout << s1 << endl;
//
//	// s2[0] = 'h'; 代码编译失败，因为const类型对象不能修改
//}
//void Teststring()
//{
//	string s("hello Bit");
//	// 3种遍历方式：
//	// 需要注意的以下三种方式除了遍历string对象，还可以遍历是修改string中的字符，
//	// 另外以下三种方式对于string而言，第一种使用最多
//	// 1. for+operator[]
//	for (size_t i = 0; i < s.size(); ++i)
//		cout << s[i] << endl;
//
//	// 2.迭代器
//	string::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << endl;
//		++it;
//	}
//
//	string::reverse_iterator rit = s.rbegin();
//	while (rit != s.rend())
//		cout << *rit << endl;
//
//	// 3.范围for
//	for (auto ch : s)
//		cout << ch << endl;
//}


//void Teststring()
//{
//	string str;
//	str.push_back(' '); // 在str后插入空格
//	str.append("hello"); // 在str后追加一个字符"hello"
//	str += 'b'; // 在str后追加一个字符'b' 
//	str += "it"; // 在str后追加一个字符串"it"
//	cout << str << endl;
//	cout << str.c_str() << endl; // 以C语言的方式打印字符串
//
//	// 获取file的后缀
//	string file1("string.cpp");
//	size_t pos = file.rfind('.');
//	string suffix(file.substr(pos, file.size() - pos));
//	cout << suffix << endl;
//
//	// npos是string里面的一个静态成员变量
//	// static const size_t npos = -1;
//
//	// 取出url中的域名
//	sring url("http://www.cplusplus.com/reference/string/string/find/");
//	cout << url << endl;
//	size_t start = url.find("://");
//	if (start == string::npos)
//	{
//		cout << "invalid url" << endl;
//		return;
//	}
//	start += 3;
//	size_t finish = url.find('/', start);
//	string address = url.substr(start, finish - start);
//	cout << address << endl;
//
//	// 删除url的协议前缀
//	pos = url.find("://");
//	url.erase(0, pos + 3);
//	cout << url << endl;
//}


//
//-**reverse逆转 * *
//
//int main()
//{
//    string s("anmo");
//    cout << s << endl;//anmo
//    reverse(s.begin(), s.end());
//    cout << s << endl;//omna
//
//    system("pause");
//    return 0;
//}
//
//- **append添加 * *
//
//int main()
//{
//    string s("I");
//    string s2(" anmo ");
//    s += " love ";
//    cout << s << endl;//I love
//    s += " you ";
//    cout << s << endl;//I love you
//    s.append(s2);
//    cout << s << endl;//I love you anmo
//    s.append("!!!");
//    cout << s << endl;//I love you anmo!!!
//
//
//    system("pause");
//    return 0;
//}
//
//- **insert插入 * *
//
//int main()
//{
//    string s("IYOU");
//    s.insert(1, " LOVE ");
//    cout << s << endl;//I LOVE YOU
//
//    system("pause");
//    return 0;
//}
//
//- **erase清除 find查找 * *
//
//int main()
//{
//    string s("hello anmo");
//    cout << s << endl;//hello anmo
//    s.erase(s.begin() + s.find(" "), s.end());
//    cout << s << endl;//hello
//
//    //  获取file的后缀
//    string s1("hauhduadh.txt");
//    cout << s1 << endl;//hauhduadh.txt
//    s1.erase(s1.begin() + s1.find("."), s1.end());
//    cout << s1 << endl;//hauhduadh
//
//    system("pause");
//    return 0;
//}
//
//- **substr截取 rfind反向查找 * *
//
//int main()
//{
//    string s("anmo.txt");
//    cout << s << endl;//anmo.txt
//    cout << s.substr(s.rfind(".") + 1) << endl;//txt
//
//    string s1("https://www.duba.com/?f=qlswdhq&tjiedb=1&ft=gjlock&--type=0");
//    int ret = s1.find(" : ") + 3;
//    cout << s1.substr(ret, s1.find("/", ret) - ret) << endl;//www.duba.com
//
//    system("pause");
//    return 0;
//}
//
//- push_back、append
//
//int main()
//{
//    string s;
//    s.push_back('I');//在s后插入I
//    cout << s << endl;//I
//    s.append(" Love ");//在s后追加一个字符串"Love"
//    cout << s << endl;//I Love
//    s += " you "; // 在s后追加一个字符串'you'
//    cout << s << endl;//I Love  you
//    s += " anmo ";// 在s后追加一个字符串"anmo" 
//    cout << s << endl;//I Love  you  anmo
//    s += '!';//在s后追加一个字符'!'
//    cout << s << endl;//I Love  you  anmo !
//
//
//    //获取file后缀
//    string file("anmo.txt");
//    size_t pos = file.rfind('.');
//    cout << file.substr(pos + 1, file.size() - pos) << endl;//txt
//
//
//    system("pause");
//    return 0;
//}


//class string
//{
//public:
//	/*string()
//	:_str(new char[1])
//	{*_str = '\0';}
//	*/
//	//string(const char* str = "\0") 错误示范
//	//string(const char* str = nullptr) 错误示范
//	string(const char* str = "")
//	{
//		// 构造string类对象时，如果传递nullptr指针，认为程序非法，此处断言下
//		if (nullptr == str)
//		{
//			assert(false);
//			return;
//		}
//
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//
//	~string()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//
//private:
//	char* _str;
//};
//// 测试
//void Teststring()
//{
//	string s1("hello bit!!!");
//	string s2(s1);
//}


//class string
//{
//public:
//	string(const char* str = "")
//	{
//		// 构造string类对象时，如果传递nullptr指针，认为程序非法，此处断言下
//		if (nullptr == str)
//		{
//			assert(false);
//			return;
//		}
//
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//
//	string(const string& s)
//		: _str(new char[strlen(s._str) + 1])
//	{
//		strcpy(_str, s._str);
//	}
//
//	string& operator=(const string& s)
//	{
//		if (this != &s)
//		{
//			char* pStr = new char[strlen(s._str) + 1];
//			strcpy(pStr, s._str);
//			delete[] _str;
//			_str = pStr;
//		}
//
//		return *this;
//	}
//
//	~string()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//
//private:
//	char* _str;
//};

//namespace bit
//{
//	class string
//	{
//	public:
//		typedef char* iterator;
//	public:
//		string(const char* str = "")
//		{
//			_size = strlen(str);
//			_capacity = _size;
//			_str = new char[_capacity + 1];
//			strcpy(_str, str);
//		}
//		string(const string& s)
//			: _str(nullptr)
//			, _size(0)
//			, _capacity(0)
//		{
//			string tmp(s);
//			this->Swap(tmp);
//		}
//		string& operator=(string s)
//		{
//			this->Swap(s);
//			return *this;
//		}
//		~string()
//		{
//			if (_str)
//			{
//				delete[] _str;
//				_str = nullptr;
//			}
//		}
//		/////////////////////////////////////////////////////////////////
//		// iterator
//		iterator begin() { return _str; }
//		iterator end() { return _str + _size; }
//		/////////////////////////////////////////////////////////////////
//		// modify
//		void push_back(char c)
//		{
//			if (_size == _capacity)
//				Reserve(_capacity * 2);
//
//			_str[_size++] = c;
//			_str[_size] = '\0';
//		}
//		string& operator+=(char c)
//		{
//			PushBack(c);
//			return *this;
//		}
//
//		// 作业实现
//		void append(const char* str);
//		string& operator+=(const char* str);
//		void clear()
//		{
//			_size = 0;
//			_str[_size] = '\0';
//		}
//		void swap(string& s)
//		{
//			swap(_str, s._str);
//			swap(_size, s._size);
//			swap(_capacity, s._capacity);
//		}
//		const char* c_str()const
//		{
//			return _str;
//		}
//		/////////////////////////////////////////////////////////////////
//		// capacity
//		size_t size()const
//			size_t capacity()const
//			bool empty()const
//
//			void resize(size_t newSize, char c = '\0')
//		{
//			if (newSize > _size)
//			{
//				// 如果newSize大于底层空间大小，则需要重新开辟空间
//				if (newSize > _capacity)
//				{
//					Reserve(newSize);
//				}
//				memset(_str + _size, c, newSize - _size);
//			}
//			_size = newSize;
//			_str[newSize] = '\0';
//		}
//		void reserve(size_t newCapacity)
//		{
//			// 如果新容量大于旧容量，则开辟空间
//			if (newCapacity > _capacity)
//			{
//				char* str = new char[newCapacity + 1];
//				strcpy(str, _str);
//				// 释放原来旧空间,然后使用新空间
//				delete[] _str;
//				_str = str;
//				_capacity = newCapacity;
//			}
//		}
//		////////////////////////////////////////////////////////////////////
//		// access
//		char& operator[](size_t index)
//		{
//			assert(index < _size);
//			return _str[index];
//		}
//		const char& operator[](size_t index)const
//		{
//			assert(index < _size);
//			return _str[index];
//		}
//		////////////////////////////////////////////////////////////////////
//		// 作业
//		bool operator<(const string& s);
//		bool operator<=(const string& s);
//		bool operator>(const string& s);
//		bool operator>=(const string& s);
//		bool operator==(const string& s);
//		bool operator!=(const string& s);
//		// 返回c在string中第一次出现的位置
//		size_t find(char c, size_t pos = 0) const;
//		// 返回子串s在string中第一次出现的位置
//		size_t find(const char* s, size_t pos = 0) const;
//
//		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
//		string& insert(size_t pos, char c);
//		string& insert(size_t pos, const char* str);
//		// 删除pos位置上的元素，并返回该元素的下一个位置
//		string& erase(size_t pos, size_t len);
// private:
//	 friend ostream& operator<<(ostream& _cout, const bit::string& s);
//	 friend istream& operator>>(istream& _cin, bit::string& s);
// private:
//	 char* _str;
//	 size_t _capacity;
//	 size_t _size;
// };
//}
//ostream& bit::operator<<(ostream& _cout, const bit::string& s) {
//	// 不能使用这个
//	//cout << s._str;
//	for (size_t i = 0; i < s.size(); ++i)
//	{
//		_cout << s[i];
//	}
//	return _cout;
//}
/////////对自定义的string类进行测试
//void TestBitstring()
//{
//	bit::string s1("hello");
//	s1.push_back(' ');
//	s1.push_back('b');
//	s1.append(1, 'i');
//	s1 += 't';
//	cout << s1 << endl;
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	// 利用迭代器打印string中的元素
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	// 这里可以看到一个类只要支持的基本的iterator，就支持范围for
//	for (auto ch : s1)
//		cout << ch << " ";
//	cout << endl;
//}

// constructing vectors
//#include <iostream>
//#include <vector>
//int main()
//{
//	// constructors used in the same order as described above:
//	std::vector<int> first; // empty vector of ints
//	std::vector<int> second(4, 100); // four ints with value 100
//	std::vector<int> third(second.begin(), second.end()); // iterating through second
//	std::vector<int> fourth(third); // a copy of third
//	// 下面涉及迭代器初始化的部分，我们学习完迭代器再来看这部分
//	// the iterator constructor can also be used to construct from arrays:
//	int myints[] = { 16,2,77,29 };
//	std::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
//	std::cout << "The contents of fifth are:";
//	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//void PrintVector(const vector<int>& v) {
//	// const对象使用const迭代器进行遍历打印
//	vector<int>::const_iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//int main()
//{
//	// 使用push_back插入4个数据
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	// 使用迭代器进行遍历打印
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	// 使用迭代器进行修改
//	it = v.begin();
//	while (it != v.end())
//	{
//		*it *= 2;
//		++it;
//	}
//	// 使用反向迭代器进行遍历再打印
//	vector<int>::reverse_iterator rit = v.rbegin();
//	while (rit != v.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//	PrintVector(v);
//	return 0;
//}

// push_back/pop_back
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	v.pop_back();
	v.pop_back();
	it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 使用find查找3所在位置的iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	// 在pos位置之前插入30
	v.insert(pos, 30);
	vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;

	pos = find(v.begin(), v.end(), 3);
	// 删除pos位置的数据
	v.erase(pos);
	it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;

	return 0;
}