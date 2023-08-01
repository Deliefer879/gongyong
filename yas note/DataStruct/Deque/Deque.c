#include <stdio.h>
#include <stdlib.h>

#include "Deque.h"

void DequeInIt(Deque* pd)
{
	pd->head = NULL;
	pd->tail = NULL;
}

int DequeIsEmpty(Deque* pd)
{
	return pd->head == NULL ? TRUE : FALSE;
}

void DequeAddFirst(Deque* pd, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->prev = NULL;
	newNode->next = pd->head;

	if (DequeIsEmpty(pd))
		pd->tail = newNode;
	else
		pd->head->prev = newNode;

	pd->head = newNode;
}

void DequeAddLast(Deque* pd, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = NULL;
	newNode->prev = pd->tail;

	if (DequeIsEmpty(pd))
		pd->head = newNode;
	else
		pd->tail->next = newNode;

	pd->tail = newNode;
}

Data DequeRemoveFirst(Deque* pd)
{
	if (DequeIsEmpty(pd))
	{
		printf("deque memory error\n");
		exit(-1);
	}
	Node* delNode = pd->head;
	Data delData = pd->head->data;

	pd->head = pd->head->next;
	
	if (pd->head == NULL)
		pd->tail = NULL;
	else
		pd->head->prev = NULL;

	free(delNode);
	return delData;
}

Data DequeRemoveLast(Deque* pd)
{
	if (DequeIsEmpty(pd))
	{
		printf("deque memory error\n");
		exit(-1);
	}
	Node* delNode = pd->tail;
	Data delData = pd->tail->data;

	pd->tail = pd->tail->prev;

	if (pd->tail == NULL)
		pd->head = NULL;
	else
		pd->tail->next = NULL;

	free(delNode);
	return delData;
}

Data DequePeekFirst(Deque* pd)
{
	if (DequeIsEmpty(pd))
	{
		printf("deque memory error\n");
		exit(-1);
	}

	return pd->head->data;
}

Data DequePeekLast(Deque* pd)
{
	if (DequeIsEmpty(pd))
	{
		printf("deque memory error\n");
		exit(-1);
	}

	return pd->tail->data;
}
