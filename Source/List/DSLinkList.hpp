/**************************************************************
 *  Create by Coolnaut, All Rights Reserved.
 *  Description:
 *
 *  @author: https://github.com/coolnaut
 *  @time: $time$
 **************************************************************/
#pragma once
#include "DSUtilityHeader.h"

template <class Type>
struct DSLinkListNode {
	DSLinkListNode* _next;
	Type _value;
	DSLinkListNode(Type value)
		:_next(nullptr)
		,_value(value)
	{}
};

template <class Type>
class DSLinkList {
	using DSLinkListNodePtr = DSLinkListNode<Type>*;
public:
	// life cycle
	DSLinkList ()
	:_head(nullptr)
	, _size(0) {}
	DSLinkList (Type arr[], size_t size) {
		while (size--) {
			pushFront(arr[size]);
		}
	}
	~DSLinkList () {
		DSLinkListNodePtr node = _head;
		DSLinkListNodePtr nextNode = node->_next;
		while (nextNode) {
			delete node;
			node = nextNode;
			nextNode = nextNode->_next;
		}
		delete node;
		_head = nullptr;
	}

	// action
	void pushBack(Type value) {
		insertWithIndex(_size, value);
	}
	void pushFront(Type value) {
		insertWithIndex(0, value);
	}
	void popBack() {
		ereaseWithIndex(_size - 1);
	}
	void popFront() {
		ereaseWithIndex(0);
	}
	bool insertWithIndex(size_t index, Type value) {
		if (!_head && index == 0) {
			_head = new DSLinkListNode<Type>(value);
			++_size;
			return true;
		} else if (index <= _size) {
				DSLinkListNodePtr insertNode = new DSLinkListNode<Type>(value);
				if (index == 0) {
					insertNode->_next = _head;
					_head = insertNode;
				} else {
					DSLinkListNodePtr node = _head;
					while (--index) {
						node = node->_next;
					}
					insertNode->_next = node->_next;
					node->_next = insertNode;
				}
			++_size;
			return true;
		}
		return false;
	}
	bool ereaseWithIndex(size_t index) {
		if (!_head || index >= _size) {
			return false;
		}
		DSLinkListNodePtr node = _head;
		DSLinkListNodePtr nextNode = _head->_next;
		if (index == 0) {
			delete node;
			_head = nextNode;
		} else {
			while (--index) {
				node = node->_next;
			}
			nextNode = node->_next;
			node->_next = nextNode->_next;
			delete nextNode;
		}
		--_size;
		return true;
	}
	void reverse() {
		if (this) {
			reverseBetween(1, _size);
			return;
		}
		// will never be executed in this file
		// Online Judge
		// You can just use the following code
		DSLinkListNodePtr preNode = nullptr;
		DSLinkListNodePtr currentNode = _head;
		while (currentNode) {
			DSLinkListNodePtr nextNode = currentNode->_next;
			currentNode->_next = preNode;
			preNode = currentNode;
			currentNode = nextNode;
		}
		_head = preNode;
	}
	void reverseBetween(int fromIndex, int toIndex) {
		if (fromIndex >= _size || toIndex > _size) {
			return;
		}
		// Online Judge
		// The following can be used as OJ solution
		// ps: ListNode* reverseBetween(ListNode* head, int m, int n)
		if (fromIndex >= toIndex) {
			return;
		}
		toIndex -= fromIndex;
		DSLinkListNodePtr pretendHead = new DSLinkListNode<int>(0);
		pretendHead->_next = _head;

		DSLinkListNodePtr fromNode = _head;
		DSLinkListNodePtr fromIndexNode = pretendHead;
		while (--fromIndex) {
			if (!fromNode) {
				return;
			}
			fromNode = fromNode->_next;
			fromIndexNode = fromIndexNode->_next;
		}
		DSLinkListNodePtr toNode = fromNode->_next;
		DSLinkListNodePtr preNode = fromNode;
		while (toIndex--) {
			DSLinkListNodePtr nextNode = toNode->_next;
			toNode->_next = preNode;
			preNode = toNode;
			toNode = nextNode;
		}
		fromIndexNode->_next = preNode;
		fromNode->_next = toNode;
		_head = pretendHead->_next;
		delete pretendHead;
	}
	void reverseKGroup(int k) {

	}
	void linkListPrint() {
		if (!_head) return;
		cout << "linkList: ";
		DSLinkListNodePtr node = _head;
		while (node) {
			cout << node->_value << " ";
			node = node->_next;
		}
		cout << "size: " << _size;
		cout << "\n";
	}
private:
	DSLinkListNodePtr _head;
	size_t _size;
};

template <class Type>
struct DSDoubleLinkListNode : public DSLinkListNode<Type> {
	DSLinkListNode<Type>* _prev;
	DSDoubleLinkListNode(Type value)
		:DSLinkListNode::DSLinkListNode(value)
		, _prev(nullptr)
	{}
};

template <class Type>
class  DSDoubleLinkList {
	using DSDLLNodePtr = DSDoubleLinkListNode<Type>*;
public:

};