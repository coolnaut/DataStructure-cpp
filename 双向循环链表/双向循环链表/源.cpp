#include"DuList.h"

void practice1()
{
	DList<int> ls;
	ls.Push_Back(1);
	ls.Push_Back(2);
	ls.Push_Back(3);
	ls.Push_Back(4);
	ls.Print();

	ls.Pop_Back();
	ls.Pop_Back();
	ls.Print();
}
void practice2()
{
	DList<int> ls;

	ls.Push_Front(4);
	ls.Push_Front(3);
	ls.Push_Front(2);
	ls.Push_Front(1);
	ls.Print();

	ls.Pop_Front();
	ls.Pop_Front();
	ls.Pop_Front();
	ls.Print();
}
int main()
{
	practice1();
	system("pause");
	return 0;
}