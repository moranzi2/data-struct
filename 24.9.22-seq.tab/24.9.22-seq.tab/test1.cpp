#define  _CRT_SECURE_NO_WARNINGS 1

#include"moran.h"

//初始化
void SeqListInit(SeqList** ps1)
{
	*ps1 = (SeqList*)malloc(sizeof(SeqList));
	(*ps1)->a = NULL;
	(*ps1)->capacity = 0;
	(*ps1)->size = 0;
}
//检查空间并且扩容
void CheckCapacity(SeqList* ps1)
{
	if (ps1 == NULL)
	{
		printf("无效的顺序表指针\n");
		return;
	}
	if (ps1->capacity == ps1->size)
	{
		size_t newCapacity = ps1->capacity == 0 ? 4 : ps1->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps1->a, newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("扩容失败\n");
			return;
		}
		ps1->a = tmp;
		ps1->capacity = newCapacity;
	}
}
//尾插
void SeqListPushBack(SeqList* ps1, SLDataType x)
{
	
	if (ps1 == NULL)
	{
		printf("无效的顺序表指针\n");
		return;
	}
	CheckCapacity(ps1);
	ps1->a[ps1->size] = x;
	ps1->size++;
}
//尾删
void SeqListPopBack(SeqList* ps1)
{
	if (ps1 == NULL)
	{
		printf("无效的顺序表指针\n");
		return;
	}
	if (ps1->size > 0)
	ps1->size--;
}
//头插
void SeqListPushFront(SeqList* ps1, SLDataType x)
{
	if (ps1 == NULL)
	{
		printf("无效的顺序表指针\n");
		return;
	}
	CheckCapacity(ps1);
	for (size_t i = ps1->size; i > 0; i--)
	{
		ps1->a[i] = ps1->a[i - 1];
	}
	ps1->a[0] = x;
	ps1->size++;
}
//头删
void SeqListPopFront(SeqList* ps1)
{
	if (ps1 == NULL)
	{
		printf("无效的顺序表指针\n");
		return;
	}
	for (size_t i = 0; i < ps1->size-1; i++)
	{
		ps1->a[i] = ps1->a[i + 1];
	}
	if (ps1->size > 0)
	ps1->size--;
}
//查找(返回下标)
size_t SeqListFind(SeqList* ps1, SLDataType x)
{
	if (ps1 == NULL)
	{
		printf("无效的顺序表指针\n");
		return 0;
	}
	for (size_t i = 0; i < ps1->size; i++)
	{
		if (ps1->a[i] == x)
		{
			return i;
		}
	}
	return 100;
}
//pos位置插入
void SeqListInsert(SeqList* ps1, size_t pos, SLDataType x)
{
	if (ps1 == NULL)
	{
		printf("无效的顺序表指针\n");
		return;
	}
	if (pos > ps1->size)
	{
		printf("pos超出范围\n");
		return;
	}
	CheckCapacity(ps1);
	for (size_t i = ps1->size; i >pos; i--)
	{
		ps1->a[i] = ps1->a[i - 1];
	}
	ps1->a[pos] = x;
	ps1->size++;
}
//pos位置删除
void SeqListErase(SeqList* ps1, size_t pos)
{
	if (ps1 == NULL)
	{
		printf("无效的顺序表指针\n");
		return;
	}
	if (pos >= ps1->size)
	{
		printf("pos超出范围\n");
		return;
	}
	for (size_t i = pos; i < ps1->size-1; i++)
	{
		ps1->a[i] = ps1->a[i + 1];
	}
	if (ps1->size > 0)
	ps1->size--;

}
//顺序表销毁
void SeqListDestory(SeqList* ps1)
{
	if (ps1 == NULL)
	{
		printf("无效的顺序表指针\n");
		return;
	}
	if (ps1->a == NULL)
	{
		printf("无效的顺序表数组指针\n");
		return;
	}
	free(ps1->a);
	ps1->a = NULL;
	ps1->capacity = 0;
	ps1->size = 0;
}
//顺序表打印
void SeqListPrint(SeqList* ps1)
{
	if (ps1 == NULL)
	{
		printf("无效的顺序表指针\n");
		return;
	}
	for (size_t i = 0; i < ps1->size; i++)
	{
		printf("%d ", ps1->a[i]);
	}
	printf("\n");
}