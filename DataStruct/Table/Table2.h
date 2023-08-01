#ifndef __TABLE2_H__
#define __TABLE2_H__

#include "Slot2.h"
#include "DLinkedListForTable.h"

#define MAX_TBL 100

typedef int HashFunc(Key k);

typedef struct _table
{
	List tbl[MAX_TBL];
	HashFunc* hf;
}Table;

void TableInIt(Table *pt, HashFunc * f);

void TBLInsert(Table* pt, Key k, Value val);

Value TBLDelete(Table* pt, Key k);

Value TBLSearch(Table* pt, Key k);

#endif 