#include <stdio.h>

#include "UsefulHeap2.h"

int PriComp(int n1, int n2);

void HeapSort(int arr[], int n, PriorityComp pc)
{
	Heap heap;
	int i;

	HeapInIt(&heap, pc);
	for (i = 0; i < n; i++)
		HInsert(&heap, arr[i]);

	for (i = 0; i < n; i++)
		arr[i] = HDelete(&heap);
}

int main()
{


}

int PriComp(int n1, int n2)
{
	return n2 - n1;//n1�� �켱�̸� 0���� ū��(������ �켱)
}