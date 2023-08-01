#include <stdio.h>
#include <stdlib.h>

#include "BinaryTreeForBinarySearch.h"
#include "TrueOrFalse.h"

BTreeNode* MakeTreeNode(void)
{
	BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	newNode->left = newNode->right = NULL;
	
	return newNode;
}

BTData GetBTData(BTreeNode* bt)
{
	return bt->data;
}

void SetBTData(BTreeNode* bt, BTData data)
{
	bt->data = data;
}

BTreeNode* GetLSubTreeNode(BTreeNode* bt)
{
	return bt->left;
}

BTreeNode* GetRSubTreeNode(BTreeNode* bt)
{
	return bt->right;
}

void MakeLSubTree(BTreeNode* bt, BTreeNode* sub)
{
	if (bt->left != NULL)
		free(bt->left);

	bt->left = sub;
}

void MakeRSubTree(BTreeNode* bt, BTreeNode* sub)
{
	if (bt->right != NULL)
		free(bt->right);

	bt->right = sub;
}

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;
	
	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}

BTreeNode* RemoveLeftSubTree(BTreeNode* bt)
{
	BTreeNode* delNode = NULL;

	if (bt != NULL)
	{
		delNode = bt->left;
		bt->left = NULL;
	}

	return delNode;
}

BTreeNode* RemoveRightSubTree(BTreeNode* bt)
{
	BTreeNode* delNode = NULL;

	if (bt != NULL)
	{
		delNode = bt->right;
		bt->right = NULL;
	}

	return delNode;
}

void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	main->left = sub;
}

void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	main->right = sub;
}