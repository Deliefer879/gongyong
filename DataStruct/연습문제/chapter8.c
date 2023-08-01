#include <stdio.h>

#include "BinaryTree.h"
#include "ExpressionTree.h"

//문제 08-1
/*
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();
	BTreeNode* bt5 = MakeBTreeNode();
	BTreeNode* bt6 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	SetData(bt5, 5);
	SetData(bt6, 6);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	MakeRightSubTree(bt2, bt5);
	MakeLeftSubTree(bt3, bt6);

	PreorderTraverse(bt1, ShowBTData);
	printf("\n");

	DeleteTree(bt2);
	bt1->left = NULL;//bt2삭제시 bt1->left는 참조하는 값을 잃음 NULL로 초기화하여 이다음 실행되는 중위순회를 가능하게 만듬

	InorderTraverse(bt1, ShowBTData);
	printf("\n");

	DeleteTree(bt3);
	bt1->right = NULL;

	PostorderTraverse(bt1, ShowBTData);
	printf("\n");*/

void ShowBTData(BTData data);

int main()
{
	char exp[] = "32+7*";
	BTreeNode* bt = MakeExpressionTree(exp);

	printf("전위 : ");
	ShowPrefixTypeExp(bt); printf("\n\n");

	printf("중위 : ");
	ShowInfixTypeExp(bt); printf("\n\n");

	printf("후위 : ");
	ShowPostfixTypeExp(bt); printf("\n\n");

	printf("계산 결과 : ");
	printf("%d\n",EvaluateExpreessionTree(bt));

}

void ShowBTData(BTData data)
{
	printf("%d ", data);
}