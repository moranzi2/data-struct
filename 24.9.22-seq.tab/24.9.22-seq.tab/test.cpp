#define  _CRT_SECURE_NO_WARNINGS 1
#include"moran.h";
void test1()
{
	SeqList* test = NULL;
	SeqListInit(&test);
	SeqListPushFront(test, 4);
	SeqListPrint(test);
	SeqListPushBack(test, 5);
	SeqListPrint(test);
	SeqListInsert(test, 1, 3);
	SeqListPrint(test);
	SeqListErase(test, 1);
	SeqListPrint(test);
	printf("%zd\n", SeqListFind(test, 4));
}
void test2()
{
	SListNode* head = BuySListNode(0);
	SListPushFront(head, 4);
	SListPrint(head);
	SListPushFront(head, 5);
	SListPrint(head);
	SListPushBack(head, 7);
	SListPrint(head);
	SListPushBack(head, 6);
	SListPrint(head);
	SListPopFront(head);
	SListPrint(head);
	SListPopBack(head);
	SListPrint(head);
}
void test3(SListNode* SL,int mink,int maxk)
{
	SListNode* sl = SL->next;
	while (sl != NULL)
	{
		if (sl->data > mink && sl->data < maxk)
		{
			sl = sl->next;
			free(SL->next);
			SL->next = sl;
		}
		else
		{
			sl = sl->next;
			SL = sl->next;
		}
	}
}
void test4(SeqList* SL)
{
	SLDataType* a1 = SL->a;
	SLDataType* a2 = &SL->a[SL->size-1];
	SLDataType tmp = 0;
	while (a2 - a1 > 0)
	{
		*a1 = tmp;
		*a1 = *a2;
		*a2 = tmp;
		a1++;
		a2--;
	}
}
SListNode* test5(SListNode* head)
{
	SListNode* tmp = head;
	SListNode* tma = head;
	if (head == NULL)
		return head;
	tmp = head->next;
	head->next = NULL;
	int count = 0;
	while (tmp != NULL)
	{
		tma = tmp;
		tmp = tmp->next;
		tma->next = head;
		head = tma;
		count++;
	}
	return head;
}
int main()
{
	/*test1();*/
	//test2();

}