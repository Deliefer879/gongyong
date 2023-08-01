#include <stdio.h>

int InterpolSearch(int arr[],int first,int last,int target);

int main()
{
	int arr[] = { 1,3,5,7,9,11,13 };
	int idx;

	idx = InterpolSearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 12);

	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("arr의 %d번 의 값 : %d\n", idx, arr[idx]);

	return 0;
}

int InterpolSearch(int arr[], int first, int last,int target)
{
	printf("f : %d\nl : %d\n\n", first, last);

	if (arr[first] > target || arr[last] < target)
		return -1;
	
	//int mid = (first + last) / 2; 이진탐색에서 mid를 결정하는 기준
	int searchPoint = ((double)(target - arr[first]) / (arr[last] - arr[first]) * (last - first)) + first;//보간 탐색에서 탐색의 위치를 계산하는 식 (p.429)

	if (arr[searchPoint] == target)
		return searchPoint;

	if (arr[searchPoint] > target)
		return InterpolSearch(arr, first, searchPoint - 1, target);
	else
		return InterpolSearch(arr, searchPoint + 1, last, target);
}
