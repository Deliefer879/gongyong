#include <stdio.h>//��� ��
#include <string.h>
#include <stdlib.h>
#include <ctype.h>//�ƽ�Ű �ڵ��� ���� �������� �������� �Ǻ��ϰų� �ҹ���,�빮�� ���� �Լ��� ����

#include "InfixToPostfix.h"//å������ ���� ����
#include "ListBaseStack.h"

int EvalRPNExp(char exp[])
{
	Stack stack;
	StackInIt(&stack);

	int i, result;
	int expLen = strlen(exp);

	int n1, n2; //å������ char�� ����
	char temp;

	for (i = 0; i < expLen; i++)
	{
		temp = exp[i];
		if (isdigit(temp))
		{
			//���ڻ����� ���ڿ��� '0'�� ���� ���ڰ��� ex) '1' = �ƽ�Ű�ڵ� 49, '0'�� 48 �� '1'-'0' = 1
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
			SPush(&stack, result);//å������ result ���� swich������ �ٷ� �Լ����ڷ�(n1+n2) ����
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
	Stack stack;//������ ����
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

