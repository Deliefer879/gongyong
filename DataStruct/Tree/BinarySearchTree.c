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
	//재귀 기반 구현
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
	BTreeNode* pVRoot = MakeTreeNode(); //가상 루트 노드
	BTreeNode* pNode = pVRoot;//부모노드
	BTreeNode* cNode = *pRoot; //현재노드
	BTreeNode* dNode;//삭제할 노드

	//루트노드를 pVRoot(가상루트 노드)의 오른쪽 자식노드가 되게 한다
	ChangeRightSubTree(pVRoot, *pRoot);

	//삭제대상인 노드 탐색
	while (cNode != NULL && GetBTData(cNode) != target)
	{
		pNode = cNode;
		
		if (target < GetBTData(cNode))
			cNode = GetLSubTreeNode(cNode);
		else
			cNode = GetRSubTreeNode(cNode);
	}

	if (cNode == NULL)// 삭제대상이 없을시 NULL반환
		return NULL;

	dNode = cNode;
				
	//1번째 삭제노드가 단말노드일 경우
	if (GetLSubTreeNode(dNode) == NULL && GetRSubTreeNode(dNode)==NULL)
	{
		if (GetLSubTreeNode(pNode) == dNode)
			pNode->left = NULL;
		else
			pNode->right = NULL;
			//dNode = RemoveRightSubTree(pNode);//반환값을 저장하지 않아도 원래 dNode에는 삭제되는 노드가 있음
	}
	//2번째 삭제노드가 1개의 자식노드를 지닐경우
	else if (GetLSubTreeNode(dNode)== NULL || GetRSubTreeNode(dNode)==NULL)
	{
		BTreeNode* dcNode;//삭제노드의 자식노드

		if (GetLSubTreeNode(dNode) != NULL)
			dcNode = GetLSubTreeNode(dNode);
		else
			dcNode = GetRSubTreeNode(dNode);

		if (GetLSubTreeNode(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}

	//3번째 삭제노드가 2개의 자식노드를 지닐경우(이경우 반환되는 노드의 위치는 원래 대체노드의 위치)
										   //(2개의 자식노드가 있는경우 삭제노드의 자식과 부모를 이어주는것이 아니라 대체할 값이있는 노드를 찾고)
	else                                   //(대체노드의 값을 삭제노드로 덮어씌워서 이진탐색 트리를 유지하고 메모리 해체를 해야하는 노드는 대체노드가 됨)
	{
		BTreeNode* mNode = GetRSubTreeNode(dNode);//삭제노드를 대체할노드(삭제노드의 오른쪽노드의 자식노드중 가장 왼쪽의 노드)
		BTreeNode* mpNode = dNode;//대체노드의 부모노드;
		BTData delData;

		while (GetLSubTreeNode(mNode) != NULL)//대체노드 찾기
		{
			mpNode = mNode;
			mNode = GetLSubTreeNode(mNode);
		}

		delData = GetBTData(dNode); //삭제할 노드의 데이터 백업
		SetBTData(dNode, GetBTData(mNode));//삭제할노드에 대체노드의 데이터 덮어쓰기(이진 탐색트리에서 노드의 삭제는 데이터의 덮어쓰기로 진행)

		//대체노드의 부모노드와 자식노드 연결
		if (GetLSubTreeNode(mpNode) == mNode)
			//MakeLSubTree(mpNode, GetRSubTreeNode(mNode));			//make와 change의 차이는 노드의 메모리를 헤제하냐 안하냐인데
			ChangeLeftSubTree(mpNode, GetRSubTreeNode(mNode));		//책에서는 호출부에서 메모리의 해제를 하니 change로 연결만 끊고 dNode(원래 대체노드)반환
		else//처음에 GetRSubTreeNode로 할당한노드가 대체노드일시       //make함수로 삭제하더라도 대체노드를 메모리 해제하는것이므로 문제 없음 
			//MakeRSubTree(mpNode, GetRSubTreeNode(mNode));
			ChangeRightSubTree(mpNode, GetRSubTreeNode(mNode));
	}

	//삭제된 노드가 루트 노드일시 추가적인 처리 필요
	if (GetRSubTreeNode(pVRoot) != *pRoot)
		*pRoot = GetRSubTreeNode(pVRoot); 		//가상루트 노드의 오른쪽을 루트노드로 설정했었는데 이는 처리과정을 통일하기 위함							  
												//만약 루트노드가 삭제된것이라면 루트노드의 주소를 바꿔줘야함(루트노드 매개변수가 더블포인터)
												//단말노드거나 자식노드가 1개인 상황에 루트노드가 삭제되면 루트노드는 NULL이되거나 그자식노드가 되기때문에 변경 필요
												//하지만 자식노드가 2개이상인 상황에서는 루트노드에 데이터를 덮어쓰는거지 노드는 변경X
												//즉 if문 실행 x(변경되는건 대체노드)

	free(pVRoot);//가상 루트노드 소멸
	return dNode;//삭제한 노드 반환(자식노드가 2개이상인경우의 삭제시 대체노드의 주소값) 그이외에는 원래 삭제되는 노드

}

void ShowBTData(BTData data)
{
	printf("%d ", data);
}

void BSTShowAll(BTreeNode* bst)
{
//	PreorderTraverse(bst,ShowBTData); 전위 순회로 볼시 루트노드 확인이 쉬움
	InorderTraverse(bst, ShowBTData);
}

