#include"BTree.h"


void test1()
{
	Solution s;
	vector<char> arr = { '1', '2', '3', '4', '#', '#' ,'5', '#', '#', '#', '#' };
	int pos = 0;
	BTreeNode<char>* root = s.BinaryTreeCreate(arr, arr.size(), pos);
	s.BinaryTreePrevorder(root);
	//s.BinaryTreeDestroy(root);
	cout << s.BinaryTreeSize(root) << endl;
	cout << s.BinaryTreeLeafSize(root) << endl;
	s.BinaryTreeLevelorder(root);
	cout << endl;
	cout << s.BinaryTreeComplete(root) << endl;
}
void test2()
{
	Solution s;
	vector<char> arr = { '1', '2', '4', '#', '#', '#' ,'3', '#', '5', '#', '#' };
	int pos = 0;
	BTreeNode<char>* root = s.BinaryTreeCreate(arr, arr.size(), pos);

	s.BinaryTreePrevOrderNonP(root);
	cout << endl;
	s.BinaryTreeInOrderNonP(root);
	cout << endl;
}
int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}