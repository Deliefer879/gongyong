#include <stdio.h>
#include <stdlib.h>

#include "TrueOrFalse.h"
#include "QueueForRadixSort.h"

void QueueInIt(Queue* pq)
{
	pq->front = pq->rear = NULL;
}

int QueueIsEmpty(Queue* pq)
{
	return pq->front == NULL ? TRUE : FALSE;
}

void EnQueue(Queue* pq, QData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (QueueIsEmpty(pq))
		pq->front = pq->rear = newNode;
	else
	{
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}

QData DeQueue(Queue* pq)
{
	if (QueueIsEmpty(pq))
	{
		printf("queue memory error\n");
		exit(-1);
	}
	QData delData = pq->front->data;
	Node* delNode = pq->front;

	pq->front = pq->front->next;
	free(delNode);

	return delData;
}

QData QueuePeek(Queue* pq)
{
	if (QueueIsEmpty(pq))
	{
		printf("queue memory error\n");
		exit(-1);
	}
	return pq->front->data;
}