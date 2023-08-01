#ifndef __QUEUE_FOR_ALGRAPH_h__
#define __QUEUE_FOR_ALGRAPH_h__

typedef int QData;

#define QUEUE_LEN 30

typedef struct _cQueue
{
	QData queArr[QUEUE_LEN];
	int first;
	int rear;
}CQueue;

typedef CQueue Queue;

void QueueInIt(Queue *pq);

int QueueIsEmpty(Queue* pq);

void EnQueue(Queue* pq,QData data);

QData DeQueue(Queue* pq);

QData QueuePeek(Queue* pq);

#endif 