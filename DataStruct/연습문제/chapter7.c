#include <stdio.h>

#include "DequeBaseQueue.h"

int main()
{
	Queue que;

	QueueInIt(&que);

	for (int i = 0; i < 5; i++)
		EnQueue(&que, i + 1);

	while (!QueueIsEmpty(&que))
		printf("%d ", DeQueue(&que));

	QueuePeek(&que);
}