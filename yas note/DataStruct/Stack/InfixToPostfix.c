#include <stdio.h>//없어도 됨
#include <string.h>
#include <stdlib.h>
#include <ctype.h>//아스키 코드의 값이 문자인지 숫자인지 판별하거나 소문자,대문자 구분 함수등 포함

#include "InfixToPostfix.h"//책에서는 포함 안함
#include "ListBaseStack.h"

int EvalRPNExp(char exp[])
{
	Stack stack;
	StackInIt(&stack);

	int i, result;
	int expLen = strlen(exp);

	int n1, n2; //책에서는 char로 했음
	char temp;

	for (i = 0; i < expLen; i++)
	{
		temp = exp[i];
		if (isdigit(temp))
		{
			//문자상태인 숫자에서 '0'를 빼면 숫자가됨 ex) '1' = 아스키코드 49, '0'은 48 즉 '1'-'0' = 1
			SPush(&stack, temp-'0');
		}
		else
		{
			n2 = SPop(&stack);
			n1 = SPop(&stack);

			switch (temp)
			{
			case'+':
				result = n1 + n2;
				break;
			case'-':
				result = n1 - n2;
				break;
			case'*':
				result = n1 * n2;
				break; 
			case'/':
				result = n1 / n2;
				break; 
			}
			SPush(&stack, result);//책에서는 result 없이 swich문에서 바로 함수인자로(n1+n2) 전달
		}
	}
	return SPop(&stack);

}

int GetOpPrec(char op)
{
	switch (op)
	{
		case '*':
		case'/':
			return 2;
		case '+':
		case '-':
			return 1;
		case '(':
			return 0;
	}

	return -1;
}

int WhoPrecOp(char op1, char op2)
{
	int op1Prior = GetOpPrec(op1);
	int op2Prior = GetOpPrec(op2);

	if (op1Prior > op2Prior)
		return 1;
	else if (op1Prior < op2Prior)
		return -1;
	else
		return 0;
}

void ConvToRPNExp(char exp[])
{
	Stack stack;//연산자 저장
	int expLen = strlen(exp);
	char* convExp = (char*)malloc(expLen + 1);
	
	char temp,popOp;
	int i, idx = 0;
	memset(convExp, 0, sizeof(char) * expLen + 1);

	StackInIt(&stack);

	for (i = 0; i < expLen; i++)
	{
		temp = exp[i];

		if (isdigit(temp))
			convExp[idx++] = temp;
		else
		{
			switch (temp)
			{
			case '(':
				SPush(&stack, temp);
				break;

			case')':
				while (1)
				{
					popOp = SPop(&stack);
					if (popOp == '(')
						break;
					convExp[idx++] = popOp;
				}
				break;
			
			case'+':case'-':
			case'*':case'/':
				while (!StackIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), temp) > -1)
					convExp[idx++] = SPop(&stack);

				SPush(&stack, temp);
				break;
			}
		}
	}
	while (!StackIsEmpty(&stack))
		convExp[idx++] = SPop(&stack);


	strcpy_s(exp, EXP_LEN, convExp);
	free(convExp);

}

