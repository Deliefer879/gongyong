#ifndef __INFIX_TO_POSTFIX_H__
#define __INFIX_TO_POSTFIX_H__

#define EXP_LEN 30

#define TRUE 1
#define FALSE 0

void ConvToRPNExp(char exp[]);

int GetOpPrec(char op);

int WhoPrecOp(char op1, char op2);

//å������ ���� �ش� ���� ����(������)
int EvalRPNExp(char exp[]);

#endif