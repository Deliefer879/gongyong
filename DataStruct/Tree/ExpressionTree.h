#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree.h"

BTreeNode* MakeExpressionTree(char exp[]); //수식트리 구성
int EvaluateExpreessionTree(BTreeNode* bt);//수식트리 계산

void ShowPrefixTypeExp(BTreeNode* bt);//전위 표기
void ShowInfixTypeExp(BTreeNode * bt);//중위 표기
void ShowPostfixTypeExp(BTreeNode * bt);//후위 표기

#endif