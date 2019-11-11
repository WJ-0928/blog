#if 0

#include<iostream>
using namespace std;

template<class T>
class SList
{
private:
	struct Node
	{
		T data;
		Node *next;
		Node()
		{
			next = nullptr;
		}
		Node(T data) {
			next = nullptr;
			this->data = data;
		}
	};
	Node* head;
	Node* tail;
	int size;
public:
	SList();
	//复制构造函数
	SList(const SList<T>& s1);
	//析构函数
	~SList();
	// 链表的初始化 
	void SListInit(SList* pl);

	// 在链表中尾插值为data的节点 
	void SListPushBack(SList* pl, int data);

	// 删除链表最后一个节点 
	void SListPopBack(SList* pl);

	// 在链表第一个元素前插入值为data的节点 
	void SListPushFront(SList* pl, int data);

	// 删除链表中第一个节点 
	void SListPopFront(SList* pl);

	// 在链表pos位置后插入置为data的节点 
	void SListInsertAfter(Node* pos, int data);

	// 删除链表中值为data的节点 
	void SListErase(SList* pl, Node* pos);

	// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回空 
	Node* SListFind(SList* pl, int data);

	// 销毁链表 
	void SListDestroy(SList* pl);

	// 获取链表中有效节点的个数 
	int SListSize(SList* pl);

	// 检测链表是否为空 
	int SListEmpty(SList* pl);

	// 获取链表的第一个节点 
	Node* SListFront(SList* pl);

	// 获取链表的第二个节点 
	Node* SListBack(SList* pl);

	// 删除链表中第一个值为data的节点 
	void SListRemove(SList* pl, int data);

	// 删除链表中所有值为data的节点 
	void SListRemoveAll(SList* pl, int data);
	//赋值运算符
	SList& operator=(const SList<T>& s1);
	//合并两个链表
	SList& operator+(const SList<T>& s1);
	//[]重载
	T operator[](int i);
	//cout<<重载
	template<class T>
	friend std::ostream& operator<<(std::ostream& os, const SList& s1);
};
//构造函数
template<class T>
SList<T>：：SList()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}
//复制构造函数
template<class T>
SList<T>::SList(const SList<T>& s1)
{
	if (s1.head != nullptr)
	{
		Node* tmp = s1.head;
		head = new Node(tmp->data);
		tail = head;
		
	}
}
//析构函数
~SList();
// 链表的初始化 
void SListInit(SList* pl);

// 在链表中尾插值为data的节点 
void SListPushBack(SList* pl, int data);

// 删除链表最后一个节点 
void SListPopBack(SList* pl);

// 在链表第一个元素前插入值为data的节点 
void SListPushFront(SList* pl, int data);

// 删除链表中第一个节点 
void SListPopFront(SList* pl);

// 在链表pos位置后插入置为data的节点 
void SListInsertAfter(Node* pos, int data);

// 删除链表中值为data的节点 
void SListErase(SList* pl, Node* pos);

// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回空 
Node* SListFind(SList* pl, int data);

// 销毁链表 
void SListDestroy(SList* pl);

// 获取链表中有效节点的个数 
int SListSize(SList* pl);

// 检测链表是否为空 
int SListEmpty(SList* pl);

// 获取链表的第一个节点 
Node* SListFront(SList* pl);

// 获取链表的第二个节点 
Node* SListBack(SList* pl);

// 删除链表中第一个值为data的节点 
void SListRemove(SList* pl, int data);

// 删除链表中所有值为data的节点 
void SListRemoveAll(SList* pl, int data);
//赋值运算符
SList& operator=(const SList<T>& s1);
//合并两个链表
SList& operator+(const SList<T>& s1);
//[]重载
T operator[](int i);
//cout<<重载
#endif