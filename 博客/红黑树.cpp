
#if 0
/*
//�����������������
//        �ڵ���������ɫ����ɫ�ͺ�ɫ
//         ����Լ����5������

1��ÿ���ڵ㶼����ɫ����ɫ���ߺ�ɫ
2�����ڵ����Ϊ��ɫ
3�����һ���ڵ����ɫ�Ǻ�ɫ�����ĺ��ӽڵ�һ���Ǻ�ɫ��
   ������в����������һ��ĺ�ɫ�ڵ�
4��ÿ��·���еĺ�ɫ�ڵ�ĸ�����ͬ
5��ÿ��Ҷ�ӽڵ㶼�Ǻ�ɫ���˴���Ҷ�ӽڵ㣺���еĿ�ָ����


//���ۣ��·���еĽڵ����һ�����ᳬ�����·���нڵ����������
//��ˣ��������һ�Ž���ƽ��Ķ���������
//��������ܱ�AVL�����ѣ�����ʵ�ֱȽϼ�
*/
#include<iostream>
using namespace std;

//�ڵ����ɫ
enum Color{RED,BLACK};

template<class T>
struct RBTreeNode
{
	RBTreeNode(const T& data=T(),Color color=RED)
		:_pLeft(nullptr)
		,_pRight(nullptr)
		,_pParent(nullptr)
		,_data(data)
		,_color(color)
	{}

	RBTreeNode<T>* _pLeft;//�ڵ������
	RBTreeNode<T>* _pRight;//�ڵ���Һ���
	RBTreeNode<T>* _pParent;//�ڵ��˫��
	T _data;//�ڵ��ֵ��
	Color _color;//�ڵ����ɫ

};




template<class T>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T> Self;
public:
	RBTreeIterator(Node* pNode)
		:_pNode(pNode)
	{}

	T& operator*()
	{
		return _pNode->_data;
	}
	T* operator->()
	{
		return &(operator*());
	}

	Self& operator++()
	{
		Increament();
		return *this;
	}

	Self operator++(int)
	{
		Self temp(*this);
		Increament();
		return temp;
	}

	Self& operator--()
	{
		DeIncreament();
		return *this;
	}

	Self operator--(int)
	{
		Self temp(*this);
		DeIncreament();
		return temp;
	}

	bool operator!=(const Self& s)const
	{
		return _pNode != s._pNode;
	}

	bool operator==(const Self& s)const
	{
		return _pNode == s._pNode;
	}
private:
	void Increament()
	{
		if (_pNode->_pRight)
		{
			//���������������Ľڵ�
			_pNode = _pNode->_pRight;
			while (_pNode->_pLeft)
				_pNode = _pNode->_pLeft;
		}
		else
		{
			Node* pParent = _pNode->_pParent;
			while (_pNode == pParent->_pRight)
			{
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}
			// ע�⣺�������-->���ڵ�û���Һ��ӣ��������ڸ�λ��
			if (_pNode->_pRight != pParent)
				_pNode = pParent;
		}
	}

	void DeIncreament()
	{
		//�����������end��λ��
		if (_pNode->_pParent->_pParent == _pNode && _pNode->_color == RED)
		{
			_pNode = _pNode->_pRight;
		}
		else if (_pNode->_pLeft)
		{
			_pNode = _pNode->_pLeft;
			while (_pNode->_pRight)
				_pNode = _pNode->_pRight;
		}
		else
		{
			Node* pParent = _pNode->_pParent;
			while (pParent->_pLeft == _pNode)
			{
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}

			_pNode = pParent;
		}
	}
	Node* _pNode;
};



template<class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef RBTreeIterator<T> iterator;
public:
	RBTree()
	{
		_pHead = new Node;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;

	}

	bool Insert(const T& data)
	{
		// ���ն��������������ʲ����½ڵ�
		Node*& pRoot = GetRoot();
		if (nullptr == pRoot)
		{
			pRoot = new Node(data, BLACK);
			pRoot->_pParent = _pHead;
			return true;
		}
		else
		{
			// �Ҵ�����ڵ��ڶ����������е�λ��
			// ��������˫�׽ڵ�
			Node* cur = pRoot;
			Node* pParent = nullptr;
			while (cur)
			{
				pParent = cur;
				if (data < cur->_data)
					cur = cur->_pLeft;
				else if (data > cur->_data)
					cur = cur->_pRight;
				else
					return false;
			}
			// �����½ڵ�
			cur = new Node(data);
			if (data < pParent->_data)
				pParent->_pLeft =cur;
			else
				pParent->_pRight = cur;

			cur->_pParent = pParent;

			//cur�½ڵ��Ĭ����ɫ����ɫ
			//���pParent����ɫ�Ǻ�ɫ����������������
			//���pParent����ɫ�Ǻ�ɫ��Υ����������----����������һ��ĺ�ɫ�ڵ�
			while (pParent != _pHead && pParent->_color == RED)
			{
				Node* grandFather = pParent->_pParent;
				if (pParent == grandFather->_pLeft)
				{
					Node* uncle = grandFather->_pRight;
					if (uncle && uncle->_color == RED )
					{
						//���һ��
						pParent->_color = BLACK;
						uncle->_color = BLACK;
						grandFather->_color = RED;
						cur = grandFather;
						pParent = cur->_pParent;
					}
					else
					{
						//����ڵ㲻����||����ڵ����&&��ɫ
						if (cur == pParent->_pRight)
						{
							//�������
							RotateL(pParent);
							swap(cur, pParent);
						}

						pParent->_color = BLACK;
						grandFather->_color = RED;
						RotateR(grandFather);
					}
				}
				else
				{
					Node* uncle = grandFather->_pLeft;
					if (uncle&&RED == uncle->_color)
					{
						pParent->_color = BLACK;
						uncle->_color = BLACK;
						grandFather->_color = RED;
						cur = grandFather;
						pParent = cur->_pParent;
					}
					else
					{
						//����ڵ㲻����||������Ϊ��
						if (cur == pParent->_pLeft)
						{
							RotateR(pParent);
							swap(cur, pParent);
						}
						pParent->_color = BLACK;
						grandFather->_color = RED;
						RotateL(grandFather);
					}
				}
			}
		}

		pRoot->_color = BLACK;
		_pHead->_pLeft = leftMost();
		_pHead->_pRight = rightMost();
		return true;
	}

	iterator Begin()
	{
		return iterator(leftMost());
	}
	iterator End()
	{
		return iterator(_pHead);
	}

	Node*& GetRoot()
	{
		return _pHead->_pParent;
	}

	void InOrder()
	{
		_InOrder(GetRoot());
	}

	Node* leftMost()
	{
		Node* pRoot = GetRoot();
		if (nullptr == pRoot)
			return _pHead;

		Node* cur = pRoot;
		while (cur->_pLeft)
			cur = cur->_pLeft;

		return cur;
	}

	Node* rightMost()
	{
		Node* pRoot = GetRoot();
		if (nullptr == pRoot)
			return _pHead;

		Node* cur = pRoot;
		while (cur->_pRight)
			cur = cur->_pRight;

		return cur;
	}

	bool IsValidRBTree()
	{
		Node* pRoot = GetRoot();
		if (nullptr == pRoot)
			return true;

		if (pRoot->_color != BLACK)
		{
			cout << "Υ������һ�����ڵ��Ǻ�ɫ" << endl;
			return false;
		}

		//��ȡһ��·���к�ɫ�ڵ�ĸ���
		size_t blackCount = 0;
		Node* cur = pRoot;
		while (cur)
		{
			if (cur->_color == BLACK)
				blackCount++;

			cur = cur->_pLeft;
		}

		size_t pathBlack = 0;
		return _IsValidRBTree(pRoot, blackCount, pathBlack);
	}

private:
	bool _IsValidRBTree(Node* pRoot, size_t blackCount, size_t pathBlack)
	{
		if (nullptr == pRoot)
			return true;

		if (pRoot->_color == BLACK)
			pathBlack++;

		Node* pParent = pRoot->_pParent;
		if (pParent != _pHead && RED == pParent->_color&&RED == pRoot->_color)
		{
			cout << "Υ������3�����ܴ�������һ��ĺ�ɫ�ڵ�" << endl;
			return false;
		}

		//Ҷ�ӽڵ�
		if (nullptr == pRoot->_pLeft&&nullptr == pRoot->_pRight)
		{
			if (pathBlack != blackCount)
			{
				cout << "Υ������4��ÿ��·���к�ɫ�ڵ��������ͬ" << endl;
				return false;
			}
		}
		return _IsValidRBTree(pRoot->_pLeft, blackCount, pathBlack) &&
			_IsValidRBTree(pRoot->_pRight, blackCount, pathBlack);
	}


	void _InOrder(Node* pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);
		}
	}

	void RotateL(Node* pParent)
	{
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;

		pParent->_pRight = pSubRL;
		if (pSubRL)
			pSubRL->_pParent = pParent;

		pSubR->_pLeft = pParent;
		Node* ppParent = pParent->_pParent;

		pSubR->_pParent = ppParent;
		pParent->_pParent = pSubR;
		if (ppParent == nullptr)
		{
			_pHead->_pParent = pSubR;
		}
		else
		{
			if (pParent == ppParent->_pLeft)
				ppParent->_pLeft = pSubR;
			else
				ppParent->_pRight = pSubR;
		}

	}
	void RotateR(Node* pParent)
	{
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;

		pParent->_pLeft = pSubLR;
		if (pSubLR)
			pSubLR->_pParent = pParent;

		pSubL->_pRight = pParent;

		Node* pPParent = pParent->_pParent;
		pParent->_pParent = pSubL;
		pSubL->_pParent = pPParent;

		if (pPParent == _pHead)
			_pHead->_pParent = pSubL;
		else
		{
			if (pParent == pPParent->_pLeft)
				pPParent->_pLeft = pSubL;
			else
				pPParent->_pRight = pSubL;
		}
	}
private:
	Node* _pHead;
};


int main()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	RBTree<int> t;
	for (auto e : a)
		t.Insert(e);

	t.InOrder();
	cout << endl;

	cout << t.leftMost()->_data << endl;
	cout << t.rightMost()->_data << endl;

	if (t.IsValidRBTree())
		cout << "t is RBTree" << endl;
	else
		cout << "t is not RBTree" << endl;


	auto it = t.Begin();
	while (it != t.End())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;

enum Color{RED,BLACK};

template<class T>
struct RBTreeNode
{
	RBTreeNode(const T& data=T(),Color color=RED)
		:_pLeft(nullptr)
		,_pRight(nullptr)
		,_pParent(nullptr)
		,_data(data)
		,_color(color)
	{}

	RBTreeNode<T>* _pLeft;
	RBTreeNode<T>* _pRight;
	RBTreeNode<T>* _pParent;
	T _data;
	Color _color;
};


template<class T>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T> Self;
public:
	RBTreeIterator(Node* pNode)
		:_pNode(pNode)
	{}

	T& operator*()
	{
		return _pNode->_data;
	}
	T* operator->()
	{
		return &(operator*());
	}

	Self& operator++()
	{
		Increament();
		return *this;
	}
	Self operator++(int)
	{
		Self temp(*this);
		Increament();
		return temp;
	}

	Self& operator--()
	{
		DeIncreament();
		return *this;
	}
	Self operator--(int)
	{
		Self temp(*this);
		DeIncreament();
		return temp;
	}
	bool operator==(const Self& s)const
	{
		return _pNode != s._pNode;
	}

	bool operator!=(const Self& s)const
	{
		return _pNode != s._pNode;
	}
private:
	void Increament()
	{
		if (_pNode->_pRight)
		{
			_pNode = _pNode->_pParent;
			while (_pNode->_pLeft)
				_pNode = _pNode->_pLeft;
		}
		else
		{
			Node* pParent = _pNode->_pParent;
			while (_pNode == pParent->_pRight)
			{
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}
			if (_pNode->_pRight != pParent)
				_pNode = pParent;
		}
	}
	// --
	void DeIncreament()
	{
		// �����������end��λ��
		if (_pNode->_pParent->_pParent == _pNode && _pNode->_color == RED)
			_pNode = _pNode->_pRight;
		else if (_pNode->_pLeft)
		{
			_pNode = _pNode->_pLeft;
			while (_pNode->_pRight)
				_pNode = _pNode->_pRight;
		}
		else
		{
			Node* pParent = _pNode->_pParent;
			while (pParent->_pLeft == _pNode)
			{
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}

			_pNode = pParent;
		}
	}
	Node* _pNode;
};

// T: �����Ǽ�ֵ��<key,value>
//    ������һ��key
// ���۽ڵ��д洢����<key, value> || key, ���ǰ���key�����бȽϵ�
// KeyOfValue: ��ȡdata�е�Key
template<class T,class KeyOfValue>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef RBTreeIterator<T> iterator;
public:
	RBTree()
		:_size(0)
	{
		_pHead = new Node;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
	}

	pair<iterator,bool> Insert(const T& data)
	{
		Node* & pRoot = GetRoot();
		Node* pNewNode = nullptr;
		if (nullptr == pRoot)
		{
			pNewNode = pRoot = new Node(data, BLACK);
			pRoot->_pParent = _pHead;
		}
		else
		{
			Node* cur = pRoot;
			Node* pParent = nullptr;
			while (cur)
			{
				pParent = cur;
				if (KeyOfValue()(data) < KeyOfValue()(cur->_data))
					cur = cur->_pLeft;
				else if (KeyOfValue()(data)> KeyOfValue()(cur->_data))
					cur = cur->_pRight;
				else
					return make_pair(iterator(cur), false);
			}
			//�����½ڵ�
			pNewNode = cur = new Node(data);
			if ((KeyOfValue()(data) < KeyOfValue()(pParent->_data)))
				pParent->_pLeft = cur;
			else
				pParent->_pRight = cur;

			cur->_pParent = pParent;

			// pCur�½ڵ�Ĭ����ɫ����ɫ
			// ���pParent����ɫ�Ǻ�ɫ�ģ�������������
			// ���pParent����ɫ�Ǻ�ɫ�ģ�Υ����������--����������һ��ĺ�ɫ�ڵ�

			while (pParent != _pHead && pParent->_color == RED)
			{
				Node*grandFather = pParent->_pParent;
				if (pParent == grandFather->_pLeft)
				{
					Node* uncle = grandFather->_pRight;
					if (uncle&&RED==uncle->_color)
					{
						pParent->_color = BLACK;
						uncle->_color = BLACK;
						grandFather->_color = RED;
						cur = grandFather;
						pParent = cur->_pParent;
					}
					else
					{
						if (cur == pParent->_pRight)
						{
							RotateL(pParent);
							swap(cur, pParent);
						}
						pParent->_color = BLACK;
						grandFather->_color = RED;
						RotateR(grandFather);
					}
				}
				else
				{
					Node* uncle = grandFather->_pLeft;
					if (uncle&&RED == uncle->_color )
					{
						pParent->_color = BLACK;
						uncle->_color = BLACK;
						grandFather->_color = RED;
						cur = grandFather;
						pParent = cur->_pParent;
					}
					else
					{
						if (cur == pParent->_pLeft)
						{
							RotateR(pParent);
							swap(cur, pParent);

						}

						pParent->_color = BLACK;
						grandFather->_color = RED;
						RotateL(grandFather);
					}
				}
			}
		}
		++_size;
		pRoot->_color = BLACK;
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();
		return make_pair(iterator(pNewNode), true);
	}
	iterator Begin()
	{
		return iterator(LeftMost());
	}
	iterator End()
	{
		return iterator(_pHead);
	}

	bool Empty()const
	{
		return _pHead->_pLeft == _pHead;
	}
	size_t Size()const
	{
		return _size;
	}

	void Clear()
	{
		_Destroy(GetRoot());
	}

	iterator Find(const T& data)
	{
		Node* cur = GetRoot();
		while (cur)
		{
			if ((KeyOfValue()(data) == KeyOfValue()(cur->_data)))
			{
				return iterator(cur);
			}
			else if ((KeyOfValue()(data) < KeyOfValue()(cur->_data)))
				cur = cur->_pLeft;
			else
				cur = cur->_pRight;
		}

		return End();
	}
	Node*& GetRoot()
	{
		return _pHead->_pParent;
	}

	void InOrder()
	{
		_InOrder(GetRoot());
	}

	Node* LeftMost()
	{
		Node* pRoot = GetRoot();
		if (nullptr == pRoot)
		{
			return _pHead;
		}

		Node* cur = pRoot;
		while (cur->_pLeft)
			cur = cur->_pLeft;
		return cur;
	}
	Node* RightMost()
	{
		Node* pRoot = GetRoot();
		if (nullptr == pRoot)
		{
			return _pHead;
		}
		Node* cur = pRoot;
		while (cur->_pRight)
			cur = cur->_pRight;

		return cur;
	}

	bool IsValidRBTree()
	{
		Node* pRoot = GetRoot();
		if (nullptr == pRoot)
			return true;

		if (pRoot->_color != BLACK)
		{
			cout << "Υ������һ�����ڵ��Ǻ�ɫ" << endl;
			return false;
		}

		size_t blackCount = 0;
		Node* cur = pRoot;
		while (cur)
		{
			if (cur->_color == BLACK)
				blackCount++;

			cur = cur->_pLeft;
		}

		size_t pathBlack = 0;
		return _IsValidRBTree(pRoot, blackCount, pathBlack);
	}
private:
	void _Destroy(Node*& pRoot)
	{
		if (pRoot)
		{
			_Destroy(pRoot->_pLeft);
			_Destroy(pRoot->_pRight);
			delete pRoot;
			pRoot = nullptr;
		}
	}

	bool _IsValidRBTree(Node* pRoot, size_t blackCount, size_t pathBlack)
	{
		if (nullptr == pRoot)
			return true;

		if (pRoot->_color == BLACK)
			pathBlack++;

		Node* pParent = pRoot->_pParent;
		if (pParent != _pHead && RED == pParent->_color&&RED == pRoot->_color)
		{
			cout << "Υ������3�����ܴ�������һ��ĺ�ɫ�ڵ�" << endl;
			return false;
		}

		if (nullptr == pRoot->_pLeft&&nullptr == pRoot->_pRight)
		{
			if (blackCount != pathBlack)
			{
				cout << "Υ������4��ÿ��·���к�ɫ�ڵ��������ͬ" << endl;
				return false;
			}
		}

		return _IsValidRBTree(pRoot->_pLeft, blackCount, pathBlack) &&
			_IsValidRBTree(pRoot->_pRight, blackCount, pathBlack);
	}

	void _InOrder(Node* pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);
		}
	}

	void RotateL(Node* pParent)
	{
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;

		pParent->_pRight = pSubRL;
		if (pSubRL)
			pSubRL->_pParent = pParent;

		pSubR->_pLeft = pParent;
		Node*ppParent = pParent->_pParent;
		
		pParent->_pParent = pSubR;
		pSubR->_pParent = ppParent;
		if (ppParent==_pHead)
		{
			_pHead->_pParent = pSubR;
		}
		else
		{
			if (pParent == ppParent->_pLeft)
				ppParent->_pLeft = pSubR;
			else
				ppParent->_pRight = pSubR;
		}
	}

	void RotateR(Node* pParent)
	{
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pParent->_pRight;

		pParent->_pLeft = pSubLR;
		if (pSubLR)
			pSubLR->_pParent = pParent;

		pSubL->_pRight = pParent;

		Node* ppParent = pParent->_pParent;
		pParent->_pParent = pSubL;
		pSubL->_pParent = ppParent;
		if (ppParent ==_pHead)
			_pHead->_pParent = pSubL;
		else
		{
			if (pParent == ppParent->_pLeft)
				ppParent->_pLeft = pSubL;
			else
				ppParent->_pRight = pSubL;
		}
	}
private:
	Node* _pHead;
	size_t _size;
};


//map
namespace bite
{
	template<class K,class V>
	class map
	{
		typedef pair<K, V> ValueType;

		struct KeyOfValue
		{
			const K& operator()(const ValueType& data)
			{
				return data.first;
			}
		};

		typedef RBTree<ValueType, KeyOfValue> RBTree;
		typename typedef RBTree::iterator iterator;

	public:
		map()
			:t()
		{}


		/////////////////////////////
		// iterator
		iterator begin()
		{
			return t.Begin();
		}
		iterator end()
		{
			return t.End();
		}

		///////////////////////////////
		// capacity

		bool empty()const
		{
			return t.Empty();
		}

		size_t size()const
		{
			return t.Size();
		}
		///////////////////////////////
		// access

		V& operator[](const K& key)
		{
			return (*(t.Insert(pair<K, V>(key, V())).first)).second;
		}

		///////////////////////////////
		// modify
		pair<iterator, bool> insert(const ValueType& data)
		{
			return t.Insert(data);
		}

		void clear()
		{
			return t.Clear();
		}

		iterator find(const K& key)
		{
			return t.Find(pair<K, V>(key, V()));
		}
	private:
		RBTree t;
	};
}
#include<string>
int main()
{
	bite::map<string, string> m;
	m.insert(pair<string, string>("�ν�", "��ʱ��"));
	m.insert(make_pair("�ν�", "��ʱ��"));
	m["����"] = "������";
	cout << m.size() << endl;

	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "--->" << it->second << endl;
		++it;
	}

	m.insert(make_pair("����", "��ţ"));
	cout << m.size() << endl;

	it = m.find("�ֳ�");
	if (it != m.end())
	{
		cout << it->second << endl;
	}
	else
	{
		cout << "�޴���" << endl;
	}
}



namespace bite
{
	template<class K>
	class set
	{
		typedef K ValueType;

		struct KeyOfValue
		{
			const K& operator()(const ValueType& data)
			{
				return data;
			}
		};

		typedef RBTree<ValueType, KeyOfValue> RBTree;
		typename typedef RBTree::iterator iterator;
	public:
		set()
			:t()
		{}

		////////////////////////////
		// iterator
		iterator begin()
		{
			return t.Begin();
		}
		iterator end()
		{
			return t.End();
		}
		//////////////////////////////
		// capacity
		bool empty()const
		{
			return t.Empty();
		}
		size_t size()const
		{
			return t.Size();
		}

		///////////////////////////
		// modify
		pair<iterator, bool> insert(const ValueType& data)
		{
			return t.Insert(data);
		}

		void clear()
		{
			t.Clear();
		}

		iterator find(const K& key)
		{
			return t.Find(key);
		}
	private:
		RBTree t;
	};
}

int main()
{
	int array[] = { 1,2,3,4,5,6,7,8,9,0,0,9,8,7,6,5,4,3,2,1 };
	bite::set<int> s;
	for (auto e : array)
		s.insert(e);

	cout << s.size() << endl;

	for (auto e : s)
		cout << e << " ";
	cout << endl;
}

#endif 