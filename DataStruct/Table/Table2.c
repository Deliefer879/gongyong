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

//체이닝 방법은 hv가 중복되면 비어있는 곳을 탐색해 삽입하는 열린 어드레싱 방법(이중 해쉬,이차 조사법) 과는 다른
//닫힌 어드레싱 방법으로 hv가 중복 되더라도 키값이 중복되지 않으면 그자리에 삽입한다(연결 리스트이용)
void TBLInsert(Table* pt, Key k, Value val)
{
	int hv = pt->hf(k);
	Slot slot = {k,val};
	
	if (TBLSearch(pt, k))//동일한 키값이 존재 한다면 삽입X
	{
		printf("키 값 중복\n");
		return;
	}

	LInsert(&(pt->tbl[hv]),slot);
									
}

//delete 함수나 search 함수에서 NULL값 반환은 value가 포인터인 상황에서는 괜찮지만
//value가 포인터 함수가 아니라면 value포인터를 매개변수로 전달하고 TRUE,FALSE를 반환하여 함수의 결과를 확인하는 형식으로 구성하여
// 매개 변수 value포인터에 값을 저장하는 LFirst,LNext함수와 같이 구성한다

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