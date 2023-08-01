#include <stdio.h>
#include <stdlib.h>

#include "BinaryTreeForAVLTree.h"

BTreeNode* MakeTreeNode()
{
	BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	newNode->left = newNode->right = NULL;

	return newNode;
}

void SetBTData(BTreeNode* bt, BTData data)
{
	bt->data = data;
}

BTData GetBTData(BTreeNode* bt)
{
	return bt->data;
}

BTreeNode* GetLSubTreeNode(BTreeNode* bt)
{
	return bt->left;
}

BTreeNode* GetRSubTreeNode(BTreeNode* bt)
{
	return bt->right;
}

void ChangeLSubTreeNode(BTreeNode* main, BTreeNode* sub)
{
	main->left = sub;
}

void ChangeRSubTreeNode(BTreeNode* main, BTreeNode* sub)
{
	main->right = sub;
}

BTreeNode* RemoveLSubTree(BTreeNode* bt)
{
	BTreeNode* delNode = NULL;

	if (bt->left != NULL)
		delNode = bt->left;

	bt->left = NULL;

	return delNode;
}

BTreeNode* RemoveRSubTree(BTreeNode* bt)
{
	BTreeNode* delNode = NULL;

	if (bt->right != NULL)
		delNode = bt->right;

	bt->right = NULL;

	return delNode;
}

void PreorderTraverse(BTreeNode* bt, FuncForTraverse action)
{
	if (bt == NULL)
		return;

	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode* bt, FuncForTraverse action)
{
	if (bt == NULL)
		return;

	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode* bt, FuncForTraverse action)
{
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}