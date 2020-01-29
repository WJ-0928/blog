#pragma once

typedef struct Node
{
	int val;
	struct Node *left;
	struct Node *right;
} Node;

typedef struct ReturnType
{
	int use;// 创建树过程中用掉的值个数
	Node *root;// 创建好树的根节点
} ReturnType;

//要求:
//1. 熟悉树的概念以及相关概念
//2. 了解树的存储方式以及其区别
//3. 了解树的应用场景
//4. 熟悉二叉树的基本概念以及性质
//5. 熟悉满二叉树和完全二叉数，并掌握其区别
//6. 熟悉二叉树的静态存储与链式存储
//7. 实现链式数据结构的以下基本操作：



//二叉树的构建及遍历
ReturnType createTree(char preordered[], int size);

// 拷贝二叉树 
Node* CopyBinTree(Node* pRoot);

// 销毁二叉树 
void DestroyBinTree(Node* pRoot);
// 二叉树的三种遍历方式 
void PreOrder(Node* pRoot);
void PreOrderNor(Node* pRoot);
void InOrder(Node* pRoot);
void InOrderNor(Node* pRoot);
void PostOrder(Node* pRoot);
void PostOrderNor(Node* pRoot);
void LevelOrder(Node* pRoot);

// 获取二叉树中节点的个数 
int GetNodeCount(Node* pRoot);

// 求二叉树的高度 
int Height(Node* pRoot);

// 检测二叉树是否平衡O(N^2) 
int IsBalanceTree(Node* pRoot);
// 检测二叉树是否平衡O(N) 
int IsBalanceTree_P(Node* pRoot, int* height);

// 获取二叉数中叶子节点的个数 
int GetLeafNodeCount(Node* pRoot);

// 获取二叉树第K层节点的个数 
int GetKLevelNodeCount(Node* pRoot, int K);

// 获取二叉树中某个节点的双亲节点 
Node* GetNodeParent(Node* pRoot, Node* pNode);

// 求二叉树的镜像 
void Mirror(Node* pRoot);


