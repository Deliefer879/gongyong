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

//�θ���� �ڽĳ���� �ε������� ��� �Լ���
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
	if (GetLChirdIdx(idx) > ph->numofData)//���� ����Ʈ���� ������ ���� �ڽĳ�尡 ���°��� �����ʵ� ���°�
		return 0;
	else if (GetLChirdIdx(idx) == ph->numofData)//�ڽĳ�尡 1���̸� �����ڽĳ������ ������ ���
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
	HeapElem lastElem = ph->heapArr[ph->numofData]; // ���� ������ ���

	int parentIdx = 1; //��Ʈ����� �ε��� ��
	int childIdx=0;


	while (childIdx=GetPriChildIdx(ph,parentIdx))// �켱������ ���� �ڽĳ���� �ε��� ��
	{
		if (lastElem.pr > ph->heapArr[childIdx].pr) //���������� ��Ʈ����� �ڽĳ���� �켱���� ��
		{
			ph->heapArr[parentIdx] = ph->heapArr[childIdx];//���ѳ���� �켱������ ������ ������ �ø�
			parentIdx = childIdx;//������ ��尡 ����� ��ġ ����
		}
		else
			break;
	}

	ph->heapArr[parentIdx] = lastElem;//���������� �񱳸� �����ϸ鼭 ��� �ٲٴ°��̾ƴ϶� ���������� ����� ��ġ�� ã�� �װ��� ����
	(ph->numofData)--;
	return delData;
}

