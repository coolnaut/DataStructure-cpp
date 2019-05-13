#pragma once
#include<vector>
#include<list>
#include<iostream>
using namespace std;

template<class T>
class Stack
{
public:
	Stack()
	{}
	void Push(const T& val)
	{
		stack_.push_back(val);
	}
	T& Pop()
	{
		stack_.pop_back();
	}
	T& Top()
	{
		return stack_.back();
	}
	size_t Size()
	{
		return stack_.size();
	}
private:
	vector<T> stack_;
};