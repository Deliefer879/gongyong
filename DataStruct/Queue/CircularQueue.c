#include <stdio.h>
#include <stdlib.h>

#include "CircularQueue.h"

//ť�� ȸ���� ���� �Լ�(���� �ε��� �� ��ȯ)
int NextPosIdx(int pos)
{
	return pos == QUEUE_LEN - 1 ? 0 : pos + 1;//������ġ�� ť�Ǳ��̺��� 1������ �迭�� ���� �����Ѱ�(0�� ��ȯ�� ȸ��)
}

void QueueInit(Queue* pq)
{
	pq->first = pq->rear = 0;
}

int QueueIsEmpty(Queue* pq)
{
	if (pq->first == pq->rear)
		return TRUE;
	return FALSE;
}

void EnQueue(Queue* pq, Data data)
{
	if (NextPosIdx(pq->rear) == pq->first)
	{
		printf("queue memory error\n");
		exit(-1);
	}
	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}

Data DeQueue(Queue* pq)
{
	if (QueueIsEmpty(pq))
	{
		printf("queue memory error\n"); 
		exit(-1);
	}
	pq->first = NextPosIdx(pq->first);
	
	return pq->queArr[pq->first];
}

Data QueuePeek(Queue* pq)
{
	if (QueueIsEmpty(pq))
	{
		printf("queue memory erroe\n");
		exit(-1);
	}
	return pq->queArr[NextPosIdx(pq->first)];
}