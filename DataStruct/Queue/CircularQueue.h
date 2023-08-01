#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#define TRUE 1
#define FALSE 0

#define QUEUE_LEN 30

typedef int Data;

typedef struct _cQueue
{
	Data queArr[QUEUE_LEN];
	int first;
	int rear;
}CQueue;

typedef CQueue Queue;

void QueueInit(Queue* pq);
int QueueIsEmpty(Queue* pq);

void EnQueue(Queue* pq, Data data);
Data DeQueue(Queue* pq);
Data QueuePeek(Queue* pq);

#endif 