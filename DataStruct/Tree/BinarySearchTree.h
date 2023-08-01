#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "BinaryTreeForBinarySearch.h"
 
typedef BTData BSTData;

void BSTmakeAndInIt(BTreeNode** pRoot);

BSTData BSTGetNodeData(BTreeNode* bst);

void BSTInsert(BTreeNode** pRoot, BSTData data);

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target);

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target);

void BSTShowAll(BTreeNode* bst);

#endif 