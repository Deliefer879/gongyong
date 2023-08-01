#include <stdio.h>

#include "ArrayBaseStack.h"

void StackInIt(Stack* pstack)
{
	pstack->topIndex = -1;
}

int StackIsEmpty(Stack* pstack)
{
	if (pstack->topIndex == -1)
		return TRUE;
	return FALSE;
}

void SPush(Stack* pstack, Data data)
{
	(pstack->topIndex)++;
	pstack->arrStack[pstack->topIndex] = data;
}

Data SPop(Stack* pstack)
{
	Data data= pstack->arrStack[pstack->topIndex];

	if (StackIsEmpty(pstack))
	{
		printf("데이터 없음\n");
		return;
	}
	(pstack->topIndex)--;
	return data;
}

Data SPeek(Stack* pstack)
{
	if (StackIsEmpty(pstack))
	{
		printf("데이터 없음\n");
		return;
	}
	return pstack->arrStack[pstack->topIndex];
}
