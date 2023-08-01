#include <stdio.h>

#include "QueueForALGraph.h"
#include "TrueOrFalse.h"

int NextPosIdx(int pos)
{
	return pos == QUEUE_LEN - 1 ? 0 : pos + 1;
}

void QueueInIt(Queue* pq)
{
	pq->first = pq->rear = 0;
}

int QueueIsEmpty(Queue* pq)
{
	if (pq->first == pq->rear)
		return TRUE;

	return FALSE;
}

void EnQueue(Queue* pq, QData data)
{
	if (NextPosIdx(pq->rear) == pq->first)
		return;

	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}

QData DeQueue(Queue* pq)
{
	if (QueueIsEmpty(pq))
		return;

	pq->first = NextPosIdx(pq->first);
	return pq->queArr[pq->first];
}

QData QueuePeek(Queue* pq)
{
	if (QueueIsEmpty(pq))
		return;

	return pq->queArr[pq->first + 1];
}
