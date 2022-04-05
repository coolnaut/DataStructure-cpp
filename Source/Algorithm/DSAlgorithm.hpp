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
struct DSCacheNode {
	Type _value;
	DSCacheNode* _next;
	DSCacheNode* _prev;
	DSCacheNode(Type value)
		:_value(value£©		
		,_next(nullptr)
		,_prev(nullptr)
	{}
};

template <class kType, class vType>
class DSLRUCache {
	using DSCacheNodePtr = DSCacheNode<vType>*;
public:
	DSLRUCache() {
	};
	void insertObjecForKey(vType value, kType key) {
		if (_head) {
			unordered_map<kType, DSCacheNodePtr>::iterator itr = _cacheTable.find(key);
			if (itr != _cacheTable.end) {
				DSCacheNodePtr node = itr.second();
				node->_prev->_next = node->_next;
				node->_next->_prev = node->_prev;
				node->_next = _head;
				node->_prev = _head->_prev;
				_head->_prev = node;
				_head = node;
				node->_value = value;
			} else {
				DSCacheNodePtr node = new DSCacheNode(value);
				node->_next = _head;
				node->_prev = _head->_prev;
				_head->_prev = node;
				_head = node;
			}
		} else {
			_head = new DSCacheNode(value);
			_head->_next = _head;
			_head->_prev = _head;
			_cacheTable[key] = _head;
		}
	}

	vType objectForKey(kType key) {
		unordered_map<kType, DSCacheNodePtr>::iterator itr = _cacheTable.find(key);
		if (itr != _cacheTable.end) {
			return itr.second();
		} 
		return vType();
	}

private:
	unordered_map<kType, DSCacheNodePtr> _cacheTable;
	DSCacheNodePtr _head;
};