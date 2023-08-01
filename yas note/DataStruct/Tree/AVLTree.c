#include <stdio.h>
#include <stdlib.h>

#include "AVLTree.h"

//실제 avltree구현은 BinarySearchTreeForAVLTree에서 구현

int GetHeight(BTreeNode* bst)
{
	if (bst == NULL)
		return 0;

	int lHeight = GetHeight(bst->left);
	int rHeight = GetHeight(bst->right);

	if (lHeight > rHeight)//단말노드에서는 둘다 l,r 둘다 0이 오니 1반환(단말노드나 양쪽깊이가 같을경우 뭐가 반환되도 어차피 같음)
		return lHeight + 1;
	else
		return rHeight + 1;
}

int GetHeightDiff(BTreeNode* bst)
{
	int lHeight = GetHeight(bst->left);
	int rHeight = GetHeight(bst->right);

	return lHeight - rHeight;
}

BTreeNode* RotateLL(BTreeNode* bst)
{
	BTreeNode* pNode = bst;
	BTreeNode* cNode = bst->left;

	ChangeLSubTreeNode(pNode, cNode->right);
	ChangeRSubTreeNode(cNode, pNode);

	return cNode;
}

BTreeNode* RotateRR(BTreeNode* bst)
{
	BTreeNode* pNode = bst;
	BTreeNode* cNode = bst->right;
	
	ChangeRSubTreeNode(pNode, cNode->left);
	ChangeLSubTreeNode(cNode, pNode);

	return cNode;
}

BTreeNode* RotateLR(BTreeNode* bst)
{
	BTreeNode* pNode = bst;
	BTreeNode* cNode = bst->left;

	ChangeLSubTreeNode(pNode, RotateRR(cNode));
	return RotateLL(pNode);
}

BTreeNode* RotateRL(BTreeNode* bst)
{
	BTreeNode* pNode = bst;
	BTreeNode* cNode = bst->right;

	ChangeRSubTreeNode(pNode, RotateLL(cNode));
	return RotateRR(pNode);
}

BTreeNode* Rebalance(BTreeNode** pbst)
{
	int hDiff = GetHeightDiff(*pbst);

	if (hDiff > 1)
	{
		if (GetHeightDiff(GetLSubTreeNode(*pbst)) > 0)
			*pbst = RotateLL(*pbst);
		else
			*pbst = RotateLR(*pbst);
	}
	else if (hDiff < -1)
	{
		if (GetHeightDiff(GetRSubTreeNode(*pbst)) < 0)
			*pbst = RotateRR(*pbst);
		else
			*pbst = RotateRL(*pbst);
	}

	return *pbst;
}