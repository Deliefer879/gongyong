#include <stdio.h>

#include "StackForALGraph.h"

void StackInIt(Stack* ps)
{
	ps->topIdx = -1;
}

int StackIsEmpty(Stack* ps)
{
	if (ps->topIdx == -1)
		return TRUE;

	return FALSE;
}

void Push(Stack* ps, SData data)
{
	ps->topIdx += 1;

	ps->arrStack[ps->topIdx] = data;
}

SData Pop(Stack* ps)
{
	if (StackIsEmpty(ps))
		return;

	SData delData = ps->arrStack[ps->topIdx];
	ps->topIdx -= 1;

	return delData;
}

SData Peek(Stack* ps)
{
	return ps->arrStack[ps->topIdx];
}