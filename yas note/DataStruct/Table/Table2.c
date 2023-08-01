#include <stdio.h>
#include <stdlib.h>

#include "Table2.h"

void TableInIt(Table* pt, HashFunc* f)
{
	int i;
	for (i = 0; i < MAX_TBL; i++)
		ListInIt(&(pt->tbl[i]));

	pt->hf = f;
}

//ü�̴� ����� hv�� �ߺ��Ǹ� ����ִ� ���� Ž���� �����ϴ� ���� ��巹�� ���(���� �ؽ�,���� �����) ���� �ٸ�
//���� ��巹�� ������� hv�� �ߺ� �Ǵ��� Ű���� �ߺ����� ������ ���ڸ��� �����Ѵ�(���� ����Ʈ�̿�)
void TBLInsert(Table* pt, Key k, Value val)
{
	int hv = pt->hf(k);
	Slot slot = {k,val};
	
	if (TBLSearch(pt, k))//������ Ű���� ���� �Ѵٸ� ����X
	{
		printf("Ű �� �ߺ�\n");
		return;
	}

	LInsert(&(pt->tbl[hv]),slot);
									
}

//delete �Լ��� search �Լ����� NULL�� ��ȯ�� value�� �������� ��Ȳ������ ��������
//value�� ������ �Լ��� �ƴ϶�� value�����͸� �Ű������� �����ϰ� TRUE,FALSE�� ��ȯ�Ͽ� �Լ��� ����� Ȯ���ϴ� �������� �����Ͽ�
// �Ű� ���� value�����Ϳ� ���� �����ϴ� LFirst,LNext�Լ��� ���� �����Ѵ�

Value TBLDelete(Table* pt, Key k)
{
	int hv = pt->hf(k);
	Slot slot;

	if (LFirst(&(pt->tbl[hv]),&slot))
	{
		if (slot.key == k)
		{	
			LRemove(&(pt->tbl[hv]));
			return slot.val;
		}

		while (LNext(&(pt->tbl[hv]), &slot))
		{
			if (slot.key == k)
			{
				LRemove(&(pt->tbl[hv]));
				return slot.val;
			}
		}

	}
	
	return NULL;
}

Value TBLSearch(Table* pt, Key k)
{
	int hv = pt->hf(k);
	Slot slot;

	if (LFirst(&(pt->tbl[hv]), &slot))
	{
		if (slot.key == k)
			return slot.val;

		while (LNext(&(pt->tbl[hv]), &slot))
		{
			if (slot.key == k)
				return slot.val;
		}

	}

	return NULL;
}