#define  _CRT_SECURE_NO_WARNINGS 1
#include"标头.h"
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void HeapInit(HP* php)
{
	if (php == nullptr)
	{
		printf("堆指针为空指针");
		return;
	}
	php->size = 0;
	php->capacity = 0;
	php->a = nullptr;
}
void HeapDestroy(HP* php)
{
	//删除一定要检查两次空指针
	if (php == nullptr)
	{
		printf("堆指针为空指针");
		return;
	}
	php->size = 0;
	php->capacity = 0;
	if(php->a!=nullptr)
	free(php->a);
	php->a = nullptr;
}
void Adjustup(HPDataType* a, int child)//向上调整;
{
	int parent = (child - 1) / 2;
	while (child!=0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (parent - 1) / 2;
		}
		else
			break;
	}
}
void HeapPush(HP* php, HPDataType x)
{
	if (php == nullptr)
	{
		printf("堆指针为空指针");
		return;
	}
	//一定要记得扩容
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		int* tmp = (int*)realloc(php->a, sizeof(int) * newcapacity);
		if (tmp == nullptr)
		{
			printf("扩容失败");
			return;
		}
		php->a = tmp;
		php->capacity = newcapacity;
	}
	++php->size;
	php->a[php->size -1] = x;
	Adjustup(php->a, php->size-1);
}
void Adjustdown(HPDataType* a, int size, int parent)  //向下调整;
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child == size - 1)
		{

		}
		else
		{
			child = a[child] < a[child + 1] ? child : child + 1;
		}
		if (a[parent] > a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapPop(HP* php)//删除堆顶（祖宗）
{
	if (php == nullptr)
	{
		printf("堆指针为空指针");
		return;
	}
	if (php->size == 0)
	{
		printf("堆中没有元素无法删除");
		return;
	}
	--php->size;
	Swap(&php->a[0], &php->a[php->size]);
	Adjustdown(php->a, php->size, 0);
}