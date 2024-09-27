#define  _CRT_SECURE_NO_WARNINGS 1

#include"moran.h"

//��ʼ��
void SeqListInit(SeqList** ps1)
{
	*ps1 = (SeqList*)malloc(sizeof(SeqList));
	(*ps1)->a = NULL;
	(*ps1)->capacity = 0;
	(*ps1)->size = 0;
}
//���ռ䲢������
void CheckCapacity(SeqList* ps1)
{
	if (ps1 == NULL)
	{
		printf("��Ч��˳���ָ��\n");
		return;
	}
	if (ps1->capacity == ps1->size)
	{
		size_t newCapacity = ps1->capacity == 0 ? 4 : ps1->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps1->a, newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("����ʧ��\n");
			return;
		}
		ps1->a = tmp;
		ps1->capacity = newCapacity;
	}
}
//β��
void SeqListPushBack(SeqList* ps1, SLDataType x)
{
	
	if (ps1 == NULL)
	{
		printf("��Ч��˳���ָ��\n");
		return;
	}
	CheckCapacity(ps1);
	ps1->a[ps1->size] = x;
	ps1->size++;
}
//βɾ
void SeqListPopBack(SeqList* ps1)
{
	if (ps1 == NULL)
	{
		printf("��Ч��˳���ָ��\n");
		return;
	}
	if (ps1->size > 0)
	ps1->size--;
}
//ͷ��
void SeqListPushFront(SeqList* ps1, SLDataType x)
{
	if (ps1 == NULL)
	{
		printf("��Ч��˳���ָ��\n");
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
//ͷɾ
void SeqListPopFront(SeqList* ps1)
{
	if (ps1 == NULL)
	{
		printf("��Ч��˳���ָ��\n");
		return;
	}
	for (size_t i = 0; i < ps1->size-1; i++)
	{
		ps1->a[i] = ps1->a[i + 1];
	}
	if (ps1->size > 0)
	ps1->size--;
}
//����(�����±�)
size_t SeqListFind(SeqList* ps1, SLDataType x)
{
	if (ps1 == NULL)
	{
		printf("��Ч��˳���ָ��\n");
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
//posλ�ò���
void SeqListInsert(SeqList* ps1, size_t pos, SLDataType x)
{
	if (ps1 == NULL)
	{
		printf("��Ч��˳���ָ��\n");
		return;
	}
	if (pos > ps1->size)
	{
		printf("pos������Χ\n");
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
//posλ��ɾ��
void SeqListErase(SeqList* ps1, size_t pos)
{
	if (ps1 == NULL)
	{
		printf("��Ч��˳���ָ��\n");
		return;
	}
	if (pos >= ps1->size)
	{
		printf("pos������Χ\n");
		return;
	}
	for (size_t i = pos; i < ps1->size-1; i++)
	{
		ps1->a[i] = ps1->a[i + 1];
	}
	if (ps1->size > 0)
	ps1->size--;

}
//˳�������
void SeqListDestory(SeqList* ps1)
{
	if (ps1 == NULL)
	{
		printf("��Ч��˳���ָ��\n");
		return;
	}
	if (ps1->a == NULL)
	{
		printf("��Ч��˳�������ָ��\n");
		return;
	}
	free(ps1->a);
	ps1->a = NULL;
	ps1->capacity = 0;
	ps1->size = 0;
}
//˳����ӡ
void SeqListPrint(SeqList* ps1)
{
	if (ps1 == NULL)
	{
		printf("��Ч��˳���ָ��\n");
		return;
	}
	for (size_t i = 0; i < ps1->size; i++)
	{
		printf("%d ", ps1->a[i]);
	}
	printf("\n");
}