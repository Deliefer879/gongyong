#include <stdio.h>

#define ARR_LEN 10

int main()
{
	int i, j;
	int insertData;

	int arr[ARR_LEN];

	for (i = 0; i < ARR_LEN; i++)
		arr[i] = 10 - i;

	for (i = 1; i < ARR_LEN; i++)
	{
		insertData = arr[i];

		for (j = i-1 ; j >=0; j--)
		{
			if (arr[j] > insertData)
				arr[j + 1] = arr[j];//비교한 데이터가 더 클경우 데이터를 1칸 뒤로 이동
			else//반복 위치를 발견 했으니 탈출
				break;
		}
		arr[j+1] = insertData;// 반복 위치를 발견하면서 1감소한 j값을 다시 복구하고 데이터 삽입
	}
		
	for (i = 0; i < ARR_LEN; i++)
		printf("%d ", arr[i]);
	
	
	return 0;
}