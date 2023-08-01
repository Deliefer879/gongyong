#ifndef __CLL_BASE_STACK_H__
#define __CLL_BASE_STACK_H__

#include "CLinkedList.h"

//스택 해더 파일선언후 원형연결리스트를 저장(StackInIt함수에서 초기화)
typedef struct _CLLstack
{
	List* plist;
}CLLstack;

typedef CLLstack Stack;

void StackInIt(Stack* pstack);

void SPush(Stack* pstack, Data data);

Data SPop(Stack* pstack);

int StackIsEmpty(Stack* pstack);

Data SPeek(Stack* pstack);

#endif