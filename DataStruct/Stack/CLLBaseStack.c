#include <stdio.h>
#include <stdlib.h>

#include "CLLBaseStack.h"
//이미 구현된 원형연결리스트의 함수를 이용해 원형연결리스트를 스택처럼 사용

void StackInIt(Stack* pstack)
{
	pstack->plist = (List*)malloc(sizeof(List));
	ListInIt(pstack->plist);
}

void SPush(Stack* pstack, Data data)
{
	LInsertFront(pstack->plist, data);
}

Data SPop(Stack* pstack)
{
	Data data;
	if (StackIsEmpty(pstack))//원래 Lfirst함수
	{
		printf("stack memory error\n");
		exit(-1);
	}
	LFirst(pstack->plist, &data);
	LRemove(pstack->plist);
	return data;
}

int StackIsEmpty(Stack* pstack)
{
	if (pstack->plist->numOfData == 0)
		return TRUE;
	return FALSE;
}

Data SPeek(Stack* pstack)
{
	if (StackIsEmpty(pstack))
	{
		printf("stack memory error\n");
		exit(-1);
	}
	Data data;
	LFirst(pstack->plist, &data);
	return data;
}
