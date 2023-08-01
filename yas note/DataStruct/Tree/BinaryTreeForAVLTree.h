#ifndef __BINARY_TREE_FOR_AVLTREE_H__
#define __BINARY_TREE_FOR_AVLTREE_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
}BTreeNode;

BTreeNode * MakeTreeNode();

void SetBTData(BTreeNode* bt,BTData data);

BTData GetBTData(BTreeNode* bt);

BTreeNode* GetLSubTreeNode(BTreeNode* bt);

BTreeNode* GetRSubTreeNode(BTreeNode* bt);

void ChangeLSubTreeNode(BTreeNode* main, BTreeNode* sub);

void ChangeRSubTreeNode(BTreeNode* main, BTreeNode* sub);

BTreeNode* RemoveLSubTree(BTreeNode* bt);

BTreeNode* RemoveRSubTree(BTreeNode* bt);

typedef void FuncForTraverse(BTData data);

void PreorderTraverse(BTreeNode* bt, FuncForTraverse action);

void InorderTraverse(BTreeNode* bt, FuncForTraverse action);

void PostorderTraverse(BTreeNode* bt, FuncForTraverse action);

#endif