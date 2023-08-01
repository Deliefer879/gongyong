#include <stdio.h>
#include <stdlib.h>

#include "Table.h"

void TBLInIt(Table* pt, HashFunc* f)
{
	int i;

	for (i = 0; i < MAX_TBL; i++)
		pt->tbl[i].status = EMPTY;//모든 슬롯을 empty로 초기화

	pt->hf = f;
}

void TBLInsert(Table* pt, Key k, Value v)
{
	int hv = pt->hf(k);

	pt->tbl[hv].key = k;
	pt->tbl[hv].val = v;
	pt->tbl[hv].status = INUSE;
}

Value TBLDelete(Table* pt, Key k)
{
	int hv = pt->hf(k);

	if (pt->tbl[hv].status != INUSE)
	{
		printf("not exist key(delete)\n");
		return NULL;
	}
	else
	{
		pt->tbl[hv].status = DELETED;
		return pt->tbl[hv].val;
	}
}

Value TBLSearch(Table* pt, Key k)
{
	int hv = pt->hf(k);

	if (pt->tbl[hv].status != INUSE)
	{
		printf("not exist key(search)\n");
		return NULL;
	}
	else
	{
		return pt->tbl[hv].val;
	}
}