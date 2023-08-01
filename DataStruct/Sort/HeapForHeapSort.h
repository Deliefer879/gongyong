#ifndef __USEFUL_HEAP2_H__
#define __USEFUL_HEAP2_H__

#include "TrueOrFalse.h"

#define ARR_LEN 10

typedef int HData;

typedef int PriorityComp(HData d1, HData d2);

typedef struct _heap
{
	PriorityComp * comp;
	int numofData;
	HData heapArr[ARR_LEN];
}Heap;

void HeapInIt(Heap* ph,PriorityComp pf);

int HeapIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data);

HData HDelete(Heap* ph);

#endif