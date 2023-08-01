#ifndef __LIST_BASE_STACK_2_H__
#define __LIST_BASE_STACK_2_H__

#include "BinaryTree.h"
#include "TrueOrFalse.h"

typedef BTreeNode* Data;

typedef struct _node
{
	Data data;
	struct _node* next;
}Node;

typedef struct _LBStack
{
	Node* head;
}LBStack;

typedef LBStack Stack;

void StackInIt(Stack* ps);

int StackIsEmpty(Stack* ps);

void SPush(Stack* ps, Data data);

Data SPop(Stack* ps);

Data SPeek(Stack* ps);

#endif