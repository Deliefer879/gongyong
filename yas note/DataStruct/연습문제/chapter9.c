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
	return len2 - len1;//문제 9-1(문자열의 길이가 짧으면 우선)

	//알파벳순으로 d1이 먼저이면 0보다 큰값 뒤면 0보다 작은 값 같으면 0
}
