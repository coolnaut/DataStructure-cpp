#include"BTree.h"


void test()
{
	Solution s;
	vector<char> arr = { '1', '2', '3', '4', '#', '#' ,'5', '#', '#', '#', '#' };
	int pos = 0;
	BTreeNode<char>* root = s.BinaryTreeCreate(arr, arr.size(), &pos);
	s.BinaryTreePrevorder(root);
	//s.BinaryTreeDestroy(root);
	cout << s.BinaryTreeSize(root) << endl;
	cout << s.BinaryTreeLeafSize(root) << endl;
	s.BinaryTreeLevelorder(root);
	cout << endl;
	cout << s.BinaryTreeComplete(root) << endl;
}
int main()
{
	test();
	return 0;
}