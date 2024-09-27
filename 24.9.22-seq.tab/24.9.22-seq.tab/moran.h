#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	size_t size;
	size_t capacity;
}SeqList;
typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
}SListNode;
void SeqListInit(SeqList** ps1);//初始化
void CheckCapacity(SeqList* ps1);//检查空间并且扩容
void SeqListPushBack(SeqList* ps1,SLDataType x);//尾插
void SeqListPopBack(SeqList* ps1);//尾删
void SeqListPushFront(SeqList* ps1,SLDataType x);//头插
void SeqListPopFront(SeqList* ps);//头删
size_t SeqListFind(SeqList* ps1,SLDataType x);//查找
void SeqListInsert(SeqList* ps1,size_t pos, SLDataType x);//任意位置插入；
void SeqListErase(SeqList* ps1, size_t pos);//删除pos位置
void SeqListDestory(SeqList* ps1);//顺序表销毁
void SeqListPrint(SeqList* ps1);//顺序表打印

SListNode* BuySListNode(SLDataType x);//动态申请节点
void SListPrint(SListNode* plist);//单链表打印
void SListPushBack(SListNode* pplist, SLDataType x);//单链表尾插
void SListPushFront(SListNode* pplist, SLDataType x);//单链表头插
void SListPopBack(SListNode* pplist);//单链表尾删
void SListPopFront(SListNode* pplist);//单链表头删
SListNode* SListFind(SListNode* plist, SLDataType x);//单链表查找
void SListInsertAfter(SListNode* pos, SLDataType x);//单链表在pos位置之后插入x
void SListEraseAfter(SListNode* pos);//单链表删除pos之后的值