#ifndef __AVL_TREE_H__
#define __AVL_TREE_H__

//리벨런싱 관련 함수들 정의
#include "BinaryTreeForAVLTree.h"

//해더 파일에 rebalance함수만 선언해두더라도 현제기준으로는 문제없다
// 오히려 여러 함수를 선언해놔 햇갈리는걸 방지
//
//int GetHeight(BTreeNode* bst);//루트노드의 서브트리들 중 높이가 높은 서브트리의 높이 반환
//
//int GetHeightDiff(BTreeNode* bst);//두 서브트리의 높이의 차 반환
//
//BTreeNode* RotateLL(BTreeNode* bst);
//
//BTreeNode* RotateRR(BTreeNode* bst);
//
//BTreeNode* RotateLR(BTreeNode* bst);
//
//BTreeNode* RotateRL(BTreeNode* bst);

BTreeNode* Rebalance(BTreeNode** pbst);

#endif