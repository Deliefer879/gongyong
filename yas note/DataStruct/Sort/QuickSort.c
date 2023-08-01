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
		while (arr[pivot] >= arr[low]&&low<= right)//(arr[pivot] > arr[low]) 이와 같이 조건을 설정하면 같은값이 3개 들어간 {3,3,3}과 같은 배열에서 
			low++;																//탈출이 불가능하다
		while (arr[pivot] <= arr[high]&&high>= (left+1))//가장 왼쪽으로 피벗을 설정하였으니 그보다 1칸 앞까지
			high--;

		if(low<=high)
			Swap(arr, low, high);
	}

	Swap(arr, pivot, high);

	return high;//옮겨진 피벗의 위치(원래 피벗이 옮겨진 idx값)
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