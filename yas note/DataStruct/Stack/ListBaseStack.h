#ifndef __LIST_BASE_STACK_H__
#define __LIST_BASE_STACK_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
}Node;

typedef struct _listStack
{
	Node* head;
}ListStack;

typedef ListStack Stack;

void StackInIt(Stack * pstack);

void SPush(Stack* pstack,Data data);

Data SPop(Stack *pstack);

int StackIsEmpty(Stack *pstack);

Data SPeek(Stack *pstack);

#endif
