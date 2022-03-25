/**************************************************************
 *  Create by Coolnaut, All Rights Reserved.
 *  Description:
 *
 *  @author: https://github.com/coolnaut
 *  @time: $time$
 **************************************************************/
#pragma once
#include "DSUtilityHeader.h"
// Sort with an array of type int
// The main purpose is algorithm examples
// Ascending sort
class DSSort {
public:
	DSSort (int arr[], size_t size)
	:_array(arr),
	_size(size) {

	}

	void selectSort() {
		if (__assert()) {
			return;
		}
		__printWithMessage("selectSort before");
		for (size_t row = 0; row < _size - 1; ++row) {
			size_t minIndex = row;
			for (size_t col = row + 1; col < _size; ++col) {
				if (_array[minIndex] > _array[col]) {
					minIndex = col;
				}
			}
			swap(_array[minIndex], _array[row]);
		}
		__printWithMessage("selectSort end");
	}

	void insertSort() {
		if (__assert()) {
			return;
		}
		__printWithMessage("insertSort before");
		for (size_t row = 1; row < _size; ++row) {
			int minValue = _array[row];
			size_t col = row;
			for (; col > 0; --col) {
				if (minValue < _array[col - 1]) {
					_array[col] = _array[col - 1];
				} else {
					break;
				}
			}
			_array[col] = minValue;
		}
		__printWithMessage("insertSort end");

	}

	void bubbleSort() {
		if (__assert()) {
			return;
		}
		__printWithMessage("bubbleSort before");
		for (size_t row = 1; row < _size; ++row) {
			for (size_t col = 0; col < _size - row; ++col) {
				if (_array[col] > _array[col + 1]) {
					swap(_array[col], _array[col + 1]);
				}
			}
		}
		__printWithMessage("bubbleSort end");
	}
	// 0 hover
	// 1 dig
	// 2 subcript
	void quickSortWithType(char type, bool recursion = true) {
		if (__assert()) {
			return;
		}
		__printWithMessage("quickSortWithType before");
		if (recursion) {
			__quickSort(type, 0, _size - 1);
		} else {
			__quickSort(type);
		}
		__printWithMessage("quickSortWithType end");
	}

	~DSSort () {
		_size = 0;
	}

// quick sort
private:
	size_t hover(size_t left, size_t right) {
		size_t pivot = right;
		while (left < right) {
			while (left < right && _array[left] <= _array[pivot]) {
				++left;
			}
			while (left < right && _array[right] >= _array[pivot]) {
				--right;
			}
			swap(_array[left], _array[right]);
		}
		swap(_array[right], _array[pivot]);
		return right;
	}
	size_t dig(size_t left, size_t right) {
		int pivot = _array[right];
		while (left < right) {
			while (left < right && _array[left] <= pivot) {
				++left;
			}
			_array[right] = _array[left];
			while (left < right && _array[right] >= pivot) {
				--right;
			}
			_array[left] = _array[right];
		}
		_array[right] = pivot;
		return right;
	}
	size_t subscript(size_t left, size_t right) {
		size_t pre = left;
		size_t end = left;
		while (end < right) {
			if (_array[end] < _array[right]) {
				swap(_array[end], _array[pre]);
				++pre;
			}
			++end;
		}
		swap(_array[pre], _array[right]);
		return pre;
	}


	void __quickSort(char type, size_t left, size_t right) {
		if (left >= right) {
			return;
		}
		size_t pivot = right;
		switch (type) {
		case 1:
			pivot = dig(left, right);
			break;
		case 2:
			pivot = subscript(left, right);
			break;
		default:
			pivot = hover(left, right);
			break;
		}
		if (pivot > left) {
			__quickSort(type, left, pivot - 1);
		}
		if (pivot < right) {
			__quickSort(type, pivot + 1, right);
		}
		
	}

	void __quickSort(char type) {
		size_t left = 0;
		size_t right = _size - 1;
		stack<size_t> indexStack;
		while (left < right || !indexStack.empty()) {
			size_t pivot = right;
			switch (type) {
			case 1:
				pivot = dig(left, right);
				break;
			case 2:
				pivot = subscript(left, right);
				break;
			default:
				pivot = hover(left, right);
				break;
			}
			if (pivot > left) {
				indexStack.push(left);
				indexStack.push(pivot - 1);
			}
			if (pivot < right) {
				indexStack.push(pivot + 1);
				indexStack.push(right);
			}
			right = indexStack.top();
			indexStack.pop();
			left = indexStack.top();
			indexStack.pop();
		}
	}

// tools
private:
	bool __assert() {
		return !_array || _size <= 1;
	}

	void __printWithMessage(const char* message) {
		cout << message << "\n";
		for (size_t index = 0; index < _size; ++index) {
			cout << _array[index] << " ";
		}
		cout << "\n";
	}

// property
private:
	int* _array;
	size_t _size;
};
