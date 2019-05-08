#include"SeqList.h"

int main()
{
	SeqList<int> arr;

	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	
	Print(arr, arr.Size());
	system("pause");
	return 0;
}