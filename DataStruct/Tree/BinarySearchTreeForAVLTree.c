#include <stdio.h>
#include <stdlib.h>

#include "BinarySearchTreeForAVLTree.h"
#include "AVLTree.h"

void MakeBSTreeAndInIt(BSTree** pbst)
{
	*pbst = NULL;
}

BTData GetBSTreeNodeData(BSTree* bst)
{
	return GetBTData(bst);
}

BSTree * BSTInsert(BSTree** pbst, BSTData data)
{
	//반목문 기반 
	/*
	BSTree* pNode = NULL;
	BSTree* cNode = *pbst;

	while (cNode != NULL)
	{
		if (cNode->data == data)
		{
			printf("key value overlap\n");
			return;
		}

		pNode = cNode;
		
		if (cNode->data > data)
			cNode = GetLSubTreeNode(cNode);
		else
			cNode = GetRSubTreeNode(cNode);
	}

	cNode = MakeTreeNode();
	SetBTData(cNode, data);

	if (pNode != NULL)
	{
		if (pNode->data > data)
			ChangeLSubTreeNode(pNode, cNode);
		else
			ChangeRSubTreeNode(pNode, cNode);
	}
	else
		*pbst = cNode;

	*pbst = Rebalance(pbst);// 재귀가아닌 반복문을 기반으로 구성시 특정 루트노드가 아닌 서브트리 내부에서 불균형 발생시 이를 감지하지 못함
	*/

	//재귀 기반 구현
	if (*pbst == NULL)
	{
		*pbst = MakeTreeNode();
		SetBTData(*pbst, data);
	}
	else if (GetBSTreeNodeData(*pbst) > data)//현제 루트노드의 데이터가 새로운데이터 보다 크다면
	{
		BSTInsert(&((*pbst)->left), data);//루트노드의 왼쪽 자식노드로 insert함수 재귀 호출
		*pbst= Rebalance(pbst);//새로삽입된 노드의 모든 부모노드를 대상으로 리벨런싱 실행(반복문 기반에서 생긴 문제 해결)
	}
	else if (GetBSTreeNodeData(*pbst) < data)
	{
		BSTInsert(&((*pbst)->right), data);
		*pbst = Rebalance(pbst);
	}
	else//데이터 중복시 실행
	{
		printf("key value over lap");
		return NULL;
	}

	return *pbst;
}

BSTree* BSTDelete(BSTree** pbst,BSTData target)
{
	BSTree* pVNode = MakeTreeNode();
	BSTree* pNode = pVNode;
	BSTree* cNode = *pbst;
	
	ChangeRSubTreeNode(pVNode, *pbst);

	while (cNode != NULL && cNode->data != target)
	{
		pNode = cNode;

		if (cNode->data > target)
			cNode = GetLSubTreeNode(cNode);
		else
			cNode = GetRSubTreeNode(cNode);
	}

	if (cNode == NULL)
	{
		printf("no delete data\n");
		return NULL;
	}

	if (GetLSubTreeNode(cNode) == NULL && GetRSubTreeNode(cNode)==NULL)
	{
		if (GetLSubTreeNode(pNode) == cNode)
			pNode->left = NULL;
		else
			pNode->right = NULL;
	}
	else if (GetLSubTreeNode(cNode) == NULL || GetRSubTreeNode(cNode) == NULL)
	{
		BSTree* ccNode;//cnode의 자식노드 임시 저장소
		if (GetLSubTreeNode(cNode) == NULL)
			ccNode = GetRSubTreeNode(cNode);
		else
			ccNode = GetLSubTreeNode(cNode);

		if (GetLSubTreeNode(pNode) == cNode)
			ChangeLSubTreeNode(pNode, ccNode);
		else
			ChangeRSubTreeNode(pNode, ccNode);
	}
	else
	{
		BSTree* rNode = GetRSubTreeNode(cNode);
		BSTree* rpNode = cNode; 
		BSTData delData;

		while (GetLSubTreeNode(rNode) != NULL)
		{
			rpNode = rNode;
			rNode = GetLSubTreeNode(rNode);
		}

		delData = GetBSTreeNodeData(cNode);

		SetBTData(cNode, GetBSTreeNodeData(rNode));

		if (GetLSubTreeNode(rpNode) == rNode)
			ChangeLSubTreeNode(rpNode, GetRSubTreeNode(rNode));
		else
			ChangeRSubTreeNode(rpNode, GetRSubTreeNode(rNode));

		cNode = rNode;
	}

	if (GetRSubTreeNode(pVNode) != *pbst)
	{
		printf("root node change\n");
		*pbst = GetRSubTreeNode(pVNode);
	}

	*pbst = Rebalance(pbst);

	free(pVNode);
	return cNode;
}

BSTree* BSTSearch(BSTree* bst, BSTData target)
{
	BSTree* cNode = bst;

	while (cNode != NULL)
	{
		if (cNode->data == target)
			break;
		
		if (cNode->data > target)
			GetLSubTreeNode(cNode);
		else
			GetRSubTreeNode(cNode);
	}

	if (cNode == NULL)
	{
		printf("no search data\n");
		return NULL;
	}

	return cNode;

}

void ShowBSTData(BSTData data)
{
	printf("%d ", data);
}

void ShowBSTree(BSTree* bst)
{
	PreorderTraverse(bst, ShowBSTData);
	//InorderTraverse(bst, ShowBSTData);
}