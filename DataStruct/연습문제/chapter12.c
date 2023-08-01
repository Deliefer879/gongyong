#include <stdio.h>

#include "BinarySearchTreeForAVLTree.h"
#include "AVLTree.h"

int main()
{
	BSTree* avlRoot;
	BSTree* clNode;//current left node
	BSTree* crNode;//current right node

	int i = 0;

	MakeBSTreeAndInIt(&avlRoot);

	for(i=0;i<16;i++)
		BSTInsert(&avlRoot, i+1);

	ShowBSTree(avlRoot);

}