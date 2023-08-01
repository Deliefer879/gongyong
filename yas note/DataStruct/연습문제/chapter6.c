#include <stdio.h>

#include "ListBaseStack.h"
#include "InfixToPostfix.h"

//���� 6-1(chapter5�� CLinkedList.(c,h) ���
/*
	Stack stack;
	Data data;

	StackInIt(&stack);

	for (int i = 0; i < 5; i++)
	{
		SPush(&stack, i + 1);
	}

	printf("%d",SPeek(&stack));
	printf("\n");

	while (!StackIsEmpty(&stack))
	{
		data = SPop(&stack);
		printf("%d ", data);
	}
	printf("\n");
	printf("%d", SPeek(&stack));
	*/

int main()
{
	char exp1[EXP_LEN] = "1+2*3";
	char exp2[EXP_LEN] = "(1+2)*3";
	char exp3[EXP_LEN] = "((1-2)+3)*(5-2)";

	ConvToRPNExp(exp1);//���ڷ� ������ ���� ���ڿ��� ������ �������� �Լ��� ���� �����ϰų� �����Ͽ� �����Ҵ��ѹ迭�� ����� �����ϰų� ��꿡 ���
	ConvToRPNExp(exp2);
	ConvToRPNExp(exp3);

	printf("%s : %d\n", exp1,EvalRPNExp(exp1));
	printf("%s : %d\n", exp2, EvalRPNExp(exp2));
	printf("%s : %d\n", exp3, EvalRPNExp(exp3));



	return 0;
}