#include <stdio.h>
#include <stdlib.h>

#include "DLinkedList.h"

void ListInIt(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
	plist->comp = NULL;
}

void FInsert(List* plist, LData data)
{
	Node* newData = (Node*)malloc(sizeof(Node));
	newData->data = data;
	newData->next = plist->head->next;
	plist->head->next = newData;
	(plist->numOfData)++;
}

void SInsert(List* plist, LData data)
{
	Node* newData = (Node*)malloc(sizeof(Node));
	newData->data = data;
	Node* pred = plist->head;

	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next;
	}

	newData->next = pred->next;
	pred->next = newData;
	(plist->numOfData)++;
}

void LInsert(List* plist, LData data)
{
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->head->next == NULL)
	{
		printf("it has any data\n");
		return FALSE;
	}

	plist->before = plist->head;
	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return TRUE;
}
int LNext(List* plist, LData* pdata)
{
	if (plist->cur->next == NULL)
	{
		return FALSE;
	}
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}
LData LRemove(List* plist)
{
	Node* delNode = plist->cur;
	LData delData = plist->cur->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(delNode);
	(plist->numOfData)--;
	return delData;
}
int LCount(List* plist)
{
	return (plist->numOfData);
}
void SetSortRule(List* plist, int (*cmp)(LData d1, LData d2))
{
	plist->comp = cmp;
}