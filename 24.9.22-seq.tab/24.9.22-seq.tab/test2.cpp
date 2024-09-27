#define  _CRT_SECURE_NO_WARNINGS 1
#include"moran.h"
//��̬����һ���ڵ�*
SListNode* BuySListNode(SLDataType x)
{
	SListNode* SL = (SListNode*)malloc(sizeof(SListNode));
	if (SL == NULL)
	{
		printf("����ڵ�ʧ��\n");
		return 0;
	}
	SL->data = x;
	SL->next = NULL;
	return SL;
}
//�������ӡ
void SListPrint(SListNode* plist)
{
	if (plist == NULL)
	{
		printf("ͷ�ڵ�Ϊ�գ���Ч\n");
		return;
	}
	plist = plist->next;
	while (plist != NULL)
	{
		printf("%d ", plist->data);
		plist = plist->next;
	}
	printf("\n");
}
//������β��
void SListPushBack(SListNode* pplist, SLDataType x)
{
	if (pplist == NULL)
	{
		printf("������ͷ�ڵ�ָ����Ч\n");
		return;
	}
	while (pplist->next != NULL)
	{
		pplist = pplist->next;
	}
	pplist->next = BuySListNode(x);
}
//������ͷ��
void SListPushFront(SListNode* pplist, SLDataType x)
{
	if (pplist == NULL)
	{
		printf("������ͷ�ڵ�ָ����Ч\n");
		return;
	}
	SListNode* tmp = pplist->next;
	pplist->next = BuySListNode(x);
	pplist->next->next = tmp;
}
//������βɾ
void SListPopBack(SListNode* pplist)
{
	if (pplist == NULL)
	{
		printf("������ͷ�ڵ�ָ����Ч\n");
		return;
	}
	if (pplist->next == NULL)
	{
		printf("��ͷ�ڵ����������ڵ㣬�޷�ɾ��\n");
		return;
	}
	while (pplist->next->next != NULL)
	{
		pplist = pplist->next;
	}
	free(pplist->next);
	pplist->next = NULL;
}
//������ͷɾ
void SListPopFront(SListNode* pplist)
{
	if (pplist == NULL)
	{
		printf("������ͷ�ڵ�ָ����Ч\n");
		return;
	}
	if (pplist->next == NULL)
	{
		printf("��ͷ�ڵ����������ڵ㣬�޷�ɾ��\n");
		return;
	}
	SListNode* tmp = pplist->next->next;
	free(pplist->next);
	pplist->next = tmp;

}
//���������
SListNode* SListFind(SListNode* plist, SLDataType x)
{
	if (plist == NULL)
	{
		printf("������ͷ�ڵ�ָ����Ч\n");
		return 0;
	}
	while (plist != NULL)
	{
		plist = plist->next;
		if (plist->data == x)
		{
			return plist;
		}
	}
	return 0;
}
//��������posλ��֮�����x
void SListInsertAfter(SListNode* pos, SLDataType x)
{
	if (pos == NULL)
	{
		printf("������ָ����Ч\n");
		return ;
	}
	SListNode* tmp = pos->next;
	pos->next = BuySListNode(x);
	pos->next->next = tmp;

}
//������ɾ��posλ��֮���Ԫ��
void SListEraseAfter(SListNode* pos)
{
	if (pos == NULL)
	{
		printf("������ָ����Ч\n");
		return;
	}
	SListNode* tmp = pos->next->next;
	free(pos->next);
	pos->next = tmp;
}