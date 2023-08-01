#include <stdio.h>
#include <stdlib.h>

#include "LinkedListForALGraph.h"

int cmp(LData d1, LData d2)
{
	if (d1 > d2)
		return 1;
	else
		return 0;
}

void ListInIt(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->cur = plist->before = plist->head->next = NULL;
	plist->numOfData = 0;
	plist->comp = cmp;
}

void LInsert(List* plist, LData data)
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

int LFirst(List* plist, LData* pData)
{
	if (!LCount(plist))
		return FALSE;
	
	plist->cur = plist->head->next;
	plist->before = plist->head;
	
	*pData = plist->cur->data;

	return TRUE;
}

int LNext(List* plist, LData* pData)
{
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pData = plist->cur->data;

	return TRUE;
}

LData LRemove(List* plist)
{
	Node* delNode = plist->cur;
	LData delData = plist->cur->data;

	plist->before->next = delNode->next;
	plist->cur = plist->before;

	free(delNode);

	return delData;
}

int LCount(List* plist)
{
	return plist->numOfData;
}
