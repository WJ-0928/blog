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
	//���ƹ��캯��
	SList(const SList<T>& s1);
	//��������
	~SList();
	// ����ĳ�ʼ�� 
	void SListInit(SList* pl);

	// ��������β��ֵΪdata�Ľڵ� 
	void SListPushBack(SList* pl, int data);

	// ɾ���������һ���ڵ� 
	void SListPopBack(SList* pl);

	// �������һ��Ԫ��ǰ����ֵΪdata�Ľڵ� 
	void SListPushFront(SList* pl, int data);

	// ɾ�������е�һ���ڵ� 
	void SListPopFront(SList* pl);

	// ������posλ�ú������Ϊdata�Ľڵ� 
	void SListInsertAfter(Node* pos, int data);

	// ɾ��������ֵΪdata�Ľڵ� 
	void SListErase(SList* pl, Node* pos);

	// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻ؿ� 
	Node* SListFind(SList* pl, int data);

	// �������� 
	void SListDestroy(SList* pl);

	// ��ȡ��������Ч�ڵ�ĸ��� 
	int SListSize(SList* pl);

	// ��������Ƿ�Ϊ�� 
	int SListEmpty(SList* pl);

	// ��ȡ����ĵ�һ���ڵ� 
	Node* SListFront(SList* pl);

	// ��ȡ����ĵڶ����ڵ� 
	Node* SListBack(SList* pl);

	// ɾ�������е�һ��ֵΪdata�Ľڵ� 
	void SListRemove(SList* pl, int data);

	// ɾ������������ֵΪdata�Ľڵ� 
	void SListRemoveAll(SList* pl, int data);
	//��ֵ�����
	SList& operator=(const SList<T>& s1);
	//�ϲ���������
	SList& operator+(const SList<T>& s1);
	//[]����
	T operator[](int i);
	//cout<<����
	template<class T>
	friend std::ostream& operator<<(std::ostream& os, const SList& s1);
};
//���캯��
template<class T>
SList<T>����SList()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}
//���ƹ��캯��
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
//��������
~SList();
// ����ĳ�ʼ�� 
void SListInit(SList* pl);

// ��������β��ֵΪdata�Ľڵ� 
void SListPushBack(SList* pl, int data);

// ɾ���������һ���ڵ� 
void SListPopBack(SList* pl);

// �������һ��Ԫ��ǰ����ֵΪdata�Ľڵ� 
void SListPushFront(SList* pl, int data);

// ɾ�������е�һ���ڵ� 
void SListPopFront(SList* pl);

// ������posλ�ú������Ϊdata�Ľڵ� 
void SListInsertAfter(Node* pos, int data);

// ɾ��������ֵΪdata�Ľڵ� 
void SListErase(SList* pl, Node* pos);

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻ؿ� 
Node* SListFind(SList* pl, int data);

// �������� 
void SListDestroy(SList* pl);

// ��ȡ��������Ч�ڵ�ĸ��� 
int SListSize(SList* pl);

// ��������Ƿ�Ϊ�� 
int SListEmpty(SList* pl);

// ��ȡ����ĵ�һ���ڵ� 
Node* SListFront(SList* pl);

// ��ȡ����ĵڶ����ڵ� 
Node* SListBack(SList* pl);

// ɾ�������е�һ��ֵΪdata�Ľڵ� 
void SListRemove(SList* pl, int data);

// ɾ������������ֵΪdata�Ľڵ� 
void SListRemoveAll(SList* pl, int data);
//��ֵ�����
SList& operator=(const SList<T>& s1);
//�ϲ���������
SList& operator+(const SList<T>& s1);
//[]����
T operator[](int i);
//cout<<����
#endif