#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//TOP-K���⣻
//��N������������ǰK��
//˼·1��N�������뵽������;,Popk�Σ�
//ʱ�临�Ӷ� N*logn+k*logn->n*logn��
//˼·2��1.��ȡǰk��ֵ�����С��
//2.�ȶѶ���ĺ�С�ѶѶ�����Ȼ�����µ���
//ʱ�临�Ӷȣ�k*logn+n*logk->n*logk;
//�ռ临�Ӷȣ�k
//��ⷽ��������N�����������ֶ�����ʮ������������֣��Ӷ���֤��
void AdjustUp(int* a, int child)//���ϵ���;
{
	int parent = (child - 1) / 2;
	while (child != 0)
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
void AdjustDown(int* a, int size, int parent)  //���µ���;
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
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//����-���
//������-��ѡ������;
void HeapSort(int* a, int n)
{
	////����;ʵ����ʱ�临�Ӷ���n*logn
	//for (int i = 1; i < n; i++)
	//{
	//	AdjustUp(a,i);
	//}
	//Ч��ΪO��N��;�����һ���к��ӵĽ�㿪ʼ�½���
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, 0);
	}
	//ѡ������N-1��*logN;
	int end = n - 1;
		while (end > 0)
		{
			Swap(&a[0], &a[end]);
			AdjustDown(a, end, 0);
			--end;
		}
}
int main()
{
	//��������൱��һ����ȫ������;
	int a[] = { 4,6,2,1,5,8,2,9 };
}