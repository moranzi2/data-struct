#define  _CRT_SECURE_NO_WARNINGS 1

//1.要注意在程序发生错误的情况下函数的返回值应当和规定相符
// 2.destory函数应当把每一个都free并且最后讲quene指针清为null
// 3.对于队列，也应当时刻检测队列中是否有元素再进行插入和删除操作
// 4.malloc函数是有可能创建空间失败的，要对失败情况讨论
// 5.在删除操作中，如果删除后队列为空，应当将前后链表指针都为null
// 初始化队列
#include"moran.h"
void QueueInit(Queue* q)
{
	if (q == nullptr)
	{
		printf("队列指针为空，程序无法进行");
		return;
	}
	q->_front = q->_rear = NULL;
	q->_size = 0;
}
// 队尾入队列
void QueuePush(Queue* q, QDataType data)
{
	if (q == nullptr)
	{
		printf("队列指针为空，程序无法进行");
		return;
	}
	QNode* node = (QNode*)malloc(sizeof(QNode));
	if (node == nullptr)
	{
		printf("内存创建失败");
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
// 队头出队列
void QueuePop(Queue* q)
{
	if (q == nullptr)
	{
		printf("队列指针为空，程序无法进行");
		return;
	}
	if (q->_front == nullptr)
	{
		printf("队列中没有元素无法操作");
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
// 获取队列头部元素
QDataType QueueFront(Queue* q)
{
	if (q == nullptr)
	{
		printf("队列指针为空，程序无法进行");
		return (QDataType)0;
	}
	if (q->_front==nullptr)
	{
		printf("队列没有元素");
		return (QDataType)0;
	}
	return q->_front->_data;
}
// 获取队列队尾元素
QDataType QueueBack(Queue* q)
{
	if (q == nullptr)
	{
		printf("队列指针为空，程序无法进行");
		return (QDataType)0;
	}
	if (q->_rear == nullptr)
	{
		printf("队列没有元素");
		return (QDataType)0;
	}
	return q->_rear->_data;
}
// 获取队列中有效元素个数
int QueueSize(Queue* q)
{
	if (q == nullptr)
	{
		printf("队列指针为空，程序无法进行");
		return 0;
	}
	return q->_size;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	if (q == nullptr)
	{
		printf("队列指针为空，程序无法进行");
		return -1;
	}
	if (q->_size == 0)
		return 1;
	else
		return 0;
}
// 销毁队列
void QueueDestroy(Queue* q)
{
	if (q == nullptr)
	{
		printf("队列指针为空，程序无法进行");
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