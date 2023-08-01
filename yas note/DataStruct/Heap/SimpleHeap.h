#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

#include "TrueOrFalse.h"

#define HEAP_LEN 100

typedef char HData;
typedef int Priority;

//simpleheap는 우선순위를 사용자가 임의로 지정해야하는 불완전한 상태임
//데이터를 기준으로 우선순위를 정할수있도록 계선 필요

typedef struct _heapElem
{
	Priority pr;//작을수록 우선순위 높음
	HData data;
} HeapElem;

typedef struct _heap
{
	int numofData;
	HeapElem heapArr[HEAP_LEN];
}Heap;

void HeapInIt(Heap *ph);

int HeapIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data,Priority pr);

HData HDelete(Heap* ph);

#endif