#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

template<class T>
class SeqList
{
	typedef T* Iterator;
	typedef const T* Const_Iterator;
public:
	/*���캯��**********************************************************************/
	SeqList()
		:arr_(new T[1])
		, size_(0)
		, capacity_(1)
	{}
	SeqList(SeqList<T>& s)
	{
		arr_ = new T[s.Capasity()];
		for (int i = 0; i < s.Size(); ++i)
		{
			arr_[i] = s[i];
		}
		size_ = s.Size();
		capacity_ = s.Capacity();
	}
	~SeqList()
	{
		delete[] arr_;
		arr_ = nullptr;
	}
	/*�����޸ĵĽӿ�**************************************************************/
	void Push_Back(const T& val)
	{
		if (size_ == capacity_)
		{
			size_t newcapacity = capacity_ * 2;
			Reserve(newcapacity);
		}
		arr_[size_] = val;
		++size_;
		//Insert(0,val);
	}
	void Pop_Back()
	{
		assert(size_ > 0);
		--size_;
	}
	void Push_Front(const T& val)
	{
		if (size_ == capacity_)
		{
			size_t newcapacity = capacity_ * 2;
			Reserve(newcapacity);
		}
		for (int i = size_; i > 0; --i)
		{
			arr_[i] = arr_[i - 1];
		}
		arr_[0] = val;
		++size_;
	}
	void Insert(size_t pos, const T& val)
	{
		assert(pos <= size_);
		if (size_ == capacity_)
		{
			size_t newcapacity = capacity_ * 2;
			Reserve(newcapacity);
		}
		for (size_t i = size_; i > pos; --i)
		{
			arr_[i] = arr_[i - 1];
		}
		arr_[pos] = val;
		++size_;
	}
	void Erase(size_t pos)
	{
		assert(pos < size_ && size_ > 0);
		for (size_t i = pos; i < size_; ++i)
		{
			arr_[i] = arr_[i + 1];
		}
		--size_;
	}
	/*���������Ľӿ�**************************************************************/
	size_t Size()
	{
		return size_;
	}
	size_t Capacity()
	{
		return capacity_;
	}
	//�Զ�����
	void Reserve(size_t newcapacity)
	{
		T* newarr = new T[newcapacity];
		for (size_t i = 0; i < size_; ++i)
		{
			newarr[i] = arr_[i];
		}
		delete[] arr_;
		arr_ = newarr;
		capacity_ = newcapacity;
	}
	/*���ڵ������Ľӿ�**********************************************************************/
	Iterator begin()
	{
		return arr_;
	}
	Iterator end()
	{
		return arr_ + size_;
	}
	Const_Iterator begin()const
	{
		return arr_;
	}
	Const_Iterator end()const
	{
		return arr_ + size_;
	}
	/*���ڲ��������صĽӿ�*********************************************************************/
	T& operator[](size_t pos)
	{
		return arr_[pos];
	}
	void Print()
	{
		cout << "[]������" << endl;
		for (size_t i = 0; i < size_; ++i)
		{
			cout << arr_[i] << " ";
		}
		cout << endl;
		cout << "��Ч�ĸ���: " << size_ << endl;
		cout << "�����ǣ�" << capacity_ << endl;
	}
private:
	T* arr_;
	size_t size_;
	size_t capacity_;
};

template<class T>
void Print(SeqList<T>& arr, size_t size)
{
	cout << "[]������" << endl;
	for (size_t i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "��Χѭ��" << endl;
	for (auto& s : arr)
	{
		cout << s << " ";
	}
	cout << endl;
}