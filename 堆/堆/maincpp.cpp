#include"Heap.h"
#include<stdlib.h>
#include<stdio.h>




//向下调整算法
//判断是否是有左孩子，无则返回
//有，则判断是否有右孩子，有判断左孩子和右孩子谁大
//判断是否需要调整
//继续调整
void hp_down(HPDataType* arr, int size, int root)
{

	while (1)
	{
		int left = root * 2 + 1;
		int right = root * 2 + 2;
		int min;
		if (left >= size)
		{
			return;
		}
		if (right < size && arr[right] < arr[left])
		{
			min = right;
		}
		else
		{
			min = left;
		}
		if (arr[root] <= arr[min])
		{
			return;
		}
		HPDataType temp = arr[root];
		arr[root] = arr[min];
		arr[min] = temp;
		//root = min;
		hp_down(arr, size, min);
	}

}
//向上调整
void hp_up(Heap* hp, int child)
{
	while (child)
	{
		int parent = (child - 1) / 2;
		if (hp->arr[parent] > hp->arr[child])
		{
			int temp = hp->arr[child];
			hp->arr[child] = hp->arr[parent];
			hp->arr[parent] = temp;
		}
		child = parent;
	}
}
//建堆
void hp_create(HPDataType* arr, int size)
{
	//从最后一个非叶子结点开始调整，知道堆顶
	int temp = (size - 2) / 2;
	while (temp >= 0)
	{
		hp_down(arr, size, temp);
		--temp;
	}
}
//堆的扩容
void check_capacity(Heap* hp)
{
	if (hp->size >= hp->capacity)
	{
		hp->capacity = hp->capacity * 2;
		HPDataType* newarr = (HPDataType*)malloc(sizeof(HPDataType) * hp->capacity);
		for (int i = 0; i < hp->size; ++i)
		{
			newarr[i] = hp->arr[i];
		}
		free(hp->arr);
		hp->arr = newarr;
	};
}
//堆的初始化
void hp_init(Heap* hp, HPDataType* arr, int capacity)
{
	hp->capacity = capacity;
	hp->size = capacity;
	hp->arr = (HPDataType*)malloc(sizeof(HPDataType) * hp->capacity);
	int temp = 0;
	while (temp < hp->size)
	{
		hp->arr[temp] = arr[temp];
		++temp;
		check_capacity(hp);
	}
	hp_create(hp->arr, hp->size);
}
//堆的销毁
void hp_destroy(Heap* hp)
{
	hp->capacity = hp->size = 0;
	free(hp->arr);
}
//堆的插入
void hp_add(Heap* hp, HPDataType data)
{
	hp->arr[hp->size] = data;
	check_capacity(hp);
	hp_up(hp, hp->size);
	++hp->size;
}
//堆的删除
void hp_del(Heap* hp)
{
	if (hp->size == 0)
	{
		return;
	}
	hp->arr[0] = hp->arr[hp->size - 1];
	hp_down(hp->arr, hp->size, 0);
	--hp->size;
}
//堆顶元素
int hp_top(Heap* hp)
{
	if (hp->size > 0)
	{
		return hp->arr[0];
	}
	return -1;
}
//堆的结点数
int hp_size(Heap* hp)
{
	return hp->size;
}
//判断堆是否为空
int hp_empty(Heap* hp)
{
	if (hp->size > 0)
	{
		return 1;
	}
	return 0;
}





#include"Heap.h"
#include<stdlib.h>
#include<stdio.h>




//向下调整算法
//判断是否是有左孩子，无则返回
//有，则判断是否有右孩子，有判断左孩子和右孩子谁大
//判断是否需要调整
//继续调整
void hp_down(HPDataType* arr, int size, int root)
{

	while (1)
	{
		int left = root * 2 + 1;
		int right = root * 2 + 2;
		int min;
		if (left >= size)
		{
			return;
		}
		if (right < size && arr[right] < arr[left])
		{
			min = right;
		}
		else
		{
			min = left;
		}
		if (arr[root] <= arr[min])
		{
			return;
		}
		HPDataType temp = arr[root];
		arr[root] = arr[min];
		arr[min] = temp;
		//root = min;
		hp_down(arr, size, min);
	}

}
//向上调整
void hp_up(Heap* hp, int child)
{
	while (child)
	{
		int parent = (child - 1) / 2;
		if (hp->arr[parent] > hp->arr[child])
		{
			int temp = hp->arr[child];
			hp->arr[child] = hp->arr[parent];
			hp->arr[parent] = temp;
		}
		child = parent;
	}
}
//建堆
void hp_create(HPDataType* arr, int size)
{
	//从最后一个非叶子结点开始调整，知道堆顶
	int temp = (size - 2) / 2;
	while (temp >= 0)
	{
		hp_down(arr, size, temp);
		--temp;
	}
}
//堆的扩容
void check_capacity(Heap* hp)
{
	if (hp->size >= hp->capacity)
	{
		hp->capacity = hp->capacity * 2;
		HPDataType* newarr = (HPDataType*)malloc(sizeof(HPDataType) * hp->capacity);
		for (int i = 0; i < hp->size; ++i)
		{
			newarr[i] = hp->arr[i];
		}
		free(hp->arr);
		hp->arr = newarr;
	};
}
//堆的初始化
void hp_init(Heap* hp, HPDataType* arr, int capacity)
{
	hp->capacity = capacity;
	hp->size = capacity;
	hp->arr = (HPDataType*)malloc(sizeof(HPDataType) * hp->capacity);
	int temp = 0;
	while (temp < hp->size)
	{
		hp->arr[temp] = arr[temp];
		++temp;
		check_capacity(hp);
	}
	hp_create(hp->arr, hp->size);
}
//堆的销毁
void hp_destroy(Heap* hp)
{
	hp->capacity = hp->size = 0;
	free(hp->arr);
}
//堆的插入
void hp_add(Heap* hp, HPDataType data)
{
	hp->arr[hp->size] = data;
	check_capacity(hp);
	hp_up(hp, hp->size);
	++hp->size;
}
//堆的删除
void hp_del(Heap* hp)
{
	if (hp->size == 0)
	{
		return;
	}
	hp->arr[0] = hp->arr[hp->size - 1];
	hp_down(hp->arr, hp->size, 0);
	--hp->size;
}
//堆顶元素
int hp_top(Heap* hp)
{
	if (hp->size > 0)
	{
		return hp->arr[0];
	}
	return -1;
}
//堆的结点数
int hp_size(Heap* hp)
{
	return hp->size;
}
//判断堆是否为空
int hp_empty(Heap* hp)
{
	if (hp->size > 0)
	{
		return 1;
	}
	return 0;
}
#include"Heap.h"
#include<stdlib.h>
#include<stdio.h>




//向下调整算法
//判断是否是有左孩子，无则返回
//有，则判断是否有右孩子，有判断左孩子和右孩子谁大
//判断是否需要调整
//继续调整
void hp_down(HPDataType* arr, int size, int root)
{

	while (1)
	{
		int left = root * 2 + 1;
		int right = root * 2 + 2;
		int min;
		if (left >= size)
		{
			return;
		}
		if (right < size && arr[right] < arr[left])
		{
			min = right;
		}
		else
		{
			min = left;
		}
		if (arr[root] <= arr[min])
		{
			return;
		}
		HPDataType temp = arr[root];
		arr[root] = arr[min];
		arr[min] = temp;
		//root = min;
		hp_down(arr, size, min);
	}

}
//向上调整
void hp_up(Heap* hp, int child)
{
	while (child)
	{
		int parent = (child - 1) / 2;
		if (hp->arr[parent] > hp->arr[child])
		{
			int temp = hp->arr[child];
			hp->arr[child] = hp->arr[parent];
			hp->arr[parent] = temp;
		}
		child = parent;
	}
}
//建堆
void hp_create(HPDataType* arr, int size)
{
	//从最后一个非叶子结点开始调整，知道堆顶
	int temp = (size - 2) / 2;
	while (temp >= 0)
	{
		hp_down(arr, size, temp);
		--temp;
	}
}
//堆的扩容
void check_capacity(Heap* hp)
{
	if (hp->size >= hp->capacity)
	{
		hp->capacity = hp->capacity * 2;
		HPDataType* newarr = (HPDataType*)malloc(sizeof(HPDataType) * hp->capacity);
		for (int i = 0; i < hp->size; ++i)
		{
			newarr[i] = hp->arr[i];
		}
		free(hp->arr);
		hp->arr = newarr;
	};
}
//堆的初始化
void hp_init(Heap* hp, HPDataType* arr, int capacity)
{
	hp->capacity = capacity;
	hp->size = capacity;
	hp->arr = (HPDataType*)malloc(sizeof(HPDataType) * hp->capacity);
	int temp = 0;
	while (temp < hp->size)
	{
		hp->arr[temp] = arr[temp];
		++temp;
		check_capacity(hp);
	}
	hp_create(hp->arr, hp->size);
}
//堆的销毁
void hp_destroy(Heap* hp)
{
	hp->capacity = hp->size = 0;
	free(hp->arr);
}
//堆的插入
void hp_add(Heap* hp, HPDataType data)
{
	hp->arr[hp->size] = data;
	check_capacity(hp);
	hp_up(hp, hp->size);
	++hp->size;
}
//堆的删除
void hp_del(Heap* hp)
{
	if (hp->size == 0)
	{
		return;
	}
	hp->arr[0] = hp->arr[hp->size - 1];
	hp_down(hp->arr, hp->size, 0);
	--hp->size;
}
//堆顶元素
int hp_top(Heap* hp)
{
	if (hp->size > 0)
	{
		return hp->arr[0];
	}
	return -1;
}
//堆的结点数
int hp_size(Heap* hp)
{
	return hp->size;
}
//判断堆是否为空
int hp_empty(Heap* hp)
{
	if (hp->size > 0)
	{
		return 1;
	}
	return 0;
}