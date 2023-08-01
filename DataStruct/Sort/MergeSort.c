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
	int* sortArr = (int*)malloc(sizeof(int) * (right+1));//임시로 정렬된 배열을 저장하는곳(나중에 arr에 복사용)

	int leftIdx, rightIdx, sortIdx,i;
	leftIdx = left;
	rightIdx = mid + 1;//left가 mid까지 정렬하니 값을 1추가하여 중복 방지
	sortIdx = left;

	while (leftIdx<=mid && rightIdx<= right)//정렬할 배열의 왼쪽 부분과 오른쪽 부분의 값을 비교하기위한 whlie문 시작
	{										//두 부분중 한곳의 정렬이 끝나면(idx값이 커지면) 탈출
		
		if (arr[leftIdx] <= arr[rightIdx])	//왼쪽 부분과 오른쪽 부분의 값을 1개씩 비교하여 작은값을 sortarr에 저장
			sortArr[sortIdx] = arr[leftIdx++];
		else
			sortArr[sortIdx] = arr[rightIdx++];
		
		sortIdx++;//저장후 sortarr의 idx값 증가
	}

	if (leftIdx > mid)//배열의 왼쪽 부분이 모두 옮겨 졌다면
	{
		for (i = rightIdx; i <= right; i++, sortIdx++)//반대쪽 부분의 남은 값을 sortarr로 이동(이미 정렬된 상태이니 순서대로이동하면 끝)
			sortArr[sortIdx] = arr[i];
	}
	else//배열의 오른쪽 부분이 모두 옮겨졌다면
	{
		for (i = leftIdx; i <= mid; i++, sortIdx++)
			sortArr[sortIdx] = arr[i];
	}

	for (i = left; i <= right; i++)//원래 배열인 arr에 sortarr을 복사해 정렬을 완료
		arr[i] = sortArr[i];


	free(sortArr); //임시로 만들었던 sortarr해제
}

void MergeSort(int arr[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;//배열을 나눌 중간값 구하기
		
		//재귀호출을 통해 2개씩 나눈다 (1개가되면 재귀를 탈출해 2개부터 정렬)
		MergeSort(arr, left, mid);
		MergeSort(arr, mid+1,right);

		MergeTwoArea(arr, left, mid, right);
	}

}
