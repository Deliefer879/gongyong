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

// 단순히 자식노드를 NULL로 바꿔 제거할뿐 제거된 노드의 메모리 해제는 호출부에서 담당
BTreeNode* RemoveLeftSubTree(BTreeNode* bt);

BTreeNode* RemoveRightSubTree(BTreeNode* bt);

//MakeSubTree함수는 자식노드 존재시 그값을 삭제하는데
//ChangeSubTree함수는 단순 교체만 진행
void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub);

void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub);

#endif