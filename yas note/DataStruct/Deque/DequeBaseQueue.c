#include "DequeBaseQueue.h"

void QueueInIt(Queue* pq)
{
	DequeInIt(pq);
}

int QueueIsEmpty(Queue* pq)
{
	return DequeIsEmpty(pq);
}

void EnQueue(Queue* pq, Data data)
{
	DequeAddLast(pq, data);
}

Data DeQueue(Queue* pq)
{
	return DequeRemoveFirst(pq);
}

Data QueuePeek(Queue* pq)
{
	return DequePeekFirst(pq);
}