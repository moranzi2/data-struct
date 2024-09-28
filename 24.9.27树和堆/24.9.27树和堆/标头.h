#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
//数据结构的主要功能是管理数据
typedef int HPDataType;
//(下标)（孩子-1）/2=父亲；父亲*2+1和父亲*2+2；
typedef struct Heap {
	HPDataType* a;
	int size;
	int capacity;
}HP;//n*logn
void HeapInit(HP* php);
void HeapDestroy(HP* php);
void Adjustup(HPDataType* a, int child);//向上调整;
void HeapPush(HP* php, HPDataType x);
void Adjustdown(HPDataType* a, int size,int parent);  //向下调整;
void HeapPop(HP* php);//删除堆顶（祖宗）
int HeapTop(HP* php);//获取根
size_t HeapSize(HP* php);
bool HeapEmpty(HP* php);
