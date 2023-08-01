#include <stdio.h>
#include <stdlib.h>

#include "DLinkedListForTable.h"
#include "TrueOrFalse.h"

void ListInIt(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));
	plist->cur = NULL;
	plist->numOfData = 0;

	plist->head->next = plist->tail;
	plist->head->prev = NULL;

	plist->tail->prev = plist->head;
	plist->tail->next = NULL;
}

void LInsert(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	plist->tail->prev->next = newNode;
	newNode->prev = plist->tail->prev;
	
	newNode->next = plist->tail;
	plist->tail->prev = newNode;

	plist->numOfData += 1;
}

int LFirst(List* plist, Data* pData)
{
	if (plist->numOfData == 0)
		return FALSE;

	plist->cur = plist->head->next;
	*pData = plist->cur->data;

	return TRUE;
}

int LNext(List* plist, Data* pData)
{
	if (plist->cur->next == plist->tail)
		return FALSE;

	plist->cur = plist->cur->next;
	*pData = plist->cur->data;
	return TRUE;
}

Data LRemove(List* plist)
{
	if (plist->numOfData == 0)
	{
		printf("no more data\n");
		return;
	}
	Data delData = plist->cur->data;
	Node* delNode = plist->cur;

	delNode->next->prev = delNode->prev;
	delNode->prev->next = delNode->next;

	plist->cur = plist->cur->prev;

	free(delNode);
	plist->numOfData -= 1;

	return delData;
}

int LCount(List* plist)
{
	return plist->numOfData;
}
