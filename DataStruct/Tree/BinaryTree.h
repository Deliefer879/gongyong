#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
}BTreeNode; 

BTreeNode* MakeBTreeNode(void);

BTData GetData(BTreeNode* bt);

void SetData(BTreeNode* bt, BTData data);

BTreeNode* GetLeftSubTree(BTreeNode* bt);//bt����� ���� ����Ʈ�� �ּҰ� ��ȯ
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);//main��忡 ���ʿ�sub��� ����
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

typedef void VisitFuncPtr(BTData data);
void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);//���� ��ȸ
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action);//���� ��ȸ
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action);//���� ��ȸ

void DeleteTree(BTreeNode* bt);

#endif