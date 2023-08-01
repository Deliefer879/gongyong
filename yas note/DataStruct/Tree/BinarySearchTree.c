#include <stdio.h>
#include <stdlib.h>

#include "BinarySearchTree.h"
#include "TrueOrFalse.h"

void BSTmakeAndInIt(BTreeNode** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode* bst)
{
	return GetBTData(bst);
}

void BSTInsert(BTreeNode** pRoot, BSTData data)
{
	BTreeNode* cNode = *pRoot;
	BTreeNode* pNode = NULL;

	while (cNode != NULL)
	{
		if (cNode->data == data)
		{
			printf("key value overlap\n\n");
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
			MakeLSubTree(pNode, cNode);
		else
			MakeRSubTree(pNode, cNode);
	}
	else
		*pRoot = cNode;
}

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)
{
	//��� ��� ����
	/*
	if (bst == NULL)
	{
		printf("data is not exist : %d -- ",target);
		return NULL;
	}

	if (bst->data == target)
		return bst;
	else if (bst->data > target)
		return BSTSearch(bst->left, target);
	else
		return BSTSearch(bst->right, target);
		*/

	BTreeNode* cNode = bst;

	while (cNode != NULL)
	{
		if (cNode->data == target)
			break;
		else if (cNode->data < target)
			cNode = GetRSubTreeNode(cNode);
		else
			cNode = GetLSubTreeNode(cNode);
	}

	if (cNode == NULL)
	{
		printf("data is not exist : %d -- ", target);
		return NULL;
	}
	else
		return cNode;
}

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target)
{
	BTreeNode* pVRoot = MakeTreeNode(); //���� ��Ʈ ���
	BTreeNode* pNode = pVRoot;//�θ���
	BTreeNode* cNode = *pRoot; //������
	BTreeNode* dNode;//������ ���

	//��Ʈ��带 pVRoot(�����Ʈ ���)�� ������ �ڽĳ�尡 �ǰ� �Ѵ�
	ChangeRightSubTree(pVRoot, *pRoot);

	//��������� ��� Ž��
	while (cNode != NULL && GetBTData(cNode) != target)
	{
		pNode = cNode;
		
		if (target < GetBTData(cNode))
			cNode = GetLSubTreeNode(cNode);
		else
			cNode = GetRSubTreeNode(cNode);
	}

	if (cNode == NULL)// ��������� ������ NULL��ȯ
		return NULL;

	dNode = cNode;
				
	//1��° ������尡 �ܸ������ ���
	if (GetLSubTreeNode(dNode) == NULL && GetRSubTreeNode(dNode)==NULL)
	{
		if (GetLSubTreeNode(pNode) == dNode)
			pNode->left = NULL;
		else
			pNode->right = NULL;
			//dNode = RemoveRightSubTree(pNode);//��ȯ���� �������� �ʾƵ� ���� dNode���� �����Ǵ� ��尡 ����
	}
	//2��° ������尡 1���� �ڽĳ�带 ���Ұ��
	else if (GetLSubTreeNode(dNode)== NULL || GetRSubTreeNode(dNode)==NULL)
	{
		BTreeNode* dcNode;//��������� �ڽĳ��

		if (GetLSubTreeNode(dNode) != NULL)
			dcNode = GetLSubTreeNode(dNode);
		else
			dcNode = GetRSubTreeNode(dNode);

		if (GetLSubTreeNode(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}

	//3��° ������尡 2���� �ڽĳ�带 ���Ұ��(�̰�� ��ȯ�Ǵ� ����� ��ġ�� ���� ��ü����� ��ġ)
										   //(2���� �ڽĳ�尡 �ִ°�� ��������� �ڽİ� �θ� �̾��ִ°��� �ƴ϶� ��ü�� �����ִ� ��带 ã��)
	else                                   //(��ü����� ���� �������� ������� ����Ž�� Ʈ���� �����ϰ� �޸� ��ü�� �ؾ��ϴ� ���� ��ü��尡 ��)
	{
		BTreeNode* mNode = GetRSubTreeNode(dNode);//������带 ��ü�ҳ��(��������� �����ʳ���� �ڽĳ���� ���� ������ ���)
		BTreeNode* mpNode = dNode;//��ü����� �θ���;
		BTData delData;

		while (GetLSubTreeNode(mNode) != NULL)//��ü��� ã��
		{
			mpNode = mNode;
			mNode = GetLSubTreeNode(mNode);
		}

		delData = GetBTData(dNode); //������ ����� ������ ���
		SetBTData(dNode, GetBTData(mNode));//�����ҳ�忡 ��ü����� ������ �����(���� Ž��Ʈ������ ����� ������ �������� ������ ����)

		//��ü����� �θ���� �ڽĳ�� ����
		if (GetLSubTreeNode(mpNode) == mNode)
			//MakeLSubTree(mpNode, GetRSubTreeNode(mNode));			//make�� change�� ���̴� ����� �޸𸮸� �����ϳ� ���ϳ��ε�
			ChangeLeftSubTree(mpNode, GetRSubTreeNode(mNode));		//å������ ȣ��ο��� �޸��� ������ �ϴ� change�� ���Ḹ ���� dNode(���� ��ü���)��ȯ
		else//ó���� GetRSubTreeNode�� �Ҵ��ѳ�尡 ��ü����Ͻ�       //make�Լ��� �����ϴ��� ��ü��带 �޸� �����ϴ°��̹Ƿ� ���� ���� 
			//MakeRSubTree(mpNode, GetRSubTreeNode(mNode));
			ChangeRightSubTree(mpNode, GetRSubTreeNode(mNode));
	}

	//������ ��尡 ��Ʈ ����Ͻ� �߰����� ó�� �ʿ�
	if (GetRSubTreeNode(pVRoot) != *pRoot)
		*pRoot = GetRSubTreeNode(pVRoot); 		//�����Ʈ ����� �������� ��Ʈ���� �����߾��µ� �̴� ó�������� �����ϱ� ����							  
												//���� ��Ʈ��尡 �����Ȱ��̶�� ��Ʈ����� �ּҸ� �ٲ������(��Ʈ��� �Ű������� ����������)
												//�ܸ����ų� �ڽĳ�尡 1���� ��Ȳ�� ��Ʈ��尡 �����Ǹ� ��Ʈ���� NULL�̵ǰų� ���ڽĳ�尡 �Ǳ⶧���� ���� �ʿ�
												//������ �ڽĳ�尡 2���̻��� ��Ȳ������ ��Ʈ��忡 �����͸� ����°��� ���� ����X
												//�� if�� ���� x(����Ǵ°� ��ü���)

	free(pVRoot);//���� ��Ʈ��� �Ҹ�
	return dNode;//������ ��� ��ȯ(�ڽĳ�尡 2���̻��ΰ���� ������ ��ü����� �ּҰ�) ���̿ܿ��� ���� �����Ǵ� ���

}

void ShowBTData(BTData data)
{
	printf("%d ", data);
}

void BSTShowAll(BTreeNode* bst)
{
//	PreorderTraverse(bst,ShowBTData); ���� ��ȸ�� ���� ��Ʈ��� Ȯ���� ����
	InorderTraverse(bst, ShowBTData);
}

