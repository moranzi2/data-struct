#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
//���ݽṹ����Ҫ�����ǹ�������
typedef int HPDataType;
//(�±�)������-1��/2=���ף�����*2+1�͸���*2+2��
typedef struct Heap {
	HPDataType* a;
	int size;
	int capacity;
}HP;//n*logn
void HeapInit(HP* php);
void HeapDestroy(HP* php);
void Adjustup(HPDataType* a, int child);//���ϵ���;
void HeapPush(HP* php, HPDataType x);
void Adjustdown(HPDataType* a, int size,int parent);  //���µ���;
void HeapPop(HP* php);//ɾ���Ѷ������ڣ�
int HeapTop(HP* php);//��ȡ��
size_t HeapSize(HP* php);
bool HeapEmpty(HP* php);
