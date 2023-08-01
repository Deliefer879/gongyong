#ifndef __BINARY_SEARCH_TREE_FOR_AVLTREE_H__
#define __BINARY_SEARCH_TREE_FOR_AVLTREE_H__

#include "BinaryTreeForAVLTree.h"

typedef BTData BSTData;
typedef BTreeNode BSTree;

void MakeBSTreeAndInIt(BSTree** pbst);

BTData GetBSTreeNodeData(BSTree* bst);

BSTree* BSTInsert(BSTree** pbst, BSTData data);

BSTree* BSTDelete(BSTree** pbst,BSTData target);

BSTree* BSTSearch(BSTree* bst, BSTData target);

void ShowBSTree(BSTree* bst);

#endif