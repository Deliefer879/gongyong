#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right);
void MergeSort(int arr[], int left, int right);

int main()
{
	int arr[7] = { 3,2,4,1,7,6,5 };
	int i;

	MergeSort(arr, 0, sizeof(arr) / sizeof(int)-1);

	for (i = 0; i < 7; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int* sortArr = (int*)malloc(sizeof(int) * (right+1));//�ӽ÷� ���ĵ� �迭�� �����ϴ°�(���߿� arr�� �����)

	int leftIdx, rightIdx, sortIdx,i;
	leftIdx = left;
	rightIdx = mid + 1;//left�� mid���� �����ϴ� ���� 1�߰��Ͽ� �ߺ� ����
	sortIdx = left;

	while (leftIdx<=mid && rightIdx<= right)//������ �迭�� ���� �κа� ������ �κ��� ���� ���ϱ����� whlie�� ����
	{										//�� �κ��� �Ѱ��� ������ ������(idx���� Ŀ����) Ż��
		
		if (arr[leftIdx] <= arr[rightIdx])	//���� �κа� ������ �κ��� ���� 1���� ���Ͽ� �������� sortarr�� ����
			sortArr[sortIdx] = arr[leftIdx++];
		else
			sortArr[sortIdx] = arr[rightIdx++];
		
		sortIdx++;//������ sortarr�� idx�� ����
	}

	if (leftIdx > mid)//�迭�� ���� �κ��� ��� �Ű� ���ٸ�
	{
		for (i = rightIdx; i <= right; i++, sortIdx++)//�ݴ��� �κ��� ���� ���� sortarr�� �̵�(�̹� ���ĵ� �����̴� ��������̵��ϸ� ��)
			sortArr[sortIdx] = arr[i];
	}
	else//�迭�� ������ �κ��� ��� �Ű����ٸ�
	{
		for (i = leftIdx; i <= mid; i++, sortIdx++)
			sortArr[sortIdx] = arr[i];
	}

	for (i = left; i <= right; i++)//���� �迭�� arr�� sortarr�� ������ ������ �Ϸ�
		arr[i] = sortArr[i];


	free(sortArr); //�ӽ÷� ������� sortarr����
}

void MergeSort(int arr[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;//�迭�� ���� �߰��� ���ϱ�
		
		//���ȣ���� ���� 2���� ������ (1�����Ǹ� ��͸� Ż���� 2������ ����)
		MergeSort(arr, left, mid);
		MergeSort(arr, mid+1,right);

		MergeTwoArea(arr, left, mid, right);
	}

}
