#pragma once
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
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

	//ͨ�����鹹��������
	BTreeNode<char>* BinaryTreeCreate(vector<char>arr, int size,  int& tmp)
	{
		if (size == 0)
		{
			return nullptr;
		}
		if (arr[tmp] == '#')
		{
			return nullptr;
		}
		BTreeNode<char>* node = new BTreeNode<char>(arr[tmp]);
		++tmp;
		node->left_ = BinaryTreeCreate(arr, size, tmp);
		++tmp;
		node->right_ = BinaryTreeCreate(arr, size,tmp);
		return node;
	}
	//������������
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
	
	//������
	int BinaryTreeSize(BTreeNode<char>*  root)
	{
		if (!root)
		{
			return 0;
		}
		return 1 + BinaryTreeSize(root->left_) + BinaryTreeSize(root->right_);
	}

	//Ҷ�ӵĸ���
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

	//��K��Ҷ�ӽ��ĸ���
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
	//���ҽ��
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
	//�ݹ�ǰ�����
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
	//���ڵݹ������Ϊ�򵥣������������ϸд��


	//�ǵݹ����
	//�������
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
	//�ж϶������Ƿ�����ȫ������
	bool BinaryTreeComplete(BTreeNode<char>* root)
	{
		if (!root)
		{
			return true;
		}
		queue< BTreeNode<char>*> myq;
		myq.push(root);
		while (1)
		{
			myq.push(root->left_);
			myq.push(root->right_);
			myq.pop();
			root = myq.front();
			if (root == nullptr)
			{
				break;
			}
		}
		while (!myq.empty())
		{
			if (myq.front() != nullptr)
			{
				return false;
			}
			myq.pop();
		}
		return true;
	}

	//ǰ�к������
	void BinaryTreePrevOrderNonP(BTreeNode<char>* root)
	{
		//ǰ�����-->�����ұ���
		stack< BTreeNode<char>*> nodeq;
		BTreeNode<char>* cur = root;
		while (cur != nullptr || !nodeq.empty())
		{
			//�Ӹ��ڵ�һֱ�������
			//֪��û�����ӣ�Ȼ��ʼ������ǰ�����Һ���
			//���������ӣ����ҵ���͵�һ����ͬ
			while (cur != nullptr)
			{
				cout << cur->data_ << " ";
				nodeq.push(cur);
				cur = cur->left_;
			}
			BTreeNode<char>* tmp = nodeq.top();
			nodeq.pop();
			cur = tmp->right_;
		}
	}
	void BinaryTreeInOrderNonP(BTreeNode<char>* root)
	{
		stack< BTreeNode<char>*> nodeq;
		BTreeNode<char>* cur = root;
		while (cur != nullptr || !nodeq.empty())
		{
			while (cur != nullptr)
			{
				nodeq.push(cur);
				cur = cur->left_;
			}
			BTreeNode<char>* tmp = nodeq.top();
			nodeq.pop();
			cout << tmp->data_ << " ";
			cur = tmp->right_;
		}
	}
	void BinaryTreePostOrderNonP(BTreeNode<char>* root)
	{
		stack< BTreeNode<char>*> parentstack;
		stack< BTreeNode<char>*> childstack;
		BTreeNode<char>* cur = root;
		
		while (cur != nullptr || !parentstack.empty())
		{
			if (cur)
			{
				parentstack.push(cur);
				childstack.push(cur);
				cur = cur->right_;
			}
			else
			{
				cur = parentstack.top();
				parentstack.pop();
				cur = cur->left_;
			}
		}
		while (!childstack.empty())
		{
			cout << childstack.top()->data_ << " ";
			childstack.pop();
		}
		cout << endl;
	}
};