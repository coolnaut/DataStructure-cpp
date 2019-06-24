#pragma once
#pragma once
template <class T>
struct BTreeNode
{
	T data_;
	BTreeNode* left_;
	BTreeNode* right_;
	BTreeNode(const T& data)
		:data_(data)
		,left_(nullptr)
		,right_(nullptr)
	{}
};
template <class T>
class BTree
{
public:
	typedef BTreeNode<T> Node;
	typedef BTreeNode<T>* pNode;

	BTree()//构造空树
		:root_(nullptr)
	{}

private:
	pNode root_;
};
//构建二叉树
BTree<int>* BinaryTreeCreate(BTree<int>* arr, int size, int* sign);

//二叉树的销毁
void BinaryTreeDestroy(BTree<int> root);

//结点个数
int BinaryTreeSize(BTree<int> root);

//叶子的个数
int BinaryTreeLeafSize(BTree<int>* root);

//第K层叶子结点的个数
int BinaryTreeLevelKSize(BTree<int>* root, int k);

//查找结点
BTree<int>* BinaryTreeFindNode(BTree<int>* root, BTDataType data);

//前中后遍历
void BinaryTreePrevorder(BTree<int>* root);
void BinaryTreeInorder(BTree<int>* root);
void BinaryTreePostorder(BTree<int>* root);

//非递归操作
//层序遍历
void BinaryTreeLevelorder(BTree<int>* root);

//判断二叉树是否是完全二叉树
char* BinaryTreeComplete(BTree<int>* root);

//前中后序遍历
void BinaryTreePrevOrderNonP(BTree<int>* root);
void BinaryTreeInOrderNonP(BTree<int>* root);
void BinaryTreePostOrderNonP(BTree<int>* root);



#pragma once
#pragma once
template <class T>
struct BTreeNode
{
	T data_;
	BTreeNode* left_;
	BTreeNode* right_;
	BTreeNode(const T& data)
		:data_(data)
		,left_(nullptr)
		,right_(nullptr)
	{}
};
template <class T>
class BTree
{
public:
	typedef BTreeNode<T> Node;
	typedef BTreeNode<T>* pNode;

	BTree()//构造空树
		:root_(nullptr)
	{}

private:
	pNode root_;
};
//构建二叉树
BTree<int>* BinaryTreeCreate(BTree<int>* arr, int size, int* sign);

//二叉树的销毁
void BinaryTreeDestroy(BTree<int> root);

//结点个数
int BinaryTreeSize(BTree<int> root);

//叶子的个数
int BinaryTreeLeafSize(BTree<int>* root);

//第K层叶子结点的个数
int BinaryTreeLevelKSize(BTree<int>* root, int k);

//查找结点
BTree<int>* BinaryTreeFindNode(BTree<int>* root, BTDataType data);

//前中后遍历
void BinaryTreePrevorder(BTree<int>* root);
void BinaryTreeInorder(BTree<int>* root);
void BinaryTreePostorder(BTree<int>* root);

//非递归操作
//层序遍历
void BinaryTreeLevelorder(BTree<int>* root);

//判断二叉树是否是完全二叉树
char* BinaryTreeComplete(BTree<int>* root);

//前中后序遍历
void BinaryTreePrevOrderNonP(BTree<int>* root);
void BinaryTreeInOrderNonP(BTree<int>* root);
void BinaryTreePostOrderNonP(BTree<int>* root);