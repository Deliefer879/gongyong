#ifndef __AVL_TREE_H__
#define __AVL_TREE_H__

//�������� ���� �Լ��� ����
#include "BinaryTreeForAVLTree.h"

//�ش� ���Ͽ� rebalance�Լ��� �����صδ��� �����������δ� ��������
// ������ ���� �Լ��� �����س� �ް����°� ����
//
//int GetHeight(BTreeNode* bst);//��Ʈ����� ����Ʈ���� �� ���̰� ���� ����Ʈ���� ���� ��ȯ
//
//int GetHeightDiff(BTreeNode* bst);//�� ����Ʈ���� ������ �� ��ȯ
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