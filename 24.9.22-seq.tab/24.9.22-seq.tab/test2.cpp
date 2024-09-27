#define  _CRT_SECURE_NO_WARNINGS 1
#include"moran.h"
//动态申请一个节点*
SListNode* BuySListNode(SLDataType x)
{
	SListNode* SL = (SListNode*)malloc(sizeof(SListNode));
	if (SL == NULL)
	{
		printf("申请节点失败\n");
		return 0;
	}
	SL->data = x;
	SL->next = NULL;
	return SL;
}
//单链表打印
void SListPrint(SListNode* plist)
{
	if (plist == NULL)
	{
		printf("头节点为空，无效\n");
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
//单链表尾插
void SListPushBack(SListNode* pplist, SLDataType x)
{
	if (pplist == NULL)
	{
		printf("所给的头节点指针无效\n");
		return;
	}
	while (pplist->next != NULL)
	{
		pplist = pplist->next;
	}
	pplist->next = BuySListNode(x);
}
//单链表头插
void SListPushFront(SListNode* pplist, SLDataType x)
{
	if (pplist == NULL)
	{
		printf("所给的头节点指针无效\n");
		return;
	}
	SListNode* tmp = pplist->next;
	pplist->next = BuySListNode(x);
	pplist->next->next = tmp;
}
//单链表尾删
void SListPopBack(SListNode* pplist)
{
	if (pplist == NULL)
	{
		printf("所给的头节点指针无效\n");
		return;
	}
	if (pplist->next == NULL)
	{
		printf("除头节点外无其他节点，无法删除\n");
		return;
	}
	while (pplist->next->next != NULL)
	{
		pplist = pplist->next;
	}
	free(pplist->next);
	pplist->next = NULL;
}
//单链表头删
void SListPopFront(SListNode* pplist)
{
	if (pplist == NULL)
	{
		printf("所给的头节点指针无效\n");
		return;
	}
	if (pplist->next == NULL)
	{
		printf("除头节点外无其他节点，无法删除\n");
		return;
	}
	SListNode* tmp = pplist->next->next;
	free(pplist->next);
	pplist->next = tmp;

}
//单链表查找
SListNode* SListFind(SListNode* plist, SLDataType x)
{
	if (plist == NULL)
	{
		printf("所给的头节点指针无效\n");
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
//单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos, SLDataType x)
{
	if (pos == NULL)
	{
		printf("所给的指针无效\n");
		return ;
	}
	SListNode* tmp = pos->next;
	pos->next = BuySListNode(x);
	pos->next->next = tmp;

}
//单链表删除pos位置之后的元素
void SListEraseAfter(SListNode* pos)
{
	if (pos == NULL)
	{
		printf("所给的指针无效\n");
		return;
	}
	SListNode* tmp = pos->next->next;
	free(pos->next);
	pos->next = tmp;
}