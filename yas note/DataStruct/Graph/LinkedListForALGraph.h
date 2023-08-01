#ifndef __LINKED_LIST_FOR_AL_GRAPH_H__
#define __LINKED_LIST_FOR_AL_GRAPH_H__

#include "TrueOrFalse.h"

typedef int LData;

typedef struct _node
{
	LData data;
	struct _node* next;
}Node;

typedef struct _linkedList
{
	Node* head;
	Node* before;
	Node* cur;
	int numOfData;
	int (*comp)(LData d1, LData d2);
}LinkedList;

typedef LinkedList List;

void ListInIt(List* plist);

void LInsert(List* plist, LData data);

int LFirst(List* plist, LData* pData);

int LNext(List* plist, LData* pData);

LData LRemove(List* plist);

int LCount(List* plist);

#endif