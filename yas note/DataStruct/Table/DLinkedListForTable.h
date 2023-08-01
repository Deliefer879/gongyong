#ifndef __DLINKED_LIST_FOR_TABLE_H__
#define  __DLINKED_LIST_FOR_TABLE_H__

#include "Slot2.h"

typedef Slot Data;

typedef struct _node
{
	struct _node* next;
	struct _node* prev;
	Data data;
}Node;

typedef struct _DLList
{
	Node* head;
	Node* tail;
	Node* cur;
	int numOfData;
}DLList;

typedef DLList List;

void ListInIt(List* plist);

void LInsert(List* plist, Data data);

int LFirst(List* plist, Data* pData);

int LNext(List* plist, Data* pData);

Data LRemove(List* plist);

int LCount(List* plist);

#endif