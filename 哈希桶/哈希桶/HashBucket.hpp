
#if 0
#include<iostream>
#include<vector>
using namespace std;

//ȡ��һ������
const int PRIMECOUNT = 28;
const size_t primeList[PRIMECOUNT] =
{
	53ul, 97ul, 193ul, 389ul, 769ul,
	1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
	49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
	1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
	50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
	1610612741ul, 3221225473ul, 4294967291ul
};

size_t GetNextPrime(size_t prime)
{
	size_t i = 0;
	for (; i < PRIMECOUNT; ++i)
	{
		if (primeList[i] > prime)
			return primeList[i];
	}
	return primeList[i];
}


template<class T>
struct HBNode
{
	HBNode(const T& data=T())
		:_data(data)
		,_pNext(nullptr)
	{}

	T _data;
	HBNode<T>* _pNext;
};

//T��������ε�
template<class T>
struct T2IntDef
{
	T operator()(const T& data)
	{
		return data;
	}
};
//T���������ͣ���Ҫ�û�����ת���ķ�ʽ
struct String2INT
{
	size_t operator()(const string& s)
	{
		return (size_t)(s.c_str());
	}
};


template<class T,class T2Int=T2IntDef<T>>
class HashBucket;

template<class T,class T2Int=T2IntDef<T>>
struct HBIterator
{
	typedef HBNode<T> Node;
	typedef HBIterator<T, T2Int> Self;
	typedef HashBucket<T, T2Int> HB;

	HBIterator(HB* ht=nullptr,Node* pNode=nullptr)
		:_pNode(pNode)
		,_ht(ht)
	{}

	T& operator*()
	{
		return _pNode->_data;
	}

	T* operator->()
	{
		return (&operator*());
	}

	//�ƶ�
	Self& operator++()
	{
		Next();
		return *this;
	}

	Self operator++(int)
	{
		Self temp(*this);
		Next();
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


	void Next()
	{
		if (_pNode->_pNext)
		{
			_pNode = _pNode->_pNext;
		}
		else
		{
			//_pNode�ǵ�ǰͰ�����һ��
			//��ȡ��һ��Ͱ��Ͱ��=���㵱ǰͰ��+1��

			size_t bucketNo = _ht->HashFunc(_pNode->_data)+1;

			//����һ���ǿ�Ͱ
			for (; bucketNo < _ht->BucketCount(); ++bucketNo)
			{
				_pNode = _ht->_table[bucketNo];
				if (_pNode)
					return;
			}

			_pNode = nullptr;
		}
	}
private:
	Node* _pNode;
	HB* _ht;//��ȡ��һ���ǿ�Ͱʱ��Ҫ�õ�
};

//���裺��ϣͰ�е�Ԫ����Ψһ��
template<class T,class T2Int>
class HashBucket
{

	friend struct HBIterator<T, T2Int>;
	typedef HBNode<T> Node;
	typedef HashBucket<T, T2Int> Self;
public:
	typedef HBIterator<T, T2Int> iterator;

public:
	HashBucket(size_t capacity=10)
		:_table(GetNextPrime(capacity))
		,_size(0)
	{}

	bool Insert(const T& data)
	{
		//1��ͨ����ϣ��������data���ڵ�Ͱ��
		size_t bucketNo = HashFunc(data);

		//2������Ԫ���Ƿ���bucketNoͰ��
		//   ���ʣ�����������Ƿ����data�Ľڵ�
		Node* cur = _table[bucketNo];
		while (cur)
		{
			if (cur->_data == data)
				return false;

			cur = cur->_pNext;
		}

		//�����½ڵ�
		cur = new Node(data);
		cur->_pNext = _table[bucketNo];
		_table[bucketNo] = cur;
		++_size;
		return true;
	}

	Node* Find(const T& data)
	{
		size_t bucketNo = HashFunc(data);
		Node* cur = _table[bucketNo];
		while (cur)
		{
			if (data == cur->_data)
				return cur;

			cur = cur->_pNext;
		}

		return nullptr;
	}

	bool Erase(const T& data)
	{
		size_t bucketNo = HashFunc(data);
		Node* cur = _table[bucketNo];
		Node* pre = nullptr;
		while (cur)
		{
			if (data == cur->_data)
			{
				//ɾ��
				if (_table[bucketNo] == cur)
				{
					// ɾ����һ���ڵ�
					_table[bucketNo] = cur->_pNext;
				}
				else
				{
					//ɾ���Ĳ��ǵ�һ���ڵ�
					pre->_pNext = cur->_pNext;
				}

				delete cur;
				--_size;
				return true;
			}
			pre = cur;
			cur = cur->_pNext;
		}
		return false;
	}

	iterator Begin()
	{
		//�ҵ���һ���ǿ�Ͱ
		for (size_t i = 0; i < _table.capacity(); ++i)
		{
			if (_table[i])
				return iterator(this, _table[i]);
		}

		return End();
	}

	iterator End()
	{
		return iterator(this, nullptr);
	}

	void Swap(Self& ht)
	{
		_table.swap(ht._table);
		swap(_size, ht._size);
	}

	size_t BucketCount()const
	{
		return _table.capacity();
	}



	void CheckCapacity()
	{
		if (_size == _table.capacity())
		{
			Self ht(GetNextPrime(_size));

			//���ɹ�ϣͰ�еĽڵ�ֱ�����¹�ϣͰ�а���
			for (size_t i = 0; i < _table.capacity(); ++i)
			{
				Node* cur = _table[i];
				while (cur)
				{
					//��cur�ڵ�Ӿɹ�ϣͰ���Ƶ��¹�ϣͰ
					//1����cur�ڵ�Ӿ�������ɾ��
					_table[i] = cur->_pNext;

					// 2. ��cur�ڵ���뵽��������
					size_t bucketNo = HashFunc(cur->_data);

					// 3. ����ڵ�--->ͷ��
					cur->_pNext = _table[bucketNo];
					ht._table[bucketNo] = cur;
				}
			}

			this->Swap(ht);
		}
	}


	void PrintHashBucket()
	{
		for (size_t i = 0; i < _table.capacity(); ++i)
		{
			cout << "_table[" << i << "]:";

			Node* cur = _table[i];
			while (cur)
			{
				cout << cur->_data << "---->";
				cur = cur->_pNext;
			}

			cout << "NULL" << endl;
		}
		cout << endl;
	}
private:
	size_t HashFunc(const T& data)
	{
		return T2Int()(data) % _table.capacity();
	}
private:
	vector<Node*> _table;
	size_t _size;
};


int main()
{
	HashBucket<int> ht;
	ht.Insert(1);
	ht.Insert(54);
	ht.Insert(2);
	ht.Insert(3);
	ht.Insert(4);
	ht.Insert(5);


	if(ht.Find(3))
		cout<< "3 is in hashBucket" << endl;
	else
		cout << "3 is not in hashbucket" << endl;


	ht.PrintHashBucket();

	HashBucket<int>::iterator it = ht.Begin();
	while (it != ht.End())
	{
		cout << *it << " ";
		++it;
	}

	cout << endl;
}

#endif

#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;
#include"common.h"

template<class T>
struct HBNode
{
	HBNode(const T& data = T())
		:_data(data)
		, _pNext(nullptr)
	{}

	T _data;
	HBNode<T>* _pNext;
};

//T��������ε�
template<class T>
struct T2IntDef
{
	T operator()(const T& data)
	{
		return data;
	}
};
//T���������ͣ���Ҫ�û�����ת���ķ�ʽ
struct String2INT
{
	size_t operator()(const string& s)
	{
		const char* str = s.c_str();
		unsigned int seed = 131; // 31 131 1313 13131 131313
		unsigned int hash = 0;
		while (*str)
		{
			hash = hash * seed + (*str++);
		}
		return (hash & 0x7FFFFFFF);
	}
};



template<class T,class KOFV,class T2Int=T2IntDef<T>>
class HashBucket;


template<class T,class KOFV,class T2Int=T2IntDef<T>>
struct HBIterator
{
	typedef HBNode<T> Node;
	typedef HBIterator<T,KOFV,T2Int> Self;
	typedef HashBucket<T, KOFV, T2Int> HB;

	HBIterator(HB* ht=nullptr,Node* pNode=nullptr)
		:_pNode(pNode)
		,_ht(ht)
	{}

	T& operator*()
	{
		return _pNode->_data;
	}
	T* operator->()
	{
		return (&operator*());
	}

	//�ƶ�
	Self& operator++()
	{
		Next();
		return *this;
	}

	Self operator++(int)
	{
		Self temp(*this);
		Next();
		return temp;
	}

	bool operator!=(const Self& s)const
	{
		return _pNode != s._pNode;
	}

	bool operator ==(const Self& s)const
	{
		return _pNode == s._pNode;
	}

	void Next()
	{
		if (_pNode->_pNext)
		{
			_pNode = _pNode->_pNext;
		}
		else
		{
			// _pNode�ǵ�ǰͰ��(������)�����һ���ڵ�

			// ��ȡ��һ��Ͱ��Ͱ�� = ���㵱ǰͰ��+1
			size_t bucketNo = _ht->HashFunc(_pNode->_data) + 1;

			//����һ���ǿ�Ͱ
			for (; bucketNo < _ht->BucketCount(); ++bucketNo)
			{
				_pNode = _ht->_table[bucketNo];
				if (_pNode)
					return;
			}

			_pNode = nullptr;
		}
	}

private:
	Node* _pNode;
	HB* _ht;//��ȡ��һ���ǿ�Ͱʱ��Ҫ�õ�
};


template<class T,class KOFV,class T2Int>
class HashBucket
{
	friend struct  HBIterator<T, KOFV, T2Int>;

	typedef HBNode<T> Node;
	typedef HashBucket<T, KOFV, T2Int> Self;

public:
	typedef HBIterator<T, KOFV, T2Int> iterator;
public:
	HashBucket(size_t capcity = 10)
		:_table(GetNextPrime(capcity))
		, _size(0)
	{}

	////////////////////////////////
	//capacity
	size_t Size()const
	{
		return _size;
	}

	bool Empty()const
	{
		return 0 == _size;
	}

	pair<iterator, bool> Insert(const T& data)
	{
		//1��ͨ����ϣ��������data���ڵ�Ͱ��
		size_t bucketNo = HashFunc(data);

		//2������Ԫ���Ƿ���bucketNo��
		//   ���ʣ�����������Ƿ����data�Ľڵ�

		Node* cur = _table[bucketNo];
		while (cur)
		{
			if (data == cur->_data)
				return make_pair(iterator(this, cur), false);

			cur = cur->_pNext;
		}

		//�����½ڵ�
		cur = new Node(data);
		cur->_pNext = _table[bucketNo];
		_table[bucketNo] = cur;
		++_size;
		return make_pair(iterator(this, cur), true);
	}


	size_t Erase(const T& data)
	{
		size_t bucketNo = HashFunc(data);
		Node* cur = _table[bucketNo];
		Node* pre = nullptr;
		while (cur)
		{
			if (data == cur->_data)
			{
				if (_table[bucketNo] == cur)
				{
					_table[bucketNo] = cur->_pNext;
				}
				else
				{
					pre->_pNext = cur->_pNext;
				}

				delete cur;
				--_size;
				return 1;
			}

			pre = cur;
			cur = cur->_pNext;
		}

		return 0;
	}


	void Clear()
	{
		for (size_t i = 0; i < _table.capacity(); ++i)
		{
			Node* cur = _table[i];

			//ɾ��i��Ͱ����Ӧ�����е����нڵ�
			while (cur)
			{
				//����ͷɾ
				_table[i] = cur->_pNext;
				delete cur;
				cur = _table[i];
			}
		}

		_size = 0;
	}


	void Swap(Self& ht)
	{
		_table.swap(ht._table);
		swap(_size, ht._size);
	}

	///////////////////////////////

	iterator Find(const T& data)
	{
		size_t bucketNo = HashFunc(data);
		Node* cur = _table[bucketNo];
		while (cur)
		{
			if (data == cur->_data)
				return iterator(this, cur);

			cur = cur->_pNext;
		}

		return End();
	}

	/////////////////////////////////////

	iterator Begin()
	{
		for (size_t i = 0; i < _table.capacity(); ++i)
		{
			if (_table[i])
				return iterator(this, _table[i]);
		}

		return End();
	}

	iterator End()
	{
		return iterator(this, nullptr);
	}


	size_t BucketCount()const
	{
		return _table.capacity();
	}

	size_t BucketSize(size_t n)const
	{
		assert(n < _table.capacity());
		Node* cur = _table[n];

		size_t count = 0;
		while (cur)
		{
			count++;
			cur = cur->_pNext;
		}


		return count;
	}

	size_t Bucket(const T& data)const
	{
		return HashFunc(data);
	}
private:
	void ChechCapacity()
	{
		if (_size == _table.capacity())
		{
			Self ht(GetNextPrime(_size));

			// ���ɹ�ϣͰ�еĽڵ�ֱ�����¹�ϣͰ�а���
			for (size_t i = 0; i < _table.capacity(); ++i)
			{
				Node* cur = _table[i];
				while (cur)
				{
					// ��pCur�ڵ�Ӿɹ�ϣͰ���Ƶ��¹�ϣͰ
					// 1. ��pCur�ڵ�Ӿ�������ɾ��
					_table[i] = cur->_pNext;

					// 2. ��pCur�ڵ���뵽��������
					size_t bucketNo = HashFunc(cur->_data);

					// 3. ����ڵ�--->ͷ��
					cur->_pNext = ht._table[bucketNo];
					ht._table[bucketNo] = cur;
				}
			}

			this->Swap(ht);
		}
	}
private:
	size_t HashFunc(const T& data)
	{
		return T2Int()(KOFV()(data)) % _table.capacity();
	}
private:
	vector<Node*> _table;
	size_t _size;
};