#include <stdio.h>

#define ARR_LEN 10

int main()
{
	int arr[ARR_LEN];
	int i = 0,j=0;
	int temp,minDataIdx;

	for (i = 0; i < ARR_LEN; i++)
		arr[i] = 10-i;

	for (i = 0; i < ARR_LEN; i++)
	{
		minDataIdx = i;
		for (j = i+1; j < ARR_LEN; j++)
		{
			if (arr[minDataIdx] > arr[j])
				minDataIdx = j;
		}
		temp = arr[i];
		arr[i] = arr[minDataIdx];
		arr[minDataIdx] = temp;
	}

	for (i = 0; i < ARR_LEN; i++)
		printf("%d ", arr[i]);

	return 0;
}