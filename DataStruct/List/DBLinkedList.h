#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
	struct _node* next;
	struct _node* prev;
	Data data;
}Node;

typedef struct _DLinkedList
{
	Node* head;
	Node* tail;
	Node* cur;
	int numOfData;
}DBLinkedList;

typedef DBLinkedList List;

void ListInIt(List *plist);

void LInsert(List *plist, Data data);//꼬리에 노드 추가

int LFirst(List* plist, Data* pData);
int LNext(List* plist, Data* pData);

Data LRemove(List* plist);

int LCount(List* plist);

#endif