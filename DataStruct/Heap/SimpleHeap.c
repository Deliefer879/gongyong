#include <stdio.h>

#include "SimpleHeap.h"

void HeapInIt(Heap* ph)
{
	ph->numofData = 0;
}

int HeapIsEmpty(Heap* ph)
{
	if (ph->numofData == 0)
		return TRUE;

	return FALSE;
}

//부모노드와 자식노드의 인덱스값을 얻는 함수들
int GetParentIdx(int idx)
{
	return idx / 2;
}

int GetLChirdIdx(int idx)
{
	return idx * 2;
}

int GetRChirdIdx(int idx)
{
	return idx * 2 + 1;
}

int GetPriChildIdx(Heap* ph, int idx)
{
	if (GetLChirdIdx(idx) > ph->numofData)//완전 이진트리인 힙에서 왼쪽 자식노드가 없는것은 오른쪽도 없는것
		return 0;
	else if (GetLChirdIdx(idx) == ph->numofData)//자식노드가 1개이면 왼쪽자식노드이자 마지막 노드
		return GetLChirdIdx(idx);
	else
	{
		if (ph->heapArr[GetLChirdIdx(idx)].pr > ph->heapArr[GetRChirdIdx(idx)].pr)
			return GetRChirdIdx(idx);
		else
			return GetLChirdIdx(idx);
	}
}

void HInsert(Heap* ph, HData data, Priority pr)
{
	HeapElem newData = { pr,data };
	int idx = ph->numofData + 1;

	while (idx != 1)
	{
		if (pr < ph->heapArr[GetParentIdx(idx)].pr)
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIdx(idx)];
			idx = GetParentIdx(idx);
		}
		else
			break;
	}

	ph->heapArr[idx] = newData;
	(ph->numofData)++;
}

HData HDelete(Heap* ph)
{
	HData delData = ph->heapArr[1].data;
	HeapElem lastElem = ph->heapArr[ph->numofData]; // 힙의 마지막 노드

	int parentIdx = 1; //루트노드의 인덱스 값
	int childIdx=0;


	while (childIdx=GetPriChildIdx(ph,parentIdx))// 우선순위가 높은 자식노드의 인덱스 값
	{
		if (lastElem.pr > ph->heapArr[childIdx].pr) //마지막노드와 루트노드의 자식노드의 우선순위 비교
		{
			ph->heapArr[parentIdx] = ph->heapArr[childIdx];//비교한노드의 우선순위가 높으면 레벨을 올림
			parentIdx = childIdx;//마지막 노드가 저장될 위치 정보
		}
		else
			break;
	}

	ph->heapArr[parentIdx] = lastElem;//마지막노드는 비교를 진행하면서 계속 바꾸는것이아니라 최종적으로 저장될 위치를 찾고 그곳에 저장
	(ph->numofData)--;
	return delData;
}

