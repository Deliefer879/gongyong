#include <stdio.h>

//순차 탐색
void LSearch(int *arr,int len,int target)
{
	int i = 0;
	
	for (i = 0; i < len; i++)
	{
		if (arr[i] == target)
		{
			printf("찾는 숫자의 인덱스 : %d\n", i);
			return;
		}
	}
	printf("찾는 숫자가 없음\n");
	return;
}

//이진 탐색

void BSearch(int *arr,int len,int target)
{
	int first = 0, last = len - 1;
	int mid = (first + last)/2;
	int opCount = 0;

	while (first<=last)
	{
		if (arr[mid] == target)
		{
			printf("찾는 숫자의 인덱스 : %d\n", mid);
			return;
		}
		
		if (target < arr[mid])
			last = mid-1;
		else
			first = mid+1;

		opCount++;
		mid = (first + last) / 2;
	}
	printf("값을 찾지 못함\n");
	printf("비교 횟수 : %d\n",opCount);
}

int main()
{
	int arr[] = {1,3,5,7,9};
	int len = sizeof(arr) / sizeof(int);
	

	int arr1[500] = {0,};
	int arr2[5000] = {0,};
	int arr3[50000] = {0,};

	int len1 = sizeof(arr1) / sizeof(int);
	int len2 = sizeof(arr2) / sizeof(int);
	int len3 = sizeof(arr3) / sizeof(int);

	//BSearch(arr1,len1,1);

	BSearch(arr1,len1,1);
	BSearch(arr2,len2,2);
	BSearch(arr3,len3,3);

}


