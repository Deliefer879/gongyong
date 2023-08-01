#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree.h"

BTreeNode* MakeExpressionTree(char exp[]); //����Ʈ�� ����
int EvaluateExpreessionTree(BTreeNode* bt);//����Ʈ�� ���

void ShowPrefixTypeExp(BTreeNode* bt);//���� ǥ��
void ShowInfixTypeExp(BTreeNode * bt);//���� ǥ��
void ShowPostfixTypeExp(BTreeNode * bt);//���� ǥ��

#endif