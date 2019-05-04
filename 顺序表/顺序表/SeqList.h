#pragma once
#include<iostream>
using namespace std;

template<class T>
class SeqList
{
	SeqList()
		:arr_(new T[1])
		, size_(0)
		, capasity_(1)
	{}
private:
	T* arr_;
	size_t size_;
	size_t capasity_;
};