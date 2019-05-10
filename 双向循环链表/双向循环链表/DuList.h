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
	{
		//DuLListNode<T>* node = new DuLListNode<T>;
		//next_ = this;
		//pre_ = this;
	}
	~DuLListNode()
	{

	}
	T val_;
	DuLListNode<T>* next_;
	DuLListNode<T>* pre_;
};
template<class T>
class DList
{
	typedef DuLListNode<T>* PNode;
public:
	DList(const T& val = T())
	{
		PNode head_ = new  DuLListNode<T>;
		head_->next_ = head_;
		head_->pre_ = head_;
	}
	void Push_Back(const T& val)
	{
		PNode node(val);
		node->next_ = head_;
		node->pre_ = head_->pre_;
		head_->pre_->next_ = node;
		head_->pre_ = node;
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
template<class T>
void Print(DList<T>& ls)
{

}