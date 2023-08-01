#ifndef __DEQUE_H__
#define __DEQUE_H__

#include "TrueOrFalse.h"

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node *next;
	struct _node *prev;
}Node;

typedef struct _dlDeque
{
	Node* head;
	Node* tail;
}DlDeque;

typedef DlDeque Deque;

void DequeInIt(Deque* pd);

int DequeIsEmpty(Deque* pd);

void DequeAddFirst(Deque* pd,Data data);
void DequeAddLast(Deque* pd,Data data);

Data DequeRemoveFirst(Deque* pd);
Data DequeRemoveLast(Deque* pd);

Data DequePeekFirst(Deque* pd);
Data DequePeekLast(Deque* pd);

#endif