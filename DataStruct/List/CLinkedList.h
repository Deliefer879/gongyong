#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#include "employee.h"

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
	struct _node *next;
	Data data;
}Node;

typedef struct _CLL
{
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;
}CList;

typedef CList List;

void ListInIt(List *plist);

void LInsert(List* plist, Data data);
void LInsertFront(List* plist, Data data);

int LFirst(List* plist, Data* pdata);
int LNext(List* plist, Data* pdata);

Data LRemove(List* plist);
int LCount(List* plist);

//문제 5-1 (해더파일이 중복되서 여기에 선언(책에서는 메인함수에 선언))
void FindWorkShift(char* name, int date, List* list);

#endif