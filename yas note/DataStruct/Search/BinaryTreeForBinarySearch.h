#ifndef __BINARYTREE_FOR_BINARYSEARCH_H__
#define __BINARYTREE_FOR_BINARYSEARCH_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
}BTreeNode;

BTreeNode* MakeTreeNode(void);

BTData GetBTData(BTreeNode* bt);

void SetBTData(BTreeNode* bt, BTData data);

BTreeNode* GetLSubTreeNode(BTreeNode* bt);

BTreeNode* GetRSubTreeNode(BTreeNode* bt);

void MakeLSubTree(BTreeNode* bt, BTreeNode* sub);

void MakeRSubTree(BTreeNode* bt, BTreeNode* sub);

typedef void VisitFuncPtr(BTData data);

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);

void InorderTraverse(BTreeNode* bt, VisitFuncPtr action);

void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action);

// �ܼ��� �ڽĳ�带 NULL�� �ٲ� �����һ� ���ŵ� ����� �޸� ������ ȣ��ο��� ���
BTreeNode* RemoveLeftSubTree(BTreeNode* bt);

BTreeNode* RemoveRightSubTree(BTreeNode* bt);

//MakeSubTree�Լ��� �ڽĳ�� ����� �װ��� �����ϴµ�
//ChangeSubTree�Լ��� �ܼ� ��ü�� ����
void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub);

void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub);

#endif