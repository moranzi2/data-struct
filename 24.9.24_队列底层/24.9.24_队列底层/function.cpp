#define  _CRT_SECURE_NO_WARNINGS 1

//1.Ҫע���ڳ��������������º����ķ���ֵӦ���͹涨���
// 2.destory����Ӧ����ÿһ����free�������queneָ����Ϊnull
// 3.���ڶ��У�ҲӦ��ʱ�̼��������Ƿ���Ԫ���ٽ��в����ɾ������
// 4.malloc�������п��ܴ����ռ�ʧ�ܵģ�Ҫ��ʧ���������
// 5.��ɾ�������У����ɾ�������Ϊ�գ�Ӧ����ǰ������ָ�붼Ϊnull
// ��ʼ������
#include"moran.h"
void QueueInit(Queue* q)
{
	if (q == nullptr)
	{
		printf("����ָ��Ϊ�գ������޷�����");
		return;
	}
	q->_front = q->_rear = NULL;
	q->_size = 0;
}
// ��β�����
void QueuePush(Queue* q, QDataType data)
{
	if (q == nullptr)
	{
		printf("����ָ��Ϊ�գ������޷�����");
		return;
	}
	QNode* node = (QNode*)malloc(sizeof(QNode));
	if (node == nullptr)
	{
		printf("�ڴ洴��ʧ��");
		return;
	}
	node->_pNext = nullptr;
	node->_data = data;
	if (q->_rear == nullptr)
	{
		q->_rear = q->_front=node;
	}
	else
	{
		q->_rear->_pNext = node;
		q->_rear = node;
	}
	q->_size++;
}
// ��ͷ������
void QueuePop(Queue* q)
{
	if (q == nullptr)
	{
		printf("����ָ��Ϊ�գ������޷�����");
		return;
	}
	if (q->_front == nullptr)
	{
		printf("������û��Ԫ���޷�����");
		return;
	}
	QNode* node = q->_front;
	q->_front = q->_front->_pNext;
	free(node);
	if (q->_front == nullptr)
	{
		q->_rear = nullptr;
	}
	q->_size--;
}
// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q)
{
	if (q == nullptr)
	{
		printf("����ָ��Ϊ�գ������޷�����");
		return (QDataType)0;
	}
	if (q->_front==nullptr)
	{
		printf("����û��Ԫ��");
		return (QDataType)0;
	}
	return q->_front->_data;
}
// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q)
{
	if (q == nullptr)
	{
		printf("����ָ��Ϊ�գ������޷�����");
		return (QDataType)0;
	}
	if (q->_rear == nullptr)
	{
		printf("����û��Ԫ��");
		return (QDataType)0;
	}
	return q->_rear->_data;
}
// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q)
{
	if (q == nullptr)
	{
		printf("����ָ��Ϊ�գ������޷�����");
		return 0;
	}
	return q->_size;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	if (q == nullptr)
	{
		printf("����ָ��Ϊ�գ������޷�����");
		return -1;
	}
	if (q->_size == 0)
		return 1;
	else
		return 0;
}
// ���ٶ���
void QueueDestroy(Queue* q)
{
	if (q == nullptr)
	{
		printf("����ָ��Ϊ�գ������޷�����");
		return;
	}
	QNode* node1 = q->_front;
	QNode* node2 = q->_front;
	while (node2)
	{
		node2 = node1->_pNext;
		free(node1);
		node1 = node2;
	}
	q->_front = q->_rear = nullptr;
	q->_size = 0;
	q = nullptr;
}