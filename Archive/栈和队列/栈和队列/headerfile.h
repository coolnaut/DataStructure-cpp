#pragma once
#include<vector>
#include<list>
#include<deque>
#include<iostream>
using namespace std;

template<class T, class container = deque<T>>
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
	container stack_;
};

template<class T, class container = deque<T>>
class Queue
{
public:
	Queue()
	{}
	void Push(const T& val)
	{
		queue_.push_back(val);
	}
	T& Pop()
	{
		queue_.pop_back();
	}
	T& Top()
	{
		return queue_.back();
	}
	size_t Size()
	{
		return queue_.size();
	}
private:
	container queue_;
};