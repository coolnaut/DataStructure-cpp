#include"SeqList.h"
void test1()
{
	SeqList<int> arr;
	arr.Push_Back(1);
	arr.Push_Back(2);
	arr.Push_Back(3);
	arr.Push_Back(4);
	arr.Print();
	//Print(arr, arr.Size());

	//arr.Pop_Back();
	//arr.Pop_Back();
	//Print(arr, arr.Size());

	//arr.Insert(2, 3);
	//arr.Insert(3, 4);
	//Print(arr, arr.Size());

	//arr.Erase(1);
	//arr.Erase(1);
	//Print(arr, arr.Size());
}
int main()
{
	test1();
	system("pause");
	return 0;
}