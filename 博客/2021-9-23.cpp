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
//	����䲻��ͨ�����룬��Ϊ�ڱ����ڼ䣬��������������ʵ����ʱ����Ҫ������ʵ������
//	ͨ��ʵ��a1��T����Ϊint��ͨ��ʵ��d1��T����Ϊdouble���ͣ���ģ������б���ֻ��һ��T��
//	�������޷�ȷ���˴����׸ý�Tȷ��Ϊint ���� double���Ͷ�����
//	ע�⣺��ģ���У�������һ�㲻���������ת����������Ϊһ��ת�������⣬����������Ҫ���ڹ�
//	Add(a1, d1);
//	*/
//
//	// ��ʱ�����ִ���ʽ��1. �û��Լ���ǿ��ת�� 2. ʹ����ʽʵ����
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
//	// ��ʽʵ����
//	Add<int>(1, 12.0);
//	return 0;
//}


//// ��ͨ����
//int Add(int left, int right)
//{
//    return left + right;
//}
//// ����ģ��
//template<class T>
//T Add(T left, T right) {
//    return left + right;
//}
//void Test()
//{
//    Add(1, 2); // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
//    Add<int>(1, 2); // ���ñ������ػ���Add�汾
//}

//
//// ��ͨ����
//int Add(int left, int right)
//{
//	return left + right;
//}
//// ����ģ��
//template<class T��class U>
//T Add(T left, U right) {
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
//	Add(1, 2.0); // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
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
//	//���������������ⶨ��
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
//	// SeqList������SeqList<int>��������
//	SeqList<int> s1;
//
//	SeqList<double> s2;
//}

//
//void Teststring1()
//{
//	// ע�⣺string�����֧��ֱ����cin��cout������������
//	string s("hello, bit!!!");
//	cout << s.size() << endl;
//	cout << s.length() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//
//	// ��s�е��ַ�����գ�ע�����ʱֻ�ǽ�size��0�����ı�ײ�ռ�Ĵ�С
//	s.clear();
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	// ��s����Ч�ַ��������ӵ�10�������λ����'a'�������
//	// ��aaaaaaaaaa��
//	s.resize(10, 'a');
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	// ��s����Ч�ַ��������ӵ�15�������λ����ȱʡֵ'\0'�������
//	// "aaaaaaaaaa\0\0\0\0\0"
//	// ע���ʱs����Ч�ַ������Ѿ����ӵ�15��
//	s.resize(15);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//	// ��s����Ч�ַ�������С��5��
//	s.resize(5);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//}
////================================================================================
//void Teststring2()
//{
//	string s;
//	// ����reserve�Ƿ��ı�string����ЧԪ�ظ���
//	s.reserve(100);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	// ����reserve����С��string�ĵײ�ռ��Сʱ���Ƿ�Ὣ�ռ���С
//	s.reserve(50);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//}
//// ����reserve��߲������ݵ�Ч�ʣ��������ݴ����Ŀ���
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
//	// s2[0] = 'h'; �������ʧ�ܣ���Ϊconst���Ͷ������޸�
//}
//void Teststring()
//{
//	string s("hello Bit");
//	// 3�ֱ�����ʽ��
//	// ��Ҫע����������ַ�ʽ���˱���string���󣬻����Ա������޸�string�е��ַ���
//	// �����������ַ�ʽ����string���ԣ���һ��ʹ�����
//	// 1. for+operator[]
//	for (size_t i = 0; i < s.size(); ++i)
//		cout << s[i] << endl;
//
//	// 2.������
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
//	// 3.��Χfor
//	for (auto ch : s)
//		cout << ch << endl;
//}


//void Teststring()
//{
//	string str;
//	str.push_back(' '); // ��str�����ո�
//	str.append("hello"); // ��str��׷��һ���ַ�"hello"
//	str += 'b'; // ��str��׷��һ���ַ�'b' 
//	str += "it"; // ��str��׷��һ���ַ���"it"
//	cout << str << endl;
//	cout << str.c_str() << endl; // ��C���Եķ�ʽ��ӡ�ַ���
//
//	// ��ȡfile�ĺ�׺
//	string file1("string.cpp");
//	size_t pos = file.rfind('.');
//	string suffix(file.substr(pos, file.size() - pos));
//	cout << suffix << endl;
//
//	// npos��string�����һ����̬��Ա����
//	// static const size_t npos = -1;
//
//	// ȡ��url�е�����
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
//	// ɾ��url��Э��ǰ׺
//	pos = url.find("://");
//	url.erase(0, pos + 3);
//	cout << url << endl;
//}