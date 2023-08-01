#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define HEAP_LEN 100

#include "TrueOrFalse.h"

//å������ �켱���� ť�� ������ ���� ��������� ���������
//�����Ƽ� ����(�켱���� ť�� ���� ���� �ڷᱸ���̱� ������ adt�� ���� ť�� �Լ��� ���� �Լ��� ������ ��)

typedef char* HData;

//�Լ� ������
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