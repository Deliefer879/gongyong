#include <stdio.h>

//���丮�� �Լ�
int factorial(int n)
{
	return n == 1 ? n : n * factorial(n-1);
	/*
	if (n == 1)
		return 1;
	else
		return n * factorial(n - 1);*/
}

//�Ǻ���ġ ���� �Լ�
int pibonacci(int n)
{
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return pibonacci(n - 1) + pibonacci(n - 2);
}

//��ͷ� ������ ���� Ž��
int bsearchrecur(int *arr,int first,int last,int target)
{
	int mid = (first+last)/2;

	if (first > last)
	{
		printf("�˻� ����\n");
		return 0;
	}

	if (arr[mid] == target)
	{
		printf("Ÿ�� �ε��� �� : %d\n", mid);
		return 0;
	}

	else if (target < arr[mid])
		return bsearchrecur(arr, first, mid - 1, target);
	else
		return bsearchrecur(arr, mid + 1, last, target);
}

//�ϳ��� Ÿ��
void hanoitowermove(int num,char from,char by,char to)
{
	if (num == 1)
		printf("���� 1�� %c���� %c���̵�\n", from, to);
	else
	{
		hanoitowermove(num - 1, from, to, by);
		printf("���� %d�� %c���� %c�� �̵� \n", num, from, to);
		hanoitowermove(num - 1, by, from, to);
	}
}

int main()
{
	hanoitowermove(5, 'a', 'b', 'c');
}