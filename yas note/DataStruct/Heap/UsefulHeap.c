#include <stdio.h>

#include "UsefulHeap.h"

void HeapInIt(Heap* ph, PriorityComp comp)
{
	ph->comp = comp;
	ph->numofData = 0;
}

int HeapIsEmpty(Heap* ph)
{
	if (ph->numofData == 0)
		return TRUE;
	return FALSE;
}

int GetLSubTreeIdx(int idx)
{
	return idx * 2;
}

int GetRSubTreeIdx(int idx)
{
	return idx * 2+1;
}

int GetRootTreeIdx(int idx)
{
	return idx/2;
}

int GetPrioritySubTree(Heap *ph,int idx)
{
	if (GetLSubTreeIdx(idx) > ph->numofData)
		return 0;
	else if (GetLSubTreeIdx(idx) == ph->numofData)
		return GetLSubTreeIdx(idx);
	else
	{
		if (ph->comp(ph->heapArr[GetLSubTreeIdx(idx)], ph->heapArr[GetRSubTreeIdx(idx)]) < 0)
			return GetRSubTreeIdx(idx);
		else
			return GetLSubTreeIdx(idx);
	}
}

void HInsert(Heap* ph, HData data)
{
	int idx = ph->numofData + 1;

	while(GetRootTreeIdx(idx))
	{
		if (ph->comp(ph->heapArr[GetRootTreeIdx(idx)], data) >= 0)
			break;

		ph->heapArr[idx] = ph->heapArr[GetRootTreeIdx(idx)];
		idx = GetRootTreeIdx(idx);
	}
	ph->heapArr[idx] = data;
	(ph->numofData)++;
}

HData HDelete(Heap* ph)
{
	HData LastData = ph->heapArr[ph->numofData];
	HData delData = ph->heapArr[1];

	int parentIdx = 1;
	int childIdx = 0;

	while (childIdx = GetPrioritySubTree(ph,parentIdx))
	{
		if (ph->comp(LastData, ph->heapArr[childIdx]) >= 0)
			break;

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}

	ph->heapArr[parentIdx] = LastData;
	(ph->numofData)--;
	return delData;
}