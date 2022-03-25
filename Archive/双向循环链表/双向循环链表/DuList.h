#pragma once
#include<iostream>
using namespace std;

template<class T>
class DuLListNode//DuplexingList
{
public:
	DuLListNode(const T& val = T())
		:val_(val)
		, next_(nullptr)
		, pre_(nullptr)
	{}
	T val_;
	DuLListNode<T>* next_;
	DuLListNode<T>* pre_;
};

template<class T>
class DList
{
	typedef DuLListNode<T> Node;
	typedef DuLListNode<T>* PNode;
public:
	DList()
	{
		head_ = new  Node;
		head_->next_ = head_;
		head_->pre_ = head_;
	}
	void Push_Back(const T& val)
	{
		PNode node = new Node(val);
		node->next_ = head_;
		node->pre_ = head_->pre_;
		head_->pre_->next_ = node;
		head_->pre_ = node;
	}
	void Pop_Back()
	{
		if (head_)
		{
			head_->pre_->pre_->next_ = head_;
			head_->pre_ = head_->pre_->pre_;
		}
	}
	void Push_Front(const T& val)
	{
		PNode node = new Node(val);
		node->next_ = head_->next_;
		node->pre_ = head_;
		head_->next_->pre_ = node;
		head_->next_ = node;
	}
	void Pop_Front()
	{
		if (head_)
		{
			head_->next_->next_->pre_ = head_;
			head_->next_ = head_->next_->next_;
		}
	}
	void Print()
	{
		PNode tmp = head_->next_;
		while (tmp != head_)
		{
			cout << tmp->val_ << " ";
			tmp = tmp->next_;
		}
		cout << endl;
	}
	~DList()
	{
		if (head_)
		{
			PNode tmp = head_->next_;
			PNode next = head_;
			while (tmp != head_)
			{
				next = tmp->next_;
				delete tmp;
				tmp = next;
			}
			delete head_;
			head_ = nullptr;
		}
	}
private:
	PNode head_;
};

