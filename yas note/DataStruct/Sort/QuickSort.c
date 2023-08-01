#include <stdio.h>

void QuickSort(int arr[],int left,int right);
int Partition(int arr[], int left, int right);
void Swap(int arr[], int idx1, int idx2);
void FindPivot(int arr[], int left, int right);

int main()
{
	//int arr[] = { 5,4,3,2,1 };
	int arr[15];

	for (int i = 0; i < 15; i++)
		arr[i] = i + 1;

	int arrLen = sizeof(arr) / sizeof(int);

	int left = 0;
	int right = arrLen - 1;
	int i; 

	QuickSort(arr,left, right);

	for(i =0;i<arrLen;i++)
		printf("%d ", arr[i]);

}

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

void FindPivot(int arr[], int left, int right)
{
	int pArr[] = { left,(left + right) / 2,right };

	if(pArr[0]>pArr[1])
		Swap(pArr, 0, 1);
	if (pArr[1] > pArr[2])
		Swap(pArr, 1, 2);
	if (pArr[0] > pArr[1])
		Swap(pArr, 1, 2);

	Swap(arr, left, pArr[1]);
}

int Partition(int arr[], int left, int right)
{
	FindPivot(arr, left, right);
	int pivot = left;
	int low = pivot + 1;
	int high = right;

	printf("pivot : %d\n", arr[pivot]);

	while (low <= high)
	{
		while (arr[pivot] >= arr[low]&&low<= right)//(arr[pivot] > arr[low]) �̿� ���� ������ �����ϸ� �������� 3�� �� {3,3,3}�� ���� �迭���� 
			low++;																//Ż���� �Ұ����ϴ�
		while (arr[pivot] <= arr[high]&&high>= (left+1))//���� �������� �ǹ��� �����Ͽ����� �׺��� 1ĭ �ձ���
			high--;

		if(low<=high)
			Swap(arr, low, high);
	}

	Swap(arr, pivot, high);

	return high;//�Ű��� �ǹ��� ��ġ(���� �ǹ��� �Ű��� idx��)
}

void QuickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}