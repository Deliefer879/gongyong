#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "ExpressionTree.h"
#include "ListBaseStack2.h"

BTreeNode* MakeExpressionTree(char exp[])
{
	Stack stack;
	StackInIt(&stack);

	int expLen = strlen(exp);
	
	int i = 0;
	char oper;

	BTreeNode* data;

	for (i = 0; i < expLen; i++)
	{
		oper = exp[i];
		data = MakeBTreeNode();

		if (isdigit(oper))
			SetData(data, oper-'0');
		else
		{
			SetData(data, oper);
			MakeRightSubTree(data, SPop(&stack));
			MakeLeftSubTree(data, SPop(&stack));
		}

		SPush(&stack, data);
	}

	return SPop(&stack);
}

void ShowNodeData(int data)
{
	if (data >= 0 && data <= 9)
		printf("%d",data);
	else
		printf("%c", data);
}

int EvaluateExpreessionTree(BTreeNode* bt)
{
	int op1, op2;

	if (GetRightSubTree(bt) == NULL && GetLeftSubTree(bt) == NULL)
		return GetData(bt);

	op1 = EvaluateExpreessionTree(GetLeftSubTree(bt));
	op2 = EvaluateExpreessionTree(GetRightSubTree(bt));

	switch (GetData(bt))
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}

	return 0;
}

void ShowPrefixTypeExp(BTreeNode* bt)
{
	PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode* bt)
{
	if (bt == NULL)
		return;
	
	if (bt->left != NULL && bt->right != NULL)
		printf("(");

	ShowInfixTypeExp(bt->left);
	ShowNodeData(bt->data);
	ShowInfixTypeExp(bt->right);

	if (bt->left != NULL || bt->right != NULL)
		printf(")");

}

void ShowPostfixTypeExp(BTreeNode* bt)
{
	PostorderTraverse(bt, ShowNodeData);
}
