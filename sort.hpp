/**************************************************************
 *  Create by LGC, All Rights Reserved.
 *  Description: 
 *
 *  @author: https://blog.csdn.net/Void_leng
 *  @time: 2022/3/06
 **************************************************************/
#include <stdio.h>
#include <stack>
using namespace std;

class Sort {
public:
	bool _desc;
	Sort()
	:_arr(nullptr),
	_length(0) {
		_desc = false;
	}
	Sort(int arr[], int length)
	:_arr(arr),
	_length(length){
		_desc = false;
	}
	void insertSort() {
		if (assert()) {
			return;
		}
		arrayPrint("排序前");
		
		for (int index = 1; index < _length; ++index) {
			int tmp = _arr[index];
			int cur = index - 1;
			for (; cur >= 0; --cur) {
				if (_desc) {
					if (_arr[cur] < tmp) {
						_arr[cur + 1] = _arr[cur];
					} else {
						break;
					}
				} else {
					if (_arr[cur] > tmp) {
						_arr[cur + 1] = _arr[cur];
					} else {
						break;
					}
				}
			}
			_arr[cur + 1] = tmp;
		}
		arrayPrint("排序后");
	}
	void selectSort() {
		if (assert()) {
			return;
		}
		arrayPrint("排序前");
		for (int index = 1; index < _length; ++index) {
			int hit = 0;
			for (int cur = 1; cur <= _length - index; ++cur) {
				if (_desc) {
					if (_arr[hit] > _arr[cur]) {
						hit = cur;
					}
				} else {
					if (_arr[hit] < _arr[cur]) {
						hit = cur;
					}
				}
			}
			swap(&_arr[hit], &_arr[_length - index]);
		}
		arrayPrint("排序后");
	}

	void bubbleSort() {
		if (assert()) {
			return;
		}
		arrayPrint("排序前");
		for (int index = 1; index < _length; ++index) {
			int flag = 0;
			for (int cur = 1; cur <= _length - index; ++cur) {
				if (_desc) {
					if (_arr[cur - 1] < _arr[cur]) {
						swap(&_arr[cur - 1], &_arr[cur]);
						flag = 1;
					}
				} else {
					if (_arr[cur - 1] > _arr[cur]) {
						swap(&_arr[cur - 1], &_arr[cur]);
						flag = 1;
					}
				}
			}
			if (flag == 0) {
				break;
			}
		}
		arrayPrint("排序后");
	}

	void heapSort() {
		if (assert()) {
			return;
		}
		arrayPrint("排序前");
		// adjust
		auto adjust = [this](int root, int length) {
			while (1) {
				int left = root * 2 + 1;
				int right = root * 2 + 2;
				int mid = left;
				if (left >= length) {
					return;
				} else if (right < length) {
					if (_desc) {
						if (_arr[right] < _arr[left]) {
							mid = right;
						}
					} else {
						if (_arr[right] > _arr[left]) {
							mid = right;
						}
					}
					
				}
				if (_desc) {
					if (_arr[root] < _arr[mid]) {
						return;
					}
				} else {
					if (_arr[root] > _arr[mid]) {
						return;
					}
				}
				swap(&_arr[mid], &_arr[root]);
				root = mid;
			}
		};
		// create
		int lastNotLevel = _length * 0.5;
		while (lastNotLevel--) {
			adjust(lastNotLevel, _length);
		}
		// sort
		for (int index = 1; index < _length; ++index) {
			swap(&_arr[0], &_arr[_length - index]);
			adjust(0, _length - index);
		}
		arrayPrint("排序后");

		return;

	}

	void quickSort() {
		arrayPrint("排序前");
		// hover
		auto hover = [this](int left, int right)->int {
			int pivot = right;
			while (left < right) {
				while (left < right && _arr[left] <= _arr[pivot]) {
					++left;
				}
				while (left < right && _arr[pivot] <= _arr[right]) {
					--right;
				}
				swap(&_arr[left], &_arr[right]);
			}
			swap(&_arr[right], &_arr[pivot]);
			return right;
		};

		// 挖坑法
		auto dig = [this](int left, int right)->int {
			int pivot = _arr[right];
			while (left < right) {
				while (left < right && _arr[left] <= pivot) {
					++left;
				}
				_arr[right] = _arr[left];
				while (left < right && pivot <= _arr[right]) {
					--right;
				}
				_arr[left] = _arr[right];
			}
			_arr[right] = pivot;
			return right;
		};

		// 前后下标法
		auto subscript = [this](int left, int right)->int {
			int pre = left, after = left;
			int pivot = _arr[right];

			while (after < right) {
				if (pivot > _arr[after]) {
					swap(&_arr[pre], &_arr[after]);
					++pre;
				}
				++after;
			}
			swap(&_arr[right], &_arr[pre]);
			return pre;
		};

		int left = 0;
		int right = _length - 1;
		stack<int> tstack;
		do {
			if (!tstack.empty()) {
				right = tstack.top();
				tstack.pop();
				left = tstack.top();
				tstack.pop();
			}
			if (left < right) {
				int pivot = subscript(left, right);// dig(left, right); //  hover(left, right);
				if (pivot > left) {
					tstack.push(left);
					tstack.push(pivot - 1);

				}
				if (pivot < right) {
					tstack.push(pivot + 1);
					tstack.push(right);
				}
			}
		} while (!tstack.empty());
		arrayPrint("排序后");
	}
	~Sort() {
		printf("\ndealloc\n");
	}
private:
	bool assert() {
		if (!_arr || _length <= 1) {
			printf("\n无法排序 或 不需要排序\n");
			return true;
		}
		return false;
	}
	void arrayPrint(const char* message) {
		int index = 0;
		printf("\n%s\n", message);
		while (index < _length) {
			printf("%d ", _arr[index]);
			++index;
		}
	}
	void swap(int* left, int* right) {
		if (*left == *right) return;
		*left ^= *right;
		*right ^= *left;
		*left ^= *right;
	}
private:
	int* _arr;
	int _length;
};
