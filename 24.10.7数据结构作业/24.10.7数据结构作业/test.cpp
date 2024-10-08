#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct Seqlist {
	struct Seqlist* next;
	int val;
}list;
void Josephus(int n,int m,list* head)
{
	int count = n;
	list* tmp = head;
	while (count > 0) {
		for (int i = 1; i < m; i++)
		{
			head = head->next;
			if (head->next == NULL)
			{
				head = tmp;
			}
		}
		if (head->next->next != NULL)
		{
			m = head->next->val;
			printf("%d\n", m);
			head->next = head->next->next;
		}
		else
		{
			m = head->next->val;
			printf("%d\n", m);
			head->next = NULL;
			head = tmp;
		}
		count--;
	}
}
int main()
{
	int n = 10;
	int m = 3;
	list* head = (list*)malloc(sizeof(list));
	head->val = 0;
	list* phead = head;
	for (int i = 0; i < n; i++)
	{
		head->next = (list*)malloc(sizeof(list));
		head = head->next;
		head->val = i + 1;
	}
	head->next = NULL;
     Josephus(n, m, phead);


}