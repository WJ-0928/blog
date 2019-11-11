

#if 0
//二叉树
#include<iostream>
using namespace std;

template<class T>
struct BSTreeNode
{
	BSTreeNode(const T& data = T())
		:_pLeft(nullptr)
		, _pRight(nullptr)
		, _data(data)
	{}

	BSTreeNode<T>* _pLeft;
	BSTreeNode<T>* _pRight;
	T _data;
};

template<class T>
class BSTree
{
	typedef BSTreeNode<T> Node;
public:
	BSTree()
		:_pRoot(nullptr)
	{}

	//查找
	Node* Find(const T& data)
	{
		Node* cur = _pRoot;
		while (cur!=NULL)
		{
			if (data < cur->_data)
				cur = cur->_pLeft;
			else if (data > cur->_data)
				cur = cur->_pRight;
			else
				return cur;
		}
		return nullptr;
	}

	//插入
	bool Insert(const T& data)
	{
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}

		Node* cur = _pRoot;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (data < cur->_data)
				cur = cur->_pLeft;
			else if (data > cur->_data)
				cur = cur->_pRight;
			else
				return false;
		}

		cur = new Node(data);
		if (data < parent->_data)
			parent->_pLeft = cur;
		else
			parent->_pRight = cur;

		return true;

	}

	//删除
	bool Erase(const T& data)
	{
		if (nullptr == _pRoot)
			return false;

		Node* cur = _pRoot;
		Node* parent = nullptr;
		while (cur)
		{
			if (data == cur->_data)
				break;
			else if (data < cur->_data)
			{
				parent = cur;
				cur = cur->_pLeft;
			}
			else
			{
				parent = cur;
				cur = cur->_pRight;
			}
		}

		if (cur == nullptr)
			return false;

		//只有右孩子
		if (nullptr == cur->_pLeft)
		{
			//待删除为根节点
			if (cur == nullptr)
				_pRoot = cur->_pRight;
			else
			{
				if (cur == parent->_pLeft)
					parent->_pLeft = cur->_pRight;
				else
					parent->_pRight = cur->_pRight;
			}
		}
		else if (nullptr == cur->_pRight)
		{
			if (cur == nullptr)
				_pRoot = cur->_pLeft;
			else
			{
				if (cur == parent->_pLeft)
					parent->_pLeft = cur->_pLeft;
				else
					parent->_pRight = cur->_pLeft;
			}
		}
		else
		{
			Node* pf = cur->_pRight;
			parent = cur;
			while (pf->_pLeft)
			{
                parent = pf;
				pf = pf->_pLeft;
			}
			cur->_data = pf->_data;
			if (pf == parent->_pLeft)
				parent->_pLeft = pf->_pRight;
			else
				parent->_pRight = pf->_pRight;

			cur = pf;
		}

		delete cur;
		return true;
	}

	Node* leftMost()
	{
		if (nullptr == _pRoot)
			return nullptr;

		Node* cur = _pRoot;
		while (cur->_pLeft)
		{
			cur = cur->_pLeft;
		}
		return cur;
	}

	Node* rightMost()
	{
		if (nullptr == _pRoot)
			return nullptr;

		Node* cur = _pRoot;
		while (cur->_pRight)
			cur = cur->_pRight;

		return cur;
	}

	void InOrder()
	{
		_InOrder(_pRoot);
	}
private:
	void _InOrder(Node* pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);
		}
	}

	Node* _pRoot;
};

int main()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int> bst;
	for (auto e : a)
	{
		bst.Insert(e);
	}

	cout << bst.leftMost()->_data << endl;
	cout << bst.rightMost()->_data << endl;
	bst.InOrder();

}

#endif

#if 0
//AVL树

#include<iostream>
using namespace std;

template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data=T())
		:_pLeft(nullptr)
		,_pRight(nullptr)
		,_pParent(nullptr)
		,_data(data)
		,_bf(0)
	{}

	AVLTreeNode<T>* _pLeft;
	AVLTreeNode<T>* _pRight;
	AVLTreeNode<T>* _pParent;
	T _data;
	int _bf;
};

template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		:_pRoot(nullptr)
	{}

	bool Insert(const T& data)
	{
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}

		Node* cur = _pRoot;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (data < cur->_data)
				cur = cur->_pLeft;
			else if (data > cur->_data)
				cur = cur->_pRight;
			else
				return false;
		}

		cur = new Node(data);
		if (data < parent->_data)
			parent->_pLeft = cur;
		else
			parent->_pRight = cur;

		cur->_pParent = parent;

		while (parent)
		{
			if (cur == parent->_pLeft)
				parent->_bf--;
			else
				parent->_bf++;

			if (0 == parent->_bf)
				break;
			else if (1 == parent->_bf || -1 == parent->_bf)
			{
				cur = parent;
				parent = cur->_pParent;
			}
			else
			{
				if (2 == parent->_bf)
				{
					if (1 == cur->_bf)
						RotateL(parent);
					else
						RotateRL(parent);
				}
				else
				{
					if (-1 == cur->_bf)
						RotateR(parent);
					else
						RotateLR(parent);
				}
				break;
			}
		}
		return true;
	}
	Node* leftMost()
	{
		if (nullptr == _pRoot)
			return nullptr;

		Node* cur = _pRoot;
		while (cur->_pLeft)
		{
			cur = cur->_pLeft;
		}
		return cur;
	}

	Node* rightMost()
	{
		if (nullptr == _pRoot)
			return nullptr;

		Node* cur = _pRoot;
		while (cur->_pRight)
		{
			cur = cur->_pRight;
		}
		return cur;
	}
	void InOrder()
	{
		_InOrder(_pRoot);
	}

	bool IsAVLTree()
	{
		return _IsAVLTree(_pRoot);
	}
private:
	bool _IsAVLTree(Node* pRoot)
	{
		if (nullptr == pRoot)
			return true;

		int leftHeight = _Height(pRoot->_pLeft);
		int rightHeight = _Height(pRoot->_pRight);
		int diff = rightHeight - leftHeight;

		if (abs(diff) > 1 || diff != pRoot->_bf)
			return false;

		return _IsAVLTree(pRoot->_pLeft) && _IsAVLTree(pRoot->_pRight);
	}
	int _Height(Node* pRoot)
	{
		if (nullptr == pRoot)
			return 0;

		int leftHeight = _Height(pRoot->_pLeft);
		int rightHeight = _Height(pRoot->_pRight);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	//右单旋
	void RotateR(Node* pParent)
	{
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;

		pParent->_pLeft = pSubLR;
		if (pSubLR)
		{
			pSubLR->_pParent = pParent;
		}

		pSubL->_pRight = pParent;
		Node* ppParent = pParent->_pParent;

		pParent->_pParent = pSubL;
		pSubL->_pParent = ppParent;

		if (nullptr == ppParent)
		{
			_pRoot = pSubL;
		}
		else
		{
			if (pParent == ppParent->_pLeft)
			{
				ppParent->_pLeft = pSubL;
			}
			else
			{
				ppParent->_pRight = pSubL;
			}
		}
		pParent->_bf = pSubL->_bf = 0;
	}

	//左单旋
	void RotateL(Node* pParent)
	{
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;

		pParent->_pRight = pSubRL;
		if (pSubRL)
			pSubRL->_pParent = pParent;

		pSubR->_pLeft = pParent;
		Node* ppParent = pParent->_pParent;

		pParent->_pParent = pSubR;
		pSubR->_pParent = ppParent;
		if (ppParent == nullptr)
		{
			_pRoot = pSubR;
		}
		else
		{
			if (pParent == ppParent->_pLeft)
				ppParent->_pLeft = pSubR;
			else
				ppParent->_pRight = pSubR;
		}

		pParent->_bf = pSubR->_bf = 0;
	}

	//左右单旋
	void RotateLR(Node* pParent)
	{
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;

		int bf = pSubLR->_bf;

		RotateL(pParent->_pLeft);
		RotateR(pParent);

		if (1 == bf)
		{
			pSubL->_bf = -1;
		}
		else if (-1 == bf)
		{
			pParent->_bf = 1;
		}
	}
	//右左双旋
	void RotateRL(Node* pParent)
	{
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;

		int bf = pSubRL->_bf;

		RotateR(pParent->_pRight);
		RotateL(pParent);

		if (1 == bf)
			pParent->_bf = -1;
		else if(-1==bf)
			pSubR->_bf = 1;
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
private:
	Node* _pRoot;
};

int main()
{
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int> AVL;
	for (auto e : a)
	{
		AVL.Insert(e);
	}

	AVL.InOrder();
	cout << endl;

	cout << AVL.leftMost()->_data << endl;
	cout << AVL.rightMost()->_data << endl;
 	if (AVL.IsAVLTree())
		cout << "AVL is AVLTree" << endl;
	else
		cout << "AVL is not AVLTree" << endl;

	return 0;
}
#endif

#if 0
/*
//红黑树：二叉搜索树
//        节点中增加颜色：红色和黑色
//        条件约束：5条性质

1、每个节点都有颜色：红色或黑色
2、根节点必须为黑色
3、如果一个节点的颜色是红色，他的孩子节点一定是黑色的
   红黑树中不会出现连在一起的红色节点
4、每条路径中的黑色节点个数相同
5、每个叶子节点都是黑色（此处的叶子节点：树中的空指针域）


//结论：最长路径中的节点个数一定不会超过最短路径中的节点个数的两倍
//因此：红黑树是一颗近似平衡的二叉搜索树
//红黑树性能比AVL树更佳，而且实现比较简单
*/

#include<iostream>
using namespace std;

enum Color { RED, BLACK };

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
			//找右子树中最左侧的节点
			_pNode = _pNode->_pRight;
			while (_pNode->_pLeft)
				_pNode = _pNode->_pLeft;
		}
		else
		{
			Node* parent = _pNode->_pParent;
			while (_pNode == parent->_pRight)
			{
				_pNode = parent;
				parent = _pNode->_pParent;
			}

			if (_pNode->_pRight != parent)
				_pNode = parent;
		}
	}

	void DeIncreament()
	{}

	Node* _pNode;
};

template<class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	RBTree()
	{
		_pHead = new Node;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
	}

	bool Insert(const T& data)
	{
		//按照二叉搜索树的性质插入新节点
		Node*& pRoot = GetRoot();
		if (nullptr == pRoot)
		{
			pRoot = new Node(data, BLACK);
			pRoot->_pParent = _pHead;
			return true;
		}
		else
		{
			//找待插入节点在二叉搜索树中的位置
			//并保存其双亲节点

			Node* cur = pRoot;
			Node* parent = nullptr;
			while (cur)
			{
				parent = cur;
				if (data < cur->_data)
					cur = cur->_pLeft;
				else if (data > cur->_data)
					cur = cur->_pRight;
				else
					return false;
			}
			//插入新节点
			cur = new Node(data);
			if (data < parent->_data)
				parent->_pLeft = cur;
			else
				parent->_pRight = cur;

			cur->_pParent = parent;

			//cur新节点的默认颜色：红色
			//如果parent的颜色是黑色，满足红黑树的性质
			//如果parent的颜色是红色，违反了性质三----不能有连在一起的红色节点

			while (parent != _pHead && parent->_color == RED)
			{
				Node* grandFather = parent->_pParent;
				if (grandFather->_pLeft == parent)
				{
					Node* uncle = grandFather->_pRight;
					if (uncle&&uncle->_color == RED)
					{
						//情况一：
						parent->_color =BLACK;
						uncle->_color = BLACK;
						grandFather->_color = RED;
						cur = grandFather;
						parent = cur->_pParent;
					}
					else
					{
						//叔叔节点不存在或为黑
						if (cur == parent->_pRight)
						{
							RotateL(parent);
							swap(cur, parent);
						}

						parent->_color = BLACK;
						grandFather->_color = RED;
						RotateR(grandFather);
					}
				}
				else
				{
					Node* uncle = grandFather->_pLeft;
					if (uncle&&uncle->_color == RED)
					{
						parent->_color = BLACK;
						uncle->_color = BLACK;
						grandFather->_color = RED;
						cur = grandFather;
						parent = cur->_pParent;
					}
					else
					{
						//叔叔节点不存在或为黑色
						if (cur == parent->_pLeft)
						{
							RotateR(parent);
							swap(cur, parent);
						}
						parent->_color = BLACK;
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
		{
			return _pHead;
		}
		Node* cur = pRoot;
		while (cur->_pLeft)
		{
			cur = cur->_pLeft;
		}
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
			cout << "违反性质一：根节点是黑色" << endl;
			return false;
		}

		//获取一条路径的黑色节点个数
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

		Node* parent = pRoot->_pParent;
		if (parent != _pHead &&parent->_color== RED  && pRoot->_color==RED)
		{
			cout << "违反性质3：不能存在连在一起的红色节点" << endl;
			return false;
		}
		//叶子节点
		if (nullptr == pRoot->_pLeft&&nullptr == pRoot->_pRight)
		{
			if (pathBlack != blackCount)
			{
				cout << "违反性质4：每条路径中黑色节点个数均相同" << endl;
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

	void RotateL(Node* parent)
	{
		Node* pSubR = parent->_pRight;
		Node* pSubRL = pSubR->_pLeft;

		parent->_pRight = pSubRL;
		if (pSubRL)
			pSubRL->_pParent = parent;

		pSubR->_pLeft = parent;
		Node* pParent = parent->_pParent;

		parent->_pParent = pSubR;
		pSubR->_pParent = pParent;
		if (_pHead == pParent)
			_pHead->_pParent = pSubR;
		else
		{
			if (parent == pParent->_pLeft)
				pParent->_pLeft = pSubR;
			else
				pParent->_pRight = pSubR;
		}
	}
	void RotateR(Node* parent)
	{
		Node* pSubL = parent->_pLeft;
		Node* pSubLR = pSubL->_pRight;

		parent->_pLeft = pSubLR;
		if (pSubLR)
			pSubLR->_pParent = parent;

		pSubL->_pRight = parent;
		Node* pParent = parent->_pParent;

		parent->_pParent = pSubL;
		pSubL->_pParent = pParent;
		if (pParent == _pHead)
			_pHead->_pParent = pSubL;
		else
		{
			if (parent == pParent->_pLeft)
				pParent->_pLeft = pSubL;
			else
				pParent->_pRight = pSubL;
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

	return 0;
}
#endif

#include<iostream>
using namespace std;

//节点的颜色
enum Color { RED, BLACK };

template<class T>
struct RBTreeNode
{
	RBTreeNode(const T& data = T(), Color color = RED)
		:_pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, _data(data)
		, _color(color)
	{}

	RBTreeNode<T>* _pLeft;//节点的左孩子
	RBTreeNode<T>* _pRight;//节点的右孩子
	RBTreeNode<T>* _pParent;//节点的双亲
	T _data;//节点的值域
	Color _color;//节点的颜色

};

template<class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	RBTree()
	{
		_pHead->_pParent = nullptr;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
	}
	bool Insert(const T& data)
	{
		Node*& pRoot = GetRoot();
		if (nullptr == pRoot)
		{
			pRoot = new Node(data, BLACK);
			pRoot->_pParent = _pHead;
			return true;
		}
		else
		{
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

			cur = new Node(data);
			if (data < pParent->_data)
				pParent->_pLeft = cur;
			else
				pParent->_pRight = cur;

			cur->_pParent = pParent;

			while (pParent != _pHead && pParent->_color == RED)
			{
				Node* grandFather = pParent->_pParent;
				if (pParent == grandFather->_pLeft)
				{
					Node* uncle = grandFather->_pRight;
					if (uncle&&uncle->_color == RED)
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
					if (uncle&&uncle->_color == RED)
					{
						pParent->_color = BLACK;
						grandFather->_color = RED;
						uncle->_color = BLACK;
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

		pRoot->_color = BLACK;
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();
		return true;
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
			cout << "违反性质一：根节点是黑色" << endl;
			return false;
		}

		//获取一条路径中黑色节点的个数
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
	Node*& GetRoot()
	{
		return _pHead->_pParent;
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
			cout << "违反性质3：不能存在连在一起的红色节点" << endl;
			return false;
		}


		if (nullptr == pRoot->_pLeft&&nullptr == pRoot->_pRight)
		{
			if (pathBlack != blackCount)
			{
				cout << "违反性质4：每条路径中黑色节点个数均相同" << endl;
				return false;
			}
		}

		return _IsValidRBTree(pRoot->_pLeft, blackCount, pathBlack) &&
			_IsValidRBTree(pRoot->_pRight, blackCount, pathBlack);
	}
private:
	Node* _pHead;
};

