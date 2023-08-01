#include <stdio.h>

int InterpolSearch(int arr[],int first,int last,int target);

int main()
{
	int arr[] = { 1,3,5,7,9,11,13 };
	int idx;

	idx = InterpolSearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 12);

	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("arr�� %d�� �� �� : %d\n", idx, arr[idx]);

	return 0;
}

int InterpolSearch(int arr[], int first, int last,int target)
{
	printf("f : %d\nl : %d\n\n", first, last);

	if (arr[first] > target || arr[last] < target)
		return -1;
	
	//int mid = (first + last) / 2; ����Ž������ mid�� �����ϴ� ����
	int searchPoint = ((double)(target - arr[first]) / (arr[last] - arr[first]) * (last - first)) + first;//���� Ž������ Ž���� ��ġ�� ����ϴ� �� (p.429)

	if (arr[searchPoint] == target)
		return searchPoint;

	if (arr[searchPoint] > target)
		return InterpolSearch(arr, first, searchPoint - 1, target);
	else
		return InterpolSearch(arr, searchPoint + 1, last, target);
}
