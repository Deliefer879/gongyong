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

	for (i = 0; i < maxLen; i++)//배열의 가장 긴 데이터의 길이만큼 반복
	{
		for (j = 0; j < arrLen; j++)//배열의 길이만큼 반복해 배열의 데이터를 버킷에 저장
		{
			bucketIdx = (arr[j] / devNum) % 10;//초기에는 devNum이 1이라 1의 자리가 구해짐

			EnQueue(&queue[bucketIdx], arr[j]);//버킷으로 이동
		}

		for (j = 0,arrIdx =0; j < BUCKET_NUM; j++)//버킷의 길이만큼 반복
		{
			while (!QueueIsEmpty(&queue[j]))//해당 버킷의 idx에 값이 있으면
				arr[arrIdx++] = DeQueue(&queue[j]); // 저장된 데이터를 순서대로 arr에 다시 복사해 덮어씀
		}

		devNum *= 10;//다음 자릿수를 구하기 위한 devNum증가
	}

}