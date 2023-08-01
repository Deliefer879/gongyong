#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

#include "TrueOrFalse.h"

#define HEAP_LEN 100

typedef char HData;
typedef int Priority;

//simpleheap�� �켱������ ����ڰ� ���Ƿ� �����ؾ��ϴ� �ҿ����� ������
//�����͸� �������� �켱������ ���Ҽ��ֵ��� �輱 �ʿ�

typedef struct _heapElem
{
	Priority pr;//�������� �켱���� ����
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