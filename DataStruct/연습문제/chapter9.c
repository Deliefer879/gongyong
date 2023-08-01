#include <stdio.h>
#include <string.h>

#include "UsefulHeap.h"

int Comp(HData d1, HData d2);

int main()
{
	Heap heap;

	HeapInIt(&heap, Comp);

	HInsert(&heap, "1234567890");
	HInsert(&heap, "123");
	HInsert(&heap, "1");
	printf("%s\n", HDelete(&heap));

	HInsert(&heap, "1234");
	HInsert(&heap, "123456789");
	HInsert(&heap, "123456");
	printf("%s\n", HDelete(&heap));

	while (!HeapIsEmpty(&heap))
		printf("%s\n", HDelete(&heap));

	return 0;
}

int Comp(HData d1, HData d2)
{
	int len1 = strlen(d1);
	int len2 = strlen(d2);
	return len2 - len1;//���� 9-1(���ڿ��� ���̰� ª���� �켱)

	//���ĺ������� d1�� �����̸� 0���� ū�� �ڸ� 0���� ���� �� ������ 0
}
