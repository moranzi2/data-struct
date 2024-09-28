#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//TOP-K问题；
//在N个数字里面找前K个
//思路1；N个数插入到堆里面;,Popk次；
//时间复杂度 N*logn+k*logn->n*logn；
//思路2：1.读取前k个值，组成小堆
//2.比堆顶大的和小堆堆顶换，然后往下调整
//时间复杂度：k*logn+n*logk->n*logk;
//空间复杂度：k
//检测方法，在这N个数字里面手动设置十个超级大的数字，从而验证。
void AdjustUp(int* a, int child)//向上调整;
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
void AdjustDown(int* a, int size, int parent)  //向下调整;
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
//升序-大堆
//堆排序-》选择排序;
void HeapSort(int* a, int n)
{
	////建堆;实际上时间复杂度是n*logn
	//for (int i = 1; i < n; i++)
	//{
	//	AdjustUp(a,i);
	//}
	//效率为O（N）;从最后一个有孩子的结点开始新建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, 0);
	}
	//选数：（N-1）*logN;
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
	//这个数组相当于一棵完全二叉树;
	int a[] = { 4,6,2,1,5,8,2,9 };
}