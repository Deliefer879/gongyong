#ifndef __STACK_FOR_ALGRAPH_H__
#define __STACK_FOR_ALGRAPH_H__

#include "TrueOrFalse.h"

#define STACK_LEN 100

typedef int SData;

typedef struct _ArrayStack
{
	SData arrStack[STACK_LEN];
	int topIdx;
}ArrayStack;

typedef ArrayStack Stack;

void StackInIt(Stack* ps);

int StackIsEmpty(Stack* ps);

void Push(Stack* ps, SData data);

SData Pop(Stack* ps);

SData Peek(Stack* ps);

#endif