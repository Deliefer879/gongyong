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

BTreeNode* GetLeftSubTree(BTreeNode* bt);//bt노드의 왼쪽 서브트리 주소값 반환
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);//main노드에 왼쪽에sub노드 연결
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

typedef void VisitFuncPtr(BTData data);
void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);//전위 순회
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action);//중위 순회
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action);//후위 순회

void DeleteTree(BTreeNode* bt);

#endif