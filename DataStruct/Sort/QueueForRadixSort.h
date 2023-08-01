#ifndef __QUEUE_FOR_RADIX_SORT_H__
#define __QUEUE_FOR_RADIX_SORT_H__

typedef int QData;

typedef struct _node
{
	QData data;
	struct _node * next;
}Node;

typedef struct _queue
{
	Node* front;
	Node* rear;
}Queue;

void QueueInIt(Queue* pq);

int QueueIsEmpty(Queue* pq);

void EnQueue(Queue* pq,QData data);

QData DeQueue(Queue* pq);

QData QueuePeek(Queue* pq);

#endif