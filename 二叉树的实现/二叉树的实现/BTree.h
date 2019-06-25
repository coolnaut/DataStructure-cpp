#pragma once
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template <class T>
struct BTreeNode
{
	T data_;
	BTreeNode* left_;
	BTreeNode* right_;
	BTreeNode(const T& data = T())
		:data_(data)
		,left_(nullptr)
		,right_(nullptr)
	{}
};

class Solution
{
public:

	//通过数组构建二叉树
	BTreeNode<char>* BinaryTreeCreate(vector<char>arr, int size,  int* tmp)
	{
		if (size == 0)
		{
			return nullptr;
		}
		if (arr[*tmp] == '#')
		{
			return nullptr;
		}
		BTreeNode<char>* node = new BTreeNode<char>(arr[*tmp]);
		++*tmp;
		node->left_ = BinaryTreeCreate(arr, size, tmp);
		++*tmp;
		node->right_ = BinaryTreeCreate(arr, size,tmp);
		return node;
	}
	//二叉树的销毁
	void BinaryTreeDestroy(BTreeNode<char>* root)
	{
		if (!root)
		{
			return;
		}
		BinaryTreeDestroy(root->left_);
		BinaryTreeDestroy(root->right_);
		delete root;

	}
	
	//结点个数
	int BinaryTreeSize(BTreeNode<char>*  root)
	{
		if (!root)
		{
			return 0;
		}
		return 1 + BinaryTreeSize(root->left_) + BinaryTreeSize(root->right_);
	}

	//叶子的个数
	int BinaryTreeLeafSize(BTreeNode<char>*  root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		if (!(root->left_ || root->right_))
		{
			return 1;
		}
		return BinaryTreeLeafSize(root->left_) + BinaryTreeLeafSize(root->right_);
	}

	//第K层叶子结点的个数
	int BinaryTreeLevelKSize(BTreeNode<char>*  root, int k)
	{
		if (root == nullptr || k <= 0)
		{
			return 0;
		}
		if (root != nullptr && k == 1)
		{
			return 1;
		}
		return BinaryTreeLevelKSize(root->left_, k--) + BinaryTreeLevelKSize(root->right_, k--);
	}
	//查找结点
	BTreeNode<char>* BinaryTreeFindNode(BTreeNode<char>* root, char data)
	{
		if (!root)
		{
			return nullptr;
		}
		if (root->data_ == data)
		{
			return root;
		}
		BTreeNode<char>* retnode = BinaryTreeFindNode(root->left_, data);
		if (!retnode)
		{
			retnode = BinaryTreeFindNode(root->right_, data);
			if (retnode)
			{
				return retnode;
			}
			return nullptr;
		}
		else
		{
			return retnode;
		}
	}
	//递归前序遍历
	void BinaryTreePrevorder(BTreeNode<char>* root)
	{
		if (!root)
		{
			return;
		}
		cout << root->data_ << "-->";
		BinaryTreePrevorder(root->left_);
		BinaryTreePrevorder(root->right_);
	}
	//由于递归变量较为简单，后序和中序不详细写入


	//非递归操作
	//层序遍历
	void BinaryTreeLevelorder(BTreeNode<char>* root)
	{
		queue<BTreeNode<char>*> myq;
		if (root)
		{
			myq.push(root);
			while (!myq.empty())
			{
				cout << myq.front()->data_ << "  " << endl;
				
				if (myq.front()->left_)
				{
					myq.push(myq.front()->left_);
				}
				if (myq.front()->right_)
				{
					myq.push(myq.front()->right_);
				}
				myq.pop();
			}
		}
	}
};




////判断二叉树是否是完全二叉树
//char* BinaryTreeComplete(BTree<int>* root);
//
////前中后序遍历
//void BinaryTreePrevOrderNonP(BTree<int>* root);
//void BinaryTreeInOrderNonP(BTree<int>* root);
//void BinaryTreePostOrderNonP(BTree<int>* root);
//
//
