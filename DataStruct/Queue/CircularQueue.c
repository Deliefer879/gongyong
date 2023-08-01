#include <stdio.h>
#include <stdlib.h>

#include "CircularQueue.h"

//큐의 회전을 돕는 함수(다음 인덱스 값 반환)
int NextPosIdx(int pos)
{
	return pos == QUEUE_LEN - 1 ? 0 : pos + 1;//현재위치가 큐의길이보다 1작으면 배열의 끝에 도달한것(0을 반환해 회전)
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