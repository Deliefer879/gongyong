#ifndef __Deque_Base_Queue_H__
#define __Deque_Base_Queue_H__

#include "Deque.h"

typedef Deque Queue;

void QueueInIt(Queue* pq);
int QueueIsEmpty(Queue* pq);

void EnQueue(Queue* pq, Data data);
Data DeQueue(Queue* pq);
Data QueuePeek(Queue* pq);

#endif