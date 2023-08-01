#include <stdio.h>

#include "BinarySearchTree.h"

int main()
{

	BTreeNode* bstRoot;
	BTreeNode* sNode;//search node;
	int i=0;

	BSTmakeAndInIt(&bstRoot);

	BSTInsert(&bstRoot, 5);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 6);

	BSTShowAll(bstRoot);

	printf("\n\n");
	BSTRemove(&bstRoot, 5);

	BSTShowAll(bstRoot);
}