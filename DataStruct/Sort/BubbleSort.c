#include <stdio.h>

#define ARR_LEN 100

int main()
{
	int arr[ARR_LEN];

	int i = 0, j = 0;
	int temp;

	for (i=1; i < ARR_LEN+1; i++)
		arr[ARR_LEN-i] = i;

	for (i =1; i < ARR_LEN; i++)
	{
		for (j = 0; j < ARR_LEN-i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (i = 0; i < ARR_LEN; i++)
		printf("%d ", arr[i]);

	printf("\n");

}