#include <stdio.h>

#include "ListBaseStack.h"
#include "InfixToPostfix.h"

//문제 6-1(chapter5의 CLinkedList.(c,h) 사용
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

	ConvToRPNExp(exp1);//인자로 전달한 원본 문자열의 변형을 막으려면 함수를 새로 정의하거나 변경하여 동적할당한배열을 만들어 리턴하거나 계산에 사용
	ConvToRPNExp(exp2);
	ConvToRPNExp(exp3);

	printf("%s : %d\n", exp1,EvalRPNExp(exp1));
	printf("%s : %d\n", exp2, EvalRPNExp(exp2));
	printf("%s : %d\n", exp3, EvalRPNExp(exp3));



	return 0;
}