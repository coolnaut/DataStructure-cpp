/**************************************************************
 *  Create by Coolnaut, All Rights Reserved.
 *  Description:
 *
 *  @author: https://github.com/coolnaut
 *  @time: $time$
 **************************************************************/
#pragma once
#include "DSBinaryTree.hpp"

template <class Type>
class DSSearchBinaryTree : public DSBinaryTree< Type> {
	using BTNodePtr = DSBinaryTreeNode<Type>*;
public:
	DSSearchBinaryTree()
		:DSBinaryTree<Type>::DSBinaryTree(){

	}

	DSSearchBinaryTree(Type arr[], size_t length)
	:DSBinaryTree<Type>::DSBinaryTree(arr, length) {

	}

	virtual bool insert(Type val) {
		if (!_root) {
			_root = new DSBinaryTreeNode(val);
			return true;
		}
		BTNodePtr* node = _root;
		BTNodePtr* parentNode = nullptr;
		while (node) {
			parentNode = node;
			if (node->_value >= val) {
				node = node->_right;
			} else {
				node = node->_left;
			}
		}
		if (parentNode->_value >= val) {
			parentNode->_right = new DSBinaryTreeNode(val);
		} else {
			parentNode->_left = new DSBinaryTreeNode(val);
		}
		return true;
	}

	virtual bool erease(Type val) {
		if (assert()) {
			return false;
		}
		// TODO
		return false;
	}

	virtual BTNodePtr findNode(Type val) {
		if (assert()) {
			return nullptr;
		}
		BTNodePtr node = _root;
		while (node) {
			if (node->_value > val) {
				node = node->_left;
			} else if (node->_value < val) {
				node = node->_right;
			} else {
				break;
			}
		}
		return node;
	}

	~DSSearchBinaryTree() {

	}

private:

};