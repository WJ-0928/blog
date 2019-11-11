

#include<iostream>
#include<vector>
using namespace std;

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


// T������������͵ģ�char short int long long long
template<class T>
struct T2IntDef
{
	T operator()(const T& data)
	{
		return data;
	}
};


// T���������ͣ���Ҫ�û�����ת���ķ�ʽ
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

// ���裺��ϣͰ�е�Ԫ��ʱΨһ��
template<class T,class KOFV,class T2Int>
class HashBucket
{
	friend struct  HBIterator<T, KOFV, T2Int>;
	typedef HBNode<T> Node;
	typedef HashBucket<T, KOFV, T2Int> Self;

public:
	typedef HBIterator<T, KOFV, T2Int> iterator;
public:
	HashBucket(size_t capacity=10)
		:_table(GetNextPrime(capacity))
		,_size(0)
	{}

	/////////////////////////////////////
	//capacity
	size_t Size()const
	{
		return _size;
	}
	size_t Empty()const
	{
		return 0 == _size;
	}

	pair<iterator, bool> Insert(const T& data)
	{
		//1��ͨ����ϣ��������data���ڵ�Ͱ��
		size_t bucketNo = HashFunc(data);

		//2������Ԫ���Ƿ���bucketNOͰ��
		//���ʣ�����������Ƿ���data�Ľڵ�
		Node* cur = _table[bucketNo];
		while (cur)
		{
			if (cur->_data == data)
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
					// ɾ����һ���ڵ�
					_table[bucketNo] = cur->_pNext;
				}
				else
				{
					// ɾ���Ĳ��ǵ�һ���ڵ�
					pre->_pNext = cur->_pNext;
				}

				delete cur;
				--_size;
				return 1��
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
			// ɾ��i��Ͱ����Ӧ�����е����нڵ�
			while (cur)
			{
				// ����ͷɾ
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
	////////////////////////////////////
	
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


	///////////////////////////////////////
	iterator Begin()
	{
		//�ҵ�һ���ǿ�Ͱ
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
	void CheckCapacity()
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
					size_t bucketNo = ht.HashFunc(cur->_data);


					//3. ����ڵ�--->ͷ��
					cur->_pNext = _table[bucketNo];
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