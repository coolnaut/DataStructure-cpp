/**************************************************************
 *  Create by LGC, All Rights Reserved.
 *  Description: 
 *
 *  @author: https://blog.csdn.net/Void_leng
 *  @time: 
 **************************************************************/
#pragma once

#include <stdio.h>
#include <stack>
#include <queue>


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) :
        val(x), left(nullptr), right(nullptr) {
    }
};

class SearchTree {
    typedef TreeNode* TreeNodePtr;
public:
    SearchTree():_root(nullptr) {};
    SearchTree(int nodeArr[], int length) {
        for (int i = 0; i < length; ++i) {
            insert(nodeArr[i]);
        }
    }

    void sequencePrint(bool recursion) {
        if (recursion) {
            int level = 1;
            while (__sequenceWithRecursion(_root, level)) {
                level += 1;
            }
        }
    }

    void preorderPrint(bool recursion) {
        if (recursion) __preorderWithRecursion(_root);
        else __preorderWithLoop(_root);
    }
    
    void midorderPrint(bool recursion) {
        if (recursion) __midorderWithRecursion(_root);
        else __midorderWithLoop(_root);
    }

    void postorderPrint(bool recursion) {
        if (recursion) __postorderWithRecursion(_root);
        else __postorderWithLoop(_root);
    }

    void insert(int val) {
        if (_root) {
            TreeNodePtr cur = _root;
            TreeNodePtr parent = nullptr;
            while (cur) {
                if (cur->val == val) {
                    return;
                } else if (cur->val < val) {
                    parent = cur;
                    cur = cur->right;
                } else {
                    parent = cur;
                    cur = cur->left;
                }
            }
            if (parent->val < val) {
                parent->right = new TreeNode(val);
            } else {
                parent->left = new TreeNode(val);
            }
        } else {
            _root = new TreeNode(val);
        }
    }
private:
    
    bool __sequenceWithRecursion(TreeNodePtr root, int currentLevel) {
        if (root && currentLevel > 0) {
            if (currentLevel == 1) {
                printf("%d ", root->val);
                return true;
            }
            bool hasLeft = __sequenceWithRecursion(root->left, currentLevel - 1);
            return  __sequenceWithRecursion(root->right, currentLevel - 1) || hasLeft;

        }
        return false;
    }

    void __sequenceWithRecursion(TreeNodePtr root) {
        queue<TreeNodePtr> levelQueue;
        TreeNodePtr node = root;
        levelQueue.push(node);
        while (!levelQueue.empty()) {
            node = levelQueue.front();
            levelQueue.pop();
            printf("%d ", node->val);
            if (node->left) {
                levelQueue.push(node->left);
            }
            if (node->right) {
                levelQueue.push(node->right);
            }
        }
    }

    void __preorderWithRecursion(TreeNodePtr root) {
        if (root) {  
            printf("%d ", root->val);
            __preorderWithRecursion(root->left);
            __preorderWithRecursion(root->right);
        }
    }

    void __preorderWithLoop(TreeNodePtr root) {
        stack<TreeNodePtr> nodeStack;
        TreeNodePtr node = root;
        while (!nodeStack.empty() || node) {
            if (node) {
                printf("%d ", node->val);
                nodeStack.push(node);
                node = node->left;
            } else {
                node = nodeStack.top();
                node = node->right;
                nodeStack.pop();
            }
        }
    }

    void __midorderWithRecursion(TreeNodePtr root) {
        if (root) {
            __midorderWithRecursion(root->left);
            printf("%d ", root->val);
            __midorderWithRecursion(root->right);
        }
    }


    void __midorderWithLoop(TreeNodePtr root) {
        stack<TreeNodePtr> nodeStack;
        TreeNodePtr node = root;
        while (!nodeStack.empty() || node) {
            if (node) {
                nodeStack.push(node);
                node = node->left;
            } else {
                node = nodeStack.top();
                printf("%d ", node->val);
                node = node->right;
                nodeStack.pop();
            }
        }
    }

    void __postorderWithRecursion(TreeNodePtr root) {
        if (root) {
            __postorderWithRecursion(root->left);
            __postorderWithRecursion(root->right);
            printf("%d ", root->val);
        }
    }


    void __postorderWithLoop(TreeNodePtr root) {
        stack<TreeNodePtr> nodeStack;
        stack<TreeNodePtr> orderStack;
        TreeNodePtr node = root;
        nodeStack.push(node);
        while (!nodeStack.empty()) {
            node = nodeStack.top();
            orderStack.push(node);
            nodeStack.pop();

            if (node->left) {
                nodeStack.push(node->left);
            }
            if (node->right) {
                nodeStack.push(node->right);
            }
        }
        while (!orderStack.empty()) {
            printf("%d ", orderStack.top()->val);
            orderStack.pop();
        }
    }


private:
    TreeNodePtr _root;
};
