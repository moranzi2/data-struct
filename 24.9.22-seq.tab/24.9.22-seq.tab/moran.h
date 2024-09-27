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
void SeqListInit(SeqList** ps1);//��ʼ��
void CheckCapacity(SeqList* ps1);//���ռ䲢������
void SeqListPushBack(SeqList* ps1,SLDataType x);//β��
void SeqListPopBack(SeqList* ps1);//βɾ
void SeqListPushFront(SeqList* ps1,SLDataType x);//ͷ��
void SeqListPopFront(SeqList* ps);//ͷɾ
size_t SeqListFind(SeqList* ps1,SLDataType x);//����
void SeqListInsert(SeqList* ps1,size_t pos, SLDataType x);//����λ�ò��룻
void SeqListErase(SeqList* ps1, size_t pos);//ɾ��posλ��
void SeqListDestory(SeqList* ps1);//˳�������
void SeqListPrint(SeqList* ps1);//˳����ӡ

SListNode* BuySListNode(SLDataType x);//��̬����ڵ�
void SListPrint(SListNode* plist);//�������ӡ
void SListPushBack(SListNode* pplist, SLDataType x);//������β��
void SListPushFront(SListNode* pplist, SLDataType x);//������ͷ��
void SListPopBack(SListNode* pplist);//������βɾ
void SListPopFront(SListNode* pplist);//������ͷɾ
SListNode* SListFind(SListNode* plist, SLDataType x);//���������
void SListInsertAfter(SListNode* pos, SLDataType x);//��������posλ��֮�����x
void SListEraseAfter(SListNode* pos);//������ɾ��pos֮���ֵ