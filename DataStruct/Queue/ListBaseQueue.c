#include <stdio.h>
#include <stdlib.h>

#include "ListBaseQueue.h"

void QueueInIt(Queue* pq)
{
	pq->front = pq->rear = NULL;
}

int QueueIsEmpty(Queue* pq)
{
	return pq->front == NULL ? TRUE : FALSE;
}

void EnQueue(Queue* pq,Data data)
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

Data DeQueue(Queue* pq)
{
	if (QueueIsEmpty(pq))
	{
		printf("queue memory error\n");
		exit(-1);
	}
	Data delData = pq->front->data;
	Node* delNode = pq->front;

	pq->front = pq->front->next;
	free(delNode);

	return delData;
}

Data QueuePeek(Queue* pq)
{
	if (QueueIsEmpty(pq))
	{
		printf("queue memory error\n");
		exit(-1);
	}
	return pq->front->data;
}