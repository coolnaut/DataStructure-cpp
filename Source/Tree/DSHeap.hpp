/**************************************************************
 *  Create by Coolnaut, All Rights Reserved.
 *  Description:
 *
 *  @author: https://github.com/coolnaut
 *  @time: 
 **************************************************************/
#pragma once
#include "DSUtilityHeader.h"

template <class Type>
class DSHeap
{
public:
	// life cycle
	DSHeap(Type arr[], size_t length, bool bigHeap = true)
		:_length(length),
		_bigHeap(bigHeap) {
		_capacity = _length * 2;
		_array = new Type[_capacity];
		for (size_t index = 0; index < _length; ++index) {
			_array[index] = arr[index];
		}
		__createHeap();
	}

	~DSHeap() {
		delete[] _array;
		_length = 0;
		_capacity = 0;
		DSLog("~DSHeap");
	};

	// action
	bool insert(Type val) {
		if (assert()) {
			return false;
		}
		_array[_length] = val;
		__checkCapacity();
		__adjustUp(_length);
		return true;
	}

	void heapSort() {
		size_t pivot = _length * 0.5 - 1;
		for (size_t index = 1; index < _length; ++index) {
			__adjustDown(0, _length - index);
			swap(_array[0], _array[_length - index]);
		}
	}

	void heapPrint() {
		if (assert()) {
			return;
		}
		for (size_t index = 0; index < _length; ++index) {
			cout << _array[index] << " ";
		}
		cout << "\n";
	}
private:

	void __checkCapacity() {
		if (_capacity <= _length) {
			_capacity = _length * 2;
			Type* newArray = new Type[_capacity];
			for (size_t index = 0; index < _length; ++index) {
				newArray[index] = _array[index];
			}
			delete[] _array;
			_array = newArray;
		}
	}
	

	void __adjustUp(size_t childIndex) {
		while (childIndex) {
			size_t parentIndex = childIndex * 0.5 - 1;
			if (_bigHeap && _array[parentIndex] < _array[childIndex]) {
				swap(_array[parentIndex], _array[childIndex]);
			} else if (!_bigHeap && _array[parentIndex] > _array[childIndex]) {
				swap(_array[parentIndex], _array[childIndex]);
			} else {
				break;
			}
			childIndex = parentIndex;
		}
	}

	void __adjustDown(size_t rootIndex, size_t length) {
		while (true) {
			size_t left = rootIndex * 2 + 1;
			size_t right = rootIndex * 2 + 2;
			size_t index = left;
			if (left >= length) {
				return;
			}
			if (_bigHeap) {
				if (right < length && _array[left] < _array[right]) {
					index = right;
				}
				if (_array[rootIndex] > _array[index]) {
					return;
				}
				
			} else {
				if (right < length && _array[left] > _array[right]) {
					index = right;
				}
				if (_array[rootIndex] < _array[index]) {
					return;
				}
			}
			swap(_array[rootIndex], _array[index]);
			rootIndex = index;
		}
	}

	void __createHeap() {
		size_t pivot = _length * 0.5;
		while (--pivot) {
			__adjustDown(pivot, _length);
		}
		__adjustDown(0, _length);
	}
private:

	bool assert() {
		return !_array || _length == 0;
	}

private:
	Type* _array;
	size_t _length;
	size_t _capacity;
	bool _bigHeap;
};