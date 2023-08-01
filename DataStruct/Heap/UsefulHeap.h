#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define HEAP_LEN 100

#include "TrueOrFalse.h"

//책에서는 우선순위 큐를 구현시 따로 헤더파일을 만들었지만
//귀찮아서 생략(우선순위 큐가 힙을 쓰는 자료구조이기 때문에 adt가 같고 큐에 함수에 힙의 함수를 넣으면 끝)

typedef char* HData;

//함수 포인터
typedef int PriorityComp(HData d1, HData d2); // =int (PriorityComp*)(HData d1, HData d2);

typedef struct _heap
{
	PriorityComp* comp;
	int numofData;
	HData heapArr[HEAP_LEN];
}Heap;

void HeapInIt(Heap * ph,PriorityComp comp);

int HeapIsEmpty(Heap *ph);

void HInsert(Heap* ph, HData data);

HData HDelete(Heap* ph);

#endif