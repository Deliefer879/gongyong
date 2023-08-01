#include <stdio.h>
#include <stdlib.h>

#include "ListBaseStack2.h"

void StackInIt(Stack* ps)
{
	ps->head = NULL;
}

int StackIsEmpty(Stack* ps)
{
	if (ps->head == NULL)
		return TRUE;
	return FALSE;
}

void SPush(Stack* ps, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = ps->head;
	ps->head = newNode;
}

Data SPop(Stack* ps)
{
	if (StackIsEmpty(ps))
	{
		printf("stack memory error\n");
		exit(-1);
	}

	Node* delNode = ps->head;
	Data delData = ps->head->data;

	ps->head = ps->head->next;
	free(delNode);

	return delData;
}

Data SPeek(Stack* ps)
{
	return ps->head->data;
}