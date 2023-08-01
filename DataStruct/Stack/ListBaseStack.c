#include <stdio.h>
#include <stdlib.h>

#include "ListBaseStack.h"

void StackInIt(Stack* pstack)
{
	pstack->head = NULL;
}

void SPush(Stack* pstack, Data data)
{
	Node* newData = (Node*)malloc(sizeof(Node));
	newData->data = data;
	
	newData->next = pstack->head;
	pstack->head = newData;
}

Data SPop(Stack* pstack)
{
	if (StackIsEmpty(pstack))
	{
		printf("stack memory error\n");
		exit(-1);
	}

	Data delData = pstack->head->data;
	Node *delNode = pstack->head;
	
	pstack->head = pstack->head->next;
	free(delNode);

	return delData;
}

int StackIsEmpty(Stack* pstack)
{
	if (pstack->head == NULL)
		return TRUE;
	return FALSE;
}

Data SPeek(Stack* pstack)
{
	if (StackIsEmpty(pstack))
	{
		printf("stack memory error\n");
		exit(-1);
	}
	
	return pstack->head->data;
}
