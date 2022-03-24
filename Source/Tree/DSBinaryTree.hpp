/**************************************************************
 *  Create by Coolnaut, All Rights Reserved.
 *  Description:
 *
 *  @author: https://github.com/coolnaut
 *  @time:
 **************************************************************/
#pragma once
#include "DSUtilityHeader.h"



#define kMessagePrint(message) cout << message;
#define kNodePrint(node) cout << node->_value << " ";

template <class Type>
struct DSBinaryTreeNode {
	Type _value;
	DSBinaryTreeNode* _left;
	DSBinaryTreeNode* _right;
	DSBinaryTreeNode(Type value)
	:_value (value),
	_left (nullptr),
	_right (nullptr){}
};

template <class Type>
class DSBinaryTree {
	using BTNodePtr = DSBinaryTreeNode<Type>*;
public:

	// life cycle
	DSBinaryTree() :
		_root(nullptr) {}

	DSBinaryTree(Type arr[], size_t length) {
		if (!arr || length == 0) {
			return;
		}
		for (size_t index = 0; index < length; ++index) {
			insert(arr[index]);
		}
	}

	virtual ~DSBinaryTree() {
		DSLog("~DSBinaryTree");
	}

	// action
	virtual bool insert(Type val) {
		if (!_root) {
			_root = new DSBinaryTreeNode<Type>(val);
			return true;
		}
		queue<BTNodePtr> nodeQueue;
		nodeQueue.push(_root);
		while(!nodeQueue.empty()) {
			BTNodePtr node = nodeQueue.front();
			nodeQueue.pop();
			if (node->_left) {
				nodeQueue.push(node->_left);
			} else {
				node->_left = new DSBinaryTreeNode<Type>(val);
				break;
			}
			if (node->_right) {
				nodeQueue.push(node->_right);
			} else {
				node->_right = new DSBinaryTreeNode<Type>(val);
				break;
			}
		}
		return true;
	}

	// print
	void sequencePrintWithRecursion(bool recursion = true) {
		if (assert()) {
			return;
		}
		if(recursion) {
			int level = 1;
			while (__sequenceWithRecursion(_root, level)) {
				level += 1;
			}
		} else {
			__sequenceWithLoop();
		}
		kMessagePrint("\n");
	}

	void preorderPrintWithRecursion(bool recursion = true) {
		if(assert()) {
			return;
		}
		if (recursion) __preorderWithRecursion(_root);
		else __preorderWithLoop(); 
		kMessagePrint("\n"); 
	}

	void midorderPrintWithRecursion(bool recursion = true) {
		if(assert()) {
			return;
		}
		if(recursion) __midorderWithRecursion(_root);
		else __midorderWithLoop();
		kMessagePrint("\n");
	}

	void postorderPrintWithRecursion(bool recursion = true) {
		if(assert()) {
			return;
		}
		if (recursion) __postorderWithRecursion(_root);
		else __postorderWithLoop();
		kMessagePrint("\n");
	}
private:
	bool __sequenceWithRecursion(BTNodePtr root, size_t level) {
		if (!root || level == 0) {
			return false;
		}
		if(level == 1) {
			kNodePrint(root);
			return true;
		}
		bool hasLeft = __sequenceWithRecursion(root->_left, level - 1);
		return __sequenceWithRecursion(root->_right, level - 1);
	}

	void __sequenceWithLoop() {
		queue<BTNodePtr> nodeQueue;
		nodeQueue.push(_root);
		while(!nodeQueue.empty()) {
			BTNodePtr node = nodeQueue.front();
			kNodePrint(node);
			nodeQueue.pop();
			if (node->_left) {
				nodeQueue.push(node->_left);
			}
			if (node->_right) {
				nodeQueue.push(node->_right);
			}
		}
	}

	void __preorderWithRecursion(BTNodePtr root) {
		if(!root) {
			return;
		}
		kNodePrint(root);
		__preorderWithRecursion(root->_left);
		__preorderWithRecursion(root->_right);
	}

	void __preorderWithLoop() {
		stack<BTNodePtr> nodeStack;
		BTNodePtr node = _root;
		while(!nodeStack.empty() || node) {
			if (node) {
				kNodePrint(node);
				nodeStack.push(node);
				node = node->_left;
			} else {
				node = nodeStack.top()->_right;
				nodeStack.pop();
			}
		}
	}

	void __midorderWithRecursion(BTNodePtr root) {
		if (!root) {
			return;
		}
		__midorderWithRecursion(root->_left);
		kNodePrint(root);
		__midorderWithRecursion(root->_right);
	}

	void __midorderWithLoop() {
		stack<BTNodePtr> nodeStack;
		BTNodePtr node = _root;
		while (!nodeStack.empty() || node) {
			if (node) {
				nodeStack.push(node);
				node = node->_left;
			} else {
				node = nodeStack.top();
				kNodePrint(node);
				node = node->_right;
				nodeStack.pop();
			}
		}
	}

	void __postorderWithRecursion(BTNodePtr root) {
		if (!root) {
			return;
		}
		__postorderWithRecursion(root->_left);
		__postorderWithRecursion(root->_right);
		kNodePrint(root);
	}

	void __postorderWithLoop() {
		stack<BTNodePtr> nodeStack;
		stack<BTNodePtr> orderStack;
		BTNodePtr node = _root;
		while (!nodeStack.empty() || node) {
			if (node) {
				nodeStack.push(node);
				orderStack.push(node);
				node = node->_right;
			} else {
				node = nodeStack.top()->_left;
				nodeStack.pop();
			}
		}
		while (!orderStack.empty()) {
			kNodePrint(orderStack.top());
			orderStack.pop();
		}
	}

protected: // tools
	virtual bool assert() {
		return !_root;
	}
protected:
	BTNodePtr _root;
};
