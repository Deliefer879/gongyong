#include <stdio.h>

#include "QueueForRadixSort.h"

#define BUCKET_NUM 10

void RadixSort(int arr[], int arrLen, int maxLen);

int main()
{
	int arr[7] = { 13,212,14,7141,10987,6,15 };

	int len = sizeof(arr) / sizeof(int);
	int i;

	RadixSort(arr, len, 5);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	printf("\n");
}


void RadixSort(int arr[], int arrLen, int maxLen)
{
	Queue queue[BUCKET_NUM];

	int j = 0;
	int i = 0;
	int arrIdx = 0;
	int bucketIdx = 0;
	int devNum=1;

	for (i = 0; i < BUCKET_NUM; i++)
		QueueInIt(&queue[i]);

	for (i = 0; i < maxLen; i++)//�迭�� ���� �� �������� ���̸�ŭ �ݺ�
	{
		for (j = 0; j < arrLen; j++)//�迭�� ���̸�ŭ �ݺ��� �迭�� �����͸� ��Ŷ�� ����
		{
			bucketIdx = (arr[j] / devNum) % 10;//�ʱ⿡�� devNum�� 1�̶� 1�� �ڸ��� ������

			EnQueue(&queue[bucketIdx], arr[j]);//��Ŷ���� �̵�
		}

		for (j = 0,arrIdx =0; j < BUCKET_NUM; j++)//��Ŷ�� ���̸�ŭ �ݺ�
		{
			while (!QueueIsEmpty(&queue[j]))//�ش� ��Ŷ�� idx�� ���� ������
				arr[arrIdx++] = DeQueue(&queue[j]); // ����� �����͸� ������� arr�� �ٽ� ������ ���
		}

		devNum *= 10;//���� �ڸ����� ���ϱ� ���� devNum����
	}

}