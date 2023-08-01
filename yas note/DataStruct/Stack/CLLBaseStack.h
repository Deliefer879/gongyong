#ifndef __CLL_BASE_STACK_H__
#define __CLL_BASE_STACK_H__

#include "CLinkedList.h"

//���� �ش� ���ϼ����� �������Ḯ��Ʈ�� ����(StackInIt�Լ����� �ʱ�ȭ)
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