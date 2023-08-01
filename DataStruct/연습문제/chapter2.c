#include <stdio.h>

//팩토리얼 함수
int factorial(int n)
{
	return n == 1 ? n : n * factorial(n-1);
	/*
	if (n == 1)
		return 1;
	else
		return n * factorial(n - 1);*/
}

//피보나치 수열 함수
int pibonacci(int n)
{
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return pibonacci(n - 1) + pibonacci(n - 2);
}

//재귀로 구현한 이진 탐색
int bsearchrecur(int *arr,int first,int last,int target)
{
	int mid = (first+last)/2;

	if (first > last)
	{
		printf("검색 실패\n");
		return 0;
	}

	if (arr[mid] == target)
	{
		printf("타겟 인덱스 값 : %d\n", mid);
		return 0;
	}

	else if (target < arr[mid])
		return bsearchrecur(arr, first, mid - 1, target);
	else
		return bsearchrecur(arr, mid + 1, last, target);
}

//하노이 타워
void hanoitowermove(int num,char from,char by,char to)
{
	if (num == 1)
		printf("원반 1을 %c에서 %c로이동\n", from, to);
	else
	{
		hanoitowermove(num - 1, from, to, by);
		printf("원반 %d을 %c에서 %c로 이동 \n", num, from, to);
		hanoitowermove(num - 1, by, from, to);
	}
}

int main()
{
	hanoitowermove(5, 'a', 'b', 'c');
}