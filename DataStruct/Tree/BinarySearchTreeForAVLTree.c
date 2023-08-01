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
	//�ݸ� ��� 
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

	*pbst = Rebalance(pbst);// ��Ͱ��ƴ� �ݺ����� ������� ������ Ư�� ��Ʈ��尡 �ƴ� ����Ʈ�� ���ο��� �ұ��� �߻��� �̸� �������� ����
	*/

	//��� ��� ����
	if (*pbst == NULL)
	{
		*pbst = MakeTreeNode();
		SetBTData(*pbst, data);
	}
	else if (GetBSTreeNodeData(*pbst) > data)//���� ��Ʈ����� �����Ͱ� ���ο���� ���� ũ�ٸ�
	{
		BSTInsert(&((*pbst)->left), data);//��Ʈ����� ���� �ڽĳ��� insert�Լ� ��� ȣ��
		*pbst= Rebalance(pbst);//���λ��Ե� ����� ��� �θ��带 ������� �������� ����(�ݺ��� ��ݿ��� ���� ���� �ذ�)
	}
	else if (GetBSTreeNodeData(*pbst) < data)
	{
		BSTInsert(&((*pbst)->right), data);
		*pbst = Rebalance(pbst);
	}
	else//������ �ߺ��� ����
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
		BSTree* ccNode;//cnode�� �ڽĳ�� �ӽ� �����
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