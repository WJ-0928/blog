

#if 0
#include<iostream>
using namespace std;



template<class T>
struct BSTreeNode
{
	BSTreeNode(const T& data=T())
		:_pLeft(nullptr)
		,_pRight(nullptr)
		,_data(data)
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

	Node* find(const T& data)
	{
		Node* cur = _pRoot;
		while (cur != NULL)
		{
			if (data < cur->_data)
			{
				cur = cur->_pLeft;
			}
			else if(data>cur->_data)
			{
				cur=cur->_pRight
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}

	bool Insert(const T& data)
	{
		// 空树---直接插入
		if (_pRoot == nullptr)
		{
			_pRoot = new Node(data);
		}
		// 非空--找待插入节点在二叉搜索树中的位置
		// 并保存其双亲节点
		Node* cur = _pRoot;
		Node*pParent = nullptr;
		while (cur)
		{
			pParent = cur;
			if (data < cur->_data)
			{
				cur = cur->_pLeft;
			}
			else if (data > cur->_data)
			{
				cur = cur->_pRight;
			}
			else
			{
				return false;
			}
		}

		// 插入元素
		cur = new Node(data);
		if (data < pParent->_data)
		{
			pParent->_pLeft = cur;
		}
		else
		{
			pParent->_pRight = cur;
		}

		return true;
	}

	bool Delete(const T& data)
	{
		if (nullptr = _pRoot)
		{
			return false;
		}
		// 找待删除节点在二叉搜索树中的位置
		// 并保存其双亲

		Node* cur = _pRoot;
		Node* pParent = nullptr;
		while (cur)
		{
			if (data == cur->_data)
				break;
			else if (data < cur->_data)
			{
				pParent = cur;
				cur = cur->_pLeft;
			}
			else
			{
				pParent = cur;
				cur = cur->_pRight;
			}
		}

		// 该节点不在二叉搜索树中
		if (cur == nullptr)
			return false;


		// 已经找到该该节点，删除
		// 只有右孩子 || 叶子节点
		if (nullptr == cur->_pLeft)
		{
			if (nullptr == pParent)
				_pRoot = cur->_pRight;
			else
			{
				if (cur == pParent->_pLeft)
				{
					pParent->_pLeft = cur->_pRight;
				}
				else
				{
					pParent->_pRight = cur->_pRight;
				}
			}
		}
		else if (nullptr == cur->_pRight)
		{
			// 只有左孩子
			if (nullptr == pParent)
				_pRoot = cur->_pLeft;
			else
			{
				if (cur == pParent->_pLeft)
				{
					pParent->_pLeft = cur->_pLeft;
				}
				else
				{
					pParent->_pRight = cur->_pLeft;
				}
			}
		}
		else
		{
			// 左右孩子均存在
			Node* pDelNode = cur->_pRight;
			pParent = cur;
			// 找替代节点：在右子树中找最小(最左)
			while (pDelNode->_pLeft)
			{
				pParent = pDelNode;
				pDelNode = pDelNode->_pLeft;
			}
			// 用替代节点中值域替换删除节点
			cur->_data = pDelNode->_data;

			if (pDelNode == pParent->_pLeft)
				pParent->_pLeft = pDelNode->_pRight;
			else
				pParent->_pRight = pDelNode;

			cur = pDelNode;
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
		{
			cur = cur->_pRight;
		}

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
private:
	Node* _pRoot;
};

void TestBSTree()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int> bst;
	for (auto e : a)
		bst.Insert(e);

	cout << bst.leftMost()->_data << endl;
	cout << bst.rightMost()->_data << endl;
	bst.InOrder();
}
#endif


#if 0

//AVL树
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

	AVLTreeNode<T>* _pLeft;//该节点的左孩子
	AVLTreeNode<T>* _pRight;//该节点的右孩子
	AVLTreeNode<T>* _pParent;//该节点的双亲
	T _data;
	int _bf;//该节点的平衡因子
};


//AVL：二叉搜索树+平衡因子的限制
template<class  T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		:_pRoot(nullptr)
	{}

	bool Insert(const T& data)
	{
		//先按照二叉搜索树的方式进行插入
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}
		// 按照二叉搜索树特性：找待插入节点在树中的位置
		// 并保存其双亲
		Node* cur = _pRoot;
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

		// 插入新节点
		cur = new Node(data);
		if (data < pParent->_data)
			pParent->_pLeft = cur;
		else
			pParent->_pRight = cur;

		cur->_pParent = pParent;

		while (pParent)
		{
			// 更新pParent的平衡因子

			if (cur == pParent->_pLeft)
				pParent->_bf--;
			else
				pParent->_bf++;

			if (0 == pParent->_bf)
				break;
			else if (-1 == pParent->_bf || 1 == pParent->_bf)
			{
				cur = pParent;
				pParent = cur->_pParent;
			}
			else
			{
				// pParent->_bf: 2 || -2
				// pParent的节点失去平衡
				if (2 == pParent->_bf)
				{
					// 右子树高-->最后必须左单旋
					if (1 == cur->_bf)
						RotateL(pParent);
					else
						RotateRL(pParent);
				}
				else
				{
					if (-1 == cur->_bf)
						RotateR(pParent);
					else
						RotateLR(pParent);
				}

				break;
			}
		}
		return true;
	}

	void InOrder()
	{
		_InOrder(_pRoot);
	}

	Node* LeftMost()
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

	Node* RightMost()
	{
		if (nullptr == _pRoot)
			return nullptr;

		Node* cur = _pRoot;
		while (cur->_pRight)
			cur = cur->_pRight;

		return cur;
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

		if (abs(rightHeight - leftHeight) > 1 || rightHeight - leftHeight != pRoot->_bf)
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

	void RotateR(Node* pParent)
	{
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;

		// 改变pParent和pSubL孩子的指向
		pParent->_pLeft = pSubLR;
		if (pSubLR)
			pSubLR->_pParent = pParent;

		pSubL->_pRight = pParent;

		// 更新pParent和pSubL的双亲
		Node* pPParent = pParent->_pParent;
		pParent->_pParent = pSubL;
		pSubL->_pParent = pPParent;

		// 更新原pParent双亲的左||右指针域指向
		if (nullptr == pPParent)
		{
			_pRoot = pSubL;
		}
		else
		{
			if (pParent == pPParent->_pLeft)
				pPParent->_pLeft = pSubL;
			else
				pPParent->_pRight = pSubL;
		}

		pParent->_bf = pSubL->_bf = 0;
	}

	void RotateL(Node* pParent)
	{
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;

		pParent->_pRight = pSubRL;
		if (pSubRL)
			pSubRL->_pParent = pParent;

		pSubR->_pLeft = pParent;
		Node* pPParent = pParent->_pParent;
		pParent->_pParent = pSubR;
		pSubR->_pParent = pPParent;

		if (nullptr == pPParent)
		{
			_pRoot = pSubR;
		}
		else
		{
			if (pParent == pPParent->_pLeft)
				pPParent->_pLeft = pSubR;
			else
				pPParent->_pRight = pSubR;
		}

		pParent->_bf = pSubR->_bf = 0;
	}

	void RotateRL(Node* pParent)
	{
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;
		int bf = pSubRL->_bf;

		RotateR(pParent->_pRight);
		RotateL(pParent);

		// 更新部分节点的平衡因子
		if (bf == -1)
			pSubR->_bf = 1;
		else if (bf == 1)
			pParent->_bf = -1;
	}

	void RotateLR(Node* pParent)
	{
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;
		int bf = pSubLR->_bf;

		RotateL(pParent->_pLeft);
		RotateR(pParent);
		if (-1 == bf)
			pParent->_bf = 1;
		else if (1 == bf)
			pSubL->_bf = -1;
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
	//int array[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int array[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int> t;
	for (auto e : array)
	{
		t.Insert(e);
	}

	// 验证：是否为二叉搜索树
	t.InOrder();
	cout << endl;

	cout << t.LeftMost()->_data << endl;
	cout << t.RightMost()->_data << endl;
	if (t.IsAVLTree())
		cout << "t is AVLTree" << endl;
	else
		cout << "t is not AVLTree" << endl;

	return 0;
}
#endif

